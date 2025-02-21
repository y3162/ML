#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Tensor  T1 = Type::Tensor(Type::Shape(2, 2, 2));
    Type::Tensor  T2 = std::move(T1);
    Type::Tensor *T3 = new Type::Tensor(Type::Shape(2, 4, 4));
    Type::Tensor  T4 = std::move(*T3);
    
    T1 = Type::Tensor(Type::Shape(2, 1, 1));
    T3 = new Type::Tensor(Type::Shape(2, 3, 3));

    std::cout << T1.to_string() << std::endl;
    std::cout << T2.to_string() << std::endl;
    std::cout << T3->to_string() << std::endl;
    std::cout << T4.to_string() << std::endl;

    return 0;
}
