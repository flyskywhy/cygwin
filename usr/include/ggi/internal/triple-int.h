/* $Id: triple-int.h,v 1.7 2005/08/02 11:26:28 pekberg Exp $
******************************************************************************

   Small functions for triple precision integer math.

   Copyright (C) 2004 Peter Ekberg        [peda@lysator.liu.se]

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
   THE AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
   IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

******************************************************************************
*/

/* define HALF_MUL_DIVMOD_3 to _not_ use a double precision type in the
 * mul_3 and divmod_3 functions (i.e. use unsigned as the limb), and
 * instead use only the lower half of an unsigned as the limb and a
 * complete unsigned to handle two concatenated limbs.
 *
 * define NAIVE_MUL_DIVMOD_3 to use slow and naive reference bitwise
 * implementations of mul_3 and divmod_3.
 *
 * On my computer, the naive implementation is approximately ten times
 * as slow as the double precision implementation, and the implementation
 * with limbs in half an unsigned is approximately twice as slow as the
 * double precision implementation.
 *
 * List of public functions: assign_3, assign_int_3, assign_unsigned_3,
 * sign_3, inc_3, dec_3, invert_3, negate_3, lshift_3, rshift_3, add_3,
 * sub_3, eq0_3, gt0_3, ge0_3, lt0_3, le0_3, eq_3, ge_3, abs_3, bits_3,
 * divmod_3, mul_3.
 *
 * Arguably missing: gt_3, lt_3, le_3, and_3, or_3, xor_3, div_3, mod_3.
 */

#ifndef _GGI_INTERNAL_TRIPLE_INT_H
#define _GGI_INTERNAL_TRIPLE_INT_H

#include <ggi/system.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif

#ifndef HALF_MUL_DIVMOD_3
/* Ok, try to find a double precision type, DTYPE_3 */
#ifdef GG_HAVE_INT64
#ifdef INT32_C
#if INT_MAX == INT32_C(2147483647)
#define DTYPE_3 uint64_t
#endif
#endif /* INT32_C */
#endif /* GG_HAVE_INT64 */

#if defined(INT16_C) && !defined(DTYPE_3)
#if INT_MAX == INT16_C(32767)
#define DTYPE_3 uint32_t
#endif
#endif /* INT16_C && !DTYPE_3 */
#endif /* HALF_MUL_DIVMOD_3 */

#define BITS_3 (sizeof(unsigned) * 8)
#define HALFBITS_3 (sizeof(unsigned) * 4)


/* l=r, and return l */
static inline unsigned *assign_3(unsigned l[3], unsigned r[3])
{
	l[0] = r[0];
	l[1] = r[1];
	l[2] = r[2];
	return l;
}

/* l=r, and return l */
static inline unsigned *assign_int_3(unsigned l[3], int r)
{
	unsigned fill = r < 0 ? ~0 : 0;
	l[0] = r;
	l[1] = fill;
	l[2] = fill;
	return l;
}

/* l=r, and return l */
static inline unsigned *assign_unsigned_3(unsigned l[3], unsigned r)
{
	l[0] = r;
	l[1] = 0;
	l[2] = 0;
	return l;
}

/* returns -1 if x is negative, 1 if x is positive and 0 if x is zero. */
static inline int sign_3(unsigned x[3])
{
	if (x[2] & INT_MIN)
		return -1;
	if (x[0] || x[1] || x[2])
		return 1;
	return 0;
}

/* ++x, and return x */
static inline unsigned *inc_3(unsigned x[3])
{
	if (!++x[0])
		if (!++x[1])
			++x[2];
	return x;
}

/* --x, and return x */
static inline unsigned *dec_3(unsigned x[3])
{
	if (!x[0]--)
		if (!x[1]--)
			--x[2];
	return x;
}

/* x=~x, and return x */
static inline unsigned *invert_3(unsigned x[3])
{
	x[0] ^= -1;
	x[1] ^= -1;
	x[2] ^= -1;
	return x;
}

/* x=-x, and return x */
static inline unsigned *negate_3(unsigned x[3])
{
	invert_3(x);
	inc_3(x);
	return x;
}

