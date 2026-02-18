	.arch armv8.5-a
	.build_version macos,  26, 0
	.text
	.zerofill __DATA,__bss,_logStream,8,3
	.cstring
	.align	3
lC0:
	.ascii "log_st_%s.txt\0"
	.align	3
lC1:
	.ascii "w\0"
	.align	3
lC2:
	.ascii "fopen\0"
	.text
	.align	2
_logInitialise:
LFB23:
	sub	sp, sp, #304
LCFI0:
	stp	x29, x30, [sp, 16]
LCFI1:
	add	x29, sp, 16
LCFI2:
	str	x0, [x29, 24]
	add	x3, x29, 32
	ldr	x0, [x29, 24]
	str	x0, [sp]
	adrp	x0, lC0@PAGE
	add	x2, x0, lC0@PAGEOFF;
	mov	x1, 256
	mov	x0, x3
	bl	_snprintf
	add	x2, x29, 32
	adrp	x0, lC1@PAGE
	add	x1, x0, lC1@PAGEOFF;
	mov	x0, x2
	bl	_fopen
	mov	x1, x0
	adrp	x0, _logStream@PAGE
	add	x0, x0, _logStream@PAGEOFF;
	str	x1, [x0]
	adrp	x0, _logStream@PAGE
	add	x0, x0, _logStream@PAGEOFF;
	ldr	x0, [x0]
	cmp	x0, 0
	bne	L3
	adrp	x0, lC2@PAGE
	add	x0, x0, lC2@PAGEOFF;
	bl	_perror
	mov	w0, 1
	bl	_exit
L3:
	nop
	ldp	x29, x30, [sp, 16]
	add	sp, sp, 304
LCFI3:
	ret
LFE23:
	.align	2
_logClose:
LFB24:
	stp	x29, x30, [sp, -16]!
LCFI4:
	mov	x29, sp
LCFI5:
	adrp	x0, _logStream@PAGE
	add	x0, x0, _logStream@PAGEOFF;
	ldr	x0, [x0]
	cmp	x0, 0
	beq	L6
	adrp	x0, _logStream@PAGE
	add	x0, x0, _logStream@PAGEOFF;
	ldr	x0, [x0]
	bl	_fclose
	adrp	x0, _logStream@PAGE
	add	x0, x0, _logStream@PAGEOFF;
	str	xzr, [x0]
L6:
	nop
	ldp	x29, x30, [sp], 16
LCFI6:
	ret
LFE24:
	.cstring
	.align	3
lC3:
	.ascii "Log stream not initialized. Call logInitialise() first.\12\0"
	.text
	.align	2
_streamLog:
LFB25:
	stp	x29, x30, [sp, -48]!
LCFI7:
	mov	x29, sp
LCFI8:
	str	x0, [x29, 24]
	adrp	x0, _logStream@PAGE
	add	x0, x0, _logStream@PAGEOFF;
	ldr	x0, [x0]
	cmp	x0, 0
	bne	L8
	adrp	x0, ___stderrp@GOTPAGE
	ldr	x0, [x0, ___stderrp@GOTPAGEOFF]
	ldr	x0, [x0]
	mov	x3, x0
	mov	x2, 56
	mov	x1, 1
	adrp	x0, lC3@PAGE
	add	x0, x0, lC3@PAGEOFF;
	bl	_fwrite
	b	L7
L8:
	add	x0, x29, 48
	str	x0, [x29, 40]
	adrp	x0, _logStream@PAGE
	add	x0, x0, _logStream@PAGEOFF;
	ldr	x0, [x0]
	ldr	x1, [x29, 40]
	mov	x2, x1
	ldr	x1, [x29, 24]
	bl	_vfprintf
L7:
	ldp	x29, x30, [sp], 48
LCFI9:
	ret
LFE25:
	.zerofill __DATA,__bss,_warningFile,8,3
	.zerofill __DATA,__bss,_noticeFile,8,3
	.zerofill __DATA,__bss,_timeFormat,8,3
	.zerofill __DATA,__bss,_timeValue,8,3
	.text
	.align	2
