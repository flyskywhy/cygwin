{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AndProcedureDemo;
var x: Integer;
begin
  and (x, $0000ffff);
end.
