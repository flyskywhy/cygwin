{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program StdErrDemo;
var
  Denominator: Integer;
begin
  ReadLn (Denominator);
  if Denominator = 0 then
    WriteLn (StdErr, ParamStr (0), ': division by zero')
  else
    WriteLn ('1 / ', Denominator, ' = ', 1 / Denominator)
end.