_currentTime:
LFB26:
	stp	x29, x30, [sp, -32]!
LCFI10:
	mov	x29, sp
LCFI11:
	adrp	x0, _timeValue@PAGE
	add	x0, x0, _timeValue@PAGEOFF;
	bl	_time
	adrp	x0, _timeValue@PAGE
	add	x0, x0, _timeValue@PAGEOFF;
	bl	_localtime
	mov	x1, x0
	adrp	x0, _timeFormat@PAGE
	add	x0, x0, _timeFormat@PAGEOFF;
	str	x1, [x0]
	adrp	x0, _timeFormat@PAGE
	add	x0, x0, _timeFormat@PAGEOFF;
	ldr	x0, [x0]
	bl	_asctime
	str	x0, [x29, 24]
	ldr	x0, [x29, 24]
	add	x0, x0, 24
	strb	wzr, [x0]
	ldr	x0, [x29, 24]
	ldp	x29, x30, [sp], 32
LCFI12:
	ret
LFE26:
	.cstring
	.align	3
lC4:
	.ascii "a+\0"
	.align	3
lC5:
	.ascii "log_Warnings.txt\0"
	.text
	.align	2
_warningLog:
LFB27:
	stp	x29, x30, [sp, -16]!
LCFI13:
	mov	x29, sp
LCFI14:
	adrp	x0, _warningFile@PAGE
	add	x0, x0, _warningFile@PAGEOFF;
	ldr	x0, [x0]
	cmp	x0, 0
	bne	L13
	adrp	x0, lC4@PAGE
	add	x1, x0, lC4@PAGEOFF;
	adrp	x0, lC5@PAGE
	add	x0, x0, lC5@PAGEOFF;
	bl	_fopen
	mov	x1, x0
	adrp	x0, _warningFile@PAGE
	add	x0, x0, _warningFile@PAGEOFF;
	str	x1, [x0]
	adrp	x0, _warningFile@PAGE
	add	x0, x0, _warningFile@PAGEOFF;
	ldr	x0, [x0]
	cmp	x0, 0
	bne	L13
	adrp	x0, lC2@PAGE
	add	x0, x0, lC2@PAGEOFF;
	bl	_perror
	mov	w0, 1
	bl	_exit
L13:
	adrp	x0, _warningFile@PAGE
	add	x0, x0, _warningFile@PAGEOFF;
	ldr	x0, [x0]
	ldp	x29, x30, [sp], 16
LCFI15:
	ret
LFE27:
	.align	2
	.globl _func


_func:
LFB29:
	stp	x29, x30, [sp, -48]!
LCFI16:
	mov	x29, sp
LCFI17:
	str	d15, [sp, 16]
LCFI18:
	str	d0, [x29, 40]
	ldr	d0, [x29, 40]
	bl	_cos
	fmov	d30, d0
	ldr	d31, [x29, 40]
	fmul	d15, d30, d31
	ldr	d0, [x29, 40]
	bl	_sin
	fmov	d31, d0
	fsub	d31, d15, d31
	fmov	d0, d31
	ldr	d15, [sp, 16]
	ldp	x29, x30, [sp], 48
LCFI19:
	ret
LFE29:
	.cstring
	.align	3
lC6:
	.ascii "bisection\0"
	.align	3
lC7:
	.ascii "%*c c %*c|%*c f(c)\12\0"
	.align	3
lC8:
	.ascii "Retry by shifting values on number line\0"
	.align	3
lC9:
	.ascii "Both roots (%f) are same\0"
	.align	3
lC10:
	.ascii "%f is a root\0"
	.align	3
lC11:
	.ascii " %*.*lf | %*.*lf \12\0"
	.align	3
lC12:
	.ascii "Warning [%s]\12\11\11L%03d  |  %s : \12\11Loop has run too many iterations. Force stopping for safety.\12\12\0"
	.align	3
lC13:
	.ascii "bisection.c\0"
	.align	3
lC14:
	.ascii "Value of root is %.10lf\12\0"
	.align	3
lC15:
	.ascii "Number of iterations: %d\12\0"
	.text
	.align	2
	.globl _bisect

	
