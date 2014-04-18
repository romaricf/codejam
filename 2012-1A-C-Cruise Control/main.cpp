#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

list<int> leftLane;
list<int> rightLane;

char* lane;
int* speed;
int* position;

bool insertInPosition(list<int> &pLane, int i)
{

//    cout << "1" << endl;
//    pLane.insert(pLane.begin(),i);
//    cout << "2" << endl;
//    pLane.insert(pLane.end(),i);
//    cout << "3" << endl;

    list<int>::iterator it = pLane.begin();
//    list<int>::iterator it2 = pLane.end();
//
//    if(it == it2)
//        cout << "true" << endl;

//    cout << "X: " << *it << endl;// " : " << position[*it] << endl;
//    cout << "i: " << i << endl;
//    cout << "position[i]: " << position[i] << endl;
    while(it!=pLane.end() && position[*it]<position[i])
    {
//        cout << "X: " << *it << endl;// " : " << position[*it] << endl;
        ++it;
    }


    pLane.insert(it,i);

    if(it!=pLane.end())
        if(position[*it]<position[i]+5)
            return true;
    if(it!=pLane.begin())
        it--;
    if(it!=pLane.begin())
    {
        it--;
//        if(it!=lane.begin())
        {
            if(position[*it]+5>position[i])
                return true;
        }
    }

    return false;
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
        int N = atoi(line.c_str());

        lane = new char[N]();
        speed = new int[N]();
        position = new int[N]();

        for (int i=0;i<N;i++)
        {
            getline (fileIn,line);
            stringstream stream(line);
            stream >> lane[i] >> speed[i] >> position[i];
//            cout << i<< ": lane " << lane[i] << " speed " << speed[i] << " pos " << position[i] << endl;
        }

//        solving

        leftLane.clear();
        rightLane.clear();

        bool collision = false;
        int duration = 0;

        // generating position list
        for (int i=0;i<N;i++)
        {
            if(lane[i] == 'L')
            {
                collision = insertInPosition(leftLane,i);
            }
            else
            {
                collision = insertInPosition(rightLane,i);
            }
            if(collision)
            {
                cout << "Collision!" << endl;
                break;
            }
        }


        cout << "Left Lane:";
        for (list<int>::iterator it=leftLane.begin(); it!=leftLane.end(); ++it)
            cout << ' ' << *it;
        cout << endl;

        cout << "Right Lane:";
        for (list<int>::iterator it=rightLane.begin(); it!=rightLane.end(); ++it)
            cout << ' ' << *it;
        cout << endl;

        if(!collision)
        {

            // find next collision


        }



        cout << "Case #"<<currentCase<<": "<<duration<<endl;
        fileOut << "Case #"<<currentCase<<": "<<duration<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
