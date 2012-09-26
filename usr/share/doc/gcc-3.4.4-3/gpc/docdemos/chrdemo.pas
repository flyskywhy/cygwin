{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ChrDemo;
var
  x: Integer;
begin
  for x := 32 to 122 do
    Write (Chr (x))
end.
