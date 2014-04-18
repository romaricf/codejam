#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <set>

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

    getline (fileIn,line);
    stringstream stream(line);
    int L, D, N;
    stream >> L >> D >> N;
    cout << "L " << L << " D " << D << " N " << N << endl;

    //set<string> dico;
    string* dico = new string[D];

    // load the words
    cout << "Dico: ";
    for(int i=0;i<D;i++)
    {
        getline (fileIn,line);
        //dico.insert(line);
        dico[i]=line;
        cout << line << " ";
    }
    cout << endl;

    int* old_select = new int[D];
    int* new_select = new int[D];
    int* tmp;

    // for each case
    for(int i=0;i<N;i++)
    {
        std::fill( old_select, old_select + D, 1 );
        std::fill( new_select, new_select + D, 0 );

        int count = 0;
        getline (fileIn,line);

        int position = 0;
        for (int j=0;j<L;j++)
        {
            std::fill( new_select, new_select + D, 0 );
            if(line[position]=='(')
            {
                position++;
                while(line[position]!=')')
                {
                    for(int k=0;k<D;k++)
                    {
                        if(old_select[k]==1 && line[position]==dico[k][j])
                        {
                            new_select[k]=1;
                        }
                    }
                    position++;
                }
                position++;
            }
            else
            {
                for(int k=0;k<D;k++)
                {
                    if(old_select[k]==1 && line[position]==dico[k][j])
                    {
                        new_select[k]=1;
                    }

                }
                position++;
            }

            tmp = old_select;
            old_select=new_select;
            new_select=tmp;
        }

        for(int k=0;k<D;k++)
        {
            if(old_select[k]==1)
                count++;
        }



        cout << "Case #"<<i+1<<": "<<count<<endl;
        fileOut << "Case #"<<i+1<<": "<<count<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
