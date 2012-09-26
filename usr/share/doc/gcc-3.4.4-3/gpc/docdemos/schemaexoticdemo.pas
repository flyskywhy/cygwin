{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SchemaExoticDemo;

type
  ColorType = (Red, Green, Blue);
  ColoredInteger (Color: ColorType) = Integer;

var
  Foo: ColoredInteger (Green);

begin
  Foo := 7;
  if Foo.Color = Red then
    Inc (Foo, 2)
  else
    Foo := Foo div 3
end.
