{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program TypeOfDemo;
type
  FooPtr = ^Foo;
  BarPtr = ^Bar;

  Foo = object         { Has a VMT, though it doesn't }
    x: Integer;        { contain virtual methods.     }
    constructor Init;
  end;

  Bar = object (Foo)
    y: Integer;
  end;

constructor Foo.Init;
begin
end;

var
  MyFoo: FooPtr;

begin
  MyFoo := New (BarPtr, Init);
  if TypeOf (MyFoo^) = TypeOf (Bar) then  { True }
    WriteLn ('OK')
end.
