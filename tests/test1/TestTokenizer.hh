#pragma once

#include <gtest/gtest.h>
#include <tuple>
#include <string>

class TestTokenizer: public testing::TestWithParam< std::tuple<std::string, std::string> >
{

};
