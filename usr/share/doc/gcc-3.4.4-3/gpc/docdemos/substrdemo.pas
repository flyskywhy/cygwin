{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program SubStrDemo;
var
  S: String (42);
begin
  S := 'Hello';
  WriteLn (SubStr (S, 2, 3));   { yields `ell' }
  WriteLn (SubStr (S, 3));      { yields `llo' }
  WriteLn (SubStr (S, 4, 7));   { yields a runtime error }
  WriteLn (SubStr (S, 42));     { yields a runtime error }
end.
