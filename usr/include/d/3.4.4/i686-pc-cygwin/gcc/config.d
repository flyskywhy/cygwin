// gcc/config.d is a generated file
module gcc.config;

private import gcc.builtins;
private import gcc.configext;

// frags-ac.in...


// We don't have long double functions..

extern (C) { // prob doesn't matter..
alias __builtin_acos acosl;
alias __builtin_asin asinl;
alias __builtin_atan atanl;
alias __builtin_atan2 atan2l;
alias __builtin_cos cosl;
alias __builtin_sin sinl;
alias __builtin_tan tanl;
alias __builtin_acosh acoshl;
alias __builtin_asinh asinhl;
alias __builtin_atanh atanhl;
alias __builtin_cosh coshl;
alias __builtin_sinh sinhl;
alias __builtin_tanh tanhl;
alias __builtin_exp expl;
alias __builtin_exp2 exp2l;
alias __builtin_expm1 expm1l;

alias __builtin_frexp frexpl;

alias __builtin_ilogb ilogbl;
alias __builtin_ldexp ldexpl;
alias __builtin_log logl;
alias __builtin_log10 log10l;
alias __builtin_log1p log1pl;
alias __builtin_log2 log2l;
alias __builtin_logb logbl;

//alias gcc.config.modfl __builtin_modf;
extern (D) real modfl(real x, real * py) {
    double dx = x;
    double y;
    double result = __builtin_modf(dx, & y);
    *py = y;
    return result;
}

alias __builtin_scalbn scalbnl;
alias __builtin_scalbln scalblnl;
alias __builtin_cbrt cbrtl;
alias __builtin_fabs fabsl;
alias __builtin_hypot hypotl;
alias __builtin_pow powl;
alias __builtin_sqrt sqrtl;
alias __builtin_erf erfl;
alias __builtin_erfc erfcl;
alias __builtin_lgamma lgammal;
alias __builtin_tgamma tgammal;
alias __builtin_ceil ceill;
alias __builtin_floor floorl;
alias __builtin_nearbyint nearbyintl;
alias __builtin_rint rintl;
alias __builtin_lrint lrintl;
alias __builtin_llrint llrintl;
alias __builtin_round roundl;
alias __builtin_lround lroundl;
alias __builtin_llround llroundl;
alias __builtin_trunc truncl;
alias __builtin_fmod fmodl;
alias __builtin_remainder remainderl;
alias __builtin_remquo remquol;
alias __builtin_copysign copysignl;
alias __builtin_nan nanl;
alias __builtin_nextafter nextafterl;
alias __builtin_nexttoward nexttowardl;
alias __builtin_fdim fdiml;
alias __builtin_fmax fmaxl;
alias __builtin_fmin fminl;
alias __builtin_fmal fmal;

alias __builtin_sqrt sqrt;
//alias __builtin_sqrtf sqrtf;//noldfuncs
}


alias __builtin_sqrtf sqrtf;

// ...frags-ac.in

// from <dirent.h>
const size_t dirent_d_name_offset = 20;
const size_t dirent_d_name_size = 256;
const size_t dirent_remaining_size = 0;
const size_t DIR_struct_size = 36;

// from <stdio.h>
const size_t FILE_struct_size = 104;
const int EOF = -1;
const int FOPEN_MAX = 20;
const int FILENAME_MAX = 259;
const int TMP_MAX = 26;
const int L_tmpnam = 259;

// from <sys/types.h>
alias long Coff_t;
alias uint Csize_t;
alias int Ctime_t;

// from <time.h>
const uint CLOCKS_PER_SEC = 1000;
extern(C) {

enum {
  FP_NAN = 0,
  FP_INFINITE = 1,
  FP_ZERO = 2,
  FP_SUBNORMAL = 3,
  FP_NORMAL = 4,
}

}


