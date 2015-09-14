#define NIIF_NONE 0x00000000
#define NIIF_INFO 0x00000001
#define NIIF_WARNING 0x00000002
#define NIIF_ERROR 0x00000003
#define NIIF_USER 0x00000004
#define NIIF_NOSOUND 0x00000010
#define NIIF_LARGE_ICON 0x00000020
#define NIIF_RESPECT_QUIET_TIME 0x00000080

#define NIF_INFO 0x00000010

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<cstdlib>
#include<sstream>
#include<sys/stat.h>
#include<dirent.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<ctime>

#define WINVER 0x500
#define _WIN_IE 0x600
#define _WIN32_IE 0x600
#include<windows.h>
#include<commctrl.h>
#include<Windowsx.h>
#include<process.h>
#include <shlobj.h>
#include "version.h"

using namespace std;

vector<string> T;
vector<string> A;
vector<string> L;
vector<string> K;
vector<LPSTR> vcombo;

#ifndef IDD_MOJDIALOG
#define IDD_MOJDIALOG 200
#endif
#ifndef IDC_LABEL
#define IDC_LABEL 201
#endif
#ifndef IDD_DLG1
#define IDD_DLG1 202
#endif
#ifndef IDC_PGB1
#define IDC_PGB1 203
#endif
#ifndef IDC_LABEL2
#define IDC_LABEL2 204
#endif
#ifndef IDD_EDITDLG
#define IDD_EDITDLG 205
#endif
#ifndef IDC_EDIT_T
#define IDC_EDIT_T 206
#endif
#ifndef IDC_EDIT_A
#define IDC_EDIT_A 207
#endif
#ifndef IDC_EDIT_K
#define IDC_EDIT_K 208
#endif
#ifndef IDC_EDIT_L
#define IDC_EDIT_L 209
#endif
#ifndef IDD_PROP
#define IDD_PROP 214
#endif
#ifndef IDC_EDIT_O1
#define IDC_EDIT_O1 215
#endif
#ifndef IDC_EDIT_O2
#define IDC_EDIT_O2 216
#endif

BOOL CALLBACK DlgProc2 (HWND,UINT,WPARAM,LPARAM);


bool pcag=false, kct=false, kc=false;
string pomocstr;
int ilzn=0, k, numer;
HWND MAINhwnd, hButton1, hButton2, hButton3,hButton4, hEdit1, hEdit2, hEdit3, hEdit4, hEdit5, hEdit6,hEdit7, hCombo1, hStatusBar,hProgressBar,hTekst2,Dlg2,hTekstT,hTekstA,hTekstK,hTekstL;
RECT rect;
RECT lpRect1,lpRect2,lpRect3;
LPSTR lpStr;
LPSTR Bufor;
LPCSTR lpcStr1;
HFONT hFont;
HDC hdc;
DWORD dlugosc;
HINSTANCE ShExELog;
HINSTANCE* hInst;
CHAR szClassName[]="OknoRodzica";

