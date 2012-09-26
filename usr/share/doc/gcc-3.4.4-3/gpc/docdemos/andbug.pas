{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AndBug;
var
  p: ^Integer;
begin
  New (p);
  ReadLn (p^);
  if (p <> nil) and (p^ < 42) then  { This is NOT safe! }
    WriteLn ('You''re lucky. But the test could have crashed ...')
end.
