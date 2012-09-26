
/* Copyright (C) 2003 by Digital Mars.
 * All Rights Reserved
 * www.digitalmars.com
 */

/* NOTE: This file has been patched from the original DMD distribution to
   work with the GDC compiler.

   Modified by David Friedman, September 2004
*/

extern (C):

alias float float_t;
alias double double_t;

version (GNU)
{
    private import gcc.config;
    // unfortunately, these do not always exist in a library
    alias gcc.config.acosl acosl;
    alias gcc.config.asinl asinl;
    alias gcc.config.atanl atanl;
    alias gcc.config.atan2l atan2l;
    alias gcc.config.cosl cosl;
    alias gcc.config.sinl sinl;
    alias gcc.config.tanl tanl;
    alias gcc.config.acoshl acoshl;
    alias gcc.config.asinhl asinhl;
    alias gcc.config.atanhl atanhl;
    alias gcc.config.coshl coshl;
    alias gcc.config.sinhl sinhl;
    alias gcc.config.tanhl tanhl;
    alias gcc.config.expl expl;
    alias gcc.config.exp2l exp2l;
    alias gcc.config.expm1l expm1l;
    alias gcc.config.frexpl frexpl;
    alias gcc.config.ilogbl ilogbl;
    alias gcc.config.ldexpl ldexpl;
    alias gcc.config.logl logl;
    alias gcc.config.log10l log10l;
    alias gcc.config.log1pl log1pl;
    alias gcc.config.log2l log2l;
    alias gcc.config.logbl logbl;
    alias gcc.config.modfl modfl;
    alias gcc.config.scalbnl scalbnl;
    alias gcc.config.scalblnl scalblnl;
    alias gcc.config.cbrtl cbrtl;
    alias gcc.config.fabsl fabsl;
    alias gcc.config.hypotl hypotl;
    alias gcc.config.powl powl;
    alias gcc.config.sqrtl sqrtl;
    alias gcc.config.erfl erfl;
    alias gcc.config.erfcl erfcl;
    alias gcc.config.lgammal lgammal;
    alias gcc.config.tgammal tgammal;
    alias gcc.config.ceill ceill;
    alias gcc.config.floorl floorl;
    alias gcc.config.nearbyintl nearbyintl;
    alias gcc.config.rintl rintl;
    alias gcc.config.lrintl lrintl;
    alias gcc.config.llrintl llrintl;
    alias gcc.config.roundl roundl;
    alias gcc.config.lroundl lroundl;
    alias gcc.config.llroundl llroundl;
    alias gcc.config.truncl truncl;
    alias gcc.config.fmodl fmodl;
    alias gcc.config.remainderl remainderl;
    alias gcc.config.remquol remquol;
    alias gcc.config.copysignl copysignl;
    alias gcc.config.nanl nanl;
    alias gcc.config.nextafterl nextafterl;
    alias gcc.config.nexttowardl nexttowardl;
    alias gcc.config.fdiml fdiml;
    alias gcc.config.fmaxl fmaxl;
    alias gcc.config.fminl fminl;
    alias gcc.config.fmal fmal;
} else {
    real   acosl(real);
    real   asinl(real);
    real   atanl(real);
    real   atan2l(real, real);
    real   cosl(real);
    real   sinl(real);
    real   tanl(real);
    real   acoshl(real x);
    real   asinhl(real x);
    real   atanhl(real x);
    real   coshl(real);
    real   sinhl(real);
    real   tanhl(real);
    real   expl(real);
    real   exp2l(real);
    real   expm1l(real);
    real   frexpl(real,int *);
    int    ilogbl(real);
    real   ldexpl(real, int);
    real   logl(real);
    real   log10l(real);
    real   log1pl(real);
    real   log2l(real);
    real   logbl(real);
    real   modfl(real, real *);
    real   scalbnl(real, int);
    real   scalblnl(real, int);
    real   cbrtl(real);
    real   fabsl(real);
    real   hypotl(real, real);
    real   powl(real, real);
    real   sqrtl(real);
    real   erfl(real x);
    real   erfcl(real x);
    real   lgammal(real x);
    real   tgammal(real x);
    real   ceill(real);
    real   floorl(real);
    real   nearbyintl(real);
    real   rintl(real);
    int    lrintl(real x);
    long   llrintl(real x);
    real   roundl(real);
    int    lroundl(real x);
    long   llroundl(real x);
    real   truncl(real);
    real   fmodl(real, real);
    real   remainderl(real, real);
    real   remquol(real, real, int *);
    real   copysignl(real, real);
    real   nanl(char *);
    real   nextafterl(real, real);
    real   nexttowardl(real, real);
    real   fdiml(real, real);
    real   fmaxl(real, real);
    real   fminl(real, real);
    real   fmal(real, real, real);
}


int isgreater(real x, real y)		{ return !(x !>  y); }
int isgreaterequal(real x, real y)	{ return !(x !>= y); }
int isless(real x, real y)		{ return !(x !<  y); }
int islessequal(real x, real y)		{ return !(x !<= y); }
int islessgreater(real x, real y)	{ return !(x !<> y); }
int isunordered(real x, real y)		{ return (x !<>= y); }

