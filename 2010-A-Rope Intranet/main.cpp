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
    int T = atoi(line.c_str());
    cout << "T=" << T << endl;

    // for each case
    while ( fileIn.good() and currentCase < T)
    {
        ++currentCase;

        getline (fileIn,line);
        int N = atoi(line.c_str());

        int* A = new int[N];
        int* B = new int[N];

        bool* AB = new bool[N*N];

        for(int i=0;i<N;i++)
        {
            getline (fileIn,line);
            stringstream stream(line);
            stream >> A[i] >> B[i];
        }

        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(A[i] < A[j] && B[i] > B[j])
                {
                    AB[i+j*N]=true;
                }
                else if(A[i] > A[j] && B[i] < B[j])
                {
                    AB[i+j*N]=true;
                }
                else
                {
                    AB[i+j*N]=false;
                }
            }
        }

        int count=0;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(AB[i+j*N])
                    ++count;
            }
        }

        cout << "Case #"<<currentCase<<": "<<count<<endl;
        fileOut << "Case #"<<currentCase<<": "<<count<<endl;

        delete[] A, B, AB;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
