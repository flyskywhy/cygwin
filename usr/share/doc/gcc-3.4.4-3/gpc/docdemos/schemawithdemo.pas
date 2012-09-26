{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SchemaWithDemo;
type
  RealArray (n: Integer) = array [1 .. n] of Real;
var
  MyArray: RealArray (42);
begin
  WriteLn (MyArray.n);  { writes 42 }
  with MyArray do
    WriteLn (n);        { writes 42 }
end.