/* l<<=r, and return l */
static inline unsigned *lshift_3(unsigned l[3], unsigned r)
{
	unsigned lbits;

	switch (r / BITS_3) {
	case 0:
		break;
	case 1:
		l[2] = l[1];
		l[1] = l[0];
		l[0] = 0;
		break;
	case 2:
		l[2] = l[0];
		l[1] = l[0] = 0;
		break;
	default:
		l[2] = l[1] = l[0] = 0;
		return l;
	}

	lbits = r & (BITS_3 - 1);

	if (lbits) {
		unsigned rbits = BITS_3 - lbits;
		l[2] = (l[2] << lbits) | (l[1] >> rbits);
		l[1] = (l[1] << lbits) | (l[0] >> rbits);
		l[0] = l[0] << lbits;
	}

	return l;
}

/* l>>=r, and return l */
static inline unsigned *rshift_3(unsigned l[3], unsigned r)
{
	unsigned fill = sign_3(l) == -1 ? ~0 : 0;
	unsigned rbits;

	switch (r / BITS_3) {
	case 0:
		break;
	case 1:
		l[0] = l[1];
		l[1] = l[2];
		l[2] = fill;
		break;
	case 2:
		l[0] = l[2];
		l[1] = l[2] = fill;
		break;
	default:
		l[2] = l[1] = l[0] = fill;
		return l;
	}

	rbits = r & (BITS_3 - 1);

	if (rbits) {
		unsigned lbits = BITS_3 - rbits;
		l[0] = (l[0] >> rbits) | (l[1] << lbits);
		l[1] = (l[1] >> rbits) | (l[2] << lbits);
		l[2] = (l[2] >> rbits) | (fill << lbits);
	}

	return l;
}

/* l+=r, and return l */
static inline unsigned *add_3(unsigned l[3], unsigned r[3])
{
	unsigned s, c1, c2;
	s = l[0] + r[0];
	c1 = s<l[0];
	l[0] = s;
	s = l[1] + r[1];
	c2 = (s <= (s+c1)) ? (s<l[1] && s<r[1]) : 1;
	l[1] = s + c1;
	l[2] += r[2] + c2;
	return l;
}

/* l-=r, and return l */
static inline unsigned *sub_3(unsigned l[3], unsigned r[3])
{
	unsigned _r[3];
	assign_3(_r, r),
	negate_3(_r);
	return add_3(l, _r);
}

/* x==0 */
static inline int eq0_3(unsigned x[3])
{
	return !(x[0] || x[1] || x[2]);
}

/* x>0 */
static inline int gt0_3(unsigned x[3])
{
	if (x[2] & INT_MIN)
		return 0;
	if (x[0] || x[1] || x[2])
		return 1;
	return 0;
}

/* x>=0 */
static inline int ge0_3(unsigned x[3])
{
	return !(x[2] & INT_MIN);
}

/* x<0 */
static inline int lt0_3(unsigned x[3])
{
	return !ge0_3(x);
}

/* x<=0 */
static inline int le0_3(unsigned x[3])
{
	if (x[2] & INT_MIN)
		return 1;
	if (x[0] || x[1] || x[2])
		return 0;
	return 1;
}

/* l==r */
static inline int eq_3(unsigned l[3], unsigned r[3])
{
	return l[0] == r[0] && l[1] == r[1] && l[2] == r[2];
}

/* l>=r */
static inline int ge_3(unsigned l[3], unsigned r[3])
{
	int signl = sign_3(l);
	int signr = sign_3(r);
	unsigned _l[3];

	if (signl > signr)
		return 1;
	if (signl < signr)
		return 0;
	assign_3(_l, l);
	sub_3(_l, r);
	return ge0_3(_l);
}

/* x = x<0 ? -x : x, and return x */
static inline unsigned *abs_3(unsigned x[3])
{
	if (lt0_3(x))
		negate_3(x);
	return x;
}

/* Returns the number of significant bits. Leading zeros in a positive
 * value and leading ones in a negative value are not counted. This has
 * the effect that 0 and -1 have no significant bits, while 1 and -2
 * have one significant bit. 2, 3, -3 and -4 have two significant bits,
 * etc.
 */
static inline unsigned bits_3(unsigned x[3])
{
	unsigned res = 3 * BITS_3;
	unsigned msb = x[2] & INT_MIN;
	unsigned fill = msb ? ~0 : 0;
	unsigned tmp;
	int i;

	for (i = 2; i >= 0 && x[i] == fill; --i)
		res -= BITS_3;

	if (i < 0)
		return res;

	tmp = x[i];
	while ((tmp & INT_MIN) == msb) {
		--res;
		tmp <<= 1;
	}
	return res;
}

#ifndef NAIVE_MUL_DIVMOD_3

