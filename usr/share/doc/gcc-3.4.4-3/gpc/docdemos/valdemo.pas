{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ValDemo;
var
  x, ec: Integer;
  l: LongInt;
  r: Real;
begin
  Val ('123', x, ec);                { x :=            123; ec := 0; }
  Val ('-123', x, ec);               { x :=           -123; ec := 0; }
  Val ('123.456', r, ec);            { r :=        123.456; ec := 0; }
  Val ('$ffff', x, ec);              { x :=          65535; ec := 0; }
  Val ('$F000', x, ec);              { x :=          61440; ec := 0; }
  Val ('-$ffff', x, ec);             { x :=         -65535; ec := 0; }
  Val ('12#100', x, ec);             { x :=            144; ec := 0; }
  Val ('-2#11111111', x, ec);        { x :=           -255; ec := 0; }
  { here we have the invalid character 'X' for base 16 }
  Val ('$fffeX', x, ec);             { x :=    <undefined>; ec := 6; }
  Val ('12#100invalid', x, ec);      { x :=    <undefined>; ec := 7; }
  Val ('36#Jerusalem', l, ec);       { l := 54758821170910; ec := 0; }
end.
