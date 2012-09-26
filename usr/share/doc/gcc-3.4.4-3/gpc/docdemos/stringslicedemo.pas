{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program StringSliceDemo;

const
  HelloWorld = 'Hello, world!';

begin
  WriteLn (HelloWorld[8 .. 12])  { yields `world' }
end.
