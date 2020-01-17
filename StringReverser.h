#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include "Solver.h"
#include "string"
#include "BasicString.h"
template <typename Problem, typename Solution>
class StringReverser : public Solver<Problem,Solution>{

public:

//    template<typename BasicString, typename BasicString>
    Solver<BasicString, BasicString> * getClone() {
        return new StringReverser<Problem,Solution>();

    }
    Solution* solve (Problem* problem){
        string reverse;
        //iterating over the string , start from the end.
        for(int i=problem->toString().size()-1;i>=0;i--){
            reverse+=problem->toString()[i];
        }
        return new BasicString(reverse); //reversed string.
    }
};


#endif //EX4_STRINGREVERSER_H
