InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad:
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, FALSE
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, FALSE
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, FALSE
	end

InsideOfTruck_OnResume:
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags::
	lockall
	msgbox InsideOfTruck_Text_AskNuzlocke, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_EnableNuzlocke
InsideOfTruck_EventScript_AskCheats::
	msgbox InsideOfTruck_Text_AskCheats, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, InsideOfTruck_EventScript_ContinueIntroFlags
	setflag FLAG_NO_CHEATS
	msgbox InsideOfTruck_Text_CheatsOff, MSGBOX_DEFAULT
InsideOfTruck_EventScript_ContinueIntroFlags::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBox::
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"


InsideOfTruck_EventScript_EnableNuzlocke::
	setflag FLAG_HARDCORE_NUZLOCKE
	msgbox InsideOfTruck_Text_NuzlockeOn, MSGBOX_DEFAULT
	goto InsideOfTruck_EventScript_AskCheats

InsideOfTruck_Text_AskNuzlocke:
	.string "Enable Hardcore Nuzlocke Rules?\n"
	.string "One catch per area, fainted POKéMON\l"
	.string "go to the DEAD box, no battle items,\l"
	.string "mandatory nicknames, wipe = game over.$"

InsideOfTruck_Text_AskCheats:
	.string "Turn the CHEAT and DEBUG menus on?\n"
	.string "Choose NO for a fair playthrough.\l"
	.string "This can't be changed later.$"

InsideOfTruck_Text_CheatsOff:
	.string "Cheats are OFF.\n"
	.string "Play fair!$"

InsideOfTruck_Text_NuzlockeOn:
	.string "Hardcore Nuzlocke Rules are ON.\n"
	.string "Good luck!$"
