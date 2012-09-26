{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program StringDemo (Output);

type
  SType = String (10);
  SPtr  = ^String;

var
  Str : SType;
  Str2: String (100000);
  Str3: String (20) value 'string expression';
  DStr: ^String;
  ZStr: SPtr;
  Len : Integer value 256;
  Ch  : Char value 'R';

{ `String' accepts any length of strings }
procedure Foo (z: String);
begin
  WriteLn ('Capacity: ', z.Capacity);
  WriteLn ('Length  : ', Length (z));
  WriteLn ('Contents: ', z);
end;

{ Another way to use dynamic strings }
procedure Bar (SLen: Integer);
var
  LString: String (SLen);
  FooStr: type of LString;
begin
  LString := 'Hello world!';
  Foo (LString);
  FooStr := 'How are you?';
  Foo (FooStr);
end;

begin
  Str  := 'KUKKUU';
  Str2 := 'A longer string variable';
  New (DStr, 1000);  { Select the string Capacity with `New' }
  DStr^ := 'The maximum length of this is 1000 chars';
  New (ZStr, Len);
  ZStr^ := 'This should fit here';
  Foo (Str);
  Foo (Str2);
  Foo ('This is a constant string');
  Foo ('This is a ' + Str3);
  Foo (Ch);  { A char parameter to string routine }
  Foo ('');  { An empty string }
  Foo (DStr^);
  Foo (ZStr^);
  Bar (10000);
end.
