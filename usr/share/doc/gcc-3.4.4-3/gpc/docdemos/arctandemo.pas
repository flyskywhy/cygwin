{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ArcTanDemo;
begin
  { yields 3.14159 as ArcTan (1) = Pi / 4 }
  WriteLn (4 * ArcTan (1) : 0 : 5)
end.
