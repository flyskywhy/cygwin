{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BreakDemo;
var
  Foo: Integer;
begin
  while True do
    begin
      repeat
        WriteLn ('Enter a number less than 100:');
        ReadLn (Foo);
        if Foo < 100 then
          Break;  { Exits `repeat' loop }
        WriteLn (Foo, ' is not exactly less than 100! Try again ...')
      until False;
      if Foo > 50 then
        Break;  { Exits `while' loop }
      WriteLn ('The number entered was not greater than 50.')
    end
end.
