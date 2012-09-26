{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program RoundDemo;
var
  Foo: Real;
begin
  Foo := 9.876543;
  WriteLn (Round (Foo));  { Prints 10 }
  Foo := 3.456789;
  WriteLn (Round (Foo));  { Prints 3 }

  WriteLn (Frac (12.345) : 1 : 5);  { 0.34500 }
  WriteLn (Int (12.345) : 1 : 5);  { 12.00000 }
  WriteLn (Round (12.345) : 1);  { 12 }
  WriteLn (Trunc (12.345) : 1);  { 12 }

  WriteLn (Frac (-12.345) : 1 : 5);  { -0.34500 }
  WriteLn (Int (-12.345) : 1 : 5);  { -12.00000 }
  WriteLn (Round (-12.345) : 1);  { -12 }
  WriteLn (Trunc (-12.345) : 1);  { -12 }

  WriteLn (Frac (12.543) : 1 : 5);  { 0.54300 }
  WriteLn (Int (12.543) : 1 : 5);  { 12.00000 }
  WriteLn (Round (12.543) : 1);  { 13 }
  WriteLn (Trunc (12.543) : 1);  { 12 }

  WriteLn (Frac (-12.543) : 1 : 5);  { -0.54300 }
  WriteLn (Int (-12.543) : 1 : 5);  { -12.00000 }
  WriteLn (Round (-12.543) : 1);  { -13 }
  WriteLn (Trunc (-12.543) : 1);  { -12 }
end.
