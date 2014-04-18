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

int t_size = 40;

void simulate(int x,int y, double** diamond_matrix_prob, double proba)
{
    while(y>1 && (diamond_matrix_prob[x+20][y-2]==0))
        y-=2;

    if(y==0)
    {
        diamond_matrix_prob[x+20][y]+=proba;
//        cout << "1" << endl;
        return;
    }

    if(diamond_matrix_prob[x+20][y-2] > 0 || y==1)
    {
//        cout << "2" << endl;
        double left_prob = diamond_matrix_prob[x-1+20][y-1];
        double right_prob = diamond_matrix_prob[x+1+20][y-1];

        // one diamond bottom left and one diamond bottom right -> blocked
        if(left_prob > 0 && right_prob > 0)
        {
//            cout << "block" << endl;
            diamond_matrix_prob[x+20][y] += proba * left_prob*right_prob;
        }


        // both sides are empty
        if(left_prob < 1 && right_prob < 1)
        {
//            cout << "going right and left with proba " << proba * (1-left_prob) * (1-right_prob) * 0.5 << endl;
            simulate(x-1,y-1, diamond_matrix_prob, proba * (1-left_prob) * (1-right_prob) * 0.5);
            simulate(x+1,y-1, diamond_matrix_prob, proba * (1-left_prob) * (1-right_prob) * 0.5);
        }

        // left filled/right empty?
        if(left_prob > 0 && right_prob < 1)
        {
//            cout << "going right with proba " << proba * (left_prob) * (1-right_prob) << endl;
            simulate(x+1,y-1, diamond_matrix_prob, proba * (left_prob) * (1-right_prob));
        }

        // left empty/right filled?
        if(left_prob < 1 && right_prob > 0)
        {
//            cout << "going left with proba " << proba * (1-left_prob) * (right_prob) << endl;
            simulate(x-1,y-1, diamond_matrix_prob, proba * (1-left_prob) * (right_prob));
        }

    }




}

int main()
{
//    string fileName = "B-small-attempt0";
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
        int N, X, Y;
        stream >> N >> X >> Y;
        cout << "N " << N << " X " << X << " Y " << Y << endl;

        double probability = 0;

        double** diamond_matrix_prob = new double*[t_size];
        for(int i=0;i<40; i++)
        {
            diamond_matrix_prob[i] = new double[t_size];
            for(int j=0;j<40; j++)
            {
                diamond_matrix_prob[i][j]=0;
            }
        }

        for(int i=0;i<N; i++)
        {
//            cout << "diamond "<<i<< " - "<<endl;
            simulate(0,40,diamond_matrix_prob, 1);

//            cout << i<< " -------------"<<endl;

        }

        for(int i=t_size-1;i>=0; i--)
        {
            for(int j=0;j<40; j++)
            {
                cout<<diamond_matrix_prob[j][i]<<" ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "Case #"<<currentCase<<": "<<diamond_matrix_prob[X+20][Y]<<endl;
        fileOut << "Case #"<<currentCase<<": "<<diamond_matrix_prob[X+20][Y]<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
