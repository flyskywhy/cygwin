{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program Or_ElseDemo;
var
  a: Integer;
begin
  ReadLn (a);
  if (a = 0) or_else (100 div a > 42) then  { This is safe. }
    WriteLn ('100 div a > 42')
end.
