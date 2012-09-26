{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program LongestBoolDemo;
var
  a: LongestBool;
begin
  LongestInt (a) := 1;
  if a then WriteLn ('Ord (True) = 1')
end.
