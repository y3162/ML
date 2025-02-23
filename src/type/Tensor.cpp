#ifdef DEBUG_TENSOR
#define LOG_TENSOR(msg) std::cerr << "[DEBUG] " << msg << std::endl
#else
#define LOG_TENSOR(msg)
#endif

#include "type.hpp"

using namespace Type;

/*
Shape shape;
size_t stride;
data_t *data;
*/

Tensor::Tensor(const Shape& shape, size_t stride, data_t *data)
: shape(shape), stride(stride), data(data)
{}

Tensor::Tensor()
: shape(Shape(1, 0)), stride(1), data(nullptr)
{
    LOG_TENSOR("Tensor()");
}

Tensor::Tensor(const Shape& shape)
: shape(shape)
{   
    LOG_TENSOR("Tensor(const Shape&)");

    size_t D = shape.get_dim();
    stride = 1;
    for (size_t i=1; i<D; ++i) {
        stride *= shape[i];
    }

    calloc_data();
}

Tensor::Tensor(const Tensor& tensor)
: shape(tensor.shape)
{
    LOG_TENSOR("Tensor(const Tensor&)");

    size_t D = shape.get_dim();
    stride = 1;
    for (size_t i=1; i<D; ++i) {
        stride *= shape[i];
    }

    calloc_data();

    size_t N = shape[0] * stride;
    for (int i=0; i<N; ++i) {
        data[i] = tensor.data[i];
    }
}

Tensor::Tensor(Tensor&& tensor) noexcept
: shape(std::exchange(tensor.shape, Shape(1, 0))), data(std::exchange(tensor.data, nullptr))
{
    LOG_TENSOR("Tensor(Tensor&&)");
}

Tensor::~Tensor()
{
    LOG_TENSOR("~Tensor()");

    shape = Shape(1, 0);

    if (!data) {
        Memory::Pool::free(data);
        data = nullptr;
    }
}

void Tensor::calloc_data()
{
    data = (data_t*)Memory::Pool::calloc(shape[0] * stride, sizeof(data_t));
    if (!data) {
        perror("Tensor");
        exit(1);
    }
}

void Tensor::to_string(std::string& str, size_t dim, size_t stride, data_t* data) const
{   
    size_t D = shape.get_dim();
    std::string space = "";
    for (int i=0; i<=dim; ++i) {
        space += " ";
    }

    size_t C = shape[dim];
    if (dim == D-1) {
        str += "[";
        for (int i=0; i<C; ++i) {
            str += std::to_string(data[i]);
            if (i < C-1) {
                str += ", ";
            }
        }
        str += "]";
    } else {
        str += "[";
        for (int i=0; i<C; ++i) {
            to_string(str, dim+1, stride/shape[dim], data + (stride*i));
            if (i < C-1) {
                str += ",\n";
                str += space;
            }
        }
        str += "]";
    }
}

std::string Tensor::to_string() const
{   
    std::string str = "";

    to_string(str, 0, stride, data);

    return str;
}
