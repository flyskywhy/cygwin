{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AbsoluteDemo;

{$X+}

const
  IOMem = $f0000000;
  MaxVarSize = MaxInt div 8;

var
  Mem: array [0 .. MaxVarSize - 1] of Byte absolute 0;

  { This address has no actual meaning }
  MyPort: Byte absolute IOMem + $c030;

{ Beware: Using any of the variables above will crash
  your program unless you know exactly what you do!
  That's why GPC warns about it without the $X+ directive. }

var
  x: Real;
  a: array [1 .. SizeOf (Real)] of Byte absolute x;
  i: Integer;
  b: Byte absolute a[i];  { GNU Pascal extension:
                             non-constant memory reference. }

begin
  x := 3.14;

  { Look at the internal representation of a real variable. }
  for i := 1 to SizeOf (Real) do
    Write (a[i] : 4);
  WriteLn;

  { The same again, more ugly ... }
  for i := 1 to SizeOf (Real) do
    Write (b : 4);
  WriteLn;

  { And yes, there's an even more ugly way to do it ... }
  for i := 1 to SizeOf (Real) do
    Write (Mem[PtrCard (@x) + i - 1] : 4);
  WriteLn
end.
