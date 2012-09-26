{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program IncDecDemo;
var
  i: Integer;
  c: Char;
begin
  Inc (i);     { i := i + 1; }
  Dec (i, 7);  { i := i - 7; }
  Inc (c, 3);  { c := Succ (c, 3); }
end.
