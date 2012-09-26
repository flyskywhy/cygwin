{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CurrentRoutineNameDemo;

procedure FooBar;
begin
  WriteLn (CurrentRoutineName)  { `FooBar' }
end;

begin
  WriteLn (CurrentRoutineName);  { `main program' }
  FooBar
end.
