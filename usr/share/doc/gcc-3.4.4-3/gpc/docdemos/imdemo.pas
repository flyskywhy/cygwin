{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ImDemo;
var
  z: Complex;
begin
  z := Cmplx (1, 2);  { 1 + i * 2 }
  WriteLn (Im (z) : 0 : 5)  { 2.00000 }
end.
