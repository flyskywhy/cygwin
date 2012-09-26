{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program Schema3Demo;
type
  RealArray (n: Integer) = array [1 .. n] of Real;
  RealArrayPtr = ^RealArray;
var
  Bar: RealArrayPtr;
  i: Integer;
begin
  Bar := New (RealArrayPtr, 137);
  for i := 1 to Bar^.n do
    Bar^[i] := 42
end.
