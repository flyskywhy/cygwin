{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program IncDemo;
var
  Foo: Integer;
  Bar: array [1 .. 5] of Integer;
  Baz: ^Integer;
begin
  Foo := 4;
  Inc (Foo, 5);      { yields 9 }
  {$X+}            { Turn on extended systax }
  Baz := @Bar[1];   { Baz points to y[1] }
  Inc (Baz, 2);      { Baz points to y[3] }
end.
