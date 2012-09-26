{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program OtherwiseDemo;

var
  i: Integer;
  a: array [1 .. 10] of Integer value [1: 2; 4: 5 otherwise 3];

begin
  for i := 1 to 10 do
    case a[i] of
      2:        WriteLn ('a[', i, '] has value two.');
      3:        WriteLn ('a[', i, '] has value three.');
      otherwise WriteLn ('a[', i, '] has neither value two nor three.')
    end
end.
