{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ArgDemo;
var
  z: Complex;
begin
  z := Cmplx (1, 1);  { 1 + i }
  WriteLn (Arg (z) : 0 : 5)  { yields 0.78540, i.e. Pi / 4 }
end.
