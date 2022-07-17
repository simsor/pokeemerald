ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Salut, DRESSEUR!\nQuel magnifique sourire tu as là!\pJ'ai une passion. Je rassemble les\nprofils de DRESSEURS de POKéMON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Alors, qu'en dis-tu?\nJe peux voir ton profil?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Pour créer son propre profil,\nil faut associer quatre mots ou\lgroupes de mots.\pJe vais donner un exemple de profil\nconstitué de quatre segments de texte.\pChacun remplace, à sa guise, ces quatre\nsegments de texte par d'autres, de\lfaçon à dépeindre son propre profil.\pLes mots que l'on peut utiliser sont\nnombreux.\pIls sont classés par catégories, telles\nque POKéMON, vie quotidienne, hobbies,\lpermettant de les trouver facilement.\pIl faut d'abord choisir une catégorie\npour afficher une liste de choix.\pEnsuite, il faut sélectionner son choix.\pIl suffit de refaire pareil pour les\nautres choix et le profil est déterminé.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Oui! Merci!\nAlors, voyons ton profil!$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Oh non, vraiment?\pJ'imagine que quelqu'un comme toi\ndoit avoir un merveilleux profil…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh? Tu ne veux pas le faire maintenant?\pComme tu veux!$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Salut, DRESSEUR!\nQuel magnifique sourire tu as!$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Puis-je voir ton nouveau profil?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Oui! Merci!\pJ'espère que ce sera encore mieux que\nle profil que tu m'as déjà montré.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, tu aimes ton profil tel qu'il est.\pJe ne t'en blâme pas. C'est devenu un\ntrès bon profil.$"

ProfileMan_Text_FantasticProfile:
	.string "F… Fantastique!\pTon profil est génial!\nIl révèle vraiment qui tu es.\pTu sais, en voyant ce profil, on est\nforcément captivé par toi!\pMerci!$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh?\nYou know the secret saying!\pThat means you're now a fellow member\nof the MYSTERY EVENT CLUB!$"
