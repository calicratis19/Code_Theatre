#include "Value.h"

int main()
{
    Value a = Value(2.0);
    a.Print();
    Value b = Value(-3.0);
    Value c = Value(10.0);
    (a*b+c).Print();
    (a*b+c).PrintChildren();
    (a*b+c).PrintOp();
    return 0;
}