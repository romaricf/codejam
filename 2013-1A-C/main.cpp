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
        int R, N, M, K;
        stream >> R >> N >> M >> K;
//        cout << "L " << L << " D " << D << " N " << N << endl;

        for (int i=0;i<N;i++)
        {
            getline (fileIn,line);
            stringstream stream2(line);

            int* setProducts = new int[K]();

            for (int j=0;j<K;j++)
            {
                stream2 >> setProducts[j];
            }

            cout << "Case #"<<currentCase<<": "<<endl;
            fileOut << "Case #"<<currentCase<<": "<<endl;
        }




    }

    fileOut.close();
    fileIn.close();

    return 0;
}
