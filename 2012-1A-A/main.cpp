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
    string fileName = "A-large";
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
        unsigned long long int r, t;
        stream >> r >> t;

        unsigned long long int blackRing =  0;
        unsigned long long int rings =  r - 1;

        unsigned long long int usedPaint = 0;

        while(usedPaint <= t)
        {
            blackRing++;
            rings += 2;

            usedPaint += rings * rings - (rings - 1) * (rings - 1);
//            cout << "used paint: " <<usedPaint <<endl;
        }
        blackRing--;

        cout << "Case #"<<currentCase<<": "<<blackRing<<endl;
        fileOut << "Case #"<<currentCase<<": "<<blackRing<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
