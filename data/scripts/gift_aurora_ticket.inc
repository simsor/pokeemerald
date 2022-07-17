MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Merci d'utiliser le système\nCADEAU MYST.\pVous devez être {PLAYER}.\nIl y a un ticket pour vous.$"

sText_AuroraTicketUseAtPort:
	.string "Il peut être utilisé au port de\nNENUCRIQUE.\pEssayez-le pour voir de quoi \nil s'agit.$"

sText_AuroraTicketThankYou:
	.string "Merci d'utiliser le système\nCADEAU MYST.$"

sText_AuroraTicketBagFull:
	.string "Oh, je regrette, {PLAYER}. La POCHE\nOBJ. RARES du SAC est pleine.\pFaites de la place dans votre SAC\net revenez me voir.$"
