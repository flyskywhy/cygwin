{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program IfDemo;
var
  Foo, Bar: Boolean;
begin
  Foo := True;
  Bar := False;
  if ((1 = 1) or (2 = 3)) and (Foo = not Bar) then
    begin
      { This is executed if either Foo is true but not Bar or vice versa }
      WriteLn ('Either Foo or Bar is true.');
      if Bar then
        WriteLn ('You will see this text if Bar is true.')
    end
  else  { This whole `else' branch is not executed }
    if 1 = 1 then
      if True = False then
        WriteLn ('This text is never written on screen.')
      else  { Note: This ``else'' belongs to ``if True = False'' }
        WriteLn ('This text is never written on screen as well.')
    else  { Note: This ``else'' belongs to ``if 1 = 1'' }
      WriteLn ('Nor is this.')
end.
