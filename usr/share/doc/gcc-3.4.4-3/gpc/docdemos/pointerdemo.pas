{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PointerDemo;
var
  a: Integer;
  b: Boolean;
  p: Pointer;
begin
  p := nil;
  p := @a;
  p := @b
end.
