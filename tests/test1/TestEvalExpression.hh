#pragma once

#include <tuple>
#include <gtest/gtest.h>
#include <string>

class TestEvalExpression: public testing::TestWithParam< std::tuple< const char *, const char * > >
{

};
