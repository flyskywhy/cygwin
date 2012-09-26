{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ArcCosDemo;
begin
  { yields 3.14159 as ArcCos (0.5) = Pi / 3 }
  WriteLn (3 * ArcCos (0.5) : 0 : 5)
end.
