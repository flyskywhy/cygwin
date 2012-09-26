{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ExpDemo;
var
  z: Complex;
begin
  z := Cmplx (1, - 2 * Pi);  { z = 1 - 2 pi i }
  z := Exp (z);  { yields e = Exp (1), since Exp ix = Cos x + i Sin x }
  WriteLn (Ln (Re (z)) : 0 : 5)  { prints 1 = Ln (Exp (1)) }
end.
