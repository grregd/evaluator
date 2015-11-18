#pragma once

#include <gtest/gtest.h>
#include <tuple>
#include <string>
#include <vector>

typedef std::vector< std::string > TokensList;

class TestTokenizer: public testing::TestWithParam< std::tuple<std::string, TokensList > >
{

};
