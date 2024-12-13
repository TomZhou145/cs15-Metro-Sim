/*
*unit_test.h
*Tom Zhou
*9/30/24
*unit testing units
*/
#include "MetroSim.h"
#include "Passenger.h"
#include "PassengerQueue.h"

#include <sstream>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

//checks if passenger id returns proper information
void PassengerBasicCheck() {
    Passenger test(0,1,2); 
    assert(test.getId() == 0); 
    assert(test.getStartingStation() == 1); 
    assert(test.getEndingStation() == 2); 
}
//test if inserting Passenger works
void PassengerQueueBasicTest() {
    Passenger test(69,1,2); 
    PassengerQueue empty; 
    empty.enqueue(test); 
    assert(empty.size() == 1); 
}

//test all PassengerQueue functionalty through 
//a series of operations
void PassengerQueueGeneralTest() {
    Passenger test(69,1,2); 
    Passenger test2(12,1,2);
    Passenger test3(43,1,2);
    Passenger test4(2,1,2);
    PassengerQueue empty; 
    empty.enqueue(test); 
    assert(empty.size() == 1); 
    empty.enqueue(test2); 
    empty.enqueue(test3); 
    empty.enqueue(test4); 
    assert(empty.size() == 4); 
    assert(empty.front().getId() == 69); 
    empty.dequeue();
    assert(empty.size() == 3);
    assert(empty.front().getId() == 12); 
    empty.dequeue();
    empty.dequeue();
    empty.dequeue();
    assert(empty.size() == 0);
}

//see if the print opertion works. 
void PassengerPrintTestlTest() {
    Passenger test(69,1,2); 
    Passenger test2(12,1,2);
    Passenger test3(43,1,2);
    Passenger test4(2,1,2);
    PassengerQueue empty; 
    PassengerQueue empty2;
    empty.enqueue(test); 
    empty.enqueue(test2); 
    empty.enqueue(test3); 
    empty.enqueue(test4); 
    empty.print(std::cerr); 
    empty2.print(std::cerr); 
}




