{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ComplexOperationsDemo (Output);

var
  z1, z2: Complex;
  Len, Angle: Real;

begin
  z1 := Cmplx (2, 1);
  WriteLn;
  WriteLn ('Complex number z1 is: (', Re (z1) : 1, ',', Im (z1) : 1, ')');
  WriteLn;
  z2 := Conjugate(z1); { GPC extension }
  WriteLn ('Conjugate of z1 is: (', Re (z2) : 1, ',', Im (z2) : 1, ')');
  WriteLn;
  Len   := Abs (z1);
  Angle := Arg (z1);
  WriteLn ('The polar representation of z1 is: Length=', Len : 1,
           ', Angle=', Angle : 1);
  WriteLn;
  z2 := Polar (Len, Angle);
  WriteLn ('Converting (Length, Angle) back to (x, y) gives: (',
           Re (z2) : 1, ',', Im (z2) : 1, ')');
  WriteLn;
  WriteLn ('The following operations operate on the complex number z1');
  WriteLn;
  z2 := ArcTan (z1);
  WriteLn ('ArcTan (z1) = (', Re (z2), ', ', Im (z2), ')');
  WriteLn;
  z2 := z1 ** 3.141;
  WriteLn ('z1 ** 3.141 =', Re (z2), ', ', Im (z2), ')');
  WriteLn;
  z2 := Sin (z1);
  WriteLn ('Sin (z1) = (', Re (z2), ', ', Im (z2), ')');
  WriteLn ('(Cos, Ln, Exp, SqRt and Sqr exist also.)');
  WriteLn;
  z2 := z1 pow 8;
  WriteLn ('z1 pow 8 = (', Re (z2), ', ', Im (z2), ')');
  WriteLn;
  z2 := z1 pow (-8);
  WriteLn ('z1 pow (-8) = (', Re (z2), ', ', Im (z2), ')');
end.
