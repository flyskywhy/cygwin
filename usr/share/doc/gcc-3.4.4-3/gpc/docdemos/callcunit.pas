{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

unit CallCUnit;

interface

var
  MyFoo: CInteger; external name 'foo';

procedure Bar; external name 'bar';

implementation

{$L callc.c}  { Or: `callc.o' if you don't have the source }

end.
