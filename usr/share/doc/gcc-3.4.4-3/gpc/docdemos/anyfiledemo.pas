{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AnyFileDemo;

procedure Test (var f: AnyFile);
var v: ^AnyFile;
begin
  { Generic file operations are allowed for `AnyFile' }
  Rewrite (f);

  { `AnyFile' can also be accessed via pointers }
  v := @f;
  Close (v^)
end;

var
  t: Text;
  f: file;
  g: file of Integer;

begin
  { Any kind of file variable can be passed as `AnyFile' }
  Test (t);
  Test (f);
  Test (g)
end.
