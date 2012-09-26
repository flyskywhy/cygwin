{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program EPVariantRecordDemo;

type
  EyeColorType = (Red, Green, Blue, Brown);

  PersonRec = record
    Age: Integer;
  case EyeColor: EyeColorType of
    Red, Green : (WearsGlasses: Boolean);
    Blue, Brown: (LengthOfLashes: Integer);
  end;

begin
end.
