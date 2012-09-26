{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program XorDemo;
var
  a, b, c: Integer;
begin
  if (a = 0) xor (b = 0) then
    c := 1  { happens if either `a' or `b' is zero,    }
            { but not if both are zero or both nonzero }
  else if (a xor b) = 0 then  { bitwise xor }
    c := 2  { happens if a = b }
  else
    xor (c, a)  { same as `c := c xor a' }
end.
