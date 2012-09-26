{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program HighDemo;
type
  Colors = (Red, Green, Blue);
var
  Col: array [Colors] of (Love, Hope, Faithfulness);
  Foo: Colors;
  Bar: Integer;
  Baz: String (123);
begin
  Foo := High (Col);             { yields Blue }
  Bar := Ord (High (Col[Foo]));  { yields Ord (Faithfulness), i.e., 2 }
  Bar := High (Integer);         { highest possible value of `Integer' }
  Bar := High (Baz)              { returns 123 }
end.
