/*
 * stat_data.inc
 *
 *  Created: 2017-01-09 03:57:20
 *  Author: Hanna Bj�rk & Sara Billberg
 *	H�mta, rensa och lagra statistik �ver t�rningskast
 */ 
;=======================================================================
; 7 Byte p� startadress 0x200
;=======================================================================
init_stat_data:
.DSEG
.ORG		0x200
STAT:		.BYTE		7
.CSEG


;=======================================================================
; Lagra statistik �ver t�rningskasten
; R16 = temp register f�r v�rde fr�n och till STAT
; R24 = t�rningens v�rde
;=======================================================================
store_stat:
	LDI			XL,			LOW(STAT) 
	LDI			XH,			HIGH(STAT)	
	LD			R16,		X
	INC			R16
	ST			X,			R16
	ADD			XL,			R24
	LD			R16,		X 
	INC			R16
	ST			X,			R16
	RET
;=======================================================================
; H�mta statistik �ver alla t�rningskast
; R24 - statistik/resultat
;=======================================================================
 get_stat:
	LDI				XL,		LOW(STAT) 
	LDI				XH,		HIGH(STAT)	
	ADD				XL,		R24	
	LD				R24,	X
	RET

			

;=======================================================================
; Rensa all sparad statistik
;=======================================================================
 clear_stat:
	LDI				R16,	0
	LDI				R24,	6
 clearloop:	
 	LDI				XL,		LOW(STAT) 
	LDI				XH,		HIGH(STAT)	
	ADD				XL,		R24
	ST				X,		R16
	DEC				R24
	CPI				R24,	-1
	BRNE			clearloop
	RET
