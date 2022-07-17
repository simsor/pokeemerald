MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special GetHipsterSpokenFlag
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase, MSGBOX_DEFAULT
	special SetHipsterSpokenFlag
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Salut, je suis le BROCANTEUR. Tu veux\néchanger des décorations avec moi?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\nJe me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Mais, nous avons déjà échangé des\ndécorations, toi et moi.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Si tu veux un objet décoratif que j'ai,\nn'hésite pas à me le demander.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Tu ne veux rien?\nBouh, je n'intéresse personne…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "A l'époque, cette décoration\nappartenait à {STR_VAR_1}.\pTu la veux?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Hé… Une minute! Tu ne possèdes aucune\ndécoration!$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Très bien, choisis la décoration que tu\nveux échanger avec moi.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Tu ne veux rien échanger avec moi?\nBouh, je me sens rejeté…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Tu as déjà tous les objets de cette\ncatégorie. Tu n'as plus de place.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Alors, on échange {STR_VAR_3}\ncontre {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Tu utilises déjà cette décoration.\nTu ne peux pas l'échanger.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Dans ce cas, faisons l'échange!\nJ'enverrai ma décoration dans ton PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Ah non, pas cet objet!\pC'est une décoration vraiment rare.\nJe ne peux pas te l'échanger!\pIl n'y a rien d'autre qui t'intéresse?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
    .string "Je suis le CONTEUR.\nJe peux te raconter l'histoire de\lDRESSEURS légendaires.\pAlors, tu veux écouter mon histoire?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
    .string "Oh…\nJe me sens frustré…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
    .string "J'en connais, des légendes.\nQuelle histoire veux-tu que je raconte?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
    .string "Mais je ne connais aucun DRESSEUR\nlégendaire. Donc, pas d'histoire.\pOù peut-on trouver un DRESSEUR digne\nd'entrer dans la légende?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
    .string "De quoi?!?\nToi… Tu as…\p{STR_VAR_2}\n{STR_VAR_1} fois?!?\pMais c'est formidable! C'est la\nnaissance d'une nouvelle légende!$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
    .string "Mais j'y pense, il y a peut-être encore\nd'autres DRESSEURS à découvrir, avec\ldes légendes plus impressionnantes?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
    .string "Et toi, tu es DRESSEUR?\pAlors dis-moi, as-tu des histoires à me\nraconter, même vaguement légendaires?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
    .string "Incidentally… Would you care to hear\nanother legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
    .string "Hum…\nJe suis un peu déçu…\pJ'aurais aimé que tu me racontes une\nhistoire digne d'être appelée légende.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
    .string "J'aimerais bien que plus de gens\ns'intéressent à mes épiques sagas de\lDRESSEURS légendaires.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
    .string "Le DRESSEUR à la sauvegarde facile$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
    .string "sauvegardé la partie$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a sauvegardé sa partie\n{STR_VAR_1} fois!\pImpossible de trouver un DRESSEUR plus\nprudent que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
    .string "Le DRESSEUR qui lançait des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
    .string "lancé des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a lancé de nouvelles modes\n{STR_VAR_1} fois!\p{STR_VAR_3} lance des modes dans toute\nla région de HOENN!$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
    .string "Le DRESSEUR qui plantait des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
    .string "planté des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a planté\n{STR_VAR_1} BAIES!\p{STR_VAR_3} est connu pour être un\ngrand amateur de BAIES!$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
    .string "Le DRESSEUR fan de VELOS$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
    .string "changé de VELO$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a changé de VELO\n{STR_VAR_1} fois!\p{STR_VAR_3} doit aimer les VELOS à\nla folie!$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
    .string "Le DRESSEUR interviewé$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
    .string "répondu à une interview$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a été interviewé\n{STR_VAR_1} fois!\p{STR_VAR_3} est vraiment un DRESSEUR\ntrès médiatisé!$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
    .string "Le DRESSEUR combattant$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
    .string "combattu$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a combattu {STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR qui ne rate\npas une occasion de se battre!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
    .string "Le DRESSEUR chasseur de POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
    .string "attrapé des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a attrapé\n{STR_VAR_1} POKéMON!\p{STR_VAR_3} est un chasseur de POKéMON\nsauvages légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
    .string "Le DRESSEUR pêcheur$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
    .string "attrapé des POKéMON avec une CANNE$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a attrapé\n{STR_VAR_1} POKéMON en les pêchant!\p{STR_VAR_3} est un pêcheur légendaire!$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
    .string "Le DRESSEUR qui couvait des OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
    .string "fait éclore des OEUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a fait éclore {STR_VAR_1}\nOEUF(S) de POKéMON!\p{STR_VAR_3} s'occupe formidablement\nbien des OEUFS!$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
    .string "Le DRESSEUR aux POKéMON évolués$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
    .string "fait évoluer des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a fait évoluer {STR_VAR_1}\nPOKéMON!\p{STR_VAR_3} est un pro de l'évolution\ndes POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
    .string "Le DRESSEUR fan de CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
    .string "utilisé des CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a soigné des\nPOKéMON {STR_VAR_1} fois dans des\lCENTRES POKéMON!\pIl n'existe pas de plus grand fan de\nCENTRES POKéMON que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
    .string "Le DRESSEUR casanier$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
    .string "soigné des POKéMON à la maison$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a soigné ses POKéMON\nà la maison {STR_VAR_1} fois!\pIl n'existe pas de DRESSEUR plus\ncasanier que {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
    .string "Le DRESSEUR fan de SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
    .string "pénétré dans le PARC SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR est entré dans le\nPARC SAFARI {STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR qui exprime\nson côté sauvage au PARC SAFARI!$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
    .string "Le DRESSEUR à la COUPE facile$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
    .string "utilisé COUPE$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a utilisé COUPE\n{STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR qui adore\nutiliser COUPE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
    .string "Le DRESSEUR ECLATE-ROC$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
    .string "éclaté des rochers$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a utilisé ECLATE-ROC\n{STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR qui ne peut\npas laisser un rocher entier!$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
    .string "Le DRESSEUR qui aime déménager$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
    .string "déplacé ta BASE SECRETE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a déplacé sa BASE\nSECRETE {STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR qui adore\ndéménager!$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
    .string "Le DRESSEUR fou de TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
    .string "utilisé TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a utilisé TREMPETTE\n{STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR qui adore\nfaire TREMPETTE!$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
    .string "Le DRESSEUR tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
    .string "fini par utiliser LUTTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a dû utiliser LUTTE\n{STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR tenace qui\nn'abandonne jamais face à l'adversité!$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
    .string "Le champion des MACHINES A SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
    .string "eu le jackpot aux MACHINES A SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a gagné le jackpot aux\nMACHINES A SOUS {STR_VAR_1} fois.\p{STR_VAR_3} est un DRESSEUR qui a eu de\nla chance aux MACHINES A SOUS!$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
    .string "Le champion de la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
    .string "gagné consécutivement à la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a gagné à la ROULETTE\n{STR_VAR_1} fois de suite.\p{STR_VAR_3} a eu beaucoup de chance\nà la ROULETTE!$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
    .string "Le candidat à la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
    .string "relevé les défis de la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a relevé les défis de la\nTOUR DE COMBAT {STR_VAR_1} fois!\p{STR_VAR_3} est un DRESSEUR cherchant\nà être premier dans la TOUR DE COMBAT!$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
    .string "Le DRESSEUR qui aime mixer$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
    .string "fait des {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a fait des {POKEBLOCK}S\n{STR_VAR_1} fois!\pPersonne n'utilise un MIXEUR mieux\nque {STR_VAR_3}!$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
    .string "Le DRESSEUR fan de CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
    .string "participé à des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a participé à des\nCONCOURS {STR_VAR_1} fois!\p{STR_VAR_3} adore exhiber ses\nPOKéMON devant un public!$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
    .string "Le maître des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
    .string "gagné des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a gagné des CONCOURS\n{STR_VAR_1} fois!\p{STR_VAR_3} doit être incroyablement\ndoué pour les CONCOURS!$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
    .string "Le joyeux consommateur$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
    .string "acheté des objets$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a acheté des objets\ndans un magasin {STR_VAR_1} fois!\p{STR_VAR_3} doit être l'un de ces\nDRESSEURS nés pour faire des achats.$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
    .string "Le DRESSEUR chercheur d'objets$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
    .string "utilisé un CHERCH'OBJET$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a utilisé un CHERCH'OBJET\n{STR_VAR_1} fois!\p{STR_VAR_3} doit aimer sonder le sol\npour trouver des objets cachés!$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
    .string "Le DRESSEUR trempé jusqu'aux os$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
    .string "pris une averse$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a été trempé jusqu'aux\nos par la pluie {STR_VAR_1} fois!\pLe charisme de {STR_VAR_3} doit même\nattirer la pluie!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
    .string "Le lecteur de POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
    .string "vérifié ton POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a vérifié son POKéDEX\n{STR_VAR_1} fois!\p{STR_VAR_3} doit adorer en apprendre\nplus sur les POKéMON dans son POKéDEX!$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
    .string "Le collectionneur de RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
    .string "reçu des RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a reçu des RUBANS\n{STR_VAR_1} fois!\p{STR_VAR_3} doit être un DRESSEUR qui\nadore collectionner les RUBANS!$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
    .string "Le DRESSEUR qui saute des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
    .string "sauté des talus$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a sauté des talus\n{STR_VAR_1} fois!\p{STR_VAR_3} ne peut pas s'empêcher de\nsauter d'un talus!$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
    .string "Le téléspectateur légendaire$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
    .string "regardé la télé$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a regardé la télé\n{STR_VAR_1} fois!\p{STR_VAR_3} doit adorer regarder\nla télé!$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
    .string "Le DRESSEUR conscient du temps$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
    .string "regardé l'heure$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a regardé l'heure\n{STR_VAR_1} fois!\p{STR_VAR_3} doit être un DRESSEUR\nponctuel, toujours conscient du temps.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
    .string "Le magicien de la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
    .string "gagné à la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a gagné à la LOTERIE\nPOKéMON {STR_VAR_1} fois!\p{STR_VAR_3} doit avoir de nombreux amis\navec qui échanger des POKéMON!$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
    .string "Le DRESSEUR client de la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
    .string "laissé des POKéMON à la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a laissé des POKéMON à\nla PENSION {STR_VAR_1} fois!\p{STR_VAR_3} doit être un vrai battant\nqui élève ses POKéMON avec énergie!$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
    .string "Le DRESSEUR fan du TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
    .string "fait le trajet en TELEPHERIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR a pris le TELEPHERIQUE\n{STR_VAR_1} fois!\p{STR_VAR_3} doit être un DRESSEUR\nsurmené qui passe son temps à voyager!$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
    .string "Le DRESSEUR fan de sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
    .string "pris un bain dans les sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
    .string "Il était une fois un DRESSEUR du nom\nde {STR_VAR_3}.\pCe DRESSEUR s'est baigné dans les\nsources chaudes {STR_VAR_1} fois!\p{STR_VAR_3} doit être un DRESSEUR avec\nune peau de bébé!$"

MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Je m'appelle PAPOTEUR!\nJ'ai une super histoire à te raconter!\pTu veux l'écouter?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\nTu m'as déprimé…"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Et puis aussi, je me disais…"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Eh bien, c'est tout, je pense…\pOn discutera plus tard!\nCiao!"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Bonjour, je suis CAPELO.\nTu veux entendre ma chanson?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\nTu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, quelle chanson émouvante… Je\nvoudrais pouvoir la chanter aux autres.$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Alors?\nQu'est-ce que tu penses de ma chanson?\pMais je ne suis pas très content des\nparoles.\pÇa te plairait d'écrire de nouvelles\nparoles pour moi?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\nTu me files le blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Merci beaucoup!\nJe vais la chanter pour toi.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Tu la voulais bien comme ça, ta chanson?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Super! La chanson est finie, alors. Je\nvais la chanter pendant longtemps.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Yo, toi! On m'appelle MINET.\nJe vais te montrer ce qui est à la mode.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Hé, mais je t'ai déjà montré ce qui est\nà la mode en ce moment.\pMaintenant, j'aimerais prêcher la bonne\nparole aux autres.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Mais, tu sais déjà ce qui est à la mode\nen ce moment.\pJe n'ai rien de nouveau à t'apprendre!$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfPhrase:
	.string "Hé, t'as entendu parler de\n«{STR_VAR_1}»?\pQu'est-ce que ça veut dire? Heu…\nT'as qu'à demander à ta maman, OK?$"
