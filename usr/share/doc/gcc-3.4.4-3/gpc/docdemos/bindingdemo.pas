{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BindingDemo (Input, Output, f);

var
  f: bindable Text;
  b: BindingType;

procedure BindFile (var f: Text);
var
  b: BindingType;
begin
  Unbind (f);
  b := Binding (f);
  repeat
    Write ('Enter a file name: ');
    ReadLn (b.Name);
    Bind (f, b);
    b := Binding (f);
    if not b.Bound then
      WriteLn ('File not bound -- try again.')
  until b.Bound
end;

begin
  BindFile (f);
  { Now the file f is bound to an external file. We can use the
    implementation defined fields of BindingType to check if the
    file exists and is readable, writable or executable. }
  b := Binding (f);
  Write ('The file ');
  if b.Existing then
    WriteLn ('exists.')
  else
    WriteLn ('does not exist.');
  Write ('It is ');
  if not b.Readable then Write ('not ');
  Write ('readable, ');
  if not b.Writable then Write ('not ');
  Write ('writable and ');
  if not b.Executable then Write ('not ');
  WriteLn ('executable.')
end.
