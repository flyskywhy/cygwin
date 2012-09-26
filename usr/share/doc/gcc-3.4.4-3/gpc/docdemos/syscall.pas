{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SysCall;

function System (CmdLine: CString): Integer; external name 'system';

var
  Result: Integer;

begin
  Result := System ('ls -l');
  WriteLn ('system() call returned: ', Result)
end.
