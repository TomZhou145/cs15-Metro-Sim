/*
 *main.cpp
 *main function for the whole MetroSim
 */

#include <iostream>
#include <istream> 
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

int main(int argc, char *argv[])
{
if (argc < 2 or argc > 4)
{
cerr << "Usage: ./MetroSim stationsFile";
cerr << "outputFile [commandsFile]" << endl;
        exit(EXIT_FAILURE);
}

if (argc == 3)   
{        
        MetroSim MetroSim(argv[1]); 
        MetroSim.PLAY(argv[2],cin); 
}
if (argc == 4)
{
        ifstream com_file(argv[3]); 

        if (com_file.fail())
        {
        cerr << "Error: could not open file " << argv[3] << endl;
        exit(EXIT_FAILURE);
        }

        MetroSim MetroSim(argv[1]); 
        MetroSim.PLAY(argv[2],com_file); 
}

return 0;
}
