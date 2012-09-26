{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ExtendDemo;
var
  Sample: Text;
begin
  Assign (Sample, 'sample.txt');
  Rewrite (Sample);
  WriteLn (Sample, 'Hello, World!');  { `sample.txt' now has one line }
  Close (Sample);

  { ... }

  Extend (Sample);
  WriteLn (Sample, 'Hello again!');  { `sample.txt' now has two lines }
  Close (Sample)
end.
