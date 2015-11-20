
#include "operands.hh"
#include "evaluators.hh"

using namespace std;

namespace Operands
{


void Bool::accept( Evaluators::Visitor & aEvaluator )
{
    aEvaluator.visit( shared_from_this()  );
}

void Numeric::accept( Evaluators::Visitor & aEvaluator )
{
    aEvaluator.visit( shared_from_this()  );
}

void Text::accept( Evaluators::Visitor & aEvaluator )
{
    aEvaluator.visit( shared_from_this() );
}


} // namespace Operands
