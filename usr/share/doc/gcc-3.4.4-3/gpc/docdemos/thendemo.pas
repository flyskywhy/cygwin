{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ThenDemo;
var
  i: Integer;
begin
  Write ('Enter a number: ');
  ReadLn (i);
  if i > 42 then
    WriteLn ('The number is greater than 42')
end.
