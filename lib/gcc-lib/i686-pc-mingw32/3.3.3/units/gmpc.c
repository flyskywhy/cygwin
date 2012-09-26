/*Compatibility wrapper routines for the GMP unit for GMP 2.x
  For GMP 3.x, this file is mostly empty.

  Copyright (C) 2000-2004 Free Software Foundation, Inc.

  Author: Frank Heckenbach <frank@pascal.gnu.de>

  This file is part of GNU Pascal.

  GNU Pascal is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published
  by the Free Software Foundation; either version 2, or (at your
  option) any later version.

  GNU Pascal is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with GNU Pascal; see the file COPYING. If not, write to the
  Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA
  02111-1307, USA.

  As a special exception, if you link this file with files compiled
  with a GNU compiler to produce an executable, this does not cause
  the resulting executable to be covered by the GNU General Public
  License. This exception does not however invalidate any other
  reasons why the executable file might be covered by the GNU
  General Public License.

  Please also note the license of the GMP library.*/

#include <gmp.h>
#undef mpz_cmp_si
#undef mpz_cmp_ui
#undef mpq_cmp_ui

#define GLOBAL(decl) decl; decl

GLOBAL (int _p_mp_bits_per_limb (void))
{
  return mp_bits_per_limb;
}

#if __GNU_MP_VERSION != 3 && __GNU_MP_VERSION != 4

#if __GNU_MP_VERSION != 2
#error The GMP unit needs GNU GMP version 2, 3 or 4.
#endif

/*
The rest of this file (up to the final `#endif') was generated with
the following command (where sed is GNU sed):
sed -ne '/#ifdef _GMP_H_HAVE_FILE/,/#endif/d;
/_PROTO/{/mp[zqf]\|mp_set_memory_functions/{
:l0;/[^;]$/{N;b l0;};s,\n[[:space:]]*, ,g;
s/_PROTO *(//;s/));\|,/#&/g;
:l1;s/\(([^)]*(\([^)]\|)[^()]*(\)*\)#/\1/;t l1;
s/\((\*\)\([^#]*\)#/\1#\2/g;s/));/>);/;
s/^/>f</;:l2;/#/{s/</o</;s/^\(\([^<]*\)<\([^#]*\)\)#/\1 \2</;b l2;};s/^[^<]*<//;
s/^\(.\([^m_]\|[m_]\+[^p]\)*\)\(_\?mp[^(]*(\)\(.*\);/GLOBAL (\1?\3\4)~{~  \3<\4;~}~/;
s/?_\?mp/__gmp/g;/void[[:space:]]*[^[:space:]*]/!s/{~  /&return /;
:l3;s/\(~.*~.*\)<[^>]*>/\1, /;t l3;s/(, /(/;s/, )/)/;s/[<>]//g;s/~/\
/g;p;};}' < /usr/include/gmp-2.0.2.h
*/

GLOBAL (void __gmp_set_memory_functions (void *(* fo) (size_t), void *(* foo) (void *, size_t, size_t), void (* fooo) (void *, size_t)))
{
  mp_set_memory_functions (fo, foo, fooo);
}

GLOBAL (void *__gmpz_realloc (mpz_ptr fo, mp_size_t foo))
{
  return _mpz_realloc (fo, foo);
}

GLOBAL (void __gmpz_abs (mpz_ptr fo, mpz_srcptr foo))
{
  mpz_abs (fo, foo);
}

