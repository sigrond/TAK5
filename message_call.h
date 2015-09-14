string str="", str2="";
int ret;

void case12(HWND* hwnd);
CHAR szClassName2[]="MyInnerWindowClass";
void WMcreateProc(HWND* hwnd2)//case WM_CREATE:
{
    odcz();
    hButton1=CreateWindowEx( 0 ,WC_BUTTON, "Dodaj" ,WS_CHILD|WS_VISIBLE|WS_TABSTOP, 5 , 75 , 60 , 20 ,*hwnd2,(HMENU) 1 ,*hInst, 0 );
    //hButton4=CreateWindowEx( 0 ,WC_BUTTON, "Edytuj" ,WS_CHILD|WS_VISIBLE|WS_TABSTOP, 60 , 75 , 60 , 20 ,*hwnd2,(HMENU) 4 ,*hInst, 0 );
    //hButton2=CreateWindowEx( 0 ,WC_BUTTON, "Otworz" ,WS_CHILD|WS_VISIBLE|WS_TABSTOP, 120 , 75 , 60 , 20 ,*hwnd2,(HMENU) 2 ,*hInst, 0 );
    hButton3=CreateWindowEx( 0 ,WC_BUTTON, "Znajdz" ,WS_CHILD|WS_VISIBLE|WS_TABSTOP, 70 , 75 , 60 , 20 ,*hwnd2,(HMENU) 3 ,*hInst, 0 );
    hEdit1=CreateWindowEx(WS_EX_CLIENTEDGE,WC_EDIT, "" ,WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_TABSTOP|ES_MULTILINE|ES_AUTOVSCROLL, 63 , 0 , 170 , 20 ,*hwnd2, 0 ,*hInst, 0 );
    hEdit6=CreateWindowEx(0,WC_EDIT, "Tytul\r\nAutorzy\r\ns.Klucz.", WS_CHILD|WS_VISIBLE|ES_READONLY|ES_MULTILINE,0,10,60,55,*hwnd2, 0, *hInst, 0);
    hEdit2=CreateWindowEx(WS_EX_CLIENTEDGE,WC_EDIT, "" ,WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_TABSTOP|ES_MULTILINE|ES_AUTOVSCROLL, 63 , 25 , 170 , 20 ,*hwnd2, 0 ,*hInst, 0 );
    hEdit4=CreateWindowEx(WS_EX_CLIENTEDGE,WC_EDIT, "" ,WS_CHILD|WS_VISIBLE|ES_AUTOHSCROLL|WS_TABSTOP|ES_MULTILINE|ES_AUTOVSCROLL, 63 , 50 , 170 , 20 ,*hwnd2, 0 ,*hInst, 0 );
    //hEdit5=CreateWindowEx(WS_EX_CLIENTEDGE|WS_EX_TOPMOST,WC_EDIT, "ekran opisu" ,WS_CHILD|WS_VISIBLE|ES_MULTILINE|ES_AUTOHSCROLL|ES_AUTOVSCROLL|WS_VSCROLL|WS_HSCROLL|ES_READONLY|WS_THICKFRAME|WS_CAPTION|WS_OVERLAPPEDWINDOW, 0 , 125 , 232 , 193 ,*hwnd2, 0 ,*hInst, 0 );
    //ShowWindow(hEdit5,SW_HIDE);
//////////////////////////////////////////////
    WNDCLASSEX myWC;
    myWC.cbSize=sizeof(WNDCLASSEX);
    myWC.style=CS_DBLCLKS|CS_HREDRAW|CS_VREDRAW;
    myWC.lpfnWndProc=MyWndProc;
    myWC.cbClsExtra=0;
    myWC.cbWndExtra=0;
    myWC.hInstance=*hInst;
    myWC.hIcon=NULL;
    myWC.hCursor=NULL;
    myWC.hbrBackground=(HBRUSH)COLOR_BACKGROUND;
    myWC.lpszMenuName=NULL;
    myWC.lpszClassName=szClassName2;
    myWC.hIconSm=NULL;
    if(!RegisterClassEx(&myWC))MessageBox(*hwnd2,"blad rejestracji klasy okna",":(",MB_OK);
/////////////////////////////////////////////////
    //hCombo1=CreateWindowEx(WS_EX_CLIENTEDGE ,WC_COMBOBOX, "hCombo1" ,WS_CHILD|WS_VISIBLE|CBS_DROPDOWNLIST, 0 , 98 , 235 , 201 ,*hwnd2, 0 ,*hInst, 0 );
    //hFont=CreateFont(0,0,0,0,0,0,0,0,0,0,0,0,0,"Arial");
    //SendMessage(hEdit5,WM_SETFONT,(WPARAM)hFont,0);
    //SendMessage(hCombo1,CB_SETDROPPEDWIDTH, 1024 ,0 );
    //SendMessage(hCombo1,CB_RESETCONTENT, 0 ,0 );
    //DelVCombo();
    case12(hwnd2);
    FiLoPa();
    //extr(101, "exiftool.exe");
    //extr(103, "AWyp.exe");
    //extr(105, "SetPath.exe");
    //extr(107, "UsDu.exe");
    //extr(111, "TAKinfo.exe");
    INITCOMMONCONTROLSEX icc;
    icc.dwSize = sizeof (INITCOMMONCONTROLSEX);
    icc.dwICC = ICC_BAR_CLASSES; // toolbary, statusbary i tooltipy
    InitCommonControlsEx (&icc);
    hStatusBar = CreateWindowEx (0,STATUSCLASSNAME,NULL,SBARS_SIZEGRIP | WS_CHILD
    | WS_VISIBLE, 0, 0, 0, 0, *hwnd2, (HMENU)200, *hInst, NULL);
    int statusBarWidths[] = {/*20,*/-1};
    SendMessage (hStatusBar, SB_SETPARTS, /*2*/1, (LPARAM)statusBarWidths);
    StatBarUpdt();
    zrobTray(hwnd2);
    int lpom1=IleUzupelnien();
    for(int i=0;i<lpom1;i++)
    Uzupelnianie();
}

