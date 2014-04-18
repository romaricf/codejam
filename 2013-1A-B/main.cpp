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

int function max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

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
        int E, R, N;
        stream >> E >> R >> N;
        cout << "E " << E << " E " << E << " N " << N << endl;

        int* v = new int[N];

        getline (fileIn,line);
        stringstream stream2(line);
        for (int i=0;i<N;i++)
        {
            stream2 >> v[i];
        }

        int* energyUsed = new int[N]();
        int* energyLeft = new int[N]();
        bool* done = new bool[N]();

        for (int i=0;i<N;i++)
        {
            energyUsed[i] = R;
            energyLeft[i] = E;

            done[i] = false;
        }

        for (doneCount=0;doneCount<N;doneCount++)
        {
            int currentMax = -1;
            for (int i=0;i<N;i++)
            {
                if(done[i]==false)
                {
                    if(currentMax == -1 || v[i]>v[currentMax])
                        currentMax = i;
                }
            }

            if(currentMax == -1)
            {
                cout << "should not happen" << endl;
                return 2;
            }

            done[currentMax] = true;

            if(i == 0)
            {
                energyUsed[i] = E;
                energyLeft[i] = R;
            }
            else
            {
                energyUsed[i] = energyLeft[i-1];
                energyLeft[i] = R;

                int backMove_i = 1;
                while(true)
                {
                    if(energyUsed[i] - backMove_i*R > 0)
                    {

                        if(energyUsed[i] - backMove_i*R >= R)
                        {
                            energyUsed[i] = R;
                            done[i-backMove_i] = true;
                            energyLeft[i] = energyLeft[i-1];
                        }
                        else
                        {
                            energyUsed[i] =
                        }
                    }
                }
            }



            // set energyLeft
            for (int j=i+1;j<N;j++)
            {
            }
        }


/////////
        bool* done = new bool[N]();
        int doneCount;

        int* energyBeginning = new int[N]();
        for (int i=0;i<N;i++)
        {
            energyBeginning = E;
        }

//        int currentE = E;
        long long int totalGain = 0;

        for (doneCount=0;doneCount<N;doneCount++)
        {
            int currentMax = -1;
            for (int i=0;i<N;i++)
            {
                if(done[i]==false)
                {
                    if(currentMax == -1 || v[i]>v[currentMax])
                        currentMax = i;
                }
            }

            if(currentMax == -1)
            {
                cout << "should not happen" << endl;
                return 2;
            }

            done[currentMax] = true;

            totalGain += energyBeginning[i] * v[currentMax];

            if(i+1 < N)
                energyBeginning[i+1] = R;

        }

        cout << "Case #"<<currentCase<<": "<<endl;
        fileOut << "Case #"<<currentCase<<": "<<endl;

        delete[] v;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
