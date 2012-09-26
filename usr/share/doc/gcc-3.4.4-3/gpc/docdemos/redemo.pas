{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ReDemo;
var
  z: Complex;
begin
  z := Cmplx (1, 2);
  WriteLn (Re (z) : 0 : 5)
end.