void WMsizeProc(HWND* hwnd)//case WM_SIZE:
{
    GetWindowRect(*hwnd,&lpRect1);
    //GetWindowRect(hEdit5,&lpRect2);//hEdit 1,2,4
    //MoveWindow(hEdit5,0,125,lpRect1.right-lpRect1.left-5,lpRect1.bottom-lpRect1.top-188,1);
    //ShowWindow(hEdit5,SW_SHOW);
    GetWindowRect(hEdit1,&lpRect2);
    MoveWindow(hEdit1,63,0,lpRect1.right-lpRect1.left-65,20,1);
    ShowWindow(hEdit1,SW_SHOW);
    GetWindowRect(hEdit2,&lpRect2);
    MoveWindow(hEdit2,63,25,lpRect1.right-lpRect1.left-65,20,1);
    ShowWindow(hEdit2,SW_SHOW);
    GetWindowRect(hEdit4,&lpRect2);
    MoveWindow(hEdit4,63,50,lpRect1.right-lpRect1.left-65,20,1);
    ShowWindow(hEdit4,SW_SHOW);
    //GetWindowRect(hCombo1,&lpRect2);
    //MoveWindow(hCombo1,0,98,lpRect1.right-lpRect1.left-6,lpRect1.bottom-lpRect1.top-160,1);
    //ShowWindow(hCombo1,SW_SHOW);
    SendMessage (hStatusBar, WM_SIZE, 0, 0);
    /////////////////////////////////////
    GetWindowRect(hEdit7,&lpRect2);//hEdit 1,2,4
    MoveWindow(hEdit7,0,98,lpRect1.right-lpRect1.left-5,lpRect1.bottom-lpRect1.top-161,1);
    ShowWindow(hEdit7,SW_SHOW);
}

