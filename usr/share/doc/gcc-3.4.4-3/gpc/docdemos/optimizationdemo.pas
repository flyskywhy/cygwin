{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program OptimizationDemo;

procedure Foo;
var
  A, B: Integer;
begin
  A := 3;
  B := 4;
  WriteLn (A + B)
end;

begin
  Foo
end.
