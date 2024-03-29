
#ifndef EX4_STATE_H
#define EX4_STATE_H

#include <thread_db.h>

/*
 * State class
 * defines a state with a cost, parent(whereWeCameFrom) , path cost , which is
 * the cost of whole ancestors.the State get template class , which is a class that defines an index .
 */

template<typename T>
class State {
private:
    T state;
    double cost;
    double costOfPath;
    double fValue;
    State<T> *whereWeCameFrom;
public:
    State(T givenState) {
        this->state = givenState;
        this->whereWeCameFrom = NULL;

    }

    bool operator==(const State<T> &givenState) { // finding out if 2 states are equal!.
        return givenState.getState() == this->state;
    }

    bool operator!=(const State<T> &givenState) { // finding out if 2 states are not equal!.
        return !(*this == givenState);;
    }

    //setters
    void setTheFcost(double f) {
        this->fValue = f;
    }

    void setTheCost(double givenCost) {
        this->cost = givenCost;
    }

    void setThePathCost(double pathCost) {
        this->costOfPath = pathCost;
    }

    void setWhereWeCameFrom(State<T> *father) {
        this->whereWeCameFrom = father;
    }

    // getters

    double getTheFcost() const {
        return this->fValue;
    }

    double getCost() const {
        return this->cost;
    }

    double getPathCost() const {
        return this->costOfPath;
    }

    State<T> *getWhereWeCameFrom() {
        return this->whereWeCameFrom;
    }

    T getState() const {
        return this->state;
    }

    State<T> *getClone() {
        return new State<T>(new T(this->state));
    }

};


#endif //EX4_STATE_H
