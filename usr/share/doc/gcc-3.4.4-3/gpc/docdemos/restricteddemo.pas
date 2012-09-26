{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program RestrictedDemo;

type
  UnrestrictedRecord = record
    a: Integer;
  end;
  RestrictedRecord = restricted UnrestrictedRecord;

var
  r1: UnrestrictedRecord;
  r2: RestrictedRecord;
  i: restricted Integer;
  k: Integer;

function AccessRestricted (p: UnrestrictedRecord): RestrictedRecord;
var URes: UnrestrictedRecord;
begin
  { The parameter is treated as unrestricted, even though the actual
    parameter may be restricted }
  URes.a := p.a;
  { It is allowed to assign a function result }
  AccessRestricted := URes;
end;

begin
  r1.a := 354;

  { Assigning a restricted function result to a restricted variable }
  { @@ Verify if this should really be allowed????? }
  r2 := AccessRestricted (r1);

  { Passing a restricted value to unrestricted formal parameter is ok }
  r2 := AccessRestricted (r2);

  {$ifdef BUG}
  { *** The following statements are not allowed *** }
  k := r2.a;      { field access (reading) }
  r2.a := 100;    { field access (writing) }
  r1 := r2;       { assignment source is restricted }
  r2 := r1;       { assignment target is restricted }
  r1 := AccessRestricted (r2); { assigning a restricted function
                                 result to an unrestricted object }
  i  := 16#ffff;  { assignment target is restricted }
  k  := i + 2;    { arithmetic with restricted value }
  {$endif}
end.
