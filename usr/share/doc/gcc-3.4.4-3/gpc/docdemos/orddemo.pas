{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program OrdDemo;
var
  Ch: Char;
  Day: (Monday, Tuesday, Wednesday, Thursday, Friday);
begin
  Ch := 'A';
  WriteLn (Ord (Ch));  { 65 }
  Day := Thursday;
  WriteLn (Ord (Day));  { 3 }
end.
