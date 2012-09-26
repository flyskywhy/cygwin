{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ParameterDemo;

procedure Foo (var Bar; var Baz: Integer; const Fred: Integer);

  procedure Glork1 (function Foo: Integer; procedure Bar (Baz: Integer));
  begin
    Bar (Foo)
  end;

begin
  Baz := Integer (Bar) + Fred
end;

var
  a, b, c: Integer;

begin
  Foo (a, b, c)
end.
