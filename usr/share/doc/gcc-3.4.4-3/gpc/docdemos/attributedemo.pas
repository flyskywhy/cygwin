{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program AttributeDemo;

{ Demo for `iocritical' attribute. }

{ Program will abort with a runtime error! }

{$I-}
procedure p; attribute (iocritical);
var t: Text;
begin
  Reset (t)  { Will not cause a runtime error here because I/O
               checking is off, but leave InOutRes set. }
end;
{$I+}

begin

  p;
  { Since `p' was declared `iocritical', and I/O checking is now on,
    InOutRes is checked immediately after the call to p, and a
    runtime error raised. }

  { So this statement is never reached. }
  InOutRes := 0;

  { Neither this one, which would be reached without the
    `iocritical' attribute. }
  WriteLn ('never gets here')

end.
