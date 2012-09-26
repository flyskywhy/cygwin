{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program InitTypeDemo;

type
  MyInteger = Integer value 42;

var
  i: MyInteger;

begin
  WriteLn (i)
end.
