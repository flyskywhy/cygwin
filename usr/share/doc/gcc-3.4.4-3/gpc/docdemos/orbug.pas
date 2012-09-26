{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program OrBug;
var
  a: Integer;
begin
  ReadLn (a);
  if (a = 0) or (100 div a > 42) then  { This is *not* safe! }
    WriteLn ('You''re lucky. But the test could have crashed ...')
end.
