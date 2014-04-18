#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string fileName = "A-large-practice";
    //string fileName = "tiny";
    string fileInName = fileName+".in";
    string fileOutName = fileName+".out";
    string line;
    long long currentCase=0;

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
        cout << "----- Case #"<<currentCase<<" -----"<<endl;

        getline (fileIn,line);

        map<char,int> alphabet;
        int current = 0; // base

        for(int i=0;i<line.length();i++)
        {
            if(alphabet.count(line[i])==0)
            {
                if(current==0)
                    alphabet[line[i]]=1;
                else if(current==1)
                    alphabet[line[i]]=0;
                else
                    alphabet[line[i]]=current;
                current++;
            }
        }

        cout << "alphabet contains:";
        for (map<char,int>::iterator it=alphabet.begin(); it!=alphabet.end(); ++it)
            cout << ' ' << (*it).first << ':' << (*it).second;
        cout << '\n';

        cout << "Base "<<current<<endl;

        int base = current;
        if(base < 2)
            base = 2;

        unsigned long long result = 0;
        for(int i=0;i<line.length();i++)
        {
            result = result * base + alphabet[line[i]];
        }


        cout << "Case #"<<currentCase<<": "<<result<<endl;
        fileOut << "Case #"<<currentCase<<": "<<result<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
