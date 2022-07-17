MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Merci d'utiliser le système\nCADEAU MYST.\pEn tenant la CARTE MIRACLE,\nvous pouvez effectuer des\psondages dans les BOUTIQUES\nPOKéMON.\pUtilisez ces sondages pour inviter\ndes DRESSEURS à ATALANOPOLIS.\pLaissez-moi vous donner un mot\nde passe secret:\p«DONNE-MOI\nUN COMBAT»\pEcrivez ça sur un sondage et\nenvoyez-le au SYSTEME DE\pCOMMUNICATION SANS FIL.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Merci d'utiliser le système\nCADEAU MYST.\pUn DRESSEUR arrivé à ATALANOPOLIS\nvous cherche.\pOn espère que vous apprecierez\nle combat contre ce DRESSEUR.\pVous pouvez inviter des DRESSEURS\nen entrant le mot de passe.\pEssayez de trouver des mots de\npasse qui pourraient fonctionner.$"
