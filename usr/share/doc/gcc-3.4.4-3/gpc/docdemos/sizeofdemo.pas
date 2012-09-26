{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SizeOfDemo;
var
  a: Integer;
  b: array [1 .. 8] of Char;
begin
  WriteLn (SizeOf (a));        { Size of an `Integer'; often 4 bytes. }
  WriteLn (SizeOf (Integer));  { The same. }
  WriteLn (SizeOf (b))         { Size of eight `Char's; usually 8 bytes. }
end.
