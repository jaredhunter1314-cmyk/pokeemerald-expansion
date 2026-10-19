# JARED'S EMERALD — project status and build notes

This file tracks the custom ROM-hack work in this repository. A feature is not considered build-verified or gameplay-tested until the relevant automated checks and a successful ROM build are confirmed.

## Target features

- [ ] Custom title-screen branding: JARED'S EMERALD (custom logo graphic is present; final ROM boot still needs verification)
- [ ] Randomized starter choices, generated once when a new game enters starter selection
- [ ] Stable randomized wild encounters, keyed to the save's trainer ID, map, encounter type, and encounter slot
- [ ] Expanded species roster using Pokémon supported by the expansion base
- [ ] Eight Gym Leaders, four Elite Four members, and the Champion have custom six-Pokémon teams
- [ ] Each major boss team has exactly one Legendary and one starter-family Pokémon
- [ ] Exactly one explicitly shiny Pokémon on each Gym Leader team
- [ ] Hard experience and Rare Candy level caps, aligned with each custom boss team's maximum level
- [ ] In-game JARED'S ITEMS menu, including item, money, coin, and Battle Point options
- [ ] Reproducible build, regression tests, and BPS patch generation

## Current source-level review

- The 13 configured major boss teams were inspected: each has six Pokémon, one Legendary, one starter-family Pokémon, and the expected maximum level.
- Each of the eight Gym Leader teams has exactly one `Shiny: Yes` entry.
- The team-check script now also checks that all 13 team maximum levels match the expected cap values.
- The custom Start menu retains its normal Exit option alongside JARED'S ITEMS.
- These are source-level checks only. They do not prove that the ROM compiles, boots, or plays correctly.

## Build and patch workflow

The GitHub Actions workflow is `.github/workflows/jareds-emerald-build.yml`. It runs on pushes to `jareds-emerald-dev` and can also be started from the repository's **Actions** tab using **JARED'S EMERALD - Build and Patch** → **Run workflow**.

The workflow is configured to:

1. Run the BPS generator's built-in self-test.
2. Run `tools/check_jareds_emerald_teams.py`.
3. Build the custom Emerald ROM.
4. Run the pokeemerald regression test suite with `make check`.
5. Build the matching clean Emerald source and verify its SHA-1 against the expected US revision 0 hash.
6. Generate a BPS patch and verify that applying it recreates the built custom ROM.
7. Upload `jareds-emerald.bps` as an artifact named `jareds-emerald-patch`, retained for 14 days.

A successful source build alone is not proof of gameplay correctness. The patch artifact must exist and be downloadable before delivery can be considered complete.

## Delivery constraints

- Target game: Pokémon Emerald, English, revision 0.
- Intended play device: iPhone emulator.
- Do not commit or distribute a copyrighted ROM image. The clean base is built from source in the workflow; the user keeps their own ROM private.
- A BPS patch must be applied to the matching clean Emerald US revision 0 ROM.

## Latest known state

- Development branch: `jareds-emerald-dev`
- The branch contains custom gameplay code, boss teams, cap configuration, title branding, menu changes, static acceptance checks, a BPS generator, and a GitHub Actions build workflow.
- Recent commits added cap-to-team-level checks, enabled the regression test suite in the workflow, and restored the Exit option to the custom Start menu.
- **Build/patch delivery status: not yet confirmed.** Do not mark the project complete until a successful workflow run and its `jareds-emerald-patch` artifact have been verified.
