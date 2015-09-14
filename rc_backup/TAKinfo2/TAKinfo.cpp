#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(int argc,char*argv[])
{
	for(int i=1;i<argc;i++)
	cout<<argv[i]<<endl;
	fstream f;
	string s;
	f.open("MyPath");
	getline(f,s);
	cout<<endl<<s<<endl<<endl<<"by Sigrond"<<endl;
	f.close();
	system("pause");
	return 0;
}
