{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SetLengthDemo;

var
  S: String (26);

begin
  S := 'Hello, world!';
  SetLength (S, Length ('Hello'));
  WriteLn (S);                                           { 'Hello' }

  SetLength (S, 26);
  WriteLn (S);                     { 'Hello, world!(%$xy"!#&~+(/]' }
                            { undefined characters ^^^^^^^^^^^^^^  }

  { SetLength (S, 42);  GPC detects this overflow at compile time. }
end.
