{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ShlDemo;
var
  a: Integer;
begin
  a := 1 shl 7;  { yields 128 = 2 pow 7 }
  shl (a, 4)  { same as `a := a shl 4' }
end.
