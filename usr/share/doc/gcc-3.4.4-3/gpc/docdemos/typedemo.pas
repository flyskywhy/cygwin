{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program TypeDemo;
type
  { This side is the }    { That side is the }
  { type declaration }    { type definition  }

  { array type }
  ArrayType                  = array [0 .. 9] of Integer;

  { record type }
  RecordType                 = record
                                 Bar: Integer
                               end;

  { subrange type }
  SubrangeType               = -123 .. 456;

  { enumeration type }
  EnumeratedType             = (Mon, Tue, Wed, Thu, Fri, Sat, Sun);

  { set type }
  CharSetType                = set of Char;

  { object type }
  ObjectType                 = object
                                 constructor Init;
                                 procedure Method;
                                 destructor Done
                               end;

  { pointer type to another type identifier }
  PArrayType                 = ^ArrayType;

  { an alias name for another type identifier }
  IntegerType                = Integer;

  { an integer which is initialized by 123 }
  InitializedInt             = Integer value 123;

  { a schema with discriminants x and y of type Integer }
  SchemaType (x, y: Integer) = array [x .. y] of Integer;

{ Dummy methods of the object type }
constructor ObjectType.Init;
begin
end;

procedure ObjectType.Method;
begin
end;

destructor ObjectType.Done;
begin
end;

begin
end.
