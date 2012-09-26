{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program FarDemo;

var
  p: procedure;

{$W no-near-far}  { Don't warn about the uselessness of `far' }

procedure Foo; far;  { `far' has no effect in GPC }
begin
  WriteLn ('Foo')
end;

begin
  p := Foo;  { Would also work without `far' in GPC. }
  p
end.
