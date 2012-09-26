{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program OrDemo;
var
  a, b, c: Integer;
begin
  if (a = 0) or (b = 0) then  { logical `or' }
    c := 1
  else if (a or b) = 0 then  { bitwise `or' }
    c := 2
  else
    or (c, a)  { same as `c := c or a' }
end.
