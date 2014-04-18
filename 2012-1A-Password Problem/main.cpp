#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    string fileName = "A-large-practice";
//    string fileName = "A-small-practice";

//string fileName = "tiny";
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
        int A,B,C;
        stream >> A >> B;
//        C=A+B;
        cout << "A " << A << " B " << B << endl;

        getline (fileIn,line);
        stringstream stream2(line);

        double* pCorrect = new double[A+1];
        pCorrect[0]=1;
        for (int i=1;i<=A;i++)
        {
            stream2 >> pCorrect[i];
            pCorrect[i] *= pCorrect[i-1];
//            cout << i << ":" << pCorrect[i] << " ";
        }
//        cout << endl;

        double* expectedKeystrokes = new double[A+1];

        // just complete password
//        expectedKeystrokes[0] = pCorrect[A]*(B-A+1) + (1-pCorrect[A])*(B-A+B+2);

        // remove i characters
        for (int i=0;i<A;i++)
        {
            expectedKeystrokes[i] = pCorrect[A-i]*(B-A+1+i*2) + (1-pCorrect[A-i])*(B-A+1+B+1+i*2);
        }

        // press enter first
        expectedKeystrokes[A] = 1+B+1;

        double min = expectedKeystrokes[0];
        for (int i=1;i<=A;i++)
        {
//            cout << i << ":" << expectedKeystrokes[i] << " ";
            if(min > expectedKeystrokes[i])
                min = expectedKeystrokes[i];
        }
//        cout << endl;

        cout <<std::fixed<<std::setprecision(6) << "Case #"<<currentCase<<": " << min<<endl;
        fileOut <<std::fixed<<setprecision(6) << "Case #"<<currentCase<<": " <<min<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
