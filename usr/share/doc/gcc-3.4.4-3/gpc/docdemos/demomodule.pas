{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

module DemoModule interface;  { interface part }

export DemoModule = (FooType, SetFoo, GetFoo);

type
  FooType = Integer;

procedure SetFoo (f: FooType);
function  GetFoo: FooType;

end.

module DemoModule implementation;  { implementation part }

import
  StandardInput;
  StandardOutput;

var
  Foo: FooType;

{ Note: the effect is the same as a `forward' directive would have:
  parameter lists and result types are not allowed in the
  declaration of exported routines, according to EP. In GPC, they
  are allowed, but not required. }
procedure SetFoo;
begin
  Foo := f
end;

function GetFoo;
begin
  GetFoo := Foo
end;

to begin do
  begin
    Foo := 59;
    WriteLn ('Just an example of a module initializer. See comment below')
  end;

to end do
  begin
    Foo := 0;
    WriteLn ('Goodbye')
  end;

end.
