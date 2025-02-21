#include "../../../src/type/type.hpp"
#include <iostream>

int main(void)
{
    Type::Tensor  T1 = Type::Tensor(Type::Shape(2, 3, 3));
    Type::Tensor *T2 = new Type::Tensor(Type::Shape(2, 3, 3));
    Type::Tensor *T3 = new Type::Tensor(Type::Shape(2, 3, 3));

    if (true) {
        Type::Tensor  T4 = Type::Tensor(Type::Shape(2, 3, 3));
        Type::Tensor *T5 = new Type::Tensor(Type::Shape(2, 3, 3));
        Type::Tensor *T6 = new Type::Tensor(Type::Shape(2, 3, 3));

        delete T6;
    }

    delete T3;

    std::cout << T1.to_string() << std::endl;
    std::cout << T2->to_string() << std::endl;
    //std::cout << M3->to_string() << std::endl;

    return 0;
}
