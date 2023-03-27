//
// Created by Saket Upadhyay on 2/20/23.
//

#include "iostream"

class Calculator{
public:
    int8_t add(int8_t a, int8_t b);
    int8_t sub(int8_t a, int8_t b);
    int8_t mul(int8_t a, int8_t b);
};

int8_t Calculator::add(int8_t a, int8_t b) {
    return a+b;
}

int8_t Calculator::sub(int8_t a, int8_t b) {
    return a-b;
}

int8_t Calculator::mul(int8_t a, int8_t b) {

    if (b > 1) {
        for (int i = 1; i < b; ++i) {
            a += a;
        }
    }
    if (b == 0) return (int8_t)0;

    return a;
}


int main(int argc, char** argv)
{
    if (argc != 3)
    {
        std::cerr<<"Error, only two arguments please."<<std::endl;
        exit(-1);
    }

    Calculator *calculator;
    calculator=new Calculator();

    std::cout<<"Addition : "<<(int)(calculator->add(atoi(argv[1]),atoi(argv[2])))<<std::endl;
    std::cout<<"Sub : "<<(int) calculator->sub(atoi(argv[1]),atoi(argv[2]))<<std::endl;
    std::cout<<"Mul : "<<(int) calculator->mul(atoi(argv[1]),atoi(argv[2]))<<std::endl;

    return 0;
}