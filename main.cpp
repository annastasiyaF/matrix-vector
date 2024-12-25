#include <iostream>
#include "matrix.h"

int main() {
    Vector<int> vec1 = Vector<int>(3);
    std::cout<<"Enter elements vec1"<<std::endl;
    std::cin>>vec1;

    Vector<int> vec2 = Vector<int>(3);
    std::cout<<"Enter elements vec2"<<std::endl;
    std::cin>>vec2;

    Vector<int> res1 = vec1 + vec2;
    std::cout<<"Sum of vec1 and vec2"<<std::endl;
    std::cout<<res1<<std::endl;

    Vector<int> res2 = vec1 - vec2;
    std::cout<<"Dif of vec1 and vec2"<<std::endl;
    std::cout<<res2<<std::endl;

    Matrix<int> matr1 = Matrix<int>(3);
    std::cout<<"Enter elements matr1"<<std::endl;
    std::cin>>matr1;

    Matrix<int> matr2 = Matrix<int>(3);
    std::cout<<"Enter elements matr2"<<std::endl;
    std::cin>>matr2;

    Matrix<int> res3 = matr1 + matr2;
    std::cout<<"Sum of matr1 and matr2"<<std::endl;
    std::cout<<res3<<std::endl;

    Matrix<int> res4 = matr2 - matr1;
    std::cout<<"Dif of matr2 and matr1"<<std::endl;
    std::cout<<res4<<std::endl;

    Matrix<int> res5 = matr1 * matr2;
    std::cout<<"Mult of matr1 and matr2"<<std::endl;
    std::cout<<res5<<std::endl;

    return 0;
}