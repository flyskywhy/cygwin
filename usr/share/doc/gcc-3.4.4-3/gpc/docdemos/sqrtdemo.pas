{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SqRtDemo;

var
  m1: Complex;

begin
  m1 := Cmplx (-1, 0);  { -1 }
  WriteLn (Re (SqRt (m1)) : 6 : 3, Im (SqRt (m1)) : 6 : 3);
    { yields 1.000 -1.000, i.e. the imaginary unit, i }
end.
