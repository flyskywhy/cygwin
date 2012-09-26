{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program DirectAccessFileDemo;
type
  DFile = file [1 .. 100] of Integer;
var
  F: DFile;
  P, N: 1 .. 100;
begin
  Rewrite (F);
  P := 42;
  N := 17;
  SeekWrite (F, P);
  Write (F, N)
end.
