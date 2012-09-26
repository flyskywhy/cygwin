

// Copyright (c) 1999-2003 by Digital Mars
// All Rights Reserved
// written by Walter Bright
// www.digitalmars.com

/* NOTE: This file has been patched from the original DMD distribution to
   work with the GDC compiler.

   Modified by David Friedman, September 2004
*/

/* These functions are built-in intrinsics to the compiler.
 */

module std.intrinsic;

version (GNU)
{
int bsf(uint v)
{
    uint m = 1;
    uint i;
    for (i = 0; i < 32; i++,m<<=1) {
	if (v&m)
	    return i;
    }
    return i; // supposed to be undefined
}
int bsr(uint v)
{
    uint m = 0x80000000;
    uint i;
    for (i = 32; i ; i--,m>>>=1) {
	if (v&m)
	    return i-1;
    }
    return i; // supposed to be undefined
}
int bt(uint *p, uint bitnum)
{
    return (*p & (1<<bitnum)) ? -1 : 0 ;
}
int btc(uint *p, uint bitnum)
{
    int result = *p & (1<<bitnum);
    *p ^= (1<<bitnum);
    return result ? -1 : 0;
}
int btr(uint *p, uint bitnum)
{
    int result = *p & (1<<bitnum);
    *p &= ~(1<<bitnum);
    return result ? -1 : 0;
}
int bts(uint *p, uint bitnum)
{
    int result = *p & (1<<bitnum);
    *p |= (1<<bitnum);
    return result ? -1 : 0;
}

uint bswap(uint v)
{
    return ((v&0xFF)<<24)|((v&0xFF00)<<8)|((v&0xFF0000)>>>8)|((v&0xFF000000)>>>24);
}

ubyte  inp(uint p) { return 0; }
ushort inpw(uint p) { return 0; }
uint   inpl(uint p) { return 0; }

ubyte  outp(uint p, ubyte v) { return v; }
ushort outpw(uint p, ushort v) { return v; }
uint   outpl(uint p, uint v) { return v; }
}
else
{
int bsf(uint v);
int bsr(uint v);
int bt(uint *p, uint bitnum);
int btc(uint *p, uint bitnum);
int btr(uint *p, uint bitnum);
int bts(uint *p, uint bitnum);

uint bswap(uint v);

ubyte  inp(uint);
ushort inpw(uint);
uint   inpl(uint);

ubyte  outp(uint, ubyte);
ushort outpw(uint, ushort);
uint   outpl(uint, uint);
}


