{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SuccDemo;

type
  Metasyntactical = (foo, bar, baz);

var
  m: Metasyntactical;
  c: Char;
  a: array [1 .. 7] of Integer;
  p: ^Integer;

begin
  m := Succ (foo);     { bar }
  c := Succ ('A', 4);  { 'E' }
  a[1] := 42;
  a[2] := Succ (a[1]);     { 43 }
  a[5] := Succ (a[2], 7);  { 50 }
  {$X+}
  p := @a[1];
  p := Succ (p);     { points to `a[2]' now }
  p := Succ (p, 3);  { points to `a[5]' now }
end.
