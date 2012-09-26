{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ProcPtrDemo (Output);

type
  ProcPtr = ^procedure (i: Integer);

var
  PVar: ProcPtr;

procedure WriteInt (i: Integer);
begin
  WriteLn ('Integer: ', i : 1)
end;

begin
  { Let PVar point to function WriteInt }
  PVar := @WriteInt;

  { Call the function by dereferencing the function pointer }
  PVar^ (12345)
end.
