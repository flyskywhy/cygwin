{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SqrDemo;

var
  i: Complex;

begin
  i := Cmplx (0, 1);
  WriteLn (Re (Sqr (i)) : 0 : 3)  { yields -1.000 }
end.
