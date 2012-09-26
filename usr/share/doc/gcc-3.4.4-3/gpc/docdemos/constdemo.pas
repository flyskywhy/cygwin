{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ConstDemo;

type
  Rec = record
    x: Integer;
    y: Integer;
  end;

const
  a = 5;
  constr: Rec = (10, 12);

procedure doit (const r: Rec; const s: String);
begin
  WriteLn (r.x);
  WriteLn (r.y);
  WriteLn (s);
end;

var
  variabler: Rec;

begin
  variabler.x := 16;
  variabler.y := 7;
  doit (variabler, 'Should be 16 and 7');
  doit (constr, 'Should be 10 and 12');
end.
