{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SetTypeDemo;

type
  BasePtr = ^BaseObj;

  BaseObj = object
    constructor Load;
  end;

  ChildObj = object (BaseObj)
    constructor Load;
  end;

constructor BaseObj.Load;
begin
end;

constructor ChildObj.Load;
begin
end;

{$X+}

{ This is somewhat fragmentary code. }
function GetObject (var InputFile: File) = Result: BasePtr;
const
  VMTTable: array [1 .. 2] of PObjectType =
    (TypeOf (BaseObj), TypeOf (ChildObj));
var
  Size: Cardinal;
  TypeID: Integer;
  VMT: PObjectType;
begin
  { Read the size of the object from some file and store it in `Size'. }
  BlockRead (InputFile, Size, SizeOf (Size));

  { Allocate memory for the object. }
  GetMem (Result, Size);

  { Read some ID from some file. }
  BlockRead (InputFile, TypeID, SizeOf (TypeID));

  { Look up the `VMT' from some table. }
  { Explicit range checking wouldn't be a bad idea here ... }
  { Without it, a wrong value just leads to a runtime error. }
  VMT := VMTTable[TypeID];

  SetType (Result^, VMT);

  { Now the object is ready, and the constructor can be called. }
  { Look up the correct constructor from some table and call it. }
end;

begin
end.
