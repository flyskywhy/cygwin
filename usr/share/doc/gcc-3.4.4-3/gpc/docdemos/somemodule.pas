{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

module SomeModule interface;

export
  SomeInterface = (a);
  AllInterface = all;  { Same as `AllInterface = (a, b, Bar);' }

var
  a, b: Integer;

procedure Bar (i: Integer);

end.

module SomeModule implementation;

procedure Bar (i: Integer);
begin
  b := a
end;

to begin do
  a := 42;

end.
