{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AddrDemo;
var
  Foo: ^Integer;
  Bar: Integer;
begin
  Foo := Addr (Bar);  { Let `Foo' point to `Bar'. }
  Bar := 17;
  Foo^ := 42;  { Change the value of `Bar' to 42 }
  WriteLn (Bar)
end.