#ifdef DTYPE_3

/* Yes!! a double precision type is available */

/* support routine for multiplying a triple-unsigned with an unsigned */
static inline unsigned *_mul_limb_u3(unsigned l[3], unsigned r)
{
	DTYPE_3 tmp;

	tmp   = (DTYPE_3)r * l[0];
	l[0]  = (unsigned)tmp;
	tmp >>= BITS_3;
	tmp  += (DTYPE_3)r * l[1];
	l[1]  = (unsigned)tmp;
	tmp >>= BITS_3;
	tmp  += (DTYPE_3)r * l[2];
	l[2]  = (unsigned)tmp;

	return l;
}

/* support routine for comparing (>=) two triple-unsigned */
static inline int _ge_u3(unsigned l[3], unsigned r[3])
{
	if (l[2] < r[2])
		return 0;
	if (l[2] > r[2])
		return 1;
	if (l[1] < r[1])
		return 0;
	if (l[1] > r[1])
		return 1;
	if (l[0] < r[0])
		return 0;
	return 1;
}

/* support routine for dividing two positive triple-ints (r/y) where
 * y > UINT_MAX. msi indicates the index of the most significant
 * non-zero unsigned in y. msi has to be non-zero. q holds the
 * resulting quotient and r the resulting remainder on return.
 *
 * Normalizes y, so that the most significant bit of the y[msi] is set.
 * Then a shifted y[msi] is used as an estimate of the denominator in
 * a standard long division algorithm. Since the shifted y[msi] is
 * always less than or equal to the real y, the estimate is sometimes
 * too high, so fixup (decrease the quotient) if that happens.
 */
static inline void _divmod_full_3(
	int msi, unsigned y[3], unsigned q[3], unsigned r[3])
{
	int bits;
	DTYPE_3 msp;
	unsigned bit;
	unsigned tmp[3];
	int overflow = 0;
	unsigned _y[3], y2[3];
	unsigned _r[3];

	/* How to normalize y? */
	bit = INT_MIN;
	bits = 0;
	while (!(y[msi] & bit)) {
		bit >>= 1;
		++bits;
	}

	/* Normalize y (in _y) and calculate a matching r (in _r)
	 * for the normalized y.
	 * Since the _r might overflow when it is matched to _y,
	 * the variable msp (Most Significant Pair) is also
	 * calculated.
	 */
	assign_3(_r, r);
	assign_3(_y, y);

	lshift_3(_y, bits);
	msp = ((DTYPE_3)_r[2]) << bits;
	msp &= ~(DTYPE_3)UINT_MAX;
	lshift_3(_r, bits);
	msp |= _r[2];

	/* Do the division */
	q[2] = 0;

	if (msi == 1) {
		q[1] = msp / _y[1];
		assign_3(y2, y);
		lshift_3(y2, BITS_3);
		assign_3(tmp, y2);
		_mul_limb_u3(tmp, q[1]);
		while (!_ge_u3(r, tmp)) {
			/* Oops, too high, fixup! */
			sub_3(tmp, y2);
			--q[1];
		}
		sub_3(r, tmp);
		assign_3(_r, r);
		lshift_3(_r, bits);
		msp = ((DTYPE_3)_r[2] << BITS_3) | _r[1];
		/* Check for overflow so that q[0] never gets > UINT_MAX */
		overflow = _r[2] >= _y[1];
	}
	else
		q[1] = 0;

	q[0] = overflow ? (unsigned)~0 : msp / _y[msi];
	assign_3(tmp, y);
	_mul_limb_u3(tmp, q[0]);
	while (!_ge_u3(r, tmp)) {
		/* Oops, too high, fixup! */
		sub_3(tmp, y);
		--q[0];
	}
	sub_3(r, tmp);
}

/* support routine for dividing a positive triple-int (r) with an
 * unsigned. q holds the resulting quotient and r the resulting
 * remainder on return.
 *
 * Uses a straight forward long division scheme.
 */
static inline void _divmod_limb_3(unsigned y, unsigned q[3], unsigned r[3])
{
	q[2]  = r[2] / y;
	r[2] -= q[2] * y;
	q[1]  = (((DTYPE_3)r[2] << BITS_3) | r[1]) / y;
	r[2]  = 0;
	r[1] -= q[1] * y;
	q[0]  = (((DTYPE_3)r[1] << BITS_3) | r[0]) / y;
	r[1]  = 0;
	r[0] -= q[0] * y;
}

