{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AbsDemo;
var
  i1: Complex;
begin
  WriteLn (Abs (42));             { 42 }
  WriteLn (Abs (-42));            { 42 }
  WriteLn (Abs (-12.1) : 0 : 1);  { 12.1 }
  i1 := Cmplx (1, 1);             { 1 + i }
  WriteLn (Abs (i1) : 0 : 3)      { 1.414, i.e. SqRt (2) }
end.
