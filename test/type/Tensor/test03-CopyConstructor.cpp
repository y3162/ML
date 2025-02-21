#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Tensor  T1 = Type::Tensor(Type::Shape(3, 4, 2, 2));
    Type::Tensor  T2 = Type::Tensor(T1);
    Type::Tensor  T3 = T2;
    Type::Tensor *T4 = new Type::Tensor(T3);

    T1 = Type::Tensor(Type::Shape(3, 1, 2, 2));
    T2 = Type::Tensor(Type::Shape(3, 2, 2, 2));
    T3 = Type::Tensor(Type::Shape(3, 3, 2, 2));

    std::cout << T1.to_string() << std::endl;
    std::cout << T2.to_string() << std::endl;
    std::cout << T3.to_string() << std::endl;
    std::cout << T4->to_string() << std::endl;

    return 0;
}
