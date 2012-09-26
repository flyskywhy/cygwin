{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program DecDemo;
var
  x: Integer;
  y: array [1 .. 5] of Integer;
  p: ^Integer;
begin
  x := 9;
  Dec (x, 10);  { yields -1 }
  {$X+}         { Turn on extended systax }
  p := @y[5];   { p points to y[5] }
  Dec (p, 3)    { p points to y[2] }
end.
