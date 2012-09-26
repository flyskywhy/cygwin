{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BitSizeOfDemo;
type
  Int12 = Integer attribute (Size = 12);
var
  a: Integer;
  b: array [1 .. 8] of Char;
  c: Int12;
  d: packed record
       x: Int12;
       y: 0 .. 3
     end;
begin
  WriteLn (BitSizeOf (a));    { Size of an `Integer'; usually 32 bits. }
  WriteLn (BitSizeOf (Integer));  { The same. }
  WriteLn (BitSizeOf (b));    { Size of eight `Char's; usually 64 bits. }
  WriteLn (BitSizeOf (c));    { e.g. 16 bits (smallest addressable
                                 space holding a 12 bit integer). }
  WriteLn (BitSizeOf (d));    { e.g. 16 }
  WriteLn (BitSizeOf (d.x));  { 12 }
  WriteLn (BitSizeOf (d.y))   { 2 }
end.
