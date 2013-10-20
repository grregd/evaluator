#pragma once

#include <tr1/tuple>
#include <gtest/gtest.h>
#include <string>

class TestEvalExpression: public testing::TestWithParam< std::tr1::tuple< const char *, const char * > >
{

};
