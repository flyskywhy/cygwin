{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program Schema1Demo;
type
  PositiveInteger = 1 .. MaxInt;
  RealArray (n: Integer) = array [1 .. n] of Real;
  Matrix (n, m: PositiveInteger) = array [1 .. n, 1 .. m] of Integer;

var
  Foo: RealArray (42);

begin
  WriteLn (Foo.n)  { yields 42 }
end.
