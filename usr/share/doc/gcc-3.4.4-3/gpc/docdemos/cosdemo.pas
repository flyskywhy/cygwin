{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CosDemo;
begin
  { yields 0.5 since Cos (Pi / 3) = 0.5 }
  WriteLn (Cos (Pi / 3) : 0 : 5)
end.
