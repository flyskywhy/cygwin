{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CallCDemo;

{$L callc.c}  { Or: `callc.o' if you don't have the source }

var
  MyFoo: CInteger; external name 'foo';

procedure Bar; external name 'bar';

begin
  MyFoo := 42;
  Bar
end.
