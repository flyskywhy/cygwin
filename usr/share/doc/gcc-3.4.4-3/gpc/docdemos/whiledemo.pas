{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program WhileDemo;
var
  Foo, Bar: Integer;
begin
  WriteLn ('Enter an descending series of integer numbers.');
  WriteLn ('Terminate by breaking this rule.');
  WriteLn ('Enter start number: ');
  Bar := MaxInt;
  ReadLn (Foo);
  while Foo < Bar do
    begin
      Bar := Foo;
      ReadLn (Foo)
    end;
  WriteLn ('The last number of your series was: ', Bar)
end.
