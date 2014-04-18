#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int best_solution = -1;
int N = 0;
int depth = 0;
bool globalSolutionPossible = true;

void recursive_exploration(int* a,int* b,int* complete1,int* complete2, int stars, int current_solution)
{
//    cout << "Depth: "<<depth<<endl;
    bool allExplored = true;


    if(best_solution>= 0)
    {
        int min_to_reach_solution = 0;
        for(int i=0;i<N;i++)
        {
            if( complete2[i] == false)
                min_to_reach_solution++;
        }

        if(current_solution+min_to_reach_solution >= best_solution)
        {
//            cout << "Chopping branch: "<<current_solution<<" Depth: "<<depth<<endl;
            return;
        }
    }
    else
    {
        if(!globalSolutionPossible)
            return;
    }

    bool solutionPossible = false;


    // 2 stars exploration
    int max2 = -1;
    for(int i=0;i<N;i++)
    {
        if( complete2[i] == false)
        {
            allExplored = false;
            if(b[i]<= stars)
            {
                if(max2 == -1 || b[i] > b[max2])
                {
                    max2 = i;
                }

            }
        }
    }
    if(max2 != -1)
    {
        solutionPossible = true;
        complete2[max2]=true;
        depth++;
        if( complete1[max2] == false)
            recursive_exploration(a,b,complete1,complete2, stars+2, current_solution+1);
        else
            recursive_exploration(a,b,complete1,complete2, stars+1, current_solution+1);
        complete2[max2]=false;
        depth--;
    }

    // 1 stars exploration
    int min1max2 = -1;
    if(solutionPossible == false)
    {
        for(int i=0;i<N;i++)
        {
            if( complete2[i] == false && complete1[i] == false)
            {
                if(a[i]<= stars)
                {
                    if(min1max2 == -1 || b[i] > b[min1max2])
                    {
                        min1max2 = i;
                    }

    //                delete[] tmp;
                }
            }
        }

        if(min1max2 != -1)
        {
            solutionPossible = true;
            depth++;
            complete1[min1max2]=true;
            recursive_exploration(a,b,complete1,complete2, stars+1, current_solution+1);
            complete1[min1max2]=false;
            depth--;
        }
    }

    if(allExplored)
    {
        if(best_solution==-1 || current_solution<best_solution)
        {
            best_solution = current_solution;
            cout << "Solution found: "<<best_solution<<" Depth: "<<depth<<endl;
        }
    }

    if(best_solution==-1 && !solutionPossible)
    {
        globalSolutionPossible = false;
        cout << "No solution..."<<" Depth: "<<depth<<endl;
    }


}

int main()
{
//    string fileName = "tiny";
    string fileName = "B-large-practice";
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
        N = atoi(line.c_str());
        best_solution = -1;
        depth = 0;
        globalSolutionPossible = true;

        cout << "N=" << N << endl;

        int* a = new int[N]();
        int* b = new int[N]();

        int* complete1 = new int[N]();
        int* complete2 = new int[N]();

        for (int i=0;i<N;i++)
        {
            getline (fileIn,line);
            stringstream stream(line);
            stream >> a[i] >> b[i];
        }

//        cout <<"a: ";
//        for (int i=0;i<N;i++)
//        {
//            cout << a[i]<<" ";
//        }
//        cout <<endl;

        recursive_exploration(a,b,complete1,complete2, 0, 0);




        cout << "Case #"<<currentCase<<": "<<best_solution<<endl;

        if(best_solution==-1)
            fileOut << "Case #"<<currentCase<<": "<<"Too Bad"<<endl;
        else
            fileOut << "Case #"<<currentCase<<": "<<best_solution<<endl;

        delete[] a;
        delete[] b;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}


