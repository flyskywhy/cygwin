{ GPC demo program. For copying conditions see the file `COPYING.DEMO'. }

program TypeVarInitDemo;
type
  Int10   = Integer value 10;
  FooType = Real;
  MyType  = Char value Pred ('A');
  EType   = (a, b, c, d, e, f, g) value d;

const
  Answer = 42;

var
  ii : Int10;                    { Value of ii set to 10 }
  ch : MyType  value Pred ('z');
  aa : Integer value Answer + 10;
  foo: FooType value Sqr (Answer);
  e1 : EType;                    { value set to d }
  e2 : EType value g;            { value set to g }
begin
end.
