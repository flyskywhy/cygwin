{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BitOperatorProcedureDemo;
var x: Integer;
begin
  x := 7;
  and (x, 14);  { sets x to 6 }
  xor (x, 3);   { sets x to 5 }
end.
