{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SliceWriteDemo;

var
  s: String (42) = 'Hello, world!';

begin
  s[8 .. 12] := 'folks';
  WriteLn (s)  { yields `Hello, folks!' }
end.
