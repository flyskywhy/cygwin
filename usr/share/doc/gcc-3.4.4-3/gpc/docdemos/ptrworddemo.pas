{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PtrWordDemo;
var
  a: PtrWord;
  p: Pointer;
begin
  GetMem (p, 10);
  a := PtrWord (p);
  Inc (a);
  p := Pointer (a)
end.
