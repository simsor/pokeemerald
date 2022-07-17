MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Merci d'utiliser le système\nCADEAU MYST.\pLa CARTE COMBAT garde la trace\nde vos combats contre les\pDRESSEURS ayant la même\nCARTE.\pRecherchez les DRESSEURS ayant\nla même carte que vous.\pVous pouvez voir le classement\ngénéral en lisant les JOURNAUX.\pVous devriez essayer!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Merci d'utiliser le système\nCADEAU MYST.\pFélicitations!\pVous recevez un prix pour avoir\ngagné trois combats!\pOn espère que ça vous donnera\nencore plus envie de combattre.$"
