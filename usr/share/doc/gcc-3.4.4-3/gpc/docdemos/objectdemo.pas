{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ObjectDemo;

type
  Str100 = String (100);

  FooParentPtr = ^FooParent;
  FooPtr = ^Foo;

  FooParent = object
    constructor Init;
    destructor Done; virtual;
    procedure Bar (c: Real); virtual;
    function Baz (b, a, z: Char) = s: Str100;  { not virtual }
  end;

  Foo = object (FooParent)
    x, y: Integer;
    constructor Init (a, b: Integer);
    destructor Done; virtual;
    procedure Bar (c: Real); virtual;  { overrides `FooParent.Bar' }
    z: Real;  { GPC extension: data fields after methods }
    function Baz: Boolean;  { new function }
  end;

constructor FooParent.Init;
begin
  WriteLn ('FooParent.Init')
end;

destructor FooParent.Done;
begin
  WriteLn ('I''m also done.')
end;

procedure FooParent.Bar (c: Real);
begin
  WriteLn ('FooParent.Bar (', c, ')')
end;

function FooParent.Baz (b, a, z: Char) = s: Str100;
begin
  WriteStr (s, 'FooParent.Baz (', b, ', ', a, ', ', z, ')')
end;

constructor Foo.Init (a, b: Integer);
begin
  inherited Init;
  x := a;
  y := b;
  z := 3.4;
  FooParent.Bar (1.7)
end;

destructor Foo.Done;
begin
  WriteLn ('I''m done.');
  inherited Done
end;

procedure Foo.Bar (c: Real);
begin
  WriteLn ('Foo.Bar (', c, ')')
end;

function Foo.Baz: Boolean;
begin
  Baz := True
end;

var
  Ptr: FooParentPtr;

begin
  Ptr := New (FooPtr, Init (2, 3));
  Ptr^.Bar (3);
  Dispose (Ptr, Done);
  New (Ptr, Init);
  with Ptr^ do
    WriteLn (Baz ('b', 'a', 'z'))
end.
