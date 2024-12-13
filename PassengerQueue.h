/*
*PassengerQueue.h
*Tom Zhou
*9/30/24
*PassengerQueue header
*/
#ifndef __PASSENGERQUEUE_H__
#define __PASSENGERQUEUE_H__
#include "Passenger.h"
#include <iostream>
#include <string>
#include <sstream>
#include <list>
class PassengerQueue 
{

public:

    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

private:
    std::list<Passenger> passengerQueue; 
    std::string printhelp(Passenger passengerQueue) const; 
    
};

#endif