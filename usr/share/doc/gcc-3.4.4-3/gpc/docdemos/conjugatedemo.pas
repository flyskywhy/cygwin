{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ConjugateDemo;
var
  z: Complex;
begin
  z := Cmplx (2, 3);  { z is 2 + i * 3 }
  WriteLn ('z = ', Re (z) : 0 : 5, ' + i * ', Im (z) : 0 : 5);
  z := Conjugate (z);  { z conjugate is 2 - i * 3 }
  WriteLn ('z conjugate = ', Re (z) : 0 : 5,' + i * ', Im (z) : 0 : 5)
end.
