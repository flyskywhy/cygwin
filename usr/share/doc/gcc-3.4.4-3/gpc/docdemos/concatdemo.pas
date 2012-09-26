{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ConcatDemo (Input, Output);

var
  Ch  : Char;
  Str : String (100);
  Str2: String (50);
  FStr: packed array [1 .. 20] of Char;

begin
   Ch := '$';
   FStr := 'demo';  { padded with blanks }
   Write ('Give me some chars to play with: ');
   ReadLn (Str);
   Str := '^' + 'prefix:' + Str + ':suffix:' + FStr + Ch;
   WriteLn (Concat ('Le', 'ng', 'th'), ' = ', Length (Str));
   WriteLn (Str)
end.
