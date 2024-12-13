/*
 * MetroSim.cpp
 * Tom Zhou
 * 9/30/2024
 * MetroSim implementation
 */

#include "MetroSim.h"
#include <sstream>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
using namespace std;

/*
 * name:     MetroSim constrructor
 * purpose:   consntructor
 * arguments: filename string
 * returns:  
 * effects:   constructor
 */
MetroSim::MetroSim(std::string filename)
{
    roundNum = 0; 
    MakeStationAndTrain(filename);
    PassengerIDCount = 1;
}

/*
 * name:    play
 * purpose:   initialize and controls a new round of MetroSim
 * arguments: the station filename and the command filename
 * returns:   none
 * effects:   plays MetroSim 
 */
void MetroSim::PLAY(std::string filename,std::istream& command)
{
    ofstream ofile(filename);
    if (ofile.fail())
        {
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
        }
    while (true)
    {
        printInterface();
        cout << "Command? ";
        string user_in;
        string user_in2;
        command >> user_in;
        if (user_in == "m")
        {
            command >> user_in2;
            if (user_in2 == "f")
            {
                cout << "Thanks for playing MetroSim. Have a nice day!\n";
                return;
            }
            else if (user_in2 == "m")
            {
                mm(ofile);
            }
        }
        else if (user_in == "p")
        {
            int int1;
            int int2;
            command >> int1;
            command >> int2;
            Passenger new_Passenger(PassengerIDCount, int1, int2);
            PassengerIDCount++;
            Station[int1].enqueue(new_Passenger);
        }
        else
        {
            printError(user_in);
        }
    }
}
/*
 * name:     MakeStationName
 * purpose:   creates an arraylist of names for all trainstation
 * arguments: filename
 * returns:   none
 * effects:    creates an arraylist of names for all trainstation
 */
void MetroSim::MakeStationAndTrain(std::string filename)
{
    StationSize = 1;
    string File = filename;
    ifstream infile(File);
    if (infile.fail())
    {
        cerr << "ERROR: Could not open file" << endl;
        exit(EXIT_FAILURE);
    }
    while (not infile.eof())
    {
        string station;
        while (getline(infile, station))
        {
            PassengerQueue temp;
            StationName.push_back(station);
            Station.push_back(temp);
            Train.push_back(temp);
            StationSize++;
        }
    }

    infile.close();
}
/*
 * name:     PrintInterface
 * purpose:   print the game interface
 * arguments: a number
 * returns:   none
 * effects:    print the game interface
 */
void MetroSim::printInterface()
{
    cout << "Passengers on the train: {";

    for (int i = 0; i < Train.size(); i++)
    {
        Train[i].print(cout);
    }
    cout << "}" << endl;

    for (int i = 0; i < Station.size(); i++)
    {
        string TrainStatus = "";
        if (roundNum == i)
        {
            TrainStatus = "TRAIN:";
        }
        else
        {
            TrainStatus = "      ";
        }
        cout << TrainStatus << " [" << i << "] " << StationName[i];
        cout << " {";
        Station[i].print(cout);
        cout << "}";
        cout << endl;
    }
}

/*
 * name:     PrintError
 * purpose:   print error message
 * arguments: none
 * returns:   none
 * effects:    print error message.
 */
void MetroSim::printError(string user)
{
    cout << "Command [" << user << "] not recognized.\n";
    cout << "        Use p x y with valid integer station IDs x and y.\n";
    cout << "        Use m m to move the train.\n";
    cout << "        Use m f to exit.\n";
    cout << "        Valid station IDs: 0 ... " << StationSize - 1 << endl;
}

/*
 * name:     mm
 * purpose:   interface for all mm related command
 * arguments: none
 * returns:   none
 * effects:    runs mm related command
 */
void MetroSim::mm(std::ofstream &filename)
{
    int QueueSize = Station[roundNum].size();
    for (; QueueSize != 0; QueueSize--)
    {
        int trainindex = Station[roundNum].front().getEndingStation();
        Train[trainindex].enqueue(Station[roundNum].front());
        Station[roundNum].dequeue();
    }
    updateRound();
    dropoffPassenger(filename);
    return;
}

/*
 * name:     updateRound
 * purpose:   update the round to the correct train station
 * arguments: none
 * returns:   none
 * effects:    update the round to the correct train station
 */
void MetroSim::updateRound()
{
    int value = StationSize - 2; 
    if (value == roundNum)
    {
        roundNum = 0;
    }
    else
    {
        roundNum++;
    }
}

/*
 * name:     dropOffPassenger
 * purpose:   dequeue the proper train section
 * arguments: none
 * returns:   none
 * effects:    dequeue the proper train section
 */
void MetroSim::dropoffPassenger(std::ofstream &filename)
{
    int PassengerNum = Train[roundNum].size(); 

    for (; PassengerNum != 0; PassengerNum--)
    {
        printOutFile(filename);
        Train[roundNum].dequeue();
    }   
}

void MetroSim::printOutFile(std::ofstream &filename)
{
    
    filename << "Passenger " << Train[roundNum].front().getId();
    filename << " left train at station "; 
    filename << StationName[Train[roundNum].front().getEndingStation()];
    filename << endl; 
}   
/*
 * name:     printTrain
 * purpose:   Print Train contect
 * arguments: none
 * returns:   none
 * effects:    test function pritn train contant/
 */

void MetroSim::printTrain()
{
    for (int i = 0; i < Train.size(); i++)
    {
        cout << "Train " << i << ": ";
        Train[i].print(cout);
        cout << endl;
    }
    return;
}