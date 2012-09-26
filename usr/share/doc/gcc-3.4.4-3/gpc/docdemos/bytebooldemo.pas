{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ByteBoolDemo;
var
  a: ByteBool;
begin
  Byte (a) := 1;
  if a then WriteLn ('Ord (True) = 1')
end.
