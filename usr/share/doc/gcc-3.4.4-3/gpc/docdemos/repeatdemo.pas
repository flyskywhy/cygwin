{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program RepeatDemo;
var
  Number, Sum: Integer;
begin
  WriteLn ('Black Jack for beginners.');
  WriteLn ('You can choose your cards yourself. :-)');
  Sum := 0;
  repeat
    Write ('Your card (number)? ');
    ReadLn (Number);
    Inc (Sum, Number);
    WriteLn ('You have ', Sum, '.')
  until Sum >= 21;
  if Sum = 21 then
    WriteLn ('You win!')
  else
    WriteLn ('You lose.')
end.
