{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PtrIntDemo;
var
  a: PtrInt;
  p: Pointer;
begin
  GetMem (p, 10);
  a := PtrInt (p);
  Inc (a);
  p := Pointer (a)
end.
