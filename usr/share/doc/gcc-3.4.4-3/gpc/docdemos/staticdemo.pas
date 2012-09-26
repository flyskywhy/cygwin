{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program StaticDemo;

procedure Foo;
{ x keeps its value between two calls to this procedure }
var
  x: Integer = 0; attribute (static);
begin
  WriteLn (x);
  Inc (x)
end;

begin
  Foo;
  Foo;
  Foo;
end.
