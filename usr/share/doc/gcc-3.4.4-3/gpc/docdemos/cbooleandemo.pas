{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CBooleanDemo;
var
  a: CBoolean;
begin
  a := True;
  if Ord (a) = 1 then WriteLn ('Ord (True) = 1')
end.
