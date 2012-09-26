{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program MkDirDemo;
var
  Foo: String (127);
begin
  WriteLn ('Enter directory name to create:');
  ReadLn (Foo);
  {$I-}  { Don't abort program on error }
  MkDir (Foo);
  if IOResult <> 0 then
    WriteLn ('Directory `', Foo, ''' could not be created')
  else
    WriteLn ('Okay')
end.
