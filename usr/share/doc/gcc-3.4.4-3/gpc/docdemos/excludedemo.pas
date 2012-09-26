{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ExcludeDemo;

var
  Ch: Char;
  MyCharSet: set of Char;

begin
  MyCharSet := ['P', 'N', 'L'];
  Exclude (MyCharSet , 'N')  { L, P }
end.