// TODO: configurate ?  This is a real mess...
version (linux) {
  // on X86, can use original DMD code, but not on other CPUs...
    version (None) {
      enum {
	FP_NAN,
	FP_INFINITE,
	FP_ZERO,
	FP_SUBNORMAL,
	FP_NORMAL
      }
    }

    extern (C) {
	int __isnan(double);
	int __isnanf(float);
	int __isnanl(real);
	int __isfinite(double);
	int __isfinitef(float);
	int __isfinitel(real);
	int __fpclassify(double);
	int __fpclassifyf(float);
	int __fpclassifyl(real);
	int __isinf(double);
	int __isinff(float);
	int __isinfl(real);
	int __signbit(double);
	int __signbitf(float);
	int __signbitl(real);
    }
  
    int isnan(real x) { return __isnanl(x); }
    int isfinite(real x) { return __isfinitel(x); }
    int isnormal(real x) { return __fpclassifyl(x) == FP_NORMAL; }
    int isnormal(double x) { return __fpclassify(x) == FP_NORMAL; }
    int isnormal(float x) { return __fpclassifyf(x) == FP_NORMAL; }
    int issubnormal(real x) { return __fpclassifyl(x) == FP_SUBNORMAL; }
    int issubnormal(double x) { return __fpclassify(x) == FP_SUBNORMAL; }
    int issubnormal(float x) { return __fpclassifyf(x) == FP_SUBNORMAL; }
    int isinf(real x) { return __isinfl(x); }
    int signbit(real x) { return __signbitl(x); }
    int fpclassify(real x) { return __fpclassifyl(x); }    
    int fpclassify(double x) { return __fpclassify(x); }    
    int fpclassify(float x) { return __fpclassifyf(x); }    

} else version (darwin) {
    // could use direct ieee stuff, but long double/real is a problem
    version (None) {
	enum {
		FP_NAN          = 1,                   /*      NaN                    */
		FP_INFINITE     = 2,                   /*      + or - infinity        */
		FP_ZERO         = 3,                   /*      + or - zero            */
		FP_NORMAL       = 4,                   /*      all normal numbers     */
		FP_SUBNORMAL    = 5                    /*      denormal numbers       */
	}
    }
    
  extern (C) {
      // the 'real' versions are declared, but do not actually exist...
      int __isnand(double);
      int __isnanf(float);
      int __isnan(real);
      int __isfinited(double);
      int __isfinitef(float);
      int __isfinite(real);
      int __isnormald(double);
      int __isnormalf(float);
      int __isnormal(real);
      int __fpclassifyd(double);
      int __fpclassifyf(float);
      int __fpclassify(real);
      int __isinfd(double);
      int __isinff(float);
      int __isinf(real);
      int __signbitd(double);
      int __signbitf(float);
      int __signbitl(real);
  }
  
  int isnan(real x) { return __isnand(x); }
  int isfinite(real x) { return __isfinited(x); }
  int isnormal(real x) { return __isnormald(x); }
  int isnormal(double x) { return __isnormald(x); }
  int isnormal(float x) { return __isnormalf(x); }
  int issubnormal(real x) { return __fpclassifyd(x) == FP_SUBNORMAL; }
  int issubnormal(double x) { return __fpclassifyd(x) == FP_SUBNORMAL; }
  int issubnormal(float x) { return __fpclassifyf(x) == FP_SUBNORMAL; }
  int isinf(real x) { return __isinfd(x); }
  int signbit(real x) { return __signbitd(x); }
  int fpclassify(real x) { return __fpclassifyd(x); }    
  int fpclassify(double x) { return __fpclassifyd(x); }    
  int fpclassify(float x) { return __fpclassifyf(x); }    
} else version (solaris) {
    // for now this is a copy of the darwin stuff (and doesn't work)
    version (all) {
	enum {
		FP_NAN          = 1,                   /*      NaN                    */
		FP_INFINITE     = 2,                   /*      + or - infinity        */
		FP_ZERO         = 3,                   /*      + or - zero            */
		FP_NORMAL       = 4,                   /*      all normal numbers     */
		FP_SUBNORMAL    = 5                    /*      denormal numbers       */
	}
    }
    
  extern (C) {
      // the 'real' versions are declared, but do not actually exist...
      int __isnand(double);
      int __isnanf(float);
      int __isnan(real);
      int __isfinited(double);
      int __isfinitef(float);
      int __isfinite(real);
      int __isnormald(double);
      int __isnormalf(float);
      int __isnormal(real);
      int __fpclassifyd(double);
      int __fpclassifyf(float);
      int __fpclassify(real);
      int __isinfd(double);
      int __isinff(float);
      int __isinf(real);
      int __signbitd(double);
      int __signbitf(float);
      int __signbitl(real);
  }
  
  int isnan(real x) { return __isnand(x); }
  int isfinite(real x) { return __isfinited(x); }
  int isnormal(real x) { return __isnormald(x); }
  int isnormal(double x) { return __isnormald(x); }
  int isnormal(float x) { return __isnormalf(x); }
  int issubnormal(real x) { return __fpclassifyd(x) == FP_SUBNORMAL; }
  int issubnormal(double x) { return __fpclassifyd(x) == FP_SUBNORMAL; }
  int issubnormal(float x) { return __fpclassifyf(x) == FP_SUBNORMAL; }
  int isinf(real x) { return __isinfd(x); }
  int signbit(real x) { return __signbitd(x); }
  int fpclassify(real x) { return __fpclassifyd(x); }    
  int fpclassify(double x) { return __fpclassifyd(x); }    
  int fpclassify(float x) { return __fpclassifyf(x); }    
} else {
    // %%TODO: slightly better: test which of __fpclassify[fdl<null>] exist
    // and use those.  Could do the same with __is
    extern (C) {
	int _d_gnu_cbridge_fpclassifyl(real);
	int _d_gnu_cbridge_fpclassifyd(double);
	int _d_gnu_cbridge_fpclassifyf(float);
	int _d_gnu_cbridge_signbitl(real);
	int _d_gnu_cbridge_signbitd(double);
	int _d_gnu_cbridge_signbitf(float);
    }
    int isnan(real x) { return _d_gnu_cbridge_fpclassifyl(x)==FP_NAN; }
    int isfinite(real x) {
	int r = _d_gnu_cbridge_fpclassifyl(x);
	return r != FP_NAN && r != FP_INFINITE;
    }
    int isnormal(real x) { return _d_gnu_cbridge_fpclassifyl(x)==FP_NORMAL; }
    int isnormal(double x) { return _d_gnu_cbridge_fpclassifyd(x)==FP_NORMAL; }
    int isnormal(float x) { return _d_gnu_cbridge_fpclassifyf(x)==FP_NORMAL; }
    int issubnormal(real x) { return _d_gnu_cbridge_fpclassifyl(x) == FP_SUBNORMAL; }
    int issubnormal(double x) { return _d_gnu_cbridge_fpclassifyd(x) == FP_SUBNORMAL; }
    int issubnormal(float x) { return _d_gnu_cbridge_fpclassifyf(x) == FP_SUBNORMAL; }
    int isinf(real x) { return _d_gnu_cbridge_fpclassifyl(x)==FP_INFINITE; }
    int signbit(real x) { return _d_gnu_cbridge_signbitl(x); }
    int fpclassify(real x) { return _d_gnu_cbridge_fpclassifyl(x); }
    int fpclassify(double x) { return _d_gnu_cbridge_fpclassifyd(x); }
    int fpclassify(float x) { return _d_gnu_cbridge_fpclassifyf(x); }
}

// TODO: configure these
private import std.c.stdio;
extern (C) int ferror(FILE *);
extern (C) int feof(FILE *);
extern (C) void clearerr(FILE *);
extern (C) void rewind(FILE *);
extern (C) int _bufsize(FILE *);
extern (C) int fileno(FILE *);

alias __builtin_snprintf Csnprintf;
alias __builtin_vsnprintf Cvsnprintf;
alias __builtin_snprintf C_snprintf;
alias __builtin_vsnprintf C_vsnprintf;

version (GNU_Have_strtold)
{
    extern (C) real strtold(char*, char**);
    alias strtold cstrtold;
}
else
{
    private extern (C) double strtod(char*, char**);
    extern (D) real cstrtold(char* a, char** b) { return strtod(a, b); }
}
