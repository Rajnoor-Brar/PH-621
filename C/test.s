
_main:
LFB0:
	sub	sp, sp, #16
LCFI0:
	mov	w0, 10
	str	w0, [sp, 4]
	mov	w0, 1
	str	w0, [sp, 12]
	mov	w0, 4
	str	w0, [sp, 8]
	mov	w0, 1
	str	w0, [sp, 8]
	b	L2
L3:
	ldr	w1, [sp, 12]
	ldr	w0, [sp, 8]
	mul	w0, w1, w0
	str	w0, [sp, 12]
	ldr	w0, [sp, 8]
	add	w0, w0, 1
	str	w0, [sp, 8]
L2:
	ldr	w1, [sp, 8]
	ldr	w0, [sp, 4]
	cmp	w1, w0
	ble	L3
	mov	w0, 0
	add	sp, sp, 16

22