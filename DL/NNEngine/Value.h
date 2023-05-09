#include<iostream>
#include<set>
using namespace std;
class Value
{
    public:
        Value(double data, set<double> children={}, char op=' ');        
        void Print();
        void PrintChildren();
        void PrintOp();
        Value operator+(Value const& other)
        {
            Value ret(this->data+other.data,{this->data,other.data},'+');
            return ret;
        }
        Value operator*(Value const& other)
        {
            Value ret(this->data*other.data,{this->data,other.data},'*');
            return ret;
        }
    char op;
    double data;
    double grad;
    set<double> children;
};