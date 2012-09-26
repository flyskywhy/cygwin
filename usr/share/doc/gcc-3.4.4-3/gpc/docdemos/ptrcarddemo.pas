{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PtrCardDemo;
var
  a: PtrCard;
  p: Pointer;
begin
  GetMem (p, 10);
  a := PtrCard (p);
  Inc (a);
  p := Pointer (a)
end.
