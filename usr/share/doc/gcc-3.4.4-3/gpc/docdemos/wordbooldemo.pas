{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program WordBoolDemo;
var
  a: WordBool;
begin
  Word (a) := 1;
  if a then WriteLn ('Ord (True) = 1')
end.
