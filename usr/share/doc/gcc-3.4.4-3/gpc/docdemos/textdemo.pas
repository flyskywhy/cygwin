{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program TextDemo;
var
  t: Text;
begin
  Rewrite (t, 'hello.txt');
  WriteLn (t, 'Hello, world!')
end.