void case11(HWND* hwnd)//Ustaw folder przeszukiwany
{
    char szFile1[MAX_PATH];
    BROWSEINFO bi;
    memset(&bi, 0, sizeof(BROWSEINFO));
    bi.hwndOwner = *hwnd;
    bi.pszDisplayName = szFile1;
    bi.lpszTitle = (char*)start.c_str();
    ITEMIDLIST *pItem = SHBrowseForFolder(&bi);
    if(pItem)
    SHGetPathFromIDList(pItem, szFile1);
    else
    {
        MessageBox(*hwnd, "cos poszlo nie tak, sciezka nie zmieniona" , ":(" ,MB_OK|MB_ICONERROR|MB_APPLMODAL);
        return;
    }
    fstream f;
    string s;
    s=(string)szFile1;
    f.open("MyPath", ios::out);
    s.append("\\");
    f<<s;
    f.close();
    FiLoPa();
}

void case12(HWND* hwnd)//Wyswietl wszystkie pliki
{
    vToDisp.clear();
    for(unsigned int i=0;i<T.size();i++)vToDisp.push_back(i);
    DestroyWindow(hEdit7);
    hEdit7=CreateWindowEx(WS_EX_CLIENTEDGE,szClassName2,"lista",WS_CHILD|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|WS_OVERLAPPEDWINDOW,0,125,232,193,*hwnd,NULL,*hInst,NULL);
    WMsizeProc(hwnd);
    //SendMessage(hCombo1,CB_RESETCONTENT, 0 ,0 );
    //DelVCombo();
    /*str="Total of: ";
    str.append(convertInt(T.size()));
    str.append("\r\n");*/
    /*for(unsigned int i=0; i<T.size(); i++)
    {
        str.append(T[i]);
        str.append("\r\n");
        str.append(A[i]);
        str.append("\r\n");
        str.append(K[i]);
        str.append("\r\n");
        wypelnianiecomboboxa(i);
    }*/
    //SetWindowText(hEdit5, (LPCTSTR)str.c_str());
}

void case13(HWND* hwnd)//Wypelnij liste
{
    hThread1 = (HANDLE) _beginthread (ThreadProc1, 0, NULL);
}

void case14(HWND* hwnd)//Usun duplikaty
{
    system("UsDu.exe");
    odcz();
    konw();
}

void podaj_info(HWND* hwnd)//info
{
    string info_str="Build date:\r\n",s="";
    info_str.append(AutoVersion::DATE);
    info_str.append(".");
    info_str.append(AutoVersion::MONTH);
    info_str.append(".");
    info_str.append(AutoVersion::YEAR);
    info_str.append("\r\n\r\nStatus:\r\n");
    info_str.append(AutoVersion::STATUS);
    info_str.append("\r\n\r\nVersion:\r\n");
    info_str.append(AutoVersion::FULLVERSION_STRING);
    info_str.append("\r\n\r\nDirectory path:\r\n");
    fstream f;
	f.open("MyPath");
	getline(f,s);
	info_str.append(s);
	f.close();
	info_str.append("\r\n\r\nApplication by Sigrond\r\nE-mail: sigrond93@gmail.com");
    //system(info_str.c_str());
    //int ret = DialogBox (/*GetModuleHandle(NULL)*/hInst, MAKEINTRESOURCE(200), *hwnd, DlgProc);
    DialogBoxParam (GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_MOJDIALOG), *hwnd, DlgProc, (LPARAM)info_str.c_str());

}

