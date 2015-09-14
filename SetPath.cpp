#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream f;
    string s;
    getline(cin, s);
    f.open("MyPath", ios::out);
    s.append("\\");
    f<<s;
    f.close();
    return 0;
}
