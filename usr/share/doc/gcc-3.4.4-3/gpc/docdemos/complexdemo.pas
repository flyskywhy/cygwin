{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ComplexDemo;
var
  a: Complex;
begin
  a := Cmplx (42, 3);
  WriteLn (Re (a), ' + ', Im (a), ' i')
end.
