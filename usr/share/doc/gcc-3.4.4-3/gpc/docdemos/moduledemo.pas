{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program ModuleDemo (Output);

import DemoModule;

begin
  SetFoo (999);
  WriteLn (GetFoo);
end.
