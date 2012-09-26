{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AssignedDemo;
type
  PInt = ^Integer;

procedure TellIfOdd (p: PInt);
begin
  if Assigned (p) and then Odd (p^) then
    WriteLn ('The pointer p points to an odd value.')
end;

var
  foo: Integer;
begin
  TellIfOdd (nil);
  foo := 1;
  TellIfOdd (@foo);
  foo := 2;
  TellIfOdd (@foo)
end.
