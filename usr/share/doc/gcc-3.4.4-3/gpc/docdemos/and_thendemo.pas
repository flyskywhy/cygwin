{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program And_ThenDemo;
var
  p: ^Integer;
begin
  New (p);
  ReadLn (p^);
  if (p <> nil) and_then (p^ < 42) then  { This is safe. }
    WriteLn (p^, ' is less than 42')
end.
