#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream f;
	string s;
	f.open("MyPath");
	f>>s;
	cout<<s<<endl<<endl<<"by Sigrond"<<endl;
	f.close();
	system("pause");
	return 0;
}
