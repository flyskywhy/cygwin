{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ChDirDemo;
var
  Foo: String (127);
begin
  WriteLn ('Enter directory name to change to:');
  ReadLn (Foo);
  {$I-}  { Don't abort the program on error }
  ChDir (Foo);
  if IOResult <> 0 then
    WriteLn ('Cannot change to directory `', Foo, '''.')
  else
    WriteLn ('Okay.')
end.
