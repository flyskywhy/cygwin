{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program LnDemo;
var
  z: Complex;
begin
  z := Cmplx (1, 1);
  z := Ln (z)  { yields Ln (SqRt (2)) + i * Pi / 4 }
               { since Ln (i * x) = Ln Abs (x) + i * Arg (x) }
end.
