#include "StringReverser.h"
#include "BasicString.h"


template<typename Problem, typename Solution>
Solution *StringReverser<Problem, Solution>::solve(Problem *problem) {
    return (string(problem->rbegin(), problem->rend()));
}
