{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CopyDemo;
var
  S: String (42);
begin
  S := 'Hello';
  WriteLn (Copy (S, 2, 3));  { yields `ell' }
  WriteLn (Copy (S, 3));     { yields `llo' }
  WriteLn (Copy (S, 4, 7));  { yields `lo' }
  WriteLn (Copy (S, 42))     { yields the empty string }
end.
