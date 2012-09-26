{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CStringDemo;
var
  s: CString;
begin
  s := 'Hello, world!';
  {$X+}
  WriteLn (s)
end.
