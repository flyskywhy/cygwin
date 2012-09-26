{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PtrDiffTypeDemo;
var
  a: array [1 .. 10] of Integer;
  d: PtrDiffType;
  p, q: ^Integer;
begin
  p := @a[1];
  q := @a[4];
  {$X+}
  d := q - p
end.
