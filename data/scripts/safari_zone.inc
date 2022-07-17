SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	setwarp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	warp MAP_ROUTE121_SAFARI_ZONE_ENTRANCE, 2, 5
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Voulez-vous quitter le PARC SAFARI\ntout de suite?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong! Le temps est écoulé!\nVotre partie de SAFARI est terminée.$"

SafariZone_Text_OutOfBalls:
	.string "Vous n'avez plus de SAFARI BALLS.\nVotre partie de SAFARI est terminée.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Voulez-vous placer un {POKEBLOCK}\ndans la MANGEOIRE {POKEBLOCK}?$"

SafariZone_Text_PokeblockStillHere:
	.string "Le {STR_VAR_1} que vous aviez\nplacé là y est encore.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Le {STR_VAR_1} a été placé\ndans la MANGEOIRE {POKEBLOCK}.$"

Route121_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Bienvenue dans le PARC SAFARI!\pIci, vous pourrez admirer de nombreuses\nespèces de POKéMON rares à HOENN.\pEt vous pourrez les voir à l'état\nsauvage, dans leur habitat naturel.\pDe plus, les DRESSEURS DE POKéMON\nsont les bienvenus dans ce parc.\pVous êtes encouragés à attraper des\nPOKéMON et à les garder!\pEntrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Bienvenue au PARC SAFARI!\nC'est la première fois que vous venez?$"

Route121_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Entrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Lorsque vous entrez dans le PARC\nSAFARI, vous recevez 30 SAFARI\lBALLS pour attraper des POKéMON.\pLa partie de SAFARI se termine lorsque\nvous n'avez plus de SAFARI BALLS ou\llorsque vous avez parcouru 500 pas.\pEntrez et amusez-vous au PARC SAFARI!$"

Route121_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Bienvenue au PARC SAFARI!\pAttrapez un max de POKéMON pour 500¥!\nVoulez-vous faire un SAFARI?$"

Route121_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "D'accord.\nRevenez nous voir une autre fois!$"

Route121_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Vous n'avez pas assez d'argent.\nDésolé.$"

Route121_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Cela fera 500¥, s'il vous plaît.$"

Route121_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Voici vos SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} reçoit 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "Nous vous préviendrons quand votre\nSAFARI sera terminé.\pEn attendant, amusez-vous bien!\nProfitez de votre équipée sauvage!$"

Route121_SafariZoneEntrance_Text_PCIsFull:
	.string "Je regrette!\nLa BOITE de votre PC est pleine.$"

Route121_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Je regrette!\nVous n'avez pas de BOITE {POKEBLOCK}S.\pVous attraperez bien plus de POKéMON\nsi vous utilisez des {POKEBLOCK}S.\pRevenez nous voir avec une\nBOITE {POKEBLOCK}S.\pOn vous en fournira peut-être une dans\nla SALLE DE CONCOURS de NENUCRIQUE.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Votre temps n'est pas encore écoulé.\nVoulez-vous quitter le PARC SAFARI?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Amusez-vous bien et profitez de votre\néquipée sauvage!$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "Bien.\pJe vais reprendre vos SAFARI BALLS\nrestantes.\pMerci d'avoir joué.\nNous espérons vous revoir bientôt.$"

SafariZone_South_Text_GoodLuck:
	.string "Bonne chance!\pSi vous avez besoin de quoi que ce soit,\nn'hésitez pas à venir me voir!$"

SafariZone_South_Text_Boy:
	.string "Le savais-tu?\pSi tu mets un {POKEBLOCK} dans cette boîte\ncarrée, les POKéMON tourneront autour.$"

SafariZone_South_Text_Man:
	.string "J'aimerais bien continuer plus loin, mais\nj'ai oublié d'apporter un VELO.\pQuelque chose me dit que des POKéMON\nrares vivent dans les zones reculées.$"

SafariZone_Southwest_Text_Woman:
	.string "Parfois, j'envoie un {POKEBLOCK} à un\nPOKéMON, mais il l'ignore.\pEst-ce que les POKéMON ont des\npréférences en matière de nourriture?$"

SafariZone_Northwest_Text_Man:
	.string "Pfou… Pfou…\nJe… J'ai réussi à venir jusqu'ici, mais…\pJe suis épuisé… Je n'ai plus la force\nd'attraper des POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "J'ai pour mission de trouver des\nPOKéMON EAU introuvables à HOENN.\pTu sais où se trouve le lac?$"

SafariZone_North_Text_Man:
	.string "Je vais attraper plein de POKéMON rares\nici et je les échangerai avec mes amis!$"

SafariZone_South_Text_Youngster:
	.string "J'ai mis un {POKEBLOCK} dans la MANGEOIRE.\nMais apparemment, il a disparu.\pJe suppose qu'un POKéMON l'a mangé\npendant que je ne regardais pas.$"

Route121_SafariZoneEntrance_Text_TrainerTip:
	.string "PARC SAFARI - CONSEIL AUX DRESSEURS!\pLancez des {POKEBLOCK}S aux POKéMON\nsauvages pour éviter qu'ils s'enfuient.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "«Reposez vos jambes fatiguées.»\nREFUGE$"

SafariZone_RestHouse_Text_Youngster:
	.string "Je n'ai pas de {POKEBLOCK}, mais j'ai quand\nmême attrapé beaucoup de POKéMON.\pTu peux augmenter tes chances\nd'attraper un POKéMON en t'approchant\lavant de jeter une SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Si tu leur donnes des {POKEBLOCK}S, les\nPOKéMON s'enfuient moins vite.\pÇa ne sert pas à grand-chose de donner\ndes {POKEBLOCK}S aux POKéMON qui ne\lsont pas farouches.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Si tu mets un {POKEBLOCK} dans la MANGEOIRE,\nça attirera les POKéMON.\pJe crois que certains types de POKéMON\nsont attirés par certains {POKEBLOCK}S.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Cette zone est encore en construction.\nVous ne pouvez pas entrer, désolé!$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Les travaux d'agrandissement du\nPARC SAFARI sont terminés.\pNous espérons que la nouvelle zone\nvous apportera entière satisfaction.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Cette zone est encore en construction.\nVous ne pouvez pas entrer, désolé!$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Waouh! Délire! C'est la première fois que\nje vois ce genre de POKéMON!$"

SafariZone_Southeast_Text_FatMan:
	.string "Je n'avais jamais vu aucun des POKéMON\nde cette zone.\pEt j'ai le droit d'attraper tous ces\nPOKéMON rares? Trop cool!$"

SafariZone_Southeast_Text_RichBoy:
	.string "Je ne pense pas que les POKéMON qui\nse trouvent ici soient de HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Il ne me reste que quelques\nSAFARI BALLS.\pJ'ai du mal à décider ce que je dois\nattraper.$"

SafariZone_Northeast_Text_Woman:
	.string "On dit qu'il y a des PIKACHU ici.\nJe me demande bien où ils se cachent.$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, bouh!\nJe n'arrive à rien ici!\pJ'ai payé l'entrée, il faut absolument\nque j'attrape quelque chose!$"
