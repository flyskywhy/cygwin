{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program MacroDemo;

const Foo = 'Borland Pascal';

{$define Foo 'Default'}

begin
  WriteLn (Foo)
end.
