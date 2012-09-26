{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CommandLineArgumentsDemo (Output);

var
  Counter: Integer;

begin
  WriteLn ('This program displays command line arguments one per line.');
  for Counter := 0 to ParamCount do
    WriteLn ('Command line argument #', Counter, ' is `',
             ParamStr (Counter), '''')
end.
