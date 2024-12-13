/*
*PassengerQueue.cpp
*Tom Zhou
*9/30/24
*PassengerQueue implementation
*/

#include "PassengerQueue.h"
#include "Passenger.h"

#include <iostream>
#include <sstream>
#include <string>
#include <list>
using namespace std;
/*
 * name:     front
 * purpose:   returns first passenger
 * arguments: none
 * returns:   first passenger
 * effects:    returns first passenger
 */
Passenger PassengerQueue::front()
{
    return passengerQueue.front();
}

/*
 * name:     dequeue
 * purpose:   deletes first passenger
 * arguments: none
 * returns:   none
 * effects:    deletes first passenger
 */
void PassengerQueue::dequeue()
{
    if (passengerQueue.size() != 0)
    {
        passengerQueue.pop_front();
    }
    if (passengerQueue.size() == 0)
    {
        return;
    }
}

/*
 * name:     enqueue
 * purpose:   add a passenger to the back of the queue
 * arguments: a passenger address
 * returns:   none
 * effects:    add a passenger to the back of the queue
 */
void PassengerQueue::enqueue(const Passenger &passenger)
{
    passengerQueue.push_back(passenger);
}

/*
 * name:     Size
 * purpose:   returns the size of passengerQueue
 * arguments: none
 * returns:   the size in int format.
 * effects:    returns the size of passengerQueue
 */
int PassengerQueue::size()
{
    return passengerQueue.size();
}

/*
 * name:     print
 * purpose:   print the whole passengerQueues's passenger info
 * arguments: the ouput address
 * returns:   none
 * effects:   print the whole passengerQueues's passenger info
 */
void PassengerQueue::print(std::ostream &output)
{
    list<Passenger>::iterator it = passengerQueue.begin();
    for (; it != passengerQueue.end(); it++)
    {
        it->print(output);
    }
    return;
}
