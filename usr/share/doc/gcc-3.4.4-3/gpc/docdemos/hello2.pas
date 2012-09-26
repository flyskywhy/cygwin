{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program Hello2;

uses GPC, Intl;

var s: TString;

begin
  Discard (BindTextDomain ('hello2', '/usr/share/locale/'));
  Discard (TextDomain ('hello2'));
  WriteLn (GetText ('Hello, World!'));
  s := FormatString (GetText ('The answer of the questions is %s'), 42);
  WriteLn (s)
end.
