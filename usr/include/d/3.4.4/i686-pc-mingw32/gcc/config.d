// gcc/config.d is a generated file
module gcc.config;

private import gcc.builtins;
private import gcc.configext;

// frags-ac.in...


// If long double functions are present, just alias
// to the __builtin_ version.  This may not do the right thing (TODO)
extern (C) { // prob doesn't matter..
alias __builtin_acosl acosl;
alias __builtin_asinl asinl;
alias __builtin_atanl atanl;
alias __builtin_atan2l atan2l;
alias __builtin_cosl cosl;
alias __builtin_sinl sinl;
alias __builtin_tanl tanl;
alias __builtin_acoshl acoshl;
alias __builtin_asinhl asinhl;
alias __builtin_atanhl atanhl;
alias __builtin_coshl coshl;
alias __builtin_sinhl sinhl;
alias __builtin_tanhl tanhl;
alias __builtin_expl expl;
alias __builtin_exp2l exp2l;
alias __builtin_expm1l expm1l;
alias __builtin_frexpl frexpl;
alias __builtin_ilogbl ilogbl;
alias __builtin_ldexpl ldexpl;
alias __builtin_logl logl;
alias __builtin_log10l log10l;
alias __builtin_log1pl log1pl;
alias __builtin_log2l log2l;
alias __builtin_logbl logbl;
alias __builtin_modfl modfl;
alias __builtin_scalbnl scalbnl;
alias __builtin_scalblnl scalblnl;
alias __builtin_cbrtl cbrtl;
alias __builtin_fabsl fabsl;
alias __builtin_hypotl hypotl;
alias __builtin_powl powl;
alias __builtin_sqrtl sqrtl;
alias __builtin_erfl erfl;
alias __builtin_erfcl erfcl;
alias __builtin_lgammal lgammal;
alias __builtin_tgammal tgammal;
alias __builtin_ceill ceill;
alias __builtin_floorl floorl;
alias __builtin_nearbyintl nearbyintl;
alias __builtin_rintl rintl;
alias __builtin_lrintl lrintl;
alias __builtin_llrintl llrintl;
alias __builtin_roundl roundl;
alias __builtin_lroundl lroundl;
alias __builtin_llroundl llroundl;
alias __builtin_truncl truncl;
alias __builtin_fmodl fmodl;
alias __builtin_remainderl remainderl;
alias __builtin_remquol remquol;
alias __builtin_copysignl copysignl;
alias __builtin_nanl nanl;
alias __builtin_nextafterl nextafterl;
alias __builtin_nexttowardl nexttowardl;
alias __builtin_fdiml fdiml;
alias __builtin_fmaxl fmaxl;
alias __builtin_fminl fminl;
alias __builtin_fmal fmal;

alias __builtin_sqrt sqrt;
//alias __builtin_sqrtf sqrtf;// needs an extra step
}

alias __builtin_sqrtf sqrtf;

// ...frags-ac.in

// from <dirent.h>
const size_t dirent_d_name_offset = 8;
const size_t dirent_d_name_size = 260;
const size_t dirent_remaining_size = 0;
const size_t DIR_struct_size = 560;

// from <stdio.h>
const size_t FILE_struct_size = 32;
const int EOF = -1;
const int FOPEN_MAX = 20;
const int FILENAME_MAX = 260;
const int TMP_MAX = 32767;
const int L_tmpnam = 16;

// from <sys/types.h>
alias int Coff_t;
alias uint Csize_t;
alias int Ctime_t;

// from <time.h>
const uint CLOCKS_PER_SEC = 1000;
extern(C) {

enum {
  FP_NAN = 256,
  FP_INFINITE = 1280,
  FP_ZERO = 16384,
  FP_SUBNORMAL = 17408,
  FP_NORMAL = 1024,
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
