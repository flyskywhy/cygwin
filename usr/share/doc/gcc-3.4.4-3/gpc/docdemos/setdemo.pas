{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SetDemo;

type
  TCharSet = set of Char;

var
  Ch: Char;
  MyCharSet: TCharSet;
begin
  MyCharSet := ['P','N','L'];
  if 'A' in MyCharSet then
    WriteLn ('Wrong: A in set MyCharSet')
  else
    WriteLn ('Right: A is not in set MyCharSet');
  Include (MyCharSet, 'A');  { A, L, N, P }
  Exclude (MyCharSet, 'N');  { A, L, P }
  MyCharSet := MyCharSet + ['B','C'];  { A, B, C, L, P }
  MyCharSet := MyCharSet - ['C','D'];  { A, B, L, P }
  WriteLn ('set MyCharSet contains:');
  for Ch in MyCharSet do
    WriteLn (Ch);
end.