/* given a and b, calculate q and r in a/b = q + r/b, and return q */
static inline unsigned *divmod_3(
	unsigned a[3], unsigned b[3], unsigned q[3], unsigned r[3])
{
	int signa = sign_3(a);
	int signb = sign_3(b);
	int msi;
	unsigned y[3];

	if (!signb)
		r[0] = 1 / signb; /* force divide by zero */

	if (!signa) {
		assign_unsigned_3(q, 0);
		assign_unsigned_3(r, 0);
		return q;
	}

	assign_3(r, a);
	abs_3(r);
	assign_3(y, b);
	abs_3(y);

	msi = 2;
	if (!y[2])
		if(!y[--msi])
			--msi;

	if (msi)
		_divmod_full_3(msi, y, q, r);
	else
		_divmod_limb_3(y[0], q, r);

	if (!(signa + signb)) {
		negate_3(q);
		negate_3(r);
	}

	return q;
}

/* The following mul_3 includes three double precision
 * multiplications which could have been three ordinary
 * multiplications with double precision results. But
 * to my (somewhat limited) knowledge, there is no
 * portable way to say that in C.
 */

/* l*=r, and return l
 *
 *      2n      1n      0n
 * l = 2  l  + 2  l  + 2  l
 *         2       1       0
 *
 *      2n      1n      0n
 * r = 2  r  + 2  r  + 2  r
 *         2       1       0
 *
 *        4n        3n        2n
 * l*r = 2  l r  + 2  l r  + 2  l r  +
 *           2 2       2 1       2 0
 *
 *        3n        2n         1n
 *     + 2  l r  + 2  l r  + 2  l r  +
 *           1 2       1 1       1 0
 *
 *        2n        1n        0n
 *     + 2  l r  + 2  l r  + 2  l r
 *           0 2       0 1       0 0
 *
 *         4n      3n
 * Ignore 2   and 2   terms as those will not fit in the resulting
 * triple-int array anyway.
 *
 *      2n
 * For 2   terms, ignore most significant half of the result
 * as those bits will not fit in the resulting triple-int array
 * anyway.
 *
 *      1n
 * For 2   terms, don't worry if a carry bit is lost when adding
 * them together in a double precision add. That overflowing carry
 * will not fit in the resulting triple-int array anyway.
 */
static inline unsigned *mul_3(unsigned l[3], unsigned r[3])
{
	int signl = sign_3(l);
	int signr = sign_3(r);
	unsigned _l[3], _r[3];
	DTYPE_3 tmp;

	if (!signl || !signr) {
		/* one of l and r is zero */
		assign_unsigned_3(l, 0);
		return l;
	}

	assign_3(_l, l);
	abs_3(_l);
	assign_3(_r, r);
	abs_3(_r);

	/*  2n
	 * 2   terms.
	 */
	l[2]  = _l[2] * _r[0];
	l[2] += _l[1] * _r[1];
	l[2] += _l[0] * _r[2];

	/*  1n
	 * 2   terms.
	 */
	tmp   = (DTYPE_3)_l[1] * _r[0];
	tmp  += (DTYPE_3)_l[0] * _r[1];
	l[1]  = (unsigned)tmp;
	l[2] += (unsigned)(tmp >> BITS_3);

	/*  0n
	 * 2   term.
	 */
	tmp   = (DTYPE_3)_l[0] * _r[0];
	assign_unsigned_3(_l, (unsigned)tmp);
	_l[1] = (unsigned)(tmp >> BITS_3);
	l[0]  = 0;
	add_3(l, _l);

	if (!(signl + signr))
		negate_3(l);
	return l;
}

#else /* DTYPE_3 */

/* Found no type with double precision, fall back to
 * multiplication and division using half the bits (m)
 * of the basic unsigned integer type with n = 2m bits.
 */

/* support routine to extract the upper half of an unsigned */
static inline unsigned _upper_half_6h(unsigned x)
{
	return x >> HALFBITS_3;
}

/* support routine to extract the lower half of an unsigned */
static inline unsigned _lower_half_6h(unsigned x)
{
	return x & (UINT_MAX >> HALFBITS_3);
}

/* support routine l=r, and return l, where l is a six-tuple-half-int */
static inline unsigned *_assign_from3_6h(unsigned l[6], unsigned r[3])
{
	l[5] = _upper_half_6h(r[2]);
	l[4] = _lower_half_6h(r[2]);
	l[3] = _upper_half_6h(r[1]);
	l[2] = _lower_half_6h(r[1]);
	l[1] = _upper_half_6h(r[0]);
	l[0] = _lower_half_6h(r[0]);

	return l;
}

