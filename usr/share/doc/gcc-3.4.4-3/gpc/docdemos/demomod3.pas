{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

module DemoMod3;

type
  FooType = Integer;

var
  Foo: FooType;

procedure SetFoo (f: FooType); attribute (name = 'SetFoo');
begin
  Foo := f
end;

function GetFoo: FooType; attribute (name = 'GetFoo');
begin
  GetFoo := Foo;
end;

end.