_bisect:
LFB30:
	sub	sp, sp, #176
LCFI20:
	stp	x29, x30, [sp, 48]
LCFI21:
	add	x29, sp, 48
LCFI22:
	str	x19, [sp, 64]
LCFI23:
	str	d0, [x29, 40]
	str	d1, [x29, 32]
	str	wzr, [x29, 108]
	ldr	d1, [x29, 32]
	ldr	d0, [x29, 40]
	bl	_fmax
	fmov	d31, d0
	fabs	d31, d31
	fcvtzs	w0, d31
	str	w0, [x29, 104]
	str	wzr, [x29, 100]
	mov	w0, 15
	str	w0, [x29, 96]
	mov	w0, 10000
	str	w0, [x29, 92]
	b	L18
L19:
	ldr	w0, [x29, 104]
	mov	w1, 26215
	movk	w1, 0x6666, lsl 16
	smull	x1, w0, w1
	lsr	x1, x1, 32
	asr	w1, w1, 2
	asr	w0, w0, 31
	sub	w0, w1, w0
	str	w0, [x29, 104]
	ldr	w0, [x29, 100]
	add	w0, w0, 1
	str	w0, [x29, 100]
L18:
	ldr	w0, [x29, 104]
	cmp	w0, 0
	bgt	L19
	adrp	x0, lC6@PAGE
	add	x0, x0, lC6@PAGEOFF;
	bl	_logInitialise
	ldr	w1, [x29, 100]
	ldr	w0, [x29, 96]
	add	w0, w1, w0
	add	w0, w0, 2
	lsr	w1, w0, 31
	add	w0, w1, w0
	asr	w0, w0, 1
	mov	w2, w0
	ldr	w1, [x29, 100]
	ldr	w0, [x29, 96]
	add	w0, w1, w0
	lsr	w1, w0, 31
	add	w0, w1, w0
	asr	w0, w0, 1
	mov	w3, w0
	ldr	w1, [x29, 100]
	ldr	w0, [x29, 96]
	add	w0, w1, w0
	add	w0, w0, 2
	lsr	w1, w0, 31
	add	w0, w1, w0
	asr	w0, w0, 1
	mov	w1, w0
	mov	w0, 32
	str	w0, [sp, 40]
	str	w1, [sp, 32]
	mov	w0, 32
	str	w0, [sp, 24]
	str	w3, [sp, 16]
	mov	w0, 32
	str	w0, [sp, 8]
	str	w2, [sp]
	adrp	x0, lC7@PAGE
	add	x0, x0, lC7@PAGEOFF;
	bl	_streamLog
	ldr	d0, [x29, 40]
	bl	_func
	str	d0, [x29, 80]
	ldr	d0, [x29, 32]
	bl	_func
	str	d0, [x29, 72]
	ldr	d30, [x29, 80]
	ldr	d31, [x29, 72]
	fmul	d31, d30, d31
	str	d31, [x29, 64]
	adrp	x0, lC16@PAGE
	ldr	d31, [x0, #lC16@PAGEOFF]
	str	d31, [x29, 56]
	adrp	x0, lC16@PAGE
	ldr	d31, [x0, #lC16@PAGEOFF]
	str	d31, [x29, 48]
	str	xzr, [x29, 112]
	str	xzr, [x29, 120]
	ldr	d31, [x29, 64]
	fcmpe	d31, #0.0
	bgt	L38
	b	L42
L38:
	adrp	x0, lC8@PAGE
	add	x0, x0, lC8@PAGEOFF;
	bl	_printf
	b	L22
L42:
	ldr	d31, [x29, 64]
	fcmp	d31, #0.0
	bne	L23
	ldr	d31, [x29, 80]
	fcmp	d31, #0.0
	bne	L24
	ldr	d31, [x29, 72]
	fcmp	d31, #0.0
	bne	L24
	adrp	x0, lC9@PAGE
	add	x0, x0, lC9@PAGEOFF;
	b	L25
L24:
	adrp	x0, lC10@PAGE
	add	x0, x0, lC10@PAGEOFF;
L25:
	ldr	d31, [x29, 80]
	fcmp	d31, #0.0
	bne	L26
	ldr	d31, [x29, 40]
	b	L27
L26:
	ldr	d31, [x29, 32]
L27:
	str	d31, [sp]
	bl	_printf
	b	L22
L23:
	ldr	d31, [x29, 64]
	fcmpe	d31, #0.0
	bmi	L39
	b	L22
L39:
	ldr	d30, [x29, 40]
	ldr	d31, [x29, 32]
	fadd	d30, d30, d31
	fmov	d31, 2.0e+0
	fdiv	d31, d30, d31
	str	d31, [x29, 112]
	ldr	d0, [x29, 112]
	bl	_func
	str	d0, [x29, 120]
	b	L29
L36:
	ldr	d30, [x29, 40]
	ldr	d31, [x29, 32]
	fadd	d30, d30, d31
	fmov	d31, 2.0e+0
	fdiv	d31, d30, d31
	str	d31, [x29, 112]
	ldr	d0, [x29, 40]
	bl	_func
	str	d0, [x29, 80]
	ldr	d0, [x29, 32]
	bl	_func
	str	d0, [x29, 72]
	ldr	d0, [x29, 112]
	bl	_func
	str	d0, [x29, 120]
	ldr	d31, [x29, 120]
	fcmp	d31, #0.0
	beq	L44
	ldr	d30, [x29, 120]
	ldr	d31, [x29, 80]
	fmul	d31, d30, d31
	fcmpe	d31, #0.0
	bmi	L40
	b	L43
L40:
	ldr	d31, [x29, 112]
	str	d31, [x29, 32]
	b	L34
L43:
	ldr	d31, [x29, 112]
	str	d31, [x29, 40]
L34:
	ldr	w1, [x29, 100]
	ldr	w0, [x29, 96]
	add	w0, w1, w0
	add	w2, w0, 2
	ldr	w1, [x29, 100]
	ldr	w0, [x29, 96]
	add	w0, w1, w0
	add	w0, w0, 2
	ldr	d31, [x29, 120]
	str	d31, [sp, 40]
	ldr	w1, [x29, 96]
	str	w1, [sp, 32]
	str	w0, [sp, 24]
	ldr	d31, [x29, 112]
	str	d31, [sp, 16]
	ldr	w0, [x29, 96]
	str	w0, [sp, 8]
	str	w2, [sp]
	adrp	x0, lC11@PAGE
	add	x0, x0, lC11@PAGEOFF;
	bl	_streamLog
	ldr	w0, [x29, 108]
	add	w0, w0, 1
	str	w0, [x29, 108]
	ldr	w1, [x29, 108]
	ldr	w0, [x29, 92]
	cmp	w1, w0
	ble	L29
	bl	_warningLog
	mov	x19, x0
	bl	_currentTime
	mov	x1, x0
	adrp	x0, lC13@PAGE
	add	x0, x0, lC13@PAGEOFF;
	str	x0, [sp, 16]
	mov	w0, 52
	str	w0, [sp, 8]
	str	x1, [sp]
	adrp	x0, lC12@PAGE
	add	x1, x0, lC12@PAGEOFF;
	mov	x0, x19
	bl	_fprintf
	b	L31
L29:
	ldr	d30, [x29, 32]
	ldr	d31, [x29, 40]
	fsub	d31, d30, d31
	ldr	d30, [x29, 56]
	fcmpe	d30, d31
	bls	L41
	b	L31
L41:
	ldr	d31, [x29, 120]
	fabs	d31, d31
	ldr	d30, [x29, 48]
	fcmpe	d30, d31
	bls	L36
	b	L31
L44:
	nop
L31:
	ldr	d31, [x29, 112]
	str	d31, [sp]
	adrp	x0, lC14@PAGE
	add	x0, x0, lC14@PAGEOFF;
	bl	_printf
	ldr	w0, [x29, 108]
	str	w0, [sp]
	adrp	x0, lC15@PAGE
	add	x0, x0, lC15@PAGEOFF;
	bl	_printf
	b	L17
L22:
	bl	_logClose
	nop
L17:
	ldp	x29, x30, [sp, 48]
	ldr	x19, [sp, 64]
	add	sp, sp, 176
LCFI24:
	ret
LFE30:
	.cstring
	.align	3
lC17:
	.ascii "Enter end points of range to look for:\0"
	.align	3
lC18:
	.ascii "%lf\0"
	.align	3
lC19:
	.ascii "\33[A\15\33[J %lf to \0"
	.text
	.align	2
	.globl _main
_main:
LFB31:
	sub	sp, sp, #48
LCFI25:
	stp	x29, x30, [sp, 16]
LCFI26:
	add	x29, sp, 16
LCFI27:
	adrp	x0, lC17@PAGE
	add	x0, x0, lC17@PAGEOFF;
	bl	_puts
	add	x0, x29, 24
	str	x0, [sp]
	adrp	x0, lC18@PAGE
	add	x0, x0, lC18@PAGEOFF;
	bl	_scanf
	ldr	d31, [x29, 24]
	str	d31, [sp]
	adrp	x0, lC19@PAGE
	add	x0, x0, lC19@PAGEOFF;
	bl	_printf
	add	x0, x29, 16
	str	x0, [sp]
	adrp	x0, lC18@PAGE
	add	x0, x0, lC18@PAGEOFF;
	bl	_scanf
	ldr	d31, [x29, 24]
	ldr	d30, [x29, 16]
	fmov	d1, d30
	fmov	d0, d31
	bl	_bisect
	mov	w0, 0
	ldp	x29, x30, [sp, 16]
	add	sp, sp, 48
LCFI28:
	ret




LFE31:
	.literal8
	.align	3
lC16:
	.word	-2127697391
	.word	1030854553
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x3
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB23-.
	.set L$set$2,LFE23-LFB23
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB23
	.long L$set$3
	.byte	0xe
	.uleb128 0x130
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0x9d
	.uleb128 0x24
	.byte	0x9e
	.uleb128 0x23
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0xc
	.uleb128 0x1d
	.uleb128 0x120
	.byte	0x4
	.set L$set$6,LCFI3-LCFI2
	.long L$set$6
	.byte	0xdd
	.byte	0xde
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE1:
LSFDE3:
	.set L$set$7,LEFDE3-LASFDE3
	.long L$set$7
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB24-.
	.set L$set$8,LFE24-LFB24
	.quad L$set$8
	.uleb128 0
	.byte	0x4
	.set L$set$9,LCFI4-LFB24
	.long L$set$9
	.byte	0xe
	.uleb128 0x10
	.byte	0x9d
	.uleb128 0x2
	.byte	0x9e
	.uleb128 0x1
	.byte	0x4
	.set L$set$10,LCFI5-LCFI4
	.long L$set$10
	.byte	0xd
	.uleb128 0x1d
	.byte	0x4
	.set L$set$11,LCFI6-LCFI5
	.long L$set$11
	.byte	0xde
	.byte	0xdd
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE3:
LSFDE5:
	.set L$set$12,LEFDE5-LASFDE5
	.long L$set$12
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB25-.
	.set L$set$13,LFE25-LFB25
	.quad L$set$13
	.uleb128 0
	.byte	0x4
	.set L$set$14,LCFI7-LFB25
	.long L$set$14
	.byte	0xe
	.uleb128 0x30
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$15,LCFI8-LCFI7
	.long L$set$15
	.byte	0xd
	.uleb128 0x1d
	.byte	0x4
	.set L$set$16,LCFI9-LCFI8
	.long L$set$16
	.byte	0xde
	.byte	0xdd
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE5:
LSFDE7:
	.set L$set$17,LEFDE7-LASFDE7
	.long L$set$17
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB26-.
	.set L$set$18,LFE26-LFB26
	.quad L$set$18
	.uleb128 0
	.byte	0x4
	.set L$set$19,LCFI10-LFB26
	.long L$set$19
	.byte	0xe
	.uleb128 0x20
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$20,LCFI11-LCFI10
	.long L$set$20
	.byte	0xd
	.uleb128 0x1d
	.byte	0x4
	.set L$set$21,LCFI12-LCFI11
	.long L$set$21
	.byte	0xde
	.byte	0xdd
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE7:
LSFDE9:
	.set L$set$22,LEFDE9-LASFDE9
	.long L$set$22
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB27-.
	.set L$set$23,LFE27-LFB27
	.quad L$set$23
	.uleb128 0
	.byte	0x4
	.set L$set$24,LCFI13-LFB27
	.long L$set$24
	.byte	0xe
	.uleb128 0x10
	.byte	0x9d
	.uleb128 0x2
	.byte	0x9e
	.uleb128 0x1
	.byte	0x4
	.set L$set$25,LCFI14-LCFI13
	.long L$set$25
	.byte	0xd
	.uleb128 0x1d
	.byte	0x4
	.set L$set$26,LCFI15-LCFI14
	.long L$set$26
	.byte	0xde
	.byte	0xdd
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE9:
LSFDE11:
	.set L$set$27,LEFDE11-LASFDE11
	.long L$set$27
LASFDE11:
	.long	LASFDE11-EH_frame1
	.quad	LFB29-.
	.set L$set$28,LFE29-LFB29
	.quad L$set$28
	.uleb128 0
	.byte	0x4
	.set L$set$29,LCFI16-LFB29
	.long L$set$29
	.byte	0xe
	.uleb128 0x30
	.byte	0x9d
	.uleb128 0x6
	.byte	0x9e
	.uleb128 0x5
	.byte	0x4
	.set L$set$30,LCFI17-LCFI16
	.long L$set$30
	.byte	0xd
	.uleb128 0x1d
	.byte	0x4
	.set L$set$31,LCFI18-LCFI17
	.long L$set$31
	.byte	0x5
	.uleb128 0x4f
	.uleb128 0x4
	.byte	0x4
	.set L$set$32,LCFI19-LCFI18
	.long L$set$32
	.byte	0xde
	.byte	0xdd
	.byte	0x6
	.uleb128 0x4f
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE11:
LSFDE13:
	.set L$set$33,LEFDE13-LASFDE13
	.long L$set$33
LASFDE13:
	.long	LASFDE13-EH_frame1
	.quad	LFB30-.
	.set L$set$34,LFE30-LFB30
	.quad L$set$34
	.uleb128 0
	.byte	0x4
	.set L$set$35,LCFI20-LFB30
	.long L$set$35
	.byte	0xe
	.uleb128 0xb0
	.byte	0x4
	.set L$set$36,LCFI21-LCFI20
	.long L$set$36
	.byte	0x9d
	.uleb128 0x10
	.byte	0x9e
	.uleb128 0xf
	.byte	0x4
	.set L$set$37,LCFI22-LCFI21
	.long L$set$37
	.byte	0xc
	.uleb128 0x1d
	.uleb128 0x80
	.byte	0x4
	.set L$set$38,LCFI23-LCFI22
	.long L$set$38
	.byte	0x93
	.uleb128 0xe
	.byte	0x4
	.set L$set$39,LCFI24-LCFI23
	.long L$set$39
	.byte	0xd3
	.byte	0xdd
	.byte	0xde
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE13:
LSFDE15:
	.set L$set$40,LEFDE15-LASFDE15
	.long L$set$40
LASFDE15:
	.long	LASFDE15-EH_frame1
	.quad	LFB31-.
	.set L$set$41,LFE31-LFB31
	.quad L$set$41
	.uleb128 0
	.byte	0x4
	.set L$set$42,LCFI25-LFB31
	.long L$set$42
	.byte	0xe
	.uleb128 0x30
	.byte	0x4
	.set L$set$43,LCFI26-LCFI25
	.long L$set$43
	.byte	0x9d
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x3
	.byte	0x4
	.set L$set$44,LCFI27-LCFI26
	.long L$set$44
	.byte	0xc
	.uleb128 0x1d
	.uleb128 0x20
	.byte	0x4
	.set L$set$45,LCFI28-LCFI27
	.long L$set$45
	.byte	0xdd
	.byte	0xde
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE15:
	.ident	"GCC: (Homebrew GCC 15.2.0_1) 15.2.0"
	.subsections_via_symbols
