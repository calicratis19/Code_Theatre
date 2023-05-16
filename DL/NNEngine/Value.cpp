#include"Value.h"

Value::Value(double data, set<double>children, string op, string label)
{
    this->data = data;
    this->label = label;
    this->children = children;
    this->op= op;
    grad = 0;
}
Value::Value(double data, string label)
{
    this->data = data;
    this->label = label;
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