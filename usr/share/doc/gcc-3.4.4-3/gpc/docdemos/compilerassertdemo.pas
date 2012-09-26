{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CompilerAssertDemo;

var
  a: LongInt;

const
  { Make sure that the highest value a can hold is larger than
    MaxInt, and set b to that value. }
  b = CompilerAssert (High (a) > MaxInt, High (a));

  { Do a similar check for the minimum value, setting c to True
    (which can be ignored). }
  c = CompilerAssert (Low (a) < Low (Integer));

begin
  { Procedure-like use of CompilerAssert in the statement part. }
  CompilerAssert (MaxInt >= 100000);

  WriteLn (b, ' ', c)
end.
