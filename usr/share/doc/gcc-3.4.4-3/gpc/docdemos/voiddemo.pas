{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program VoidDemo;

procedure p (var x: Void);
begin
end;

var
  i: Integer;
  s: String (42);

begin
  p (i);
  p (s)
end.
