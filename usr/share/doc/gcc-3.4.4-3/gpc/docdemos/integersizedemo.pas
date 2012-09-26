{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program IntegerSizeDemo;
type
  MyInt  = Integer attribute (Size = 42);  { 42 bits, signed }
  MyWord = Word attribute (Size = 2);      { 2 bits, unsigned,
                                              i.e., 0 .. 3 }
  MyCard = Cardinal attribute (Size = 2);  { the same }

  HalfInt = Integer attribute (Size = BitSizeOf (Integer) div 2);
    { A signed integer type which is half as big as the normal
      `Integer' type, regardless of how big `Integer' is
      on any platform the program is compiled on. }

begin
end.
