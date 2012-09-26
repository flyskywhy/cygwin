{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program TimeStampDemo;

var
  t: TimeStamp;

begin
  GetTimeStamp (t);
  WriteLn ('DateValid: ', t.DateValid);
  WriteLn ('TimeValid: ', t.TimeValid);
  WriteLn ('Year: ', t.Year);
  WriteLn ('Month: ', t.Month);
  WriteLn ('Day: ', t.Day);
  WriteLn ('DayOfWeek (0 .. 6, 0=Sunday): ', t.DayOfWeek);
  WriteLn ('Hour (0 .. 23): ', t.Hour);
  WriteLn ('Minute (0 .. 59): ', t.Minute);
  WriteLn ('Second (0 .. 61): ', t.Second);
  WriteLn ('MicroSecond (0 .. 999999): ', t.MicroSecond);
  WriteLn ('TimeZone (in seconds east of UTC): ', t.TimeZone);
  WriteLn ('DST: ', t.DST);
  WriteLn ('TZName1: ', t.TZName1);
  WriteLn ('TZName2: ', t.TZName2);
  WriteLn;
  WriteLn ('Date is: ', Date (t));
  WriteLn ('Time is: ', Time (t));
end.
