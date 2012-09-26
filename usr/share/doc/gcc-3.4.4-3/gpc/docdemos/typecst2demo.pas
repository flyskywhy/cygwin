{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program TypeCst2Demo;

type
  CharPtr = ^Char;
  CharArray = array [0 .. 99] of Char;
  CharArrayPtr = ^CharArray;

var
  Foo1, Foo2: CharPtr;
  Bar: CharArrayPtr;

{$X+} { We need extended syntax in order to use ``Succ'' on a pointer }

begin
  Foo1 := CharPtr (Bar);
  Foo2 := CharPtr (Succ (Bar))
end.
