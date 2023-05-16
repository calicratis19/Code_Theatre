#include "Value.h"

int main()
{
    // Value a = Value(2.0);
    // a.Print();
    // Value b = Value(-3.0);
    // Value c = Value(10.0);
    // (a*b+c).Print();
    // (a*b+c).PrintChildren();
    // (a*b+c).PrintOp();

    Value x1(2.0,"x1");
    Value x2(0.0,"x2");

    Value w1(-3.0,"w1");
    Value w2(1.0,"W2");

    Value b(6.883483284,"b");

    Value xw1 = x1*w1;xw1.label = "xw1";
    Value xw2 = x2*w2;xw2.label = "xw2";

    Value n = xw1+xw2 + b; n.label = "n";
    Value o  = n.tanh(); o.label = "o";
    cout<<o.data<<endl;
    cout<<"1-tanh"<<1-(o.data*o.data)<<endl;

    return 0;
}