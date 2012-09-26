{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PointerArithmeticDemo;
var
  a: array [1 .. 7] of Char;
  p, q: ^Char;
  i: Integer;

{$X+}  { We need extended syntax for pointer arithmetic }

begin
  for p := @a[1] to @a[7] do
    p^ := 'x';

  p := @a[7];
  q := @a[3];
  while p > q do
    begin
      p^ := 'y';
      Dec (p)
    end;

  p := @a[7];
  q := @a[3];
  i := q - p;    { yields 4 }
end.
