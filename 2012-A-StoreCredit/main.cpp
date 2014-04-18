#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{

    string fileName = "A-large-practice";
    string fileInName = fileName+".in";
    string fileOutName = fileName+".out";
    string line;
    int A;
    int B;
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
        int C = atoi(line.c_str()); // credit
        getline (fileIn,line);
        int I = atoi(line.c_str()); // number of items

        getline (fileIn,line);
        std::stringstream stream(line);
        int* P = new int[I]; // prices
        for(int i=0; i<I; i++)
        {
            stream >> P[i];
        }

        A=-1;

        for(int i=0; i<I-1; i++)
        {
            for(int j=i+1; j<I; j++)
            {
                if(P[i]+P[j]==C)
                {
                    A=i;
                    B=j;
                }
                if(A>-1)
                    break;
            }
            if(A>-1)
                break;
        }

        if(A==-1)
            cout << "Weird..."<<endl;
        else
        {
            //cout << "Case #"<<currentCase<<": "<<A+1<<" "<<B+1<<endl;
            fileOut << "Case #"<<currentCase<<": "<<A+1<<" "<<B+1<<endl;
        }
        delete P;


    }


    fileIn.close();


    //cin.get();

    return 0;
}