/* support routine l=r, and return l, where r is a six-tuple-half-int */
static inline unsigned *_assign_to3_6h(unsigned l[3], unsigned r[6])
{
	l[2] = (r[5] << HALFBITS_3) | r[4];
	l[1] = (r[3] << HALFBITS_3) | r[2];
	l[0] = (r[1] << HALFBITS_3) | r[0];

	return l;
}

/* support routine l=r, and return l, where l and r are six-tuple-half-ints */
static inline unsigned *_assign_6h(unsigned l[6], unsigned r[6])
{
	l[0] = r[0];
	l[1] = r[1];
	l[2] = r[2];
	l[3] = r[3];
	l[4] = r[4];
	l[5] = r[5];
	return l;
}

/* support routine l<<=r, and return l, where l is a six-tuple-half-int */
static inline unsigned *_lshift_6h(unsigned l[6], unsigned r)
{
	unsigned lbits;
	int halfs = r / HALFBITS_3;
	int i;

	if (halfs) {
		for (i = 5; i >= halfs; --i)
			l[i] = l[i - halfs];
		for (; i >= 0; --i)
			l[i] = 0;
	}

	lbits = r & (HALFBITS_3 - 1);

	if (lbits) {
		unsigned rbits = HALFBITS_3 - lbits;
		for (i = 5; i > 0; --i)
			l[i] = _lower_half_6h((l[i] << lbits) | (l[i-1] >> rbits));
		l[0] = _lower_half_6h(l[0] << lbits);
	}

	return l;
}

/* support routine l<<=(r*HALFBITS_3), and return l,
 * where l is a six-tuple-half-int
 */
static inline unsigned *_lshift_limb_6h(unsigned l[6], unsigned r)
{
	int i;

	if (r) {
		for (i = 5; i >= (int)r; --i)
			l[i] = l[i - r];
		for (; i >= 0; --i)
			l[i] = 0;
	}

	return l;
}

/* support routine x>>=HALFBITS_3, and return x,
 * where x is a six-tuple-half-unsigned
 */
static inline unsigned *_rshift_1limb_u6h(unsigned x[6])
{
	int i;

	for (i = 0; i < 5; ++i)
		x[i] = x[i + 1];
	x[5] = 0;

	return x;
}

/* support routine ++x, and return x, where x is a six-tuple-half-int */
static inline unsigned *_inc_6h(unsigned x[6])
{
	int i;
	for (i = 0; i < 5; ++i) {
		if (++x[i])
			return x;
	}
	++x[5];
	return x;
}

/* support routine x=~x, and return x, where x is a six-tuple-half-int */
static inline unsigned *_invert_6h(unsigned x[6])
{
	x[0] ^= _lower_half_6h(~0);
	x[1] ^= _lower_half_6h(~0);
	x[2] ^= _lower_half_6h(~0);
	x[3] ^= _lower_half_6h(~0);
	x[4] ^= _lower_half_6h(~0);
	x[5] ^= _lower_half_6h(~0);
	return x;
}

/* support routine x=-x, and return x, where x is a six-tuple-half-int */
static inline unsigned *_negate_6h(unsigned x[6])
{
	_invert_6h(x);
	_inc_6h(x);
	return x;
}

/* support routine l+=r, and return l, where l and r are six-tuple-half-ints */
static inline unsigned *_add_6h(unsigned l[6], unsigned r[6])
{
	int i;

	for (i = 0; i < 5; ++i) {
		l[i] += r[i];
		l[i+1] += _upper_half_6h(l[i]);
		l[i] &= _lower_half_6h(~0);
	}
	l[5] += r[5];
	l[5] &= _lower_half_6h(~0);
	return l;
}

/* support routine l-=r, and return l, where l and r are six-tuple-half-ints */
static inline unsigned *_sub_6h(unsigned l[6], unsigned r[6])
{
	unsigned _r[6];
	_assign_6h(_r, r),
	_negate_6h(_r);
	return _add_6h(l, _r);
}

/* support routine l*=r, and return l, where l is a six-tuple-half-int */
static inline unsigned *_mul_limb_u6h(unsigned l[6], unsigned r)
{
	unsigned tmp;
	int i;

	tmp   = r * l[0];
	l[0]  = _lower_half_6h(tmp);
	for (i = 1; i < 6; ++i) {
		tmp  = _upper_half_6h(tmp);
		tmp += r * l[i];
		l[i] = _lower_half_6h(tmp);
	}

	return l;
}