#include "subtitles.h"
#include "string_operations.h"
#include "file_operations.h"
BOOL CALLBACK EditDlgProc (HWND,UINT,WPARAM,LPARAM);
#include "other_functions.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
LRESULT CALLBACK MyWndProc(HWND,UINT,WPARAM,LPARAM);
BOOL CALLBACK DlgProc (HWND,UINT,WPARAM,LPARAM);
BOOL CALLBACK PropDlgProc (HWND,UINT,WPARAM,LPARAM);


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR lpCmd,int nShow)
{
    hInst=&hInstance;
    WNDCLASSEX wc;
    wc.hInstance=*hInst;
    wc.lpszClassName=szClassName;
    wc.lpfnWndProc=WndProc;
    wc.style=CS_BYTEALIGNCLIENT | CS_BYTEALIGNWINDOW | CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
    wc.cbSize=sizeof(WNDCLASSEX);
    wc.hIcon=LoadIcon(hInstance,"Ikona");
    wc.hIconSm=LoadIcon(hInstance,"Ikona");
    wc.hCursor=LoadCursor(NULL,IDC_ARROW);
    wc.lpszMenuName="Menuopcje";
    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.hbrBackground=(HBRUSH)COLOR_BACKGROUND;
    if(!RegisterClassEx(&wc)) return 0;
    MAINhwnd=CreateWindowEx(/*WS_EX_TOPMOST |*/ WS_EX_ACCEPTFILES | WS_EX_CONTROLPARENT,
    szClassName,"TAK", WS_VISIBLE | WS_THICKFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
    GetSystemMetrics(SM_CXSCREEN)-257,GetSystemMetrics(SM_CYSCREEN)-420,241,390,NULL,NULL,hInstance,NULL);
    ShowWindow(MAINhwnd,nShow);
    MSG msg;
    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

#include "message_call.h"

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)//procedura okna glownego
{
    switch(msg)
    {
        case WM_CREATE:
        WMcreateProc(&hwnd);
        break;
        case WM_SIZE:
        WMsizeProc(&hwnd);
        break;
        case WM_COMMAND:
        switch(wParam)
        {
            case 11://Ustaw folder przeszukiwany
            case11(&hwnd);
            break;
            case 12://Wyswietl wszystkie pliki
            case12(&hwnd);
            break;
            case 13://Wypelnij liste
            case13(&hwnd);
            break;
            case 14://Usun duplikaty
            case14(&hwnd);
            break;
            case 15://Info
            podaj_info(&hwnd);
            break;
            case 18:
            MessageBox(hwnd,"TODO:\r\nPoswiec chwile, zeby uzupelnic dane o plikach.","i wywolujemy edycje wpisow",MB_OK);
            break;
            case 20:
            if(remove("zasob")!=0)
            MessageBox(hwnd,"usuniecie pliku zasob zakonczone bledem",":(",MB_OK);
            break;
            case 21:
            DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_PROP), hwnd, PropDlgProc);
            break;
            case 1://dodaj
            case1(&hwnd);
            break;
            /*case 2://otworz
            case2(&hwnd);
            break;*/
            case 3://znajdz
            case3(&hwnd);
            break;
            /*case 4:
            case4(&hwnd);
            break;*/
            /*case 20:
            DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DLG1), NULL, DlgProc2);
            break;*/
    }
    //if(wParam==CBN_DROPDOWN)
    //BOOL GetWindowRect(HWND hWnd,RECT* lpRect);
    //BOOL MoveWindow(HWND hWnd,int X,int Y,int nWidth,int nHeight,BOOL Repaint);
    //else
    //
    break;
    case CMSG_TRAY1:
    {
        Shell_NotifyIcon(NIM_MODIFY, &nid);
     if (wParam == ID_TRAY1)
     if (lParam == WM_LBUTTONDOWN)
     ShowWindow (hwnd, SW_SHOW);
    }
break;
    case WM_DESTROY:
    /*ShowWindow(MAINhwnd,SW_HIDE);
    WaitForSingleObject( hThread1, INFINITE );
    WaitForSingleObject( hThread2, INFINITE );
    ShowWindow(MAINhwnd,SW_SHOW);*/
    usunTray();
    //DelVCombo();
    DestroyWindow(hButton1);
    DestroyWindow(hButton2);
    DestroyWindow(hButton3);
    DestroyWindow(hEdit1);
    DestroyWindow(hEdit2);
    DestroyWindow(hStatusBar);
    DestroyWindow(hEdit4);
    DestroyWindow(hEdit5);
    DestroyWindow(hEdit6);
    DestroyWindow(hCombo1);
    if(remove("exiftool.exe")!=0)
    if(!ShellExecute(NULL, "open", "cmd", "/C del exiftool.exe", NULL, SW_HIDE))
    system("del exiftool.exe");
    /*if(!ShellExecute(NULL, "open", "cmd", "/C del AWyp.exe", NULL, SW_HIDE))
    system("del AWyp.exe");*/
    //system("del SetPath.exe");
    if(remove("UsDu.exe")!=0)
    if(!ShellExecute(NULL, "open", "cmd", "/C del UsDu.exe", NULL, SW_HIDE))
    system("del UsDu.exe");
    if(remove("Dat")!=0)
    if(!ShellExecute(NULL, "open", "cmd", "/C del Dat", NULL, SW_HIDE))
    system("del Dat");
    //system("del TAKinfo.exe");
    PostQuitMessage(0);
    break;
    default:
    //zrobTray();
    return DefWindowProc(hwnd,msg,wParam,lParam);
  }
  ShowWindow(hEdit5,SW_SHOW);
  return 0;
}
BOOL CALLBACK DlgProc (HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)//okienko informacyne
{
    switch (Msg)
    {
        case WM_INITDIALOG:
        {
            HWND hTekst = GetDlgItem (hwnd, IDC_LABEL);
            SetWindowText (hTekst, (char*)lParam);
        }
        break;
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK: EndDialog (hwnd, IDOK); break;
                case IDCANCEL: EndDialog (hwnd, IDCANCEL); break;
            }
        }
        break;

        default: return FALSE;
    }

    return TRUE;
}

