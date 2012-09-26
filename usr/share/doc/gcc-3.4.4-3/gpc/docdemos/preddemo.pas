{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PredDemo;

type
  Metasyntactical = (foo, bar, baz);

var
  m: Metasyntactical;
  c: Char;
  a: array [1 .. 7] of Integer;
  p: ^Integer;

begin
  m := Pred (bar);     { foo }
  c := Pred ('Z', 2);  { 'X' }
  a[1] := 42;
  a[4] := Pred (a[1]);     { 41 }
  a[5] := Pred (a[4], 3);  { 38 }
  {$X+}
  p := @a[5];
  p := Pred (p);     { now p points to a[4] }
  p := Pred (p, 3);  { now p points to a[1] }
end.
