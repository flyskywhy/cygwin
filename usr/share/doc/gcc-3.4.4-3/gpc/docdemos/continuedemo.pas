{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ContinueDemo;
var
  Foo, Bar: Integer;
begin
  WriteLn ('Enter three numbers:');
  for Bar := 1 to 3 do
    begin
      ReadLn (Foo);
      if Foo < 5 then
        Continue;
      WriteLn ('Your number was greater than 5.')
    end
end.
