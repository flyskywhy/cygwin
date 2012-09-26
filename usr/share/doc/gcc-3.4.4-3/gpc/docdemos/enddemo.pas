{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program EndDemo;
begin
  if True then
    WriteLn ('single statement');
  if True then
    begin  { clamp statement1 ... }
      WriteLn ('statement1');
      WriteLn ('statement2')
    end    { ... to statement2 }
end.
