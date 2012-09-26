{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program FalseDemo;

var
  a: Boolean;

begin
  a := 1 = 2;  { yields False }
  WriteLn (Ord (False));  { 0 }
  WriteLn (a);  { False }
  if False then WriteLn ('This is not executed.')
end.
