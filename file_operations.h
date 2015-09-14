
void odcz()
{
    T.clear();
    A.clear();
    L.clear();
    K.clear();
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

void zapi()//zapisz wektory z pamieci do pliku
{
     fstream f;
     f.open("zasob", ios::out);
     string s="";
     string s2="";
     f << s2;
     f.close();
     for(unsigned int i=0; i<T.size(); i++)
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

void konw()
{
    string s="", str="";
    fstream f, file;
    int i=0;
    f.open("zasob");
    while(getline(f, s))
    {
        i++;
        if(i==4)
        str.append(bezfil(s)+bezdir(s));
        else
        str.append(s);
        if(i==4)
        {
            i=0;
            str+=(char)10;
        }
        else
        str+=(char)9;
    }
    f.close();
    s="";
    file.open("twojformat.xls", ios::out);
    file<<s;
    file.close();
    file.open("twojformat.xls", ios::out);
    file<<usat(str);
    file.close();
}

string start ="\\";
void SetPath()//odczytaj domyslna sciezke z pliku
{
    //system("SetPath.exe");
    fstream pt;
    pt.open("MyPath");
    start="";
    getline(pt, start);
    pt.close();
}

void FiLoPa()
{
    fstream pt;
    pt.open("MyPath");
    start="";
    getline(pt, start);
    pt.close();
}

void extr(int i, string s)
{
    HRSRC hHP = FindResource (NULL, MAKEINTRESOURCE(i), RT_RCDATA);
	HGLOBAL pHP = LoadResource (NULL, hHP);
    DWORD dwDlugosc = SizeofResource (NULL, hHP);
	HANDLE hPlik = CreateFile(s.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL , NULL);
    DWORD dwBajtyZapisane=0;
    WriteFile (hPlik, pHP, dwDlugosc, &dwBajtyZapisane, NULL);
    CloseHandle (hPlik);
    //UnlockResource(pHP);//The UnlockResource function is obsolete.
    FreeResource(pHP);
}

string wyszukanie;
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


#define UpdtPeriod 2629800//raz na miesiac
void ZapiszCzas()
{
    time_t rawtime;
    //struct tm * timeinfo;
    time ( &rawtime );
    void* pom1a=new time_t;
    pom1a=&rawtime;
    //timeinfo = localtime ( &rawtime );
    //printf ( "Current local time and date: %s", asctime (timeinfo) );
    fstream f;
    f.open("czas", fstream::out | fstream::trunc | fstream::binary);
    f.write((char*)pom1a,sizeof(time_t));
    f.close();
}

void __cdecl ThreadProc1 (void* Args);
HANDLE hThread1=NULL;
string PodajCzas()
{
    fstream f;
    f.open("czas", fstream::in | fstream::binary);
    time_t* rawtime;
    void* pom1a=new time_t;
    f.read((char*)pom1a,sizeof(time_t));
    f.close();
    rawtime=(time_t*)pom1a;
    time_t ChT;
    time(&ChT);
    if(ChT - *rawtime >= UpdtPeriod)/////////////////////////   !!!   okresowa aktualizacja   !!!
    hThread1 = (HANDLE) _beginthread (ThreadProc1, 0, NULL);
    struct tm * timeinfo;
    timeinfo = localtime ( rawtime );
    string s="";
    s.append(asctime (timeinfo));
    return s;
}

//begin: (AWyp) funkcje uzupelniajace zasob
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
     string s2="/C exiftool.exe -author -keywords ", s3=" >> Dat", s4;
//string s2="exiftool.exe -author -keywords ", s3=" >> Dat", s4;
     s4=s2+'"'+s+'"'+s3;
//system(s4.c_str());
     if(!ShellExecute(NULL, "open", "cmd", s4.c_str(), NULL, SW_HIDE))
     {
         MessageBox (MAINhwnd, "nie udalo sie otworzyc exiftool.exe", "error", MB_ICONERROR);
         //return;
     }
     fstream f;
     f.open("Dat");
     f>>ad;
     f>>ad;
     getline(f, ad);
     f>>kd;
     f>>kd;
     getline(f, kd);
     f.close();
//system("del Dat");
     /*if(!ShellExecute(NULL, "open", "cmd", "/C del Dat", NULL, SW_HIDE))
     {
         MessageBox (MAINhwnd, "nie udalo sie usunac Dat", "error", MB_ICONERROR);
         //return;
     }*/
     if(ad.size()>0)
     ad.erase(ad.begin());
     if(kd.size()>0)
     kd.erase(kd.begin());
}
HANDLE hThread3=NULL;
void __cdecl ThreadProc3 (void* Args);
void AWyp(string f)
{
    //DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DLG1), MAINhwnd, DlgProc2);
    hThread3 = (HANDLE) _beginthread (ThreadProc3, 0, NULL);
    //cout<<"Czekaj. Wyszukiwanie plikow..."<<endl;
    vd.clear();
    vf.clear();
    WyszukajIWypisz(f, start);
    //cout<<"Czytanie metafile... "<<endl;
//system("pause");
    SetWindowText (hTekst2, "Czytanie metafile...");
    odcz();
    int vds=vd.size();
    string pom1="",pom2="",pom3="";
    pom1.append(convertInt(vds).c_str());
    pom1.append(" / ");
    SetWindowText (hTekst2, pom1.c_str());
    //cout<<vds<<" plikow"<<endl;
    //float vdsl=0;
    for(int i=0; i<vds; i++)
    {
            GetData(vd[i]+vf[i]);
            T.push_back(WoExt(vf[i]));
            A.push_back(ad);
            L.push_back(vd[i]+'@'+vf[i]);
            K.push_back(kd);
            //cout<<'.';
            pom2="";
            pom2.append(convertInt(i+1).c_str());
            pom3=pom1+pom2;
            SetWindowText (hTekst2, pom3.c_str());
            SendMessage(hProgressBar, PBM_SETPOS, (WPARAM)(1000*(i+1))/vds, 0);
    }
    //cout<<"zapis..."<<endl;
    SetWindowText (hTekst2, "Zapis...");
    zapi();
    SetWindowText (hTekst2, "Zakonczono...");
    SendNotifyMessage(Dlg2,WM_CLOSE,0,0);
}
//end: (AWyp) funkcje uzupelniajace zasob

int IleUzupelnien()
{
    fstream f;
    int w;
    f.open("prop2",ios::in|ios::binary);
    f.read((char*)&w,sizeof(int));
    if(!f.good())
    {
        w=3;
        f.close();
        f.open("prop2",ios::out|ios::binary);
        f.write((char*)&w,sizeof(int));
        f.close();
    }
    f.close();
    return w;
}

void ZapiszIleUzupelnien(string s)
{
    //MessageBox(NULL,s.c_str(),"do zapisania",MB_OK);
    fstream f;
    int w;
    istringstream iss(s);
    iss >> w;
    f.open("prop2",ios::out|ios::binary);
    f.write((char*)&w,sizeof(int));
    f.close();
    //MessageBox(NULL,convertInt(w).c_str(),"zpisano",MB_OK);
}


















