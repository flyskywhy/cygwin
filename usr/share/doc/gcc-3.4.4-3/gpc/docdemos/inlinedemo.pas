{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program InlineDemo;

function Max (x, y: Integer): Integer; attribute (inline);
begin
  if x > y then
    Max := x
  else
    Max := y
end;

begin
  WriteLn (Max (42, 17), ' ', Max (-4, -2))
end.
