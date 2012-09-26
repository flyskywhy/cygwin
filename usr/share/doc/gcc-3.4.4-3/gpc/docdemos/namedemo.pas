{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program NameDemo;

{ Make two variables aliases of each other by using `name'.
  This is not good style. If you must have aliases for any reason,
  `absolute' declarations may be the lesser evil ... }
var
  Foo: Integer; attribute (name = 'Foo_Bar');
  Bar: Integer; external name 'Foo_Bar';

{ A function from the C library }
function PutS (Str: CString): Integer; external name 'puts';

var
  Result: Integer;
begin
  Result := PutS ('Hello World!');
  WriteLn ('puts wrote ', Result, ' characters (including a newline).');
  Foo := 42;
  WriteLn ('Foo = ', Foo);
  Bar := 17;
  WriteLn ('Setting Bar to 17.');
  WriteLn ('Now, Foo = ', Foo, '!!!')
end.
