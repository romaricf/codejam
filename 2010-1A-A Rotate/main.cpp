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
//    string fileName = "A-small-practice";
//    string fileName = "tiny";
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
        int N, K;
        stream >> N >> K;
        cout << "N " << N << " K " << K << endl;

        char* matrix = new char[N*N];
        string word;

        // read the matrix
        for (int i=0;i<N;i++)
        {
            getline (fileIn,line);
            for (int j=0;j<N;j++)
            {
                matrix[i*N+j]= line[j];
            }
        }

//        cout << "Original" << endl;
//        for (int i=0;i<N;i++)
//        {
//            for (int j=0;j<N;j++)
//            {
//                cout << matrix[i*N+j] << " ";
//            }
//            cout << endl;
//        }

        // gravity
        for (int i=0;i<N;i++)
        {
            for (int j=N-1;j>=0;j--)
            {
                while(matrix[i*N+j]== '.')
                {
                    bool emptyLine = true;
                    for (int k=j;k>0;k--)
                    {
                        matrix[i*N+k]=matrix[i*N+k-1];
                        if(matrix[i*N+k]!='.')
                            emptyLine=false;
                    }
                    matrix[i*N]='.';
                    if(emptyLine)
                        break;
                }
            }
        }

        cout << "Gravity" << endl;
        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                cout << matrix[i*N+j] << " ";
            }
            cout << endl;
        }

        // find winners
        bool red = false;
        bool blue = false;

        for (int i=0;i<N;i++)
        {
            for (int j=0;j<N;j++)
            {
                char c = matrix[i*N+j];

                // horizontal
                for(int k=1;k<=K && j+k<N;k++)
                {
                    if(matrix[i*N+j+k] != c)
                        break;
                    if(k==K-1)
                    {
                        if(c=='B')
                            blue=true;
                        else if(c=='R')
                            red=true;
                    }
                }

                // vertical
                for(int k=1;k<=K && i+k<N;k++)
                {
                    if(matrix[(i+k)*N+j] != c)
                        break;
                    if(k==K-1)
                    {
                        if(c=='B')
                            blue=true;
                        else if(c=='R')
                            red=true;
                    }
                }

                // diagonal low right
                for(int k=1;k<=K && i+k<N && j+k<N;k++)
                {
                    if(matrix[(i+k)*N+j+k] != c)
                        break;
                    if(k==K-1)
                    {
                        if(c=='B')
                            blue=true;
                        else if(c=='R')
                            red=true;
                    }
                }

                // diagonal low left
                for(int k=1;k<=K && i+k<N && j-k>=0;k++)
                {
                    if(matrix[(i+k)*N+j-k] != c)
                        break;
                    if(k==K-1)
                    {
                        if(c=='B')
                            blue=true;
                        else if(c=='R')
                            red=true;
                    }
                }
            }
        }
//            int c = 0;
//            char prev = '.';
//
//            for (int j=0;j<N;j++)
//            {
//                if(matrix[i*N+j]==prev)
//                {
//                    c++;
//                }
//                else
//                {
//                    c=1;
//                    prev = matrix[i*N+j];
//                }
//
//                if(c==K)
//                {
//                    if(prev=='B')
//                        blue=true;
//                    else if(prev=='R')
//                        red=true;
//                }
//            }
//        }
//
//        // horizontal
//        for (int i=0;i<N;i++)
//        {
//            int c = 0;
//            char prev = '.';
//
//            for (int j=0;j<N;j++)
//            {
////                if(matrix[i*N+j]=='.')
////                    break;
//
//                if(matrix[j*N+i]==prev)
//                {
//                    c++;
//                }
//                else
//                {
//                    c=1;
//                    prev = matrix[j*N+i];
//                }
//
//                if(c==K)
//                {
//                    if(prev=='B')
//                        blue=true;
//                    else if(prev=='R')
//                        red=true;
//                }
//            }
//        }
//
//        // diagonal
//        for (int i=0;i<N-K+1;i++)
//        {
//            int c = 0;
//            char prev = '.';
//
//            for (int j=0;j<N-i;j++)
//            {
//                if(matrix[j*N+j+i]==prev)
//                {
//                    c++;
//                }
//                else
//                {
//                    c=1;
//                    prev = matrix[j*N+j+i];
//                }
//
//                if(c==K)
//                {
//                    if(prev=='B')
//                        blue=true;
//                    else if(prev=='R')
//                        red=true;
//                }
//            }
//        }
//        for (int j=1;j<N-K+1;j++)
//        {
//            int c = 0;
//            char prev = '.';
//
//            for (int k=0;k<N-j;k++)
//            {
//                if(matrix[j*N+k*N+k]==prev)
//                {
//                    c++;
//                }
//                else
//                {
//                    c=1;
//                    prev = matrix[j*N+k*N+k];
//                }
//
//                if(c==K)
//                {
//                    if(prev=='B')
//                        blue=true;
//                    else if(prev=='R')
//                        red=true;
//                }
//            }
//        }
//
//        for (int i=K-1;i<N;i++)
//        {
//            int c = 0;
//            char prev = '.';
//
//            for (int j=0;j<N;j++)
//            {
//                if(matrix[j*N-j+i]==prev)
//                {
//                    c++;
//                }
//                else
//                {
//                    c=1;
//                    prev = matrix[j*N-j+i];
//                }
//
//                if(c==K)
//                {
//                    if(prev=='B')
//                        blue=true;
//                    else if(prev=='R')
//                        red=true;
//                }
//            }
//        }
//
//        for (int j=1;j<N-K+1;j++)
//        {
//            int c = 0;
//            char prev = '.';
//
//            for (int k=0;k<N-j;k++)
//            {
//                if(matrix[j*N+k*N+(N-k-1)]==prev)
//                {
//                    c++;
//                }
//                else
//                {
//                    c=1;
//                    prev = matrix[j*N+k*N+(N-k-1)];
//                }
//
//                if(c==K)
//                {
//                    if(prev=='B')
//                        blue=true;
//                    else if(prev=='R')
//                        red=true;
//                }
//            }
//        }


        cout << "Case #"<<currentCase<<": Red "<< red << " Blue "<<blue<<endl;
        if(red && blue)
            fileOut << "Case #"<<currentCase<<": Both"<<endl;
        else if(red)
            fileOut << "Case #"<<currentCase<<": Red"<<endl;
        else if(blue)
            fileOut << "Case #"<<currentCase<<": Blue"<<endl;
        else
            fileOut << "Case #"<<currentCase<<": Neither"<<endl;
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
