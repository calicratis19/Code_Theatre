#include<iostream>
#include<math.h>
#include<set>
using namespace std;
class Value
{
    public:
        Value(double data, set<double> children={}, string op="", string label="");    
        Value(double data, string label="");      
    
        void Print();
        void PrintChildren();
        void PrintOp();
        Value operator+(Value const& other)
        {
            Value ret(this->data+other.data,{this->data,other.data},"+");
            return ret;
        }
        Value operator*(Value const& other)
        {
            Value ret(this->data*other.data,{this->data,other.data},"*");
            return ret;
        }
        Value tanh()
        {
            double _data = (exp(2*data)-1)/(exp(2*data)+1);
            Value ret(_data,{},"tanh");
            return ret;
        }
    string op;
    string label;
    double data;
    double grad;
    set<double> children;
};