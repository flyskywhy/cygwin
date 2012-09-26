{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program HaltDemo;
begin
  WriteLn ('This string will always be this program''s output.');
  Halt;  { Terminate right here and right now. }
  WriteLn ('And this string won''t ever!')
end.
