{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program OddDemo;
var
  Foo: Integer;
begin
  Write ('Please enter an odd number: ');
  ReadLn (Foo);
  if not Odd (Foo) then
    WriteLn ('Odd''s not even! Something''s odd out there ...')
  else
    WriteLn (Foo, ' is pretty odd.')
end.
