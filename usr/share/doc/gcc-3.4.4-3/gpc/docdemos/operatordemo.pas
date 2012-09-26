{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program OperatorDemo;

type
  Vector3 = record
    x, y, z: Real;
  end;

var
  a, b, c: Vector3 = (1, 2, 3);

operator + (u, v: Vector3) w: Vector3;
begin
  w.x := u.x + v.x;
  w.y := u.y + v.y;
  w.z := u.z + v.z;
end;

begin
  c := a + b
end.