GLOBAL (void __gmpz_add (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_add (fo, foo, fooo);
}

GLOBAL (void __gmpz_add_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_add_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_and (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_and (fo, foo, fooo);
}

GLOBAL (void __gmpz_array_init (mpz_ptr fo, mp_size_t foo, mp_size_t fooo))
{
  mpz_array_init (fo, foo, fooo);
}

GLOBAL (void __gmpz_cdiv_q (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_cdiv_q (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_cdiv_q_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  return mpz_cdiv_q_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_cdiv_qr (mpz_ptr fo, mpz_ptr foo, mpz_srcptr fooo, mpz_srcptr foooo))
{
  mpz_cdiv_qr (fo, foo, fooo, foooo);
}

GLOBAL (unsigned long int __gmpz_cdiv_qr_ui (mpz_ptr fo, mpz_ptr foo, mpz_srcptr fooo, unsigned long int foooo))
{
  return mpz_cdiv_qr_ui (fo, foo, fooo, foooo);
}

GLOBAL (void __gmpz_cdiv_r (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_cdiv_r (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_cdiv_r_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  return mpz_cdiv_r_ui (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_cdiv_ui (mpz_srcptr fo, unsigned long int foo))
{
  return mpz_cdiv_ui (fo, foo);
}

GLOBAL (void __gmpz_clear (mpz_ptr fo))
{
  mpz_clear (fo);
}

GLOBAL (void __gmpz_clrbit (mpz_ptr fo, unsigned long int foo))
{
  mpz_clrbit (fo, foo);
}

GLOBAL (int __gmpz_cmp (mpz_srcptr fo, mpz_srcptr foo))
{
  return mpz_cmp (fo, foo);
}

GLOBAL (int __gmpz_cmp_si (mpz_srcptr fo, signed long int foo))
{
  return mpz_cmp_si (fo, foo);
}

GLOBAL (int __gmpz_cmp_ui (mpz_srcptr fo, unsigned long int foo))
{
  return mpz_cmp_ui (fo, foo);
}

GLOBAL (void __gmpz_com (mpz_ptr fo, mpz_srcptr foo))
{
  mpz_com (fo, foo);
}

GLOBAL (void __gmpz_divexact (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_divexact (fo, foo, fooo);
}

GLOBAL (void __gmpz_fac_ui (mpz_ptr fo, unsigned long int foo))
{
  mpz_fac_ui (fo, foo);
}

GLOBAL (void __gmpz_fdiv_q (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_fdiv_q (fo, foo, fooo);
}

GLOBAL (void __gmpz_fdiv_q_2exp (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_fdiv_q_2exp (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_fdiv_q_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  return mpz_fdiv_q_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_fdiv_qr (mpz_ptr fo, mpz_ptr foo, mpz_srcptr fooo, mpz_srcptr foooo))
{
  mpz_fdiv_qr (fo, foo, fooo, foooo);
}

GLOBAL (unsigned long int __gmpz_fdiv_qr_ui (mpz_ptr fo, mpz_ptr foo, mpz_srcptr fooo, unsigned long int foooo))
{
  return mpz_fdiv_qr_ui (fo, foo, fooo, foooo);
}

GLOBAL (void __gmpz_fdiv_r (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_fdiv_r (fo, foo, fooo);
}

GLOBAL (void __gmpz_fdiv_r_2exp (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_fdiv_r_2exp (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_fdiv_r_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  return mpz_fdiv_r_ui (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_fdiv_ui (mpz_srcptr fo, unsigned long int foo))
{
  return mpz_fdiv_ui (fo, foo);
}

GLOBAL (void __gmpz_gcd (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_gcd (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_gcd_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  return mpz_gcd_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_gcdext (mpz_ptr fo, mpz_ptr foo, mpz_ptr fooo, mpz_srcptr foooo, mpz_srcptr fooooo))
{
  mpz_gcdext (fo, foo, fooo, foooo, fooooo);
}

GLOBAL (double __gmpz_get_d (mpz_srcptr fo))
{
  return mpz_get_d (fo);
}

GLOBAL (/* signed */ long int __gmpz_get_si (mpz_srcptr fo))
{
  return mpz_get_si (fo);
}

GLOBAL (char *__gmpz_get_str (char * fo, int foo, mpz_srcptr fooo))
{
  return mpz_get_str (fo, foo, fooo);
}

GLOBAL (unsigned long int __gmpz_get_ui (mpz_srcptr fo))
{
  return mpz_get_ui (fo);
}

GLOBAL (mp_limb_t __gmpz_getlimbn (mpz_srcptr fo, mp_size_t foo))
{
  return mpz_getlimbn (fo, foo);
}

GLOBAL (unsigned long int __gmpz_hamdist (mpz_srcptr fo, mpz_srcptr foo))
{
  return mpz_hamdist (fo, foo);
}

GLOBAL (void __gmpz_init (mpz_ptr fo))
{
  mpz_init (fo);
}

GLOBAL (void __gmpz_init_set (mpz_ptr fo, mpz_srcptr foo))
{
  mpz_init_set (fo, foo);
}

GLOBAL (void __gmpz_init_set_d (mpz_ptr fo, double foo))
{
  mpz_init_set_d (fo, foo);
}

GLOBAL (void __gmpz_init_set_si (mpz_ptr fo, signed long int foo))
{
  mpz_init_set_si (fo, foo);
}

GLOBAL (int __gmpz_init_set_str (mpz_ptr fo, const char * foo, int fooo))
{
  return mpz_init_set_str (fo, foo, fooo);
}

GLOBAL (void __gmpz_init_set_ui (mpz_ptr fo, unsigned long int foo))
{
  mpz_init_set_ui (fo, foo);
}

GLOBAL (int __gmpz_invert (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  return mpz_invert (fo, foo, fooo);
}

GLOBAL (void __gmpz_ior (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_ior (fo, foo, fooo);
}

GLOBAL (int __gmpz_jacobi (mpz_srcptr fo, mpz_srcptr foo))
{
  return mpz_jacobi (fo, foo);
}

GLOBAL (int __gmpz_legendre (mpz_srcptr fo, mpz_srcptr foo))
{
  return mpz_legendre (fo, foo);
}

GLOBAL (void __gmpz_mod (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_mod (fo, foo, fooo);
}

GLOBAL (void __gmpz_mul (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_mul (fo, foo, fooo);
}

GLOBAL (void __gmpz_mul_2exp (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_mul_2exp (fo, foo, fooo);
}

GLOBAL (void __gmpz_mul_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_mul_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_neg (mpz_ptr fo, mpz_srcptr foo))
{
  mpz_neg (fo, foo);
}

GLOBAL (int __gmpz_perfect_square_p (mpz_srcptr fo))
{
  return mpz_perfect_square_p (fo);
}

GLOBAL (unsigned long int __gmpz_popcount (mpz_srcptr fo))
{
  return mpz_popcount (fo);
}

GLOBAL (void __gmpz_pow_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_pow_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_powm (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo, mpz_srcptr foooo))
{
  mpz_powm (fo, foo, fooo, foooo);
}

GLOBAL (void __gmpz_powm_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo, mpz_srcptr foooo))
{
  mpz_powm_ui (fo, foo, fooo, foooo);
}

GLOBAL (int __gmpz_probab_prime_p (mpz_srcptr fo, int foo))
{
  return mpz_probab_prime_p (fo, foo);
}

GLOBAL (void __gmpz_random (mpz_ptr fo, mp_size_t foo))
{
  mpz_random (fo, foo);
}

GLOBAL (void __gmpz_random2 (mpz_ptr fo, mp_size_t foo))
{
  mpz_random2 (fo, foo);
}

GLOBAL (unsigned long int __gmpz_scan0 (mpz_srcptr fo, unsigned long int foo))
{
  return mpz_scan0 (fo, foo);
}

GLOBAL (unsigned long int __gmpz_scan1 (mpz_srcptr fo, unsigned long int foo))
{
  return mpz_scan1 (fo, foo);
}

GLOBAL (void __gmpz_set (mpz_ptr fo, mpz_srcptr foo))
{
  mpz_set (fo, foo);
}

GLOBAL (void __gmpz_set_d (mpz_ptr fo, double foo))
{
  mpz_set_d (fo, foo);
}

GLOBAL (void __gmpz_set_f (mpz_ptr fo, mpf_srcptr foo))
{
  mpz_set_f (fo, foo);
}

GLOBAL (void __gmpz_set_q (mpz_ptr fo, mpq_srcptr foo))
{
  mpz_set_q (fo, foo);
}

GLOBAL (void __gmpz_set_si (mpz_ptr fo, signed long int foo))
{
  mpz_set_si (fo, foo);
}

GLOBAL (int __gmpz_set_str (mpz_ptr fo, const char * foo, int fooo))
{
  return mpz_set_str (fo, foo, fooo);
}

GLOBAL (void __gmpz_set_ui (mpz_ptr fo, unsigned long int foo))
{
  mpz_set_ui (fo, foo);
}

GLOBAL (void __gmpz_setbit (mpz_ptr fo, unsigned long int foo))
{
  mpz_setbit (fo, foo);
}

GLOBAL (size_t __gmpz_size (mpz_srcptr fo))
{
  return mpz_size (fo);
}

GLOBAL (size_t __gmpz_sizeinbase (mpz_srcptr fo, int foo))
{
  return mpz_sizeinbase (fo, foo);
}

GLOBAL (void __gmpz_sqrt (mpz_ptr fo, mpz_srcptr foo))
{
  mpz_sqrt (fo, foo);
}

GLOBAL (void __gmpz_sqrtrem (mpz_ptr fo, mpz_ptr foo, mpz_srcptr fooo))
{
  mpz_sqrtrem (fo, foo, fooo);
}

GLOBAL (void __gmpz_sub (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_sub (fo, foo, fooo);
}

GLOBAL (void __gmpz_sub_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_sub_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_tdiv_q (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_tdiv_q (fo, foo, fooo);
}

GLOBAL (void __gmpz_tdiv_q_2exp (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_tdiv_q_2exp (fo, foo, fooo);
}

GLOBAL (void __gmpz_tdiv_q_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_tdiv_q_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_tdiv_qr (mpz_ptr fo, mpz_ptr foo, mpz_srcptr fooo, mpz_srcptr foooo))
{
  mpz_tdiv_qr (fo, foo, fooo, foooo);
}

GLOBAL (void __gmpz_tdiv_qr_ui (mpz_ptr fo, mpz_ptr foo, mpz_srcptr fooo, unsigned long int foooo))
{
  mpz_tdiv_qr_ui (fo, foo, fooo, foooo);
}

GLOBAL (void __gmpz_tdiv_r (mpz_ptr fo, mpz_srcptr foo, mpz_srcptr fooo))
{
  mpz_tdiv_r (fo, foo, fooo);
}

GLOBAL (void __gmpz_tdiv_r_2exp (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_tdiv_r_2exp (fo, foo, fooo);
}

GLOBAL (void __gmpz_tdiv_r_ui (mpz_ptr fo, mpz_srcptr foo, unsigned long int fooo))
{
  mpz_tdiv_r_ui (fo, foo, fooo);
}

GLOBAL (void __gmpz_ui_pow_ui (mpz_ptr fo, unsigned long int foo, unsigned long int fooo))
{
  mpz_ui_pow_ui (fo, foo, fooo);
}

GLOBAL (void __gmpq_init (mpq_ptr fo))
{
  mpq_init (fo);
}

GLOBAL (void __gmpq_clear (mpq_ptr fo))
{
  mpq_clear (fo);
}

GLOBAL (void __gmpq_set (mpq_ptr fo, mpq_srcptr foo))
{
  mpq_set (fo, foo);
}

GLOBAL (void __gmpq_set_ui (mpq_ptr fo, unsigned long int foo, unsigned long int fooo))
{
  mpq_set_ui (fo, foo, fooo);
}

GLOBAL (void __gmpq_set_si (mpq_ptr fo, signed long int foo, unsigned long int fooo))
{
  mpq_set_si (fo, foo, fooo);
}

GLOBAL (void __gmpq_set_z (mpq_ptr fo, mpz_srcptr foo))
{
  mpq_set_z (fo, foo);
}

GLOBAL (void __gmpq_add (mpq_ptr fo, mpq_srcptr foo, mpq_srcptr fooo))
{
  mpq_add (fo, foo, fooo);
}

GLOBAL (void __gmpq_sub (mpq_ptr fo, mpq_srcptr foo, mpq_srcptr fooo))
{
  mpq_sub (fo, foo, fooo);
}

GLOBAL (void __gmpq_mul (mpq_ptr fo, mpq_srcptr foo, mpq_srcptr fooo))
{
  mpq_mul (fo, foo, fooo);
}

GLOBAL (void __gmpq_div (mpq_ptr fo, mpq_srcptr foo, mpq_srcptr fooo))
{
  mpq_div (fo, foo, fooo);
}

GLOBAL (void __gmpq_neg (mpq_ptr fo, mpq_srcptr foo))
{
  mpq_neg (fo, foo);
}

GLOBAL (int __gmpq_cmp (mpq_srcptr fo, mpq_srcptr foo))
{
  return mpq_cmp (fo, foo);
}

GLOBAL (int __gmpq_cmp_ui (mpq_srcptr fo, unsigned long int foo, unsigned long int fooo))
{
  return mpq_cmp_ui (fo, foo, fooo);
}

GLOBAL (int __gmpq_equal (mpq_srcptr fo, mpq_srcptr foo))
{
  return mpq_equal (fo, foo);
}

GLOBAL (void __gmpq_inv (mpq_ptr fo, mpq_srcptr foo))
{
  mpq_inv (fo, foo);
}

GLOBAL (void __gmpq_set_num (mpq_ptr fo, mpz_srcptr foo))
{
  mpq_set_num (fo, foo);
}

GLOBAL (void __gmpq_set_den (mpq_ptr fo, mpz_srcptr foo))
{
  mpq_set_den (fo, foo);
}

GLOBAL (void __gmpq_get_num (mpz_ptr fo, mpq_srcptr foo))
{
  mpq_get_num (fo, foo);
}

GLOBAL (void __gmpq_get_den (mpz_ptr fo, mpq_srcptr foo))
{
  mpq_get_den (fo, foo);
}

GLOBAL (double __gmpq_get_d (mpq_srcptr fo))
{
  return mpq_get_d (fo);
}

GLOBAL (void __gmpq_canonicalize (mpq_ptr fo))
{
  mpq_canonicalize (fo);
}

GLOBAL (void __gmpf_abs (mpf_ptr fo, mpf_srcptr foo))
{
  mpf_abs (fo, foo);
}

GLOBAL (void __gmpf_add (mpf_ptr fo, mpf_srcptr foo, mpf_srcptr fooo))
{
  mpf_add (fo, foo, fooo);
}

GLOBAL (void __gmpf_add_ui (mpf_ptr fo, mpf_srcptr foo, unsigned long int fooo))
{
  mpf_add_ui (fo, foo, fooo);
}

GLOBAL (void __gmpf_clear (mpf_ptr fo))
{
  mpf_clear (fo);
}

GLOBAL (int __gmpf_cmp (mpf_srcptr fo, mpf_srcptr foo))
{
  return mpf_cmp (fo, foo);
}

GLOBAL (int __gmpf_cmp_si (mpf_srcptr fo, signed long int foo))
{
  return mpf_cmp_si (fo, foo);
}

GLOBAL (int __gmpf_cmp_ui (mpf_srcptr fo, unsigned long int foo))
{
  return mpf_cmp_ui (fo, foo);
}

GLOBAL (void __gmpf_div (mpf_ptr fo, mpf_srcptr foo, mpf_srcptr fooo))
{
  mpf_div (fo, foo, fooo);
}

GLOBAL (void __gmpf_div_2exp (mpf_ptr fo, mpf_srcptr foo, unsigned long int fooo))
{
  mpf_div_2exp (fo, foo, fooo);
}

GLOBAL (void __gmpf_div_ui (mpf_ptr fo, mpf_srcptr foo, unsigned long int fooo))
{
  mpf_div_ui (fo, foo, fooo);
}

GLOBAL (void __gmpf_dump (mpf_srcptr fo))
{
  mpf_dump (fo);
}

GLOBAL (int __gmpf_eq (mpf_srcptr fo, mpf_srcptr foo, unsigned long int fooo))
{
  return mpf_eq (fo, foo, fooo);
}

GLOBAL (double __gmpf_get_d (mpf_srcptr fo))
{
  return mpf_get_d (fo);
}

GLOBAL (unsigned long int __gmpf_get_prec (mpf_srcptr fo))
{
  return mpf_get_prec (fo);
}

GLOBAL (char *__gmpf_get_str (char * fo, mp_exp_t * foo, int fooo, size_t foooo, mpf_srcptr fooooo))
{
  return mpf_get_str (fo, foo, fooo, foooo, fooooo);
}

GLOBAL (void __gmpf_init (mpf_ptr fo))
{
  mpf_init (fo);
}

GLOBAL (void __gmpf_init2 (mpf_ptr fo, unsigned long int foo))
{
  mpf_init2 (fo, foo);
}

GLOBAL (void __gmpf_init_set (mpf_ptr fo, mpf_srcptr foo))
{
  mpf_init_set (fo, foo);
}

GLOBAL (void __gmpf_init_set_d (mpf_ptr fo, double foo))
{
  mpf_init_set_d (fo, foo);
}

GLOBAL (void __gmpf_init_set_si (mpf_ptr fo, signed long int foo))
{
  mpf_init_set_si (fo, foo);
}

GLOBAL (int __gmpf_init_set_str (mpf_ptr fo, const char * foo, int fooo))
{
  return mpf_init_set_str (fo, foo, fooo);
}

GLOBAL (void __gmpf_init_set_ui (mpf_ptr fo, unsigned long int foo))
{
  mpf_init_set_ui (fo, foo);
}

GLOBAL (void __gmpf_mul (mpf_ptr fo, mpf_srcptr foo, mpf_srcptr fooo))
{
  mpf_mul (fo, foo, fooo);
}

GLOBAL (void __gmpf_mul_2exp (mpf_ptr fo, mpf_srcptr foo, unsigned long int fooo))
{
  mpf_mul_2exp (fo, foo, fooo);
}

GLOBAL (void __gmpf_mul_ui (mpf_ptr fo, mpf_srcptr foo, unsigned long int fooo))
{
  mpf_mul_ui (fo, foo, fooo);
}

GLOBAL (void __gmpf_neg (mpf_ptr fo, mpf_srcptr foo))
{
  mpf_neg (fo, foo);
}

GLOBAL (void __gmpf_random2 (mpf_ptr fo, mp_size_t foo, mp_exp_t fooo))
{
  mpf_random2 (fo, foo, fooo);
}

GLOBAL (void __gmpf_reldiff (mpf_ptr fo, mpf_srcptr foo, mpf_srcptr fooo))
{
  mpf_reldiff (fo, foo, fooo);
}

GLOBAL (void __gmpf_set (mpf_ptr fo, mpf_srcptr foo))
{
  mpf_set (fo, foo);
}

GLOBAL (void __gmpf_set_d (mpf_ptr fo, double foo))
{
  mpf_set_d (fo, foo);
}

GLOBAL (void __gmpf_set_default_prec (unsigned long int fo))
{
  mpf_set_default_prec (fo);
}

GLOBAL (void __gmpf_set_prec (mpf_ptr fo, unsigned long int foo))
{
  mpf_set_prec (fo, foo);
}

GLOBAL (void __gmpf_set_prec_raw (mpf_ptr fo, unsigned long int foo))
{
  mpf_set_prec_raw (fo, foo);
}

GLOBAL (void __gmpf_set_q (mpf_ptr fo, mpq_srcptr foo))
{
  mpf_set_q (fo, foo);
}

GLOBAL (void __gmpf_set_si (mpf_ptr fo, signed long int foo))
{
  mpf_set_si (fo, foo);
}

GLOBAL (int __gmpf_set_str (mpf_ptr fo, const char * foo, int fooo))
{
  return mpf_set_str (fo, foo, fooo);
}

GLOBAL (void __gmpf_set_ui (mpf_ptr fo, unsigned long int foo))
{
  mpf_set_ui (fo, foo);
}

GLOBAL (void __gmpf_set_z (mpf_ptr fo, mpz_srcptr foo))
{
  mpf_set_z (fo, foo);
}

GLOBAL (size_t __gmpf_size (mpf_srcptr fo))
{
  return mpf_size (fo);
}

GLOBAL (void __gmpf_sqrt (mpf_ptr fo, mpf_srcptr foo))
{
  mpf_sqrt (fo, foo);
}

GLOBAL (void __gmpf_sqrt_ui (mpf_ptr fo, unsigned long int foo))
{
  mpf_sqrt_ui (fo, foo);
}

GLOBAL (void __gmpf_sub (mpf_ptr fo, mpf_srcptr foo, mpf_srcptr fooo))
{
  mpf_sub (fo, foo, fooo);
}

GLOBAL (void __gmpf_sub_ui (mpf_ptr fo, mpf_srcptr foo, unsigned long int fooo))
{
  mpf_sub_ui (fo, foo, fooo);
}

GLOBAL (void __gmpf_ui_div (mpf_ptr fo, unsigned long int foo, mpf_srcptr fooo))
{
  mpf_ui_div (fo, foo, fooo);
}

GLOBAL (void __gmpf_ui_sub (mpf_ptr fo, unsigned long int foo, mpf_srcptr fooo))
{
  mpf_ui_sub (fo, foo, fooo);
}

#endif
