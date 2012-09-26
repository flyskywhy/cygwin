{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SizeTypeDemo;
var
  a: array [1 .. 10] of Integer;
  Size: SizeType;
begin
  Size := SizeOf (a);
  WriteLn (Size)
end.
