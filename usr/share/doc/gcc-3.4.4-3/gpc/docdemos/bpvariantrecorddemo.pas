{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program BPVariantRecordDemo;

type
  PersonRec = record
    Age: Integer;
  case EyeColor: (Red, Green, Blue, Brown) of
    Red, Green : (WearsGlasses: Boolean);
    Blue, Brown: (LengthOfLashes: Integer);
  end;

begin
end.
