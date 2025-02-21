#pragma once

#include <iostream>
#include <stdarg.h>
#include <variant>

namespace Type
{
    using data_t = double;

    class Shape
    {
    private:
        size_t dim;
        size_t *elems;

        void calloc_elems();

    public:
        Shape();
        Shape(size_t, ...);
        Shape(const Shape&);
        Shape(Shape&&) noexcept;
        ~Shape();

        size_t get_dim() const;

        Shape& operator=(const Shape&);
        Shape& operator=(Shape&&) noexcept;
        size_t& operator[](size_t);
        const size_t& operator[](size_t) const;
        bool operator==(const Shape&) const;
        bool operator!=(const Shape&) const;

        std::string to_string() const;
    };

    class Tensor
    {
    private:
        Shape shape;
        size_t stride;
        data_t *data;

        Tensor(const Shape&, size_t, data_t*);

        void calloc_data();
        void to_string(std::string&, size_t, size_t, data_t*) const;

    public:
        Tensor();
        Tensor(const Shape&);
        Tensor(const Tensor&);
        Tensor(Tensor&&) noexcept;
        ~Tensor();

        Tensor& operator=(data_t);
        Tensor& operator=(const Tensor&);
        Tensor& operator[](size_t);
        const Tensor& operator[](size_t) const;

        std::string to_string() const;
    };
}
