{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program RecordDemo;

type
  FooPtr = ^Foo;

  Foo = record
    Bar: Integer;
    NextFoo: FooPtr;
    case Choice: 1 .. 3 of
      1: (a: Integer);  { These three choices may share }
      2: (b: Real);     { one location in memory. }
      3: (c: Char;
          d: Boolean);
  end;

  Int5 = Integer attribute (Size = 5);
  SmallFoo = packed record
    b: 0 .. 3;
    a: Int5;
    r: Boolean
  end;  { needs 1 byte }

var
  f: Foo;

begin
  f.b := 3.14;
  WriteLn (f.a)  { yields some strange number which is part of the   }
                 { internal representation of the real number `f.b'. }
end.
