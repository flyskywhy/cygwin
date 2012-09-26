{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AndDemo;
var
  a, b, c: Integer;
begin
  if (a = 0) and (b = 0) then  { logical `and' }
    c := 1
  else if (a and b) = 0 then  { bitwise `and' }
    c := 2
  else
    and (c, a)  { same as `c := c and a' }
end.
