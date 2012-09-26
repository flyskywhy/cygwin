{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program RmDirDemo;
var
  Foo: String (127);
begin
  WriteLn ('Enter directory name to remove: ');
  ReadLn (Foo);
  {$I-}  { Don't abort on I/O errors }
  RmDir (Foo);
  if IOResult <> 0 then
    WriteLn ('Directory ', Foo, ' could not be removed.')
  else
    WriteLn ('Okay.')
end.
