{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program NullDemo;
type
  PString = ^String;
var
  Com1: String (25) = 'This is an amazing number';
  Com2: String (25) = 'This is a boring number';

procedure FooBar (Foo: Integer; var Comment: PString);
begin
  if Odd (Foo) then
    WriteLn ('FooBar:', Foo, ' is odd')
   else
    WriteLn ('FooBar:', Foo, ' is even');
  if @Comment <> nil then
    if not Odd (Foo) then
      Comment := @Com1
    else
      Comment := @Com2
end;

var
  S: String (25);
  P: PString value @S;

begin
  { FooBar allows you to leave out variables
    for any information you might not need }
  FooBar (1, Null);
  { But FooBar is flexible, after all }
  FooBar (6, P);
  WriteLn ('FooBar said about 6: `', P^, '''')
end.
