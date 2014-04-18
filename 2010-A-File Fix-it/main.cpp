#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <map>

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

        stringstream stream(line);
        int N,M;
        stream >> N >> M;
        cout << "N " << N << " M " << M << endl;


        set<string> directories;

        for(int i=0;i<N;i++)
        {
            getline (fileIn,line);
            directories.insert(line);
        }

        int insertCount = 0;

        for(int i=0;i<M;i++)
        {

            getline (fileIn,line);
            istringstream liness( line );
            string word;
            string pathexplorer = "";;
            if(getline( liness, word, '/' ))
            {
                while(getline( liness, word, '/' ))
                {
                    pathexplorer += "/"+word;

                    if(directories.find(pathexplorer) == directories.end())
                    {
                        insertCount++;
                        directories.insert(pathexplorer);
                    }
                }
            }
        }


        cout << "Case #"<<currentCase<<": "<<insertCount<<endl;
        fileOut << "Case #"<<currentCase<<": "<<insertCount<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
