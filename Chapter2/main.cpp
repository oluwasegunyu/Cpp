//
// Created by yxy on 18-4-11.
//
#include <iostream>

int main(){
    double base;
    int exponent;
    double result=1;

    std::cin >> base >> exponent;
    for(int i=1; i<=exponent;++i){
        result *= base;
    }
    std::cout<< "result: " << result <<std::endl;
    return 0;
}
