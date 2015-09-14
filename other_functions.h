
void StatBarUpdt();
string SearchFilter=".";
void __cdecl ThreadProc1 (void* Args)
{
    //system("AWyp.exe < MyPath");//to musi byc jeszcze inaczej
    extr(101, "exiftool.exe");
    AWyp(SearchFilter);//ten argument mozna bedzie z kads wczytywac
    /*if(!ShellExecute(NULL, "open", "cmd", "/C del exiftool.exe", NULL, SW_HIDE))
    system("del exiftool.exe");*/
    extr(107, "UsDu.exe");
    if(!ShellExecute(NULL, "open", "UsDu.exe", NULL, NULL, SW_HIDE))
    system("UsDu.exe");
    /*if(!ShellExecute(NULL, "open", "cmd", "/C del UsDu.exe", NULL, SW_HIDE))
    system("del UsDu.exe");*/
    odcz();
    konw();
    ZapiszCzas();
    StatBarUpdt();
    //MessageBox(NULL,"koniec procesu 1","debug",MB_ICONHAND);
    _endthread();
}

void case14(HWND* hwnd);
void __cdecl ThreadProc2 (void* Args)
{
    //system("AWyp.exe < MyPath");//to musi byc jeszcze inaczej
    if(!ShellExecute(NULL, "open", "cmd", "/C AWyp < MyPath", NULL, SW_HIDE))
    MessageBox (MAINhwnd, "blad aktualizacji bazy danch", "error", MB_ICONERROR);
    else
    {
        odcz();
        konw();
        ZapiszCzas();
        StatBarUpdt();
        case14(&MAINhwnd);
    }
    _endthread();
}

void __cdecl ThreadProc3 (void* Args)
{
    DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DLG1), NULL, DlgProc2);
    _endthread();
}
//HANDLE hThread = (HANDLE) _beginthread (ThreadProc, 0, NULL);

#define ID_TRAY1   601
#define CMSG_TRAY1 0x8001
NOTIFYICONDATA nid;
void zrobTray(HWND*hwnd)
{
    ZeroMemory(&nid, sizeof(nid));
    string traylabel="TAK ver.";
    traylabel.append(AutoVersion::FULLVERSION_STRING);
    LPSTR sTip = (char*)traylabel.c_str();
    nid.cbSize = sizeof (NOTIFYICONDATA);
    nid.hWnd = *hwnd;
    nid.uID = ID_TRAY1;
    nid.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP|NIF_INFO;
    nid.uCallbackMessage = CMSG_TRAY1;
    nid.hIcon=LoadIcon(*hInst,"Ikona");
    lstrcpy(nid.szTip, sTip);
    Shell_NotifyIcon(NIM_ADD, &nid);
}

void usunTray()
{
    //ZeroMemory(&nid, sizeof(nid));
    /*nid.cbSize = sizeof (NOTIFYICONDATA);
      nid.hWnd = MAINhwnd;
      nid.uID = ID_TRAY1;
      nid.uFlags = 0;*/
    Shell_NotifyIcon (NIM_DELETE, &nid);
}

void pokazELog(UINT hiin)
{
     switch (hiin)
     {
            case NULL:
            MessageBox(NULL, "The operating system is out of memory or resources." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case ERROR_FILE_NOT_FOUND:
            MessageBox(NULL, "The specified file was not found." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case ERROR_PATH_NOT_FOUND:
            MessageBox(NULL, "The specified path was not found." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case ERROR_BAD_FORMAT:
            MessageBox(NULL, "The .exe file is invalid (non-Win32 .exe or error in .exe image)." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_ACCESSDENIED:
            MessageBox(NULL, "The operating system denied access to the specified file." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_ASSOCINCOMPLETE:
            MessageBox(NULL, "The file name association is incomplete or invalid." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_DDEBUSY:
            MessageBox(NULL, "The DDE transaction could not be completed because other DDE transactions were being processed." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_DDEFAIL:
            MessageBox(NULL, "The DDE transaction failed." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_DDETIMEOUT:
            MessageBox(NULL, "The DDE transaction could not be completed because the request timed out." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_DLLNOTFOUND:
            MessageBox(NULL, "The specified DLL was not found." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_NOASSOC:
            MessageBox(NULL, "There is no application associated with the given file name extension. This error will also be returned if you attempt to print a file that is not printable." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_OOM:
            MessageBox(NULL, "There was not enough memory to complete the operation." , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
            break;
            case SE_ERR_SHARE:
            MessageBox(NULL, "A sharing violation occurred." , ":(" ,MB_OK|MB_ICONERROR);
            break;
     }
}

/*void DelVCombo()
{
     for(unsigned int i=0; i<vcombo.size(); i++)
     GlobalFree(vcombo[i]);
     vcombo.clear();
}*/

/*void wypelnianiecomboboxa(int i)
{
     for(int f=0; f<ilspc(L[i]); f++)
     {
             Bufor = (LPSTR)GlobalAlloc(GPTR, (linknr(bezfil(L[i])+bezdir(L[i]), f)).size()+1);
             wsprintf(Bufor, "%s",nospcend(linknr(bezfil(L[i])+bezdir(L[i]), f)).c_str());
             SendMessage(hCombo1,CB_ADDSTRING, 0 ,(LPARAM) Bufor );
             GlobalFree(Bufor);
             vcombo.push_back((LPSTR)GlobalAlloc(GPTR, (linknr(bezfil(L[i])+bezdir(L[i]), f)).size()+1));
             wsprintf(vcombo[vcombo.size()-1], "%s",nospcend(linknr(bezfil(L[i])+bezdir(L[i]), f)).c_str());
     }
}*/

void StatBarUpdt()
{
    string statusBarStr1="last DBupdate:";
    statusBarStr1.append(PodajCzas().c_str());
    SendMessage (hStatusBar, SB_SETTEXT, /*1*/0, (LPARAM)statusBarStr1.c_str());
}

vector<HWND> vHWND;
vector<pair<string,int> > vLabels;
HWND hBut0;
int MaxLength;
int MaxLabelSize(int a,int b,int c)
{
    if(a>=b && a>=c) if(a>20) return a;
    if(b>=a && b>=c) if(b>20) return b;
    if(c>=a && c>=b) if(c>20) return c;
    return 20;
}

int wysokosc;
vector<int> vToDisp;
void createbuttons(HWND* hwnd)
{
    int n=vToDisp.size();
    wysokosc=20;
    int pom_wys;
    string pom_str="";
    vHWND.clear();
    vLabels.clear();
    MaxLength=60;
    string lstr1="napis nr:\r\n",lstr2="Total of: ",lstr3="\r\n";
    lstr2.append(convertInt(vToDisp.size()));
    hBut0=CreateWindowEx(WS_EX_TOPMOST,WC_EDIT, lstr2.c_str(), WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_AUTOHSCROLL|ES_AUTOVSCROLL|ES_READONLY,0,0,100,20,*hwnd, 0, *hInst, 0);
    vHWND.push_back(hBut0);
    for(int j=0,i=0;j<n;j++)
    {
        i=vToDisp[j];
        pom_str=(A[i].empty()||A[i]==" ")?T[i]:(T[i]+lstr3+A[i]);
        vLabels.push_back(make_pair(pom_str,MaxLabelSize(T[i].size(),A[i].size(),K[i].size())));
        if(vLabels[j].second*11>MaxLength)
        MaxLength=vLabels[j].second*11;
        pom_wys=40-10*(int)(A[i].empty()||A[i]==" ");
        hBut0=CreateWindowEx( 0 ,WC_BUTTON, vLabels[j].first.c_str(),WS_CHILD|WS_VISIBLE|BS_MULTILINE|BS_LEFT, 0 , wysokosc , vLabels[j].second*11-40 , pom_wys ,*hwnd,(HMENU)(i+1) ,*hInst, 0 );
        vHWND.push_back(hBut0);
        wysokosc+=pom_wys;
    }
}

int ButtonNumber(HWND B_hwnd)
{
    for(unsigned int i=1;i<vHWND.size();i++)
    if(vHWND[i]==B_hwnd)
    return i;
    return -1;
}

int global_pom1;
void Uzupelnianie()
{
    if(T.empty())
    return;
    int x;
    srand (time(NULL));
    x=rand()%T.size();
    if(T[x].empty()||A[x].empty()||K[x].empty())
    {
        global_pom1=x;
        DialogBoxParam (GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_EDITDLG), MAINhwnd, EditDlgProc, (LPARAM)x);
    }
    else
    for(unsigned int i=0;i<T.size();i++)
    if(T[i].empty()||A[i].empty()||K[i].empty())
    {
        global_pom1=i;
        DialogBoxParam (GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_EDITDLG), MAINhwnd, EditDlgProc, (LPARAM)i);
        break;
    }
}


