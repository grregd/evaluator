#pragma once

#include <memory>
#include <stack>

// fwd decl
namespace Evaluators
{
class Evaluator;
} // namespace Evaluators


class ExpressionToken
{
public:
    virtual ~ExpressionToken() {}

public:
    virtual void accept( Evaluators::Evaluator & ) = 0;
};

typedef std::shared_ptr< ExpressionToken > ExpressionTokenPtr;
typedef std::stack< ExpressionTokenPtr >        ExpressionTokensStack;

