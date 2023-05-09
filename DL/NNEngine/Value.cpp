#include"Value.h"

Value::Value(double data, set<double>children, char op)
{
    this->data = data;
    this->children = children;
    this->op= op;
    grad = 0;
}
void Value::Print()
{
    cout<<"data: "<<data<<endl;
}

void Value::PrintChildren()
{
    for(auto i:children)
        cout<<i<<" ";
    cout<<endl;
}

void Value::PrintOp()
{
    cout<<op<<endl;
}