{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ResetDemo;
var
  Sample: Text;
  s: String (42);
begin
  Rewrite (Sample);  { Open an internal file for writing }
  WriteLn (Sample, 'Hello, World!');
  Reset (Sample);  { Open it again for reading }
  ReadLn (Sample, s);
  WriteLn (s);
  Close (Sample)
end.
