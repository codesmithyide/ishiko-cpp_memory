// SPDX-FileCopyrightText: 2005-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "BigEndianWordTests.hpp"
#include "Ishiko/Memory/BigEndianWord.hpp"

using namespace Ishiko;

BigEndianWordTests::BigEndianWordTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "BigEndianWord tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
}

void BigEndianWordTests::ConstructorTest1(Test& test)
{
    BigEndianWord word(0);

    ISHIKO_TEST_FAIL_IF_NEQ(word[0], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(word[1], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(word.toUint16(), 0);
    ISHIKO_TEST_PASS();
}

void BigEndianWordTests::ConstructorTest2(Test& test)
{
    BigEndianWord word(255);

    ISHIKO_TEST_FAIL_IF_NEQ(word[0], 0);
    ISHIKO_TEST_FAIL_IF_NEQ(word[1], 255);
    ISHIKO_TEST_FAIL_IF_NEQ(word.toUint16(), 255);
    ISHIKO_TEST_PASS();
}
