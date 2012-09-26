{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BPInitVarDemo;
const
  A: Integer = 7;
  B: array [1 .. 3] of Char = ('F', 'o', 'o');
  C: array [1 .. 3] of Char = 'Bar';
  Foo: record
    x, y: Integer;
  end = (x: 3; y: 4);
begin
end.
