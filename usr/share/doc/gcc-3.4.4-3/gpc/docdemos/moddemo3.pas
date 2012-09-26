{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ModDemo3 (Output);

{$L demomod3.pas}  { explicitly link module }

{ Manually do the "import" from DemoMod3 }
type
  FooType = Integer;

procedure SetFoo (f: FooType); external name 'SetFoo';
function  GetFoo: FooType;     external name 'GetFoo';

begin
  SetFoo (999);
  WriteLn (GetFoo)
end.
