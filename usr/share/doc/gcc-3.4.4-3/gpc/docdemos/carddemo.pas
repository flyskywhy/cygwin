{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CardDemo;
var
  Foo: set of 1 .. 100;
begin
  Foo := [1, 2, 3, 5, 1, 1, 1, 2, 2, 2, 3, 3, 5, 5];  { four elements }
  WriteLn ('foo consists of ', Card (Foo), ' elements')
end.
