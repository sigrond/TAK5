
string usat(string s)//usun malpe ze stringu
{
	string o="";
	for(unsigned int i=0;i<s.size();i++)
	{
		if(s[i]!='@')
		o+=s[i];
	}
	return o;
}

string bezdir(string s)//utnij folder
{
       string s2="";
       bool pm=true;
       for(unsigned int i=0; i<s.size(); i++)
       {
               if(pm)
               {if(s[i]=='@') pm=false;}
               else
               {
                   if(s[i]=='@') pm=true;
                   else
                   s2+=s[i];
               }
       }
       return s2;
}

string bezfil(string s)//katalog pliku
{
       string s2="";
       bool pm=false;
       for(unsigned int i=0; i<s.size(); i++)
       {
               if(pm)
               {if(s[i]=='@') pm=false;}
               else
               {
                   if(s[i]=='@') pm=true;
                   else
                   s2+=s[i];
               }
       }
       return s2;
}

string usbizn(string mstr)//zamiana \r i \n na spację
{
       for(unsigned int i=0; i<mstr.size(); i++)
       {
               if((int)mstr[i]==13 || (int)mstr[i]==10)
               {
                                  mstr[i]=(char)32;
               }
       }
       return mstr;
}

string linknr(string s, int a)
{
       string s2="";
       a++;
       for(unsigned int i=0; i<s.size() && a>=0; i++)
       {
               if(s[i+1]==':')
               a--;
               if(a==0)
               s2+=s[i];
       }
       return s2;
}

int ilspc(string s)//dwókropków koniecznie!
{
    int a=0;
    for(unsigned int i=0; i<s.size(); i++)
    if(s[i]==':')
    a++;
    return a;
}

string nospcend(string s)
{
       if(s[0]==' ')
       s.erase(s.begin());
       if(s[s.size()-1]==' ')
       s.erase(s.begin()+s.size()-1);
       return s;
}

string UsunZnakiZakazane(string s)
{
       //\/:*?<>|
       string s2="";
       for(unsigned int i=0; i<s.size(); i++)
       if(s[i]=='\\' || s[i]=='/' || s[i]==':' || s[i]=='*' || s[i]=='\?' || s[i]=='<' || s[i]=='>' || s[i]=='|')
       ;
       else
       s2+=s[i];
       return s2;
}

string ignoreStrshift(string s)
{
       string s2="";
       for(unsigned int i=0; i<s.size(); i++)
       if((int)s[i]>=65 && (int)s[i]<=90)
       s2+=(char)(int)s[i]+32;
       else
       s2+=s[i];
       return s2;
}

string convertInt(int number)//convert int to string
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

string UsEndlSpc(string lStr1)
{
    string lStr2="";
    for(unsigned int i=0;i<lStr1.size();i++)
    {
        if(lStr1[i]==(char)10 || lStr1[i]==(char)13)
        lStr1[i]=(char)32;
    }
    int lPom1=lStr1.size();
    lStr1+="\0";
    for(int i=0;i<lPom1;i++)
    {
        if(!(lStr1[i+1]==(char)32 && lStr1[i]==(char)32))
        lStr2+=lStr1[i];
    }
    return lStr2;
}
