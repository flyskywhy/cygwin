{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ExitDemo;

procedure Foo (Bar: Integer);
var
  Baz, Fac: Integer;
begin
  if Bar < 1 then
    Exit;  { Exit `Foo' }
  Fac := 1;
  for Baz := 1 to Bar do
    begin
      Fac := Fac * Baz;
      if Fac >= Bar then
        Exit;  { Exit `Foo' }
      WriteLn (Bar,' is greater than ', Baz, '!, which is equal to ', Fac)
  end
end;

begin
  Foo (-1);
  Foo (789);
  Exit;            { Terminates program }
  Foo (987654321)  { This is not executed anymore }
end.
