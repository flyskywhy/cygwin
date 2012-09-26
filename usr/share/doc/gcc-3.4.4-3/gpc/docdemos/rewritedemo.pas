{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program RewriteDemo;
var
  Sample: Text;
begin
  Assign (Sample, 'sample.txt');
  Rewrite (Sample);
  WriteLn (Sample, 'Hello, World!');
  Close (Sample)
end.
