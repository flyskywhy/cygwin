{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program IncludeDemo;

var
  Ch: Char;
  MyCharSet: set of Char;

begin
  MyCharSet := ['P', 'N', 'L'];
  Include (MyCharSet , 'A')  { A, L, N, P }
end.