void case1(HWND* hwnd)//dodaj
{
    dlugosc=GetWindowTextLength(hEdit1);
    lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc+1);
    GetWindowText(hEdit1,lpStr,dlugosc+1);
    str=lpStr;
    GlobalFree(lpStr);
    str=UsunZnakiZakazane(usbizn(str));
    T.push_back(str);
    dlugosc=GetWindowTextLength(hEdit2);
    lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc+1);
    GetWindowText(hEdit2,lpStr,dlugosc+1);
    str=lpStr;
    GlobalFree(lpStr);
    str=UsunZnakiZakazane(usbizn(str));
    A.push_back(str);
    str="";
    L.push_back(str);
    dlugosc=GetWindowTextLength(hEdit4);
    lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc+1);
    GetWindowText(hEdit4,lpStr,dlugosc+1);
    str=lpStr;
    GlobalFree(lpStr);
    str=UsunZnakiZakazane(usbizn(str));
    K.push_back(str);
    zapi();
    konw();
    MessageBox(*hwnd, "Aby zapisc polozenie pliku upewnij sie, ze plik znajduje sie w \"Ustawionym folderze przeszukiwanym\",\r\na nastepnie kliknij znajdz." , ":>" ,MB_OK|MB_ICONINFORMATION|MB_APPLMODAL);
}

/*void case2(HWND* hwnd)//otworz
{
    numer = ComboBox_GetCurSel(hCombo1);
    if(numer!=CB_ERR)
    {
        ShExELog=ShellExecute(NULL, "open", (LPCSTR)vcombo[numer], NULL, NULL, SW_SHOWMAXIMIZED|SW_HIDE);
        pokazELog((UINT)ShExELog);//do³¹czy³em i magicznie wszystko zacze³o dzia³aæ !!! aaaargh !!!
        ShowWindow(*hwnd,SW_MINIMIZE);
    }
}*/

