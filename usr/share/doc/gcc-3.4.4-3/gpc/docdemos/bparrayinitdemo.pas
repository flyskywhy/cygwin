{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BPArrayInitDemo;

const
  MyStringsCount = 5;

type
  Ident = String [20];

const
  MyStrings: array [1 .. MyStringsCount] of Ident =
    ('export', 'implementation', 'import',
     'interface', 'module');

begin
end.
