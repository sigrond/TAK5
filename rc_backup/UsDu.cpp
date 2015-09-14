//usuwanie duplikatów
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;
vector<string> T;
vector<string> A;
vector<string> L;
vector<string> K;
void odcz()
{
    int a=0;
    fstream f;
    f.open("zasob");
    string s="";
    while(getline(f, s))
    {
        a++;
        switch (a)
        {
            case 1:
            T.push_back(s);
            break;
            case 2:
            A.push_back(s);
            break;
            case 3:
            L.push_back(s);
            break;
            case 4:
            K.push_back(s);
            a=0;
            break;
        }
        s="";
    }
    f.close();
}
void zapi()
{
     int a=0, num=0;
     fstream f;
     f.open("zasob", ios::out);
     string s="";
     string s2="";
     f << s2;
     f.close();
     for(int i=0; i<T.size(); i++)
     {
             s.append(T[i]);
             s+=(char)10;
             s.append(A[i]);
             s+=(char)10;
             s.append(L[i]);
             s+=(char)10;
             s.append(K[i]);
             s+=(char)10;
     }
     f.open("zasob", ios::out);
     f << s;
     f.close();
}
int main()
{
    odcz();
    for(int i=0; i<L.size(); i++)
    {
            for(int j=i+1; j<L.size(); j++)
            {
                    if(L[i]==L[j])
                    {
                                  T.erase(T.begin()-1+j);
                                  A.erase(A.begin()-1+j);
                                  L.erase(L.begin()-1+j);
                                  K.erase(K.begin()-1+j);
                                  j--;
                    }
            }
    }
    zapi();
    return 0;
}
    
