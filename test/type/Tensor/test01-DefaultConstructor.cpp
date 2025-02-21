#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Tensor  T1;
    Type::Tensor  T2 = Type::Tensor();
    Type::Tensor *T3 = new Type::Tensor();

    std::cout << T1.to_string() << std::endl;
    std::cout << T2.to_string() << std::endl;
    std::cout << T3->to_string() << std::endl;

    return 0;
}
