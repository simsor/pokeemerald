MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Merci d'utiliser le système\nCADEAU MYST.\pIl y a de plus en plus de rumeurs\nsur l'apparition de POKéMON rares.\pLes rumeurs parlent de la GROTTE\nMETAMO sur la ROUTE 103.\pVous devriez y aller pour vérifier\nsi les rumeurs sont vraies.$"
