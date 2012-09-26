{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program LowDemo;
type
  Colors = (Red, Green, Blue);
var
  Col: array [12 .. 20] of Colors;
  Foo: 12 .. 20;
  Bar: Integer;
begin
  Foo := Low (Col);            { returns 12 }
  Col[Foo] := Low (Col[Foo]);  { returns Red }
  Bar := Low (Integer)         { lowest possible value of `Integer' }
end.
