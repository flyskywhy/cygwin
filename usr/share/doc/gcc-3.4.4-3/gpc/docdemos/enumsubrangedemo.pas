{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program EnumSubrangeDemo;
type
  { This is an enumerated type. }
  Days = (Mon, Tue, Wed, Thu, Fri, Sat, Sun);

  { This is a subrange of `Days'. }
  Working = Mon .. Fri;

begin
end.
