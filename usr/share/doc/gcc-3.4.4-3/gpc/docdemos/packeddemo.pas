{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PackedDemo;

type
  MonthInt = packed 1 .. 12;  { needs one byte }
  FastMonthInt = 1 .. 12;     { needs e.g. four bytes }

  FixString10 = packed array [1 .. 10] of Char;
  FoxyString10 = array [0 .. 9] of Char;

  Flags = packed array [1 .. 32] of Boolean;  { needs four bytes }

  Int15 = Integer attribute (Size = 15);
  DateRec = packed record
    Day: 1 .. 31;       { five bits }
    Month: MonthInt;    { four bits }
    Year: Int15         { 15 bits = -16384 .. 16383 }
  end;

  Dates = array [1 .. 1000] of DateRec;

var
  S: FixString10;
  T: FoxyString10;

begin
  S := 'Hello!';  { blank padded }
  WriteLn (S);

  T := 'GNU Pascal';  { GPC extension: this also works. }
  WriteLn (T)
end.