/* support routine l>=r, where l and r are six-tuple-half-unsigneds */
static inline int _ge_u6h(unsigned l[6], unsigned r[6])
{
	int i;
	for (i = 5; i > 0; --i) {
		if (l[i] < r[i])
			return 0;
		if (l[i] > r[i])
			return 1;
	}
	if (l[0] < r[0])
		return 0;
	return 1;
}

/* See comment for _divmod_full_3, this routine does the same
 * thing with six-tuple-half-int operands instead of triple-int
 * operands.
 */
static inline void _divmod_full_6h(
	int msi, unsigned y[6], unsigned q[6], unsigned r[6])
{
	int bits;
	unsigned msp;
	unsigned bit;
	unsigned tmp[6];
	int overflow = 0;
	unsigned _r[6];
	unsigned _y[6], y2[6];
	int i;

	bit = ((unsigned)INT_MIN) >> HALFBITS_3;
	bits = 0;
	while (!(y[msi] & bit)) {
		bit >>= 1;
		++bits;
	}

	_assign_6h(_r, r);
	_assign_6h(_y, y);

	_lshift_6h(_y, bits);
	msp = _r[5] << bits;
	msp &= ~0 << HALFBITS_3;
	_lshift_6h(_r, bits);
	msp |= _r[5];

	for (i = 5; i > 5 - msi; --i)
		q[i] = 0;

	_assign_6h(y2, y);
	_lshift_limb_6h(y2, i);

	for (; i > 0; --i) {
		q[i] = overflow ? _lower_half_6h(~0) : msp / _y[msi];
		_assign_6h(tmp, y2);
		_mul_limb_u6h(tmp, q[i]);
		while (!_ge_u6h(r, tmp)) {
			/* Oops, too high, fixup! */
			_sub_6h(tmp, y2);
			--q[i];
		}
		_rshift_1limb_u6h(y2);
		_sub_6h(r, tmp);
		_assign_6h(_r, r);
		_lshift_6h(_r, bits);
		msp = (_r[i+msi] << HALFBITS_3) | _r[i+msi-1];
		/* Check for overflow so that the next q limb
		 * never gets greater than UINT_MAX >> HALFBITS_3
		 */
		overflow = _r[i+msi] >= _y[msi];
	}

	q[0] = overflow ? _lower_half_6h(~0) : msp / _y[msi];
	_assign_6h(tmp, y2);
	_mul_limb_u6h(tmp, q[0]);
	while (!_ge_u6h(r, tmp)) {
		/* Oops, too high, fixup! */
		_sub_6h(tmp, y2);
		--q[0];
	}
	_sub_6h(r, tmp);
}

/* support routine for dividing a positive six-tuple-half-int (r) with
 * a half-int (y). q holds the resulting quotient and r the resulting
 * remainder on return.
 *
 * Uses a straight forward long division algorithm.
 */
static inline void _divmod_limb_6h(unsigned y, unsigned q[6], unsigned r[6])
{
	q[5]  = r[5] / y;
	r[5] -= q[5] * y;
	q[4]  = ((r[5] << HALFBITS_3) | r[4]) / y;
	r[5]  = 0;
	r[4] -= q[4] * y;
	q[3]  = ((r[4] << HALFBITS_3) | r[3]) / y;
	r[4]  = 0;
	r[3] -= q[3] * y;
	q[2]  = ((r[3] << HALFBITS_3) | r[2]) / y;
	r[3]  = 0;
	r[2] -= q[2] * y;
	q[1]  = ((r[2] << HALFBITS_3) | r[1]) / y;
	r[2]  = 0;
	r[1] -= q[1] * y;
	q[0]  = ((r[1] << HALFBITS_3) | r[0]) / y;
	r[1]  = 0;
	r[0] -= q[0] * y;
	r[0]  = _lower_half_6h(r[0]);
}

