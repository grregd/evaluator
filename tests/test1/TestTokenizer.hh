#pragma once

#include <tr1/tuple>
#include <gtest/gtest.h>
#include <string>

class TestTokenizer: public testing::TestWithParam< std::tr1::tuple<std::string, std::string> >
{

};
