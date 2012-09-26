{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program CaseOtherwiseDemo;
var x: Integer;
begin
  ReadLn (x);
  case x of
    1: WriteLn ('one');
    2: WriteLn ('two');
    otherwise
       WriteLn ('many')
  end
end.
