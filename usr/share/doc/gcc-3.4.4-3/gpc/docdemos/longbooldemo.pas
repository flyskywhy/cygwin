{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program LongBoolDemo;
var
  a: LongBool;
begin
  LongInt (a) := 1;
  if a then WriteLn ('Ord (True) = 1')
end.
