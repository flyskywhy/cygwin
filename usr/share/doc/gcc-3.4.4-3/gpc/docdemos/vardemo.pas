{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program VarDemo;

type
  FooType = Integer;

var
  Bar: FooType;
  ArrayFoo: array [0 .. 9] of Integer;   { array var definition }
  FecordFoo: record                      { record var definition }
               Bar: Integer
             end;
  CharsetFoo: set of Char;               { set var }
  SubrangeFoo: -123 .. 456;              { subrange var }
  EnumeratedFoo: (Mon, Tue, Wed, Thu, Fri, Sat, Sun);  {enumerated var }
  PointerBar: ^FooType;                  { pointer var }

procedure ReadFoo (var Foo: FooType);
begin
  ReadLn (Foo)
end;

begin
  var Bar: Integer;  { GNU Pascal extension }
  Bar := 42
end.
