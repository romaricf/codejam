#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main()
{
    string fileName = "B-large-practice";
    string fileInName = fileName+".in";
    string fileOutName = fileName+".out";
    string line;
    int currentCase=0;

    vector<string> v;

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
        std::istringstream stm(line);
        v.clear();
        string word ;
        while( stm >> word ) // read white-space delimited tokens one by one
        {
            v.push_back(word);
        }

        fileOut << "Case #"<<currentCase<<":";
        for(int i=0;i<v.size();i++)
        {
            fileOut << " " << v[v.size()-i-1];
        }
        fileOut <<endl;

    }

    fileOut.close();
    fileIn.close();

    return 0;
}
