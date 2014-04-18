#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string fileName = "A-large-practice";
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
    int N = atoi(line.c_str());
    cout << "N=" << N << endl;

    // for each case
    while ( fileIn.good() and currentCase < N)
    {
        ++currentCase;

        getline (fileIn,line);
        int I = atoi(line.c_str()); // number of items

        getline (fileIn,line);
        std::stringstream stream(line);
        long long* v1 = new long long[I]; //
        for(int i=0; i<I; i++)
        {
            stream >> v1[i];
        }

        std::sort(v1,v1+I);

        getline (fileIn,line);
        std::stringstream stream2(line);
        long long* v2 = new long long[I]; //
        for(int i=0; i<I; i++)
        {
            stream2 >> v2[i];
        }

        std::sort(v2, v2+I);

        long long sum = 0;
        for(int i=0; i<I; i++)
        {
            sum += (v1[i]*v2[I-i-1]);
        }


        cout << "Case #"<<currentCase<<": "<<sum<<endl;
        fileOut << "Case #"<<currentCase<<": "<<sum<<endl;

        delete v1; delete v2;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
