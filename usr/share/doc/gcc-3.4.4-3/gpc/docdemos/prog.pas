{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program Prog;

var
  GlobalVar: Integer;

procedure GlobalProc;
var LocalVar: Integer;

  procedure LocalProc;
  var LocalLocalVar: Integer;
  begin
    WriteLn ('This is a local procedure.')
  end;

begin
  WriteLn ('This is a global procedure.')
end;

begin
  WriteLn ('This is the main program.')
end.