BOOL CALLBACK DlgProc2 (HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)//pasek postepu ladowania
{
    switch (Msg)
    {
        case WM_INITDIALOG:
        {
            Dlg2=hwnd;
            hTekst2 = GetDlgItem (hwnd, IDC_LABEL2);
            SetWindowText (hTekst2, "Czekaj. Wyszukiwanie plikow...");
            hProgressBar = GetDlgItem (hwnd, IDC_PGB1);
            SendMessage(hProgressBar, PBM_SETRANGE, 0, (LPARAM)MAKELONG(0,1000));
        }
        break;
        /*case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK: EndDialog (hwnd, IDOK); break;
                case IDCANCEL: EndDialog (hwnd, IDCANCEL); break;
            }
        }*/
        break;
        case WM_CLOSE:
        //case WM_DESTROY:
        EndDialog (hwnd, IDOK);
        break;

        default: return FALSE;
    }

    return TRUE;
}
int pozycja, pozycjaH;
int dy,dx;
LRESULT CALLBACK MyWndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)//procedura wlasnego okna wenetrznego
{
    ostringstream ss;
    SCROLLINFO si;
    switch(msg)
    {
        case WM_CREATE:
        createbuttons(&hwnd);
        ZeroMemory( & si, sizeof( si ) );
        si.cbSize = sizeof( SCROLLINFO );
        si.fMask = SIF_ALL;
        si.nPos = 0;
        si.nMin=0;
        si.nMax=wysokosc;
        GetWindowRect(hEdit5,&lpRect2);
        si.nPage=lpRect2.bottom-lpRect2.top;
        SetScrollInfo( hwnd, SB_VERT, & si, TRUE );
        ScrollWindowEx( hwnd, 0, 1,( CONST RECT * ) NULL,( CONST RECT * ) NULL,( HRGN ) NULL,( LPRECT ) NULL, SW_SCROLLCHILDREN | SW_INVALIDATE | SW_ERASE );
        UpdateWindow( hwnd );
        break;
        case WM_VSCROLL:
        ZeroMemory( & si, sizeof( si ) );
        si.cbSize = sizeof( SCROLLINFO );
        si.fMask = SIF_ALL;
        GetScrollInfo( hwnd, SB_VERT, & si );
        pozycja = si.nPos;
        switch(LOWORD(wParam))
        {
            case SB_TOP:
            pozycja = si.nMin;
            break;
            case SB_BOTTOM:
            pozycja = si.nMax;
            break;
            case SB_LINEUP:
            pozycja-=10;
            break;
            case SB_LINEDOWN:
            pozycja+=10;
            break;
            case SB_PAGEUP:
            pozycja -= si.nPage;
            break;
            case SB_PAGEDOWN:
            pozycja += si.nPage;
            break;
            case SB_THUMBPOSITION:
            pozycja = si.nTrackPos;
            break;
            case SB_THUMBTRACK:
            pozycja = si.nTrackPos;
            break;
        }
        if(pozycja<si.nMin)
        pozycja=si.nMin;
        if(pozycja>si.nMax)
        pozycja=si.nMax;
        dy = si.nPos - pozycja;
        ScrollWindowEx( hwnd, 0, dy,( CONST RECT * ) NULL,( CONST RECT * ) NULL,( HRGN ) NULL,( LPRECT ) NULL, SW_SCROLLCHILDREN | SW_INVALIDATE | SW_ERASE );
        UpdateWindow( hwnd );
        ZeroMemory( & si, sizeof( si ) );
        si.cbSize = sizeof( SCROLLINFO );
        si.fMask = SIF_ALL;
        si.nPos = pozycja;
        si.nMin=0;
        si.nMax=wysokosc;
        GetWindowRect(hEdit5,&lpRect2);
        si.nPage=lpRect2.bottom-lpRect2.top;
        SetScrollInfo( hwnd, SB_VERT, & si, TRUE );
        break;
        case WM_HSCROLL:
        ZeroMemory( & si, sizeof( si ) );
        si.cbSize = sizeof( SCROLLINFO );
        si.fMask = SIF_ALL;
        GetScrollInfo( hwnd, SB_HORZ, & si );
        pozycjaH = si.nPos;
        switch(LOWORD(wParam))
        {
            case SB_LEFT:
            pozycjaH = si.nMin;
            break;
            case SB_RIGHT:
            pozycjaH = si.nMax;
            break;
            case SB_LINELEFT:
            pozycjaH-=10;
            break;
            case SB_LINERIGHT:
            pozycjaH+=10;
            break;
            case SB_PAGELEFT:
            pozycjaH -= si.nPage;
            break;
            case SB_PAGERIGHT:
            pozycjaH += si.nPage;
            break;
            case SB_THUMBPOSITION:
            pozycjaH = si.nTrackPos;
            break;
            case SB_THUMBTRACK:
            pozycjaH = si.nTrackPos;
            break;
        }
        if(pozycjaH<si.nMin)
        pozycjaH=si.nMin;
        if(pozycjaH>si.nMax)
        pozycjaH=si.nMax;
        dx = si.nPos - pozycjaH;
        ScrollWindowEx( hwnd, dx, 0,( CONST RECT * ) NULL,( CONST RECT * ) NULL,( HRGN ) NULL,( LPRECT ) NULL, SW_SCROLLCHILDREN | SW_INVALIDATE | SW_ERASE );
        UpdateWindow( hwnd );
        ZeroMemory( & si, sizeof( si ) );
        si.cbSize = sizeof( SCROLLINFO );
        si.fMask = SIF_ALL;
        si.nPos = pozycjaH;
        si.nMin=0;
        si.nMax=MaxLength;
        GetWindowRect(hEdit5,&lpRect2);
        si.nPage=lpRect2.right-lpRect2.left;
        SetScrollInfo( hwnd, SB_HORZ, & si, TRUE );
        break;
        case WM_COMMAND:
        if(wParam>0)
        {
            ShExELog=ShellExecute(NULL, "open", usat(L[vToDisp[wParam-1]]).c_str()/*(LPCSTR)vcombo[wParam-1]*/, NULL, NULL, SW_SHOWMAXIMIZED|SW_HIDE);
            pokazELog((UINT)ShExELog);
        }
        break;
        case WM_CONTEXTMENU:
        if(ButtonNumber((HWND)wParam)>=0)//MessageBox(hwnd,usat(L[ButtonNumber((HWND)wParam)-1]).c_str(),"R-clik",MB_OK);
        {
            global_pom1=vToDisp[ButtonNumber((HWND)wParam)-1];
            DialogBoxParam (GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_EDITDLG), MAINhwnd, EditDlgProc, (LPARAM)(vToDisp[ButtonNumber((HWND)wParam)-1]));
        }
        break;
        default:
        return DefWindowProc(hwnd,msg,wParam,lParam);
    }
    return 0;
}

