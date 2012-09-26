{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AlignOfDemo;
var
  a: Integer;
  b: array [1 .. 8] of Char;
begin
  WriteLn (AlignOf (a));  { Alignment of `Integer', e.g. 4 bytes. }
  WriteLn (AlignOf (Integer));  { The same. }
  WriteLn (AlignOf (b));  { Alignment of `Char'; usually 1 byte. }
end.
