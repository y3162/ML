#include "type.hpp"
using namespace Type;

/*
Shape shape;
size_t stride;
data_t *data;
*/

Tensor& Tensor::operator=(data_t x)
{
    if (shape.get_dim() != 0) {
        fprintf(stderr, "Tensor::operator= : scalar cannot assign to Tensor whose size is %s.\n", shape.to_string().c_str());
        exit(1);
    }

    data[0] = x;

    return *this;
}

Tensor& Tensor::operator=(const Tensor &tensor)
{
    if (this == &tensor) {
        return *this;
    }

    size_t N = tensor.shape[0] * tensor.stride;
    data = (data_t*)Memory::Pool::realloc(data, N * sizeof(data_t));
    if (!data) {
        perror("Tensor");
        exit(1);
    }

    shape = tensor.shape;
    //calloc_data();

    for (int i=0; i<N; ++i) {
        data[i] = tensor.data[i];
    }

    return *this;
}

Tensor& Tensor::operator[](size_t index)
{   
    size_t D = shape.get_dim();

    if (D == 0) {
        fprintf(stderr, "Tensor::operator[] : This Tensor has only one element.\n");
        exit(1);
    }

    Shape s = Shape(D-1);
    for (int i=0; i<D-1; ++i) {
        s[i] = shape[i+1];
    }

    return * new Tensor(s, stride/shape[0], data + (index*stride));
}

const Tensor& Tensor::operator[](size_t index) const
{
    size_t D = shape.get_dim();

    if (D == 0) {
        fprintf(stderr, "Tensor::operator[] : This Tensor has only one element.\n");
        exit(1);
    }

    Shape s = Shape(D-1);
    for (int i=0; i<D-1; ++i) {
        s[i] = shape[i+1];
    }

    Tensor *ret = new Tensor(s);
    for (int i=0; i<stride; ++i) {
        ret->data[i] = data[i];
    }

    return *ret;
}