int nr_edytowanego;
BOOL CALLBACK EditDlgProc (HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    int dlugosc_napisu=1;
    switch (Msg)
    {
        case WM_INITDIALOG:
        {
            /*Dlg2=hwnd;
            hTekst2 = GetDlgItem (hwnd, IDC_LABEL2);
            SetWindowText (hTekst2, "Czekaj. Wyszukiwanie plikow...");
            hProgressBar = GetDlgItem (hwnd, IDC_PGB1);
            SendMessage(hProgressBar, PBM_SETRANGE, 0, (LPARAM)MAKELONG(0,1000));*/
            hTekstT = GetDlgItem (hwnd, IDC_EDIT_T);
            SetWindowText (hTekstT, T[(int)lParam].c_str());
            hTekstA = GetDlgItem (hwnd, IDC_EDIT_A);
            if(A[(int)lParam].empty()) SetWindowText (hTekstA, " "); else
            SetWindowText (hTekstA, A[(int)lParam].c_str());
            hTekstK = GetDlgItem (hwnd, IDC_EDIT_K);
            if(K[(int)lParam].empty()) SetWindowText (hTekstK, " "); else
            SetWindowText (hTekstK, K[(int)lParam].c_str());
            hTekstL = GetDlgItem (hwnd, IDC_EDIT_L);
            SetWindowText (hTekstL, usat(L[(int)lParam]).c_str());
            nr_edytowanego=(int)lParam;
        }
        break;
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                dlugosc_napisu=GetWindowTextLength(hTekstT);
                lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc_napisu+1);
                GetWindowText(hTekstT,lpStr,dlugosc_napisu+1);
                T[nr_edytowanego]=lpStr;
                GlobalFree(lpStr);
                T[nr_edytowanego]=UsEndlSpc(T[nr_edytowanego]);
                dlugosc_napisu=GetWindowTextLength(hTekstA);
                lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc_napisu+1);
                GetWindowText(hTekstA,lpStr,dlugosc_napisu+1);
                A[nr_edytowanego]=lpStr;
                GlobalFree(lpStr);
                A[nr_edytowanego]=UsEndlSpc(A[nr_edytowanego]);
                dlugosc_napisu=GetWindowTextLength(hTekstK);
                lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc_napisu+1);
                GetWindowText(hTekstK,lpStr,dlugosc_napisu+1);
                K[nr_edytowanego]=lpStr;
                GlobalFree(lpStr);
                K[nr_edytowanego]=UsEndlSpc(K[nr_edytowanego]);
                /*dlugosc_napisu=GetWindowTextLength(hTekstL);
                lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc_napisu+1);
                GetWindowText(hTekstL,lpStr,dlugosc_napisu+1);
                L[nr_edytowanego]=lpStr;
                GlobalFree(lpStr);*/
                zapi();
                konw();
                EndDialog (hwnd, IDCANCEL);
                break;
                case IDCANCEL:
                EndDialog (hwnd, IDCANCEL);
                break;
                case 3:
                if(global_pom1>=0)
                {
                    ShExELog=ShellExecute(NULL, "open", usat(L[global_pom1]).c_str()/*(LPCSTR)vcombo[wParam-1]*/, NULL, NULL, SW_SHOWMAXIMIZED);
                    pokazELog((UINT)ShExELog);
                }
                break;
            }
        }
        break;
        case WM_CLOSE:
        //case WM_DESTROY:
        EndDialog (hwnd, IDOK);
        break;

        default: return FALSE;
    }

    return TRUE;
}

