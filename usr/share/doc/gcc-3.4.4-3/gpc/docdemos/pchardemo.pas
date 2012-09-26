{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PCharDemo;
var
  s: PChar;
begin
  s := 'Hello, world!';
  {$X+}
  WriteLn (s)
end.
