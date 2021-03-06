/*
 * tarning.inc
 *
 *  Created: 2016-12-15 13:40:35
 *  Author: Sara Billberg, Hanna Bj�rk
 *
 */ 
;==============================================================================
; Ett t�rningskast
; R21 - antal t�rningssidor, de siffror som kan uppst� vid kastet
; R24 - vilken knapp �r nedtryckt fr�n read_keyboard_num
;==============================================================================
roll_dice:
	LDI			R21,		6		;dice have 6 values
test: 
	NOP
	NOP
	RCALL		read_keyboard_num	;key-value in R24
	CPI			R24,		TWO_KEY
	BREQ		roll				;yes, key 2 is still pressed
	RET								;no, key is released
roll: 
	DEC			R21
	BREQ		roll_dice			;R16 is zero, start agn at 6
	RJMP		test				;no, keep rolling