{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program GetMemDemo;
var
  Buffer: Pointer;
  Size: Cardinal;
begin
  Size := Random (10000);  { the size can be determined at run time }
  GetMem (Buffer, Size);
  { Do something with Buffer }
  FreeMem (Buffer)  { or: FreeMem (Buffer, Size) }
end.
