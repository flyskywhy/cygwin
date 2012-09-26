{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PAnsiCharDemo;
var
  s: PAnsiChar;
begin
  s := 'Hello, world!';
  {$X+}
  WriteLn (s)
end.
