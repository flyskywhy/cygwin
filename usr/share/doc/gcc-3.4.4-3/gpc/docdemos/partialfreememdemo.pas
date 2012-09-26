{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program PartialFreeMemDemo;

type
  Vector = array [0 .. 1023] of Integer;
  VecPtr = ^Vector;

var
  p, q: VecPtr;

begin
  GetMem (p, 1024 * SizeOf (Integer));
  q := VecPtr (@p^[512]);

  { ... }

  FreeMem (p, 512 * SizeOf (Integer));

  { ... }

  FreeMem (q, 512 * SizeOf (Integer));
end.
