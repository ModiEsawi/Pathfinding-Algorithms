
#ifndef EX4_FINALCLIENTHANDLER_H
#define EX4_FINALCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "vector"
#include "BasicString.h"
template<typename Problem, typename Solution>
class FinalClientHandler : public server_side::ClientHandler {
private:
    Solver<Problem, Solution> *problemSolver;
    CacheManager<Problem, Solution> *cacheManager;
public:

    //Constructor
    FinalClientHandler(Solver<Problem,Solution> *solver, CacheManager<Problem,Solution> *cm) : problemSolver(solver),
                                                                                               cacheManager(cm) {}

    //handle client requests
    void handleClient(Client client) override {
        vector<string> problems;
        string stringProblem;

        while (stringProblem != "end") {

            stringProblem = client.read(1024);
            if (stringProblem[stringProblem.size() - 1] == '\n') { //delete new line char if there was
                stringProblem = stringProblem.substr(0, stringProblem.size() - 1);
            }
            if (stringProblem[stringProblem.size() - 1] == '\r') {
                stringProblem = stringProblem.substr(0, stringProblem.size() - 1);
            }
            problems.push_back(stringProblem); //add the rows to the list
//            client.write(" ");
//            this->cacheManager.insertSolution(stringProblem, solutionToProblem);
//            client.write(solutionToProblem);
        }
        problems.pop_back();
        auto *problem = new Problem(problems); //build a problem from the list of the strings
//        if (this->cm->isSolved(problem)) { //solved before
//            Solution *sol = this->cm->getSolution(problem); //get the saved solution
//            string solutionString = sol->toString(); // build a string solution
//            delete sol;
//            delete problem;
//            client.write(solutionString); //write back to the client
//        }
//        else {                  // will be back after fixing cache manager!
        Solution *finalSolution = this->problemSolver->solve(problem); //solve
        string solutionString = finalSolution->toString(); //build a string solution

//        this->cacheManager->saveSolution(problem, sol); //save the solution
        delete finalSolution;
        delete problem;
        client.write(solutionString); //write back to the client
//        }

    }
};


#endif //EX4_FINALCLIENTHANDLER_H