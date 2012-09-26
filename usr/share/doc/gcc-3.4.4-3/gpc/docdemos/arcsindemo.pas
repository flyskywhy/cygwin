{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ArcSinDemo;
begin
  { yields 3.14159 as ArcSin (0.5) = Pi / 6 }
  WriteLn (6 * ArcSin (0.5) : 0 : 5)
end.
