{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ModDemo2 (Output);

import Catch22 in 'demomod2.pas';

begin
  SetFoo (999);
  WriteLn (GetFoo);
end.
