#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    string fileName = "tiny";
    string fileInName = fileName+".in";
    string fileOutName = fileName+".out";
    string line;
    int currentCase=0;

    ifstream fileIn(fileInName.c_str());
    ofstream fileOut(fileOutName.c_str());;

    if ( ! fileIn.is_open() )
    {
        cout << "File " << fileInName << " not found";
        return 1;
    }

    // number of cases
    getline (fileIn,line);
    int T = atoi(line.c_str());
    cout << "T=" << T << endl;

    // for each case
    while ( fileIn.good() and currentCase < T)
    {
        ++currentCase;
        cout << "----- Case #"<<currentCase<<" -----"<<endl;

        getline (fileIn,line);
        stringstream stream(line);
        int originalX, originalY;
        stream >> originalX >> originalY;
        cout << "originalX " << originalX << " originalY " << originalY << endl;

        int X = abs(originalX);
        int Y = abs(originalY);



        int* movesX = new int[500]();
        int* movesY = new int[500]();

        int x=0;
        int y=0;

        int lastMove = 0;


        while(x<X && y<Y)
        {
            lastMove++;
        }


        cout << "Case #"<<currentCase<<": "<<endl;
        fileOut << "Case #"<<currentCase<<": "<<endl;

        delete[] movesX;
        delete[] movesY;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
