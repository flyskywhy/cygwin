{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program NearDemo;

var
  p: procedure;

{$W no-near-far}  { Don't warn about the uselessness of `near' }

procedure Foo; near;  { `near' has no effect in GPC }
begin
  WriteLn ('Foo')
end;

begin
  p := Foo;  { Works, despite the `near'. }
  p
end.
