{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program IntegerTypesDemo (Output);

var
  ByteVar: Byte;
  ShortIntVar: ShortInt;
  Foo: MedCard;
  Big: LongestInt;

begin
  ShortIntVar := 1000;
  Big := MaxInt * ShortIntVar;
  ByteVar := 127;
  Foo := 16#deadbeef
end.
