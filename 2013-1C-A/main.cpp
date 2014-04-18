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
//    string fileName = "A-large";
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
        int N;
        string nameString;
        stream >> nameString >> N;
//        cout << "Name " << nameString << " N " << N << endl;

        const char* name = nameString.c_str();

        long long int wordFound = 0;

        int multiplier = 0;

        for(int i=0; i < nameString.length() +1 -N; i++)
        {
            bool found = true;
//            int count = 0;

            for(int j=i;j < i+N; j++)
            {
                if(!(name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i] != 'o' && name[i] != 'u'))
                {
                    found = false;
                    break;
                }
            }

            if(found)
            {
                cout << "Found position:"<<i<<endl;
                wordFound+= (i+1)*(nameString.length()-i-N);
            }

        }




        cout << "Case #"<<currentCase<<": "<<wordFound<<endl;
        fileOut << "Case #"<<currentCase<<": "<<wordFound<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