/* given a and b, calculate q and r in a/b = q + r/b, and return q */
static inline unsigned *divmod_3(
	unsigned a[3], unsigned b[3], unsigned q[3], unsigned r[3])
{
	int signa = sign_3(a);
	int signb = sign_3(b);
	int msi;
	unsigned y[3];
	unsigned _q[6];
	unsigned _y[6];
	unsigned _r[6];

	if (!signb)
		r[0] = 1 / signb; /* force divide by zero */

	if (!signa) {
		assign_unsigned_3(q, 0);
		assign_unsigned_3(r, 0);
		return q;
	}

	assign_3(r, a);
	abs_3(r);
	_assign_from3_6h(_r, r);
	assign_3(y, b);
	abs_3(y);
	_assign_from3_6h(_y, y);

	msi = 6;
	while (!_y[--msi]);

	if (msi)
		_divmod_full_6h(msi, _y, _q, _r);
	else
		_divmod_limb_6h(y[0], _q, _r);

	_assign_to3_6h(q, _q);
	_assign_to3_6h(r, _r);

	if (!(signa + signb)) {
		negate_3(q);
		negate_3(r);
	}

	return q;
}

/* l*=r, and return l
 *
 *      5m       4m      3m      2m       1m      0m
 * l = 2   l  + 2  l  + 2  l  + 2   l  + 2  l  + 2  l
 *          5       4       3        2       1       0
 *
 *      5m       4m      3m      2m       1m      0m
 * r = 2   r  + 2  r  + 2  r  + 2   r  + 2  r  + 2  r
 *          5       4       3        2       1       0
 *
 *        10m        9m        8m        7m        6m        5m
 * l*r = 2   l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  +
 *            5 5       5 4       5 3       5 2       5 1       5 0
 *
 *         9m        8m        7m        6m        5m        4m
 *     +  2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  +
 *            4 5       4 4       4 3       4 2       4 1       4 0
 *
 *         8m        7m        6m        5m        4m        3m
 *     +  2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  +
 *            3 5       3 4       3 3       3 2       3 1       3 0
 *
 *         7m        6m        5m        4m        3m        2m
 *     +  2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  +
 *            2 5       2 4       2 3       2 2       2 1       2 0
 *
 *         6m        5m        4m        3m        2m        1m
 *     +  2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  +
 *            1 5       1 4       1 3       1 2       1 1       1 0
 *
 *         5m        4m        3m        2m        1m        0m
 *     +  2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  + 2  l r  +
 *            0 5       0 4       0 3       0 2       0 1       0 0
 *
 *         10m   9m   8m   7m      6m
 * Ignore 2   , 2  , 2  , 2   and 2   terms as those will not fit in
 * the resulting triple-int array anyway.
 *
 *      5m
 * For 2   terms, ignore most significant half of the result
 * as those bits will not fit in the resulting triple-int array
 * anyway.
 *
 *      4m
 * For 2   terms, don't worry if a carry bit is lost when adding
 * them together in an add. That overflowing carry will not fit
 * in the resulting triple-int array anyway.
 */
