{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ArrayDemo;
type
  IntArray = array [1 .. 20] of Integer;
  WeekDayChars = array [(Mon, Tue, Wed, Thu, Fri, Sat, Sun)] of Char;
  Foo = array [0 .. 9, 'a' .. 'z', (Baz, Glork1, Fred)] of Real;
  TwoDimIntArray = array [1 .. 10] of IntArray;
  { is equivalent to: }
  TwoDimIntArray2 = array [1 .. 10, 1 .. 20] of Integer;

procedure PrintChars (F: array of Char);
var
  i: Integer;
begin
  for i := Low (F) to High (F) do
    WriteLn (F[i])
end;

var
  Waldo: WeekDayChars;

begin
  Waldo := 'HiWorld';
  PrintChars (Waldo)
end.
