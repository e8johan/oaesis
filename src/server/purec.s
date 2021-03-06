	XDEF link_in
	XDEF link_remove
	XDEF set_stack
	XDEF newmvec
	XDEF newbvec
	XDEF newtvec
	XDEF get_stack
	XDEF vdicall
	XDEF accstart
	XDEF VsetScreen
	XDEF VsetMode

	XREF aes_call
	XREF old_motion_vector
	XREF old_button_vector
	XREF catch_mouse_motion
	XREF catch_mouse_buttons
	XREF catch_timer_click
	XREF p_fsel_extern
	XREF aescall

	TEXT
	
myxgemdos:
	cmp.w		#$c8,d0
	bne		retaddr

	movem.l	d0-d7/a0-a6,-(sp)

    move.l  p_fsel_extern,a0
    tst.w   (a0)
    beq     intern

    move.l  d1,a0
    move.l  (a0),a0
    cmp.w   #$5a,(a0)
    beq    ignore
    cmp.w   #$5b,(a0)
    beq    ignore

intern:
	move.l	d1,a0
	jsr		aes_call
	movem.l	(sp)+,d0-d7/a0-a6

	rte
	
ignore:
    movem.l (sp)+,d0-d7/a0-a6
retaddr:
	jmp		link_in;

link_in:
	move.l	$88,retaddr+2;
	move.l	#myxgemdos,$88
	rts;

link_remove:
	move.l	retaddr+2,$88;
	rts;


set_stack:
	move.l	(sp),-(a0)
	move.l	a0,sp
	rts

newmvec:
	move.l sp,newstack+800
	lea newstack+800,sp
	movem.l	d0-d2/a0-a2,-(sp)
	move.l  d1,-(sp)
	move.l  d0,-(sp)
	jsr	catch_mouse_motion
	addq.l  #8,sp
	movem.l	(sp)+,d0-d2/a0-a2
	move.l (sp),sp
	rts

newbvec:
	move.l sp,newstack+800
	lea newstack+800,sp
	movem.l	d0-d2/a0-a2,-(sp)
	move.l	d0,-(sp)
	jsr	catch_mouse_buttons
	addq.l	#4,sp
	movem.l	(sp)+,d0-d2/a0-a2
	move.l  (sp),sp
	rts

newtvec:
	move.l sp,newstack+800
	lea newstack+800,sp
	movem.l	d0-d2/a0-a2,-(sp)
	jsr	catch_timer_click
	movem.l	(sp)+,d0-d2/a0-a2
	move.l  (sp),sp
	rts

vdicall:
	move.l a0,d1
	move.l #$73,d0
	trap   #2
	rts

accstart:
	move.l 4(sp),a0
	move.l 16(a0),a1
	move.l a1,8(a0)
	add.l  12(a0),a1
	move.l a1,16(a0)
	move.l 8(a0),a1
	jmp (a1)

VsetScreen:
	move.w d1,-(sp)
	move.w d0,-(sp)
	move.l a1,-(sp)
	move.l a0,-(sp)
	move.w #$05,-(sp)
	trap   #14
	lea    14(sp),sp
	rts
		
VsetMode:
	move.w d0,-(sp)
	move.w #$58,-(sp)
	trap   #14
	addq.l #4,sp
	rts

aescall:
	move.l a0,d1
	move.l #200,d0
	trap   #2
	rts
		
	.even
mmov:
	dc.w 0,2,0,0
mbut:
	dc.w 0,1,1,0
mtim:
	dc.w 0,0,0,20
	
newstack:
	ds.l 201
