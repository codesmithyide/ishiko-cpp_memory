/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/memory/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_MEMORY_FIXEDBUFFER_HPP_
#define _ISHIKO_CPP_MEMORY_FIXEDBUFFER_HPP_

#include "Byte.hpp"

namespace Ishiko
{

// TODO: same as Buffer but fixed size and on the stack
template<size_t N>
class FixedBuffer
{
public:
    void zero() noexcept;

    Byte* data() noexcept;
    size_t capacity() noexcept;

private:
    Byte m_data[N];
};

template<size_t N>
void FixedBuffer<N>::zero() noexcept
{
    memset(m_data, 0, N);
}

template<size_t N>
Byte* FixedBuffer<N>::data() noexcept
{
    return m_data;
}

template<size_t N>
size_t FixedBuffer<N>::capacity() noexcept
{
    return N;
}

}

#endif