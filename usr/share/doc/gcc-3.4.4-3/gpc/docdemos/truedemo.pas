{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program TrueDemo;

var
  a: Boolean;

begin
  a := 1 = 1;  { yields True }
  WriteLn (Ord (True));  { 1 }
  WriteLn (a);  { True }
  if True then WriteLn ('This is executed.')
end.
