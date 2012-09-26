{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ShrDemo;
var
  a: Integer;
begin
  a := 1024 shr 4;  { yields 64 }
  a := -127 shr 4;  { yields -8 }
  shr (a, 2)  { same as `a := a shr 2' }
end.
