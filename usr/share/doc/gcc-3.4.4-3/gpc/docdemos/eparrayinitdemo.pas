{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program EPArrayInitDemo;

const
  MyStringsCount = 5;

type
  Ident = String (20);

var
  MyStrings: array [1 .. MyStringsCount] of Ident value
    [1: 'export'; 2: 'implementation'; 3: 'import';
     4: 'interface'; 5: 'module'];

begin
end.
