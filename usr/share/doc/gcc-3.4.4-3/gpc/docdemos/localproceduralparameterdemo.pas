{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program LocalProceduralParameterDemo;

procedure CallProcedure (procedure Proc);
begin
  Proc
end;

procedure MainProcedure;
var LocalVariable: Integer;

  procedure LocalProcedure;
  begin
    WriteLn (LocalVariable)
  end;

begin
  LocalVariable := 42;
  CallProcedure (LocalProcedure)
end;

begin
  MainProcedure
end.
