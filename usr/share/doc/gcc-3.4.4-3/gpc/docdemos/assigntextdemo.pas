{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AssignTextDemo;
var
  t: Text;
  Line: String (4096);
begin
  Assign (t, 'mytext.txt');
  Reset (t);
  while not EOF (t) do
    begin
      ReadLn (t, Line);
      WriteLn (Line)
    end
end.
