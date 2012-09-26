{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ElseDemo;
var
  i: Integer;
begin
  Write ('Enter a number: ');
  ReadLn (i);
  if i > 42 then
    WriteLn ('The number is greater than 42')
  else
    WriteLn ('The number is not greater than 42')
end.
