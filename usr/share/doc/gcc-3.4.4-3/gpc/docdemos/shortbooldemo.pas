{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ShortBoolDemo;
var
  a: ShortBool;
begin
  ShortInt (a) := 1;
  if a then WriteLn ('Ord (True) = 1')
end.
