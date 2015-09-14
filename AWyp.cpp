#include<iostream>
#include<cstdlib>
#include<sstream>
#include<sys/stat.h>
#include<dirent.h>
#include<vector>
#include<fstream>
#include "windows.h"
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
string ignoreStrshift(string s)
{
       string s2="";
       for(int i=0; i<s.size(); i++)
       if((int)s[i]>=65 && (int)s[i]<=90)
       s2+=(char)(int)s[i]+32;
       else
       s2+=s[i];
       return s2;
}
vector<string> vd;
vector<string> vf;
void WyszukajIWypisz(string const & szukaj, string scierzka)
{
    DIR * fol;
    dirent * dir;
    if ((fol = opendir(scierzka.c_str())) == NULL) return;
    string temp;
    struct stat info;
    while((dir = readdir(fol)) != NULL)
    {
        temp = dir->d_name;
        if (temp == "." || temp == "..") continue;
        if (stat((scierzka + temp).c_str(), &info) != 0) continue;
        if (S_ISDIR(info.st_mode)) WyszukajIWypisz(szukaj, scierzka + temp + '\\');
        if (ignoreStrshift(temp).find(ignoreStrshift(szukaj)) != string::npos) {vd.push_back(scierzka);vf.push_back(dir->d_name);}
    }
    closedir(fol);
}
string WoExt(string s)
{
       if(s.find('.') != string::npos)
       {
                           int sSiz=s.size();
                           while(s[sSiz-1]!=(char)46 && sSiz>0)
                           {
                           sSiz--;
                           //cout<<s[sSiz]<<int(s[sSiz])<<endl;
                           s.erase(s.end()-1);
                           }
                           s.erase(s.end()-1);
       }
       return s;
}
string ad, kd;
void GetData(string s)
{
     ad="";
     kd="";
     string s2="exiftool.exe -author -keywords ", s3=" >> Dat", s4;
     s4=s2+'"'+s+'"'+s3;
     system(s4.c_str());
     fstream f;
     f.open("Dat");
     f>>ad;
     f>>ad;
     getline(f, ad);
     f>>kd;
     f>>kd;
     getline(f, kd);
     f.close();
     system("del Dat");
     if(ad.size()>0)
     ad.erase(ad.begin());
     if(kd.size()>0)
     kd.erase(kd.begin());
}
int main()
{
    string start, f;
    cout<<"sciezka- na koncu: "<<(char)92<<endl;
    getline(cin, start);
    cout<<"szukaj? >"<<endl;
    getline(cin, f);
    cout<<"Czekaj. Wyszukiwanie plikow..."<<endl;
    WyszukajIWypisz(f, start);
    cout<<"Czytanie metafile... "<<endl;
    odcz();
    int vds=vd.size();
    cout<<vds<<" plikow"<<endl;
    float vdsl=0;
    for(int i=0; i<vds; i++)
    {
            GetData(vd[i]+vf[i]);
            T.push_back(WoExt(vf[i]));
            A.push_back(ad);
            L.push_back(vd[i]+'@'+vf[i]);
            K.push_back(kd);
            cout<<'.';
    }
    cout<<"zapis..."<<endl;
    zapi();
    system("pause");
    return 0;
}
