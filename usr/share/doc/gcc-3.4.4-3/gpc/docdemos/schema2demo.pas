{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program Schema2Demo;
type
  RealArray (n: Integer) = array [1 .. n] of Real;
  RealArrayPtr = ^RealArray;
var
  Bar: RealArrayPtr;
begin
end.
