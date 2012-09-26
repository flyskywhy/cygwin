{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SinDemo;
begin
  { yields 0.5 since Sin (Pi / 6) = 0.5 }
  WriteLn (Sin (Pi / 6) : 0 : 5)
end.
