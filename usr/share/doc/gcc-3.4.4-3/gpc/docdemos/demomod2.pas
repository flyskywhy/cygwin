{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

module DemoMod2;  { Alternative method }

export Catch22 = (FooType, SetFoo, GetFoo);

type
  FooType = Integer;

procedure SetFoo (f: FooType);
function  GetFoo: FooType;

end; { note: this `end' is required here, even if the
       module-block below would be empty. }

var
  Foo: FooType;

procedure SetFoo;
begin
  Foo := f
end;

function GetFoo;
begin
  GetFoo := Foo
end;

end.