HWND hTekst1,hTekst3;
BOOL CALLBACK PropDlgProc (HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)//okno wlasciwosci
{
    int dlugosc_napisu=1;
    string poms1;
    switch (Msg)
    {
        case WM_INITDIALOG:
        {
            hTekst1 = GetDlgItem (hwnd, IDC_EDIT_O1);
            SetWindowText (hTekst1, SearchFilter.c_str());
            hTekst3 = GetDlgItem (hwnd, IDC_EDIT_O2);
            SetWindowText (hTekst3, convertInt(IleUzupelnien()).c_str());
        }
        break;
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case IDOK:
                dlugosc_napisu=GetWindowTextLength(hTekst1);
                lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc_napisu+1);
                GetWindowText(hTekst1,lpStr,dlugosc_napisu+1);
                SearchFilter=lpStr;
                GlobalFree(lpStr);
                dlugosc_napisu=GetWindowTextLength(hTekst3);
                lpStr=(LPSTR)GlobalAlloc(GPTR,dlugosc_napisu+1);
                GetWindowText(hTekst3,lpStr,dlugosc_napisu+1);
                poms1=lpStr;
                GlobalFree(lpStr);
                ZapiszIleUzupelnien(poms1);
                EndDialog (hwnd, IDOK);
                break;
                case IDCANCEL: EndDialog (hwnd, IDCANCEL); break;
            }
        }
        break;

        default: return FALSE;
    }

    return TRUE;
}