static inline unsigned *mul_3(unsigned l[3], unsigned r[3])
{
	int signl = sign_3(l);
	int signr = sign_3(r);
	unsigned _l[3], _r[3];
	unsigned lh[5], rh[5];
	unsigned tmp, tmp1, tmp2;

	if (!signl || !signr) {
		/* one of l and r is zero */
		assign_unsigned_3(l, 0);
		return l;
	}

	assign_3(_l, l);
	abs_3(_l);
	assign_3(_r, r);
	abs_3(_r);

	/*  5m
	 * 2   terms.
	 */
	l[2]  =        _upper_half_6h(_l[2])  * (rh[0]=_lower_half_6h(_r[0]));
	l[2] += (lh[4]=_lower_half_6h(_l[2])) * (rh[1]=_upper_half_6h(_r[0]));
	l[2] += (lh[3]=_upper_half_6h(_l[1])) * (rh[2]=_lower_half_6h(_r[1]));
	l[2] += (lh[2]=_lower_half_6h(_l[1])) * (rh[3]=_upper_half_6h(_r[1]));
	l[2] += (lh[1]=_upper_half_6h(_l[0])) * (rh[4]=_lower_half_6h(_r[2]));
	l[2] += (lh[0]=_lower_half_6h(_l[0])) *        _upper_half_6h(_r[2]);
	l[2] <<= HALFBITS_3;

	/*  4m
	 * 2   terms.
	 */
	l[2] += lh[4] * rh[0];
	l[2] += lh[3] * rh[1];
	l[2] += lh[2] * rh[2];
	l[2] += lh[1] * rh[3];
	l[2] += lh[0] * rh[4];

	/*  3m
	 * 2   terms.
	 */
	tmp  = lh[3] * rh[0];
	tmp1 = lh[2] * rh[1];
	tmp2 = tmp + tmp1;
	if (tmp2 < tmp && tmp2 < tmp1)
		l[2] += 1 << HALFBITS_3;
	tmp  = lh[1] * rh[2];
	tmp1 = tmp + tmp2;
	if (tmp1 < tmp && tmp1 < tmp2)
		l[2] += 1 << HALFBITS_3;
	tmp  = lh[0] * rh[3];
	tmp2 = tmp + tmp1;
	if (tmp2 < tmp && tmp2 < tmp1)
		l[2] += 1 << HALFBITS_3;
	l[2] += _upper_half_6h(tmp2);
	l[1] = tmp2 << HALFBITS_3;

	/*  2m
	 * 2   terms.
	 */
	tmp  = lh[2] * rh[0];
	tmp1 = lh[1] * rh[1];
	tmp2 = tmp + tmp1;
	if (tmp2 < tmp && tmp2 < tmp1)
		++l[2];
	tmp  = lh[0] * rh[2];
	tmp1 = tmp + tmp2;
	if (tmp1 < tmp && tmp1 < tmp2)
		++l[2];
	tmp2 = l[1];
	l[1] += tmp1;
	if (l[1] < tmp1 && l[1] < tmp2)
		++l[2];

	/*  1m
	 * 2   terms.
	 */
	tmp  = lh[1] * rh[0];
	tmp1 = lh[0] * rh[1];
	tmp2 = tmp + tmp1;
	if (tmp2 < tmp && tmp2 < tmp1) {
		l[1] += 1 << HALFBITS_3;
		if (l[1] < (1 << HALFBITS_3))
			++l[2];
	}
	_l[0] = tmp2 << HALFBITS_3;
	_l[1] = _upper_half_6h(tmp2);
	_l[2] = 0;
	l[0] = 0;
	add_3(l, _l);

	/*  0m
	 * 2   term.
	 */
	_l[0] = lh[0] * rh[0];
	_l[1] = 0;
	add_3(l, _l);

	/* Finish off previous terms. */

	if (!(signl + signr))
		negate_3(l);

	return l;
}

#endif /* DTYPE_3 */

#else /* !NAIVE_MUL_DIVMOD_3 */

/* l*=r, and return l
 * Slow and naive bitwise multiplication using shift and add for reference. */
static inline unsigned *mul_3(unsigned l[3], unsigned r[3])
{
	int signl = sign_3(l);
	int signr = sign_3(r);
	unsigned _l[3];
	int i, j;

	if (!signl || !signr) {
		/* one of l and r is zero */
		assign_unsigned_3(l, 0);
		return l;
	}

	assign_3(_l, l);
	abs_3(_l);
	assign_unsigned_3(l, 0);

	for (i = 2; i >= 0; --i) {
		unsigned a = _l[i];
		for (j = BITS_3 - 1; j >= 0; --j) {
			lshift_3(l, 1);
			if (a & ((unsigned)1<<j))
				add_3(l, r);
		}
	}

	if (signl < 0)
		negate_3(l);
	return l;
}

/* given a and b, calculate q and r in a/b = q + r/b, and return q
 * Slow and naive bitwise division using shift and sub for reference.
 */
static inline unsigned *divmod_3(
	unsigned a[3], unsigned b[3], unsigned q[3], unsigned r[3])
{
	int signa = sign_3(a);
	int signb = sign_3(b);
	unsigned y[3];
	unsigned tmp[3];
	int bits;

	if (!signb)
		r[0] = 1 / signb; /* force divide by zero */

	assign_unsigned_3(q, 0);
	if (!signa) {
		assign_unsigned_3(r, 0);
		return q;
	}

	assign_3(r, a);
	abs_3(r);
	assign_3(y, b);
	abs_3(y);

	for (bits = bits_3(r) - bits_3(y); bits >= 0; --bits) {
		lshift_3(q, 1);
		assign_3(tmp, r);
		rshift_3(tmp, bits);
		if (ge_3(tmp, y)) {
			++q[0]; /* Will never overflow into q[1] */
			assign_3(tmp, y);
			lshift_3(tmp, bits);
			sub_3(r, tmp);
		}
	}

	if (!(signa + signb)) {
		negate_3(q);
		negate_3(r);
	}

	return q;
}

#endif /* !NAIVE_MUL_DIVMOD_3 */

#endif /* _GGI_INTERNAL_TRIPLE_INT_H */