void case3(HWND* hwnd)//znajdz
{
    vToDisp.clear();
    //SendMessage(hCombo1,CB_RESETCONTENT, 0 ,0 );
    //DelVCombo();
    dlugosc=GetWindowTextLength(hEdit1);
    lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc+1);
    GetWindowText(hEdit1,lpStr,dlugosc+1);
    str2=lpStr;
    GlobalFree(lpStr);
    str="";
    if(str2.size()>0)//wyszukaj tytul
    {
        for(unsigned int i=0; i<T.size(); i++)
        {
            if(ignoreStrshift(T[i]).find(ignoreStrshift(str2))!=string::npos)
            {
                /*str.append(T[i]);
                str.append("\r\n");
                str.append(A[i]);
                str.append("\r\n");
                str.append(K[i]);
                str.append("\r\n");*/
                if(L[i]!="")
                {
                    ;//wypelnianiecomboboxa(i);
                }
                else
                {
                    WyszukajIWypisz(T[i], start);
                    for(unsigned int iv=0; iv<vd.size(); iv++)
                    {
                        /*str+=(char)48+iv;
                        str+=(char)46;
                        str+=(char)32;
                        str.append(vf[iv]);*/
                        if(iv>0)
                        L[i]+=(char)32;
                        L[i].append(vd[iv]);
                        L[i]+='@';
                        L[i].append(vf[iv]);
                        //str.append("\r\n");
                    }
                    //wypelnianiecomboboxa(i);
                    zapi();
                    konw();
                }
                //str+=(char)13;
                //str+=(char)10;
                vToDisp.push_back(i);
            }
        }
        /*Bufor = (LPSTR)GlobalAlloc(GPTR, str.size()+1);
        wsprintf(Bufor, "%s",str.c_str());
        SetWindowText(hEdit5, Bufor);
        GlobalFree(Bufor);*/
        //SetWindowText(hEdit5, (LPCTSTR)str.c_str());
    }
    else if(str2.size()==0)//tytul nie podany
    {
        dlugosc=GetWindowTextLength(hEdit2);
        lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc+1);
        GetWindowText(hEdit2,lpStr,dlugosc+1);
        str2=lpStr;
        GlobalFree(lpStr);
        str="";
        if(str2.size()>0)//wyszukaj autora
        {
            for(unsigned int i=0; i<A.size(); i++)
            {
                if(ignoreStrshift(A[i]).find(ignoreStrshift(str2))!=string::npos)
                {
                    /*str.append(T[i]);
                    str.append("\r\n");
                    str.append(A[i]);
                    str.append("\r\n");
                    str.append(K[i]);
                    str.append("\r\n");*/
                    if(L[i]!="")
                    {
                        //str.append(bezdir(L[i]));
                        //str.append("\r\n");
                        ;//wypelnianiecomboboxa(i);
                    }
                    else
                    {
                        WyszukajIWypisz(T[i], start);
                        for(unsigned int iv=0; iv<vd.size(); iv++)
                        {
                            /*str+=(char)48+iv;
                            str+=(char)46;
                            str+=(char)32;
                            str.append(vf[iv]);*/
                            if(iv>0)
                            L[i]+=(char)32;
                            L[i].append(vd[iv]);
                            L[i]+='@';
                            L[i].append(vf[iv]);
                            //str.append("\r\n");
                        }
                        //wypelnianiecomboboxa(i);
                        zapi();
                        konw();
                    }
                    //str.append("\r\n");
                    vToDisp.push_back(i);
                }
            }
            /*Bufor = (LPSTR)GlobalAlloc(GPTR, str.size()+1);
            wsprintf(Bufor, "%s",str.c_str());
            SetWindowText(hEdit5, Bufor);
            GlobalFree(Bufor);*/
            //SetWindowText(hEdit5, (LPCTSTR)str.c_str());
        }
        else if(str2.size()==0)//brak tytulu i autora
        {
            dlugosc=GetWindowTextLength(hEdit4);
            lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc+1);
            GetWindowText(hEdit4,lpStr,dlugosc+1);
            str2=lpStr;
            GlobalFree(lpStr);
            str="";
            if(str2.size()>0)//wyszukaj slowa kluczowe
            {
                for(unsigned int i=0; i<K.size(); i++)
                {
                    if(ignoreStrshift(K[i]).find(ignoreStrshift(str2))!=string::npos)
                    {
                        /*str.append(T[i]);
                        str.append("\r\n");
                        str.append(A[i]);
                        str.append("\r\n");
                        str.append(K[i]);
                        str.append("\r\n");*/
                        if(L[i]!="")
                        {
                            //str.append(bezdir(L[i]));
                            //str.append("\r\n");
                            ;//wypelnianiecomboboxa(i);
                        }
                        else
                        {
                            vd.clear();
                            vf.clear();
                            WyszukajIWypisz(T[i], start);
                            for(unsigned int iv=0; iv<vd.size(); iv++)
                            {
                                /*str+=(char)48+iv;
                                str+=(char)46;
                                str+=(char)32;
                                str.append(vf[iv]);*/
                                if(iv>0)
                                L[i]+=(char)32;
                                L[i].append(vd[iv]);
                                L[i]+='@';
                                L[i].append(vf[iv]);
                                //str.append("\r\n");
                            }
                            //wypelnianiecomboboxa(i);
                            zapi();
                            konw();
                        }
                        //str.append("\r\n");
                        vToDisp.push_back(i);
                    }
                }
                /*Bufor = (LPSTR)GlobalAlloc(GPTR, str.size()+1);
                wsprintf(Bufor, "%s",str.c_str());
                SetWindowText(hEdit5, Bufor);
                GlobalFree(Bufor);*/
                //SetWindowText(hEdit5, (LPCTSTR)str.c_str());
            }
            else
            {
                //SetWindowText(hEdit5, "Nie powiodlo sie! Nie podales zadnych danych.");
            }
        }
    }
    DestroyWindow(hEdit7);
    hEdit7=CreateWindowEx(WS_EX_CLIENTEDGE,szClassName2,"znalezione",WS_CHILD|WS_VISIBLE|WS_VSCROLL|WS_HSCROLL|WS_OVERLAPPEDWINDOW,0,125,232,193,*hwnd,NULL,*hInst,NULL);
    WMsizeProc(hwnd);
}

/*void case4(HWND* hwnd)//edytuj
{
    numer = ComboBox_GetCurSel(hCombo1);
    if(numer!=CB_ERR)
    DialogBoxParam (GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_EDITDLG), MAINhwnd, EditDlgProc, (LPARAM)numer);
}*/
