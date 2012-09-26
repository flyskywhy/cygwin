{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BPAbsoluteDemo;

type
  TString = String (80);
  TTypeChoice = (t_Integer, t_Char, t_String);

{ @@ WARNING: BAD STYLE! }
procedure ReadVar (var x: Void; TypeChoice: TTypeChoice);
var
  xInt: Integer absolute x;
  xChar: Char absolute x;
  xStr: TString absolute x;
begin
  case TypeChoice of
    t_Integer: ReadLn (xInt);
    t_Char   : ReadLn (xChar);
    t_String : ReadLn (xStr);
  end
end;

var
  i: Integer;
  c: Char;
  s: TString;

begin
  ReadVar (i, t_Integer);
  ReadVar (c, t_Char);
  ReadVar (s, t_String);
  WriteLn (i, ' ', c, ' ', s)
end.
