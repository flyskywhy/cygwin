{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program NilDemo;
const
  NodeNum = 10;
type
  PNode = ^TNode;
  TNode = record
    Key: Integer;
    Next: PNode
  end;
var
  Root, Node: PNode;
  Foo: Integer;
begin
  New (Root);
  Root^.Key := 1;             { Set root key }
  Node := Root;
  for Foo := 2 to NodeNum do  { Create linked list with NODE_NUM nodes }
    begin
      New (Node^.Next);
      Node := Node^.Next;
      Node^.Key := Foo        { Set key }
    end;
  Node^.Next := nil;          { Mark end of linked list }
  { Shorten list by removing its first element until list is empty }
  while Root <> nil do
    begin
      Node := Root;
      WriteLn ('Current key:', Root^.Key);
      Root := Root^.Next;
      Dispose (Node);
      Node := nil             { Indicate old node is not assigned }
    end
end.
