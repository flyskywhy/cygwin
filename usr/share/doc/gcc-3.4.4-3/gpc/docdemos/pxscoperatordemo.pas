{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PXSCOperatorDemo;

type
  Point = record
    x, y: Real;
  end;

operator + (a, b: Point) c: Point;
begin
  c.x := a.x + b.x;
  c.y := a.y + b.y;
end;

var
  a, b, c: Point = (42, 0.5);

begin
  c := a + b
end.
