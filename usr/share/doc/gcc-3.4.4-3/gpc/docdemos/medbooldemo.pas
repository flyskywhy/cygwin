{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program MedBoolDemo;
var
  a: MedBool;
begin
  MedInt (a) := 1;
  if a then WriteLn ('Ord (True) = 1')
end.
