{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ForDemo;
var
  CharSet: set of Char;
  c: Char;
  n: Integer;
  Fac: array [0 .. 10] of Integer;
  PInt: ^Integer;
begin
  CharSet := ['g', 'p', 'c'];
  for c in CharSet do
    WriteLn (c);  { prints `c', `g', `p' in three lines }
  Fac[0] := 1;
  for n := 1 to 10 do  { computes the factorial of n for n = 0 .. 10 }
    Fac[n] := Fac[n - 1] * n;
  {$X+}
  { prints n! for n = 0 .. 10 }
  for PInt := @Fac[0] to @Fac[10] do
    WriteLn (PInt - @Fac[0], '! = ', PInt^)
end.
