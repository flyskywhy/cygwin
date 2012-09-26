{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CaseDemo;
var
  Foo: String (10);
  Bar: Integer;
begin
  WriteLn ('Enter up to ten arbitrary characters:');
  ReadLn (Foo);
  for Bar := 1 to Length (Foo) do
    begin
      Write (Foo[Bar], ' is ');
      case Foo[Bar] of
        'A' .. 'Z', 'a' .. 'z':
          WriteLn ('an English letter');
        '0' .. '9':
          WriteLn ('a number');
      otherwise
        WriteLn ('an unrecognized character')
      end
    end
end.
