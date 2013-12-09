#include "mainView.h"


mainView::mainView(void)
{
}


mainView::~mainView(void)
{
}

void mainView::createView(HWND hwnd){
	RECT clientArea;
	GetClientRect(hwnd,&clientArea);
	//HDC hdc=GetDC(hwnd);
	//SelectObject (hdc, GetStockObject (DEFAULT_GUI_FONT)) ;
	//ReleaseDC(hwnd,hdc);

	HMENU hMenu = CreateMenu () ;
	HMENU hMenuPopup = CreateMenu () ;
	AppendMenu (hMenuPopup, MF_STRING, 1002, L"E&xit") ;
	AppendMenu (hMenu, MF_POPUP, (UINT) hMenuPopup, L"&File") ;
	SetMenu(hwnd,hMenu);

	ShowWindow(CreateWindow(L"BUTTON",L"vertex",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,10,360,100,130,hwnd,(HMENU) ID_GB_V,NULL,NULL),SW_SHOW);
	ShowWindow(CreateWindow(L"BUTTON",L"color",WS_CHILD|WS_VISIBLE|BS_GROUPBOX,120,360,clientArea.right-10-120,130,hwnd,(HMENU) ID_GB_C,NULL,NULL),SW_SHOW);
	CreateWindow(L"BUTTON",L"vertex 1",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,25,395,70,20,hwnd,(HMENU) ID_RB_V1,NULL,NULL);
	CreateWindow(L"BUTTON",L"vertex 2",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,25,420,70,20,hwnd,(HMENU) ID_RB_V2,NULL,NULL);
	CreateWindow(L"BUTTON",L"vertex 3",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,25,445,70,20,hwnd,(HMENU) ID_RB_V3,NULL,NULL);

	CreateWindow(TRACKBAR_CLASS,L"Red",WS_CHILD|WS_VISIBLE,130,395,240,20,hwnd,(HMENU) ID_SL_R,NULL,NULL);
	CreateWindow(TRACKBAR_CLASS,L"Green",WS_CHILD|WS_VISIBLE,130,420,240,20,hwnd,(HMENU) ID_SL_G,NULL,NULL);
	CreateWindow(TRACKBAR_CLASS,L"Blue",WS_CHILD|WS_VISIBLE,130,445,240,20,hwnd,(HMENU) ID_SL_B,NULL,NULL);
	
	SendMessage(GetDlgItem(hwnd,ID_SL_R),TBM_SETRANGE,TRUE, MAKELONG(0,255));
	SendMessage(GetDlgItem(hwnd,ID_SL_G),TBM_SETRANGE,TRUE, MAKELONG(0,255));
	SendMessage(GetDlgItem(hwnd,ID_SL_B),TBM_SETRANGE,TRUE, MAKELONG(0,255));

	
	CreateWindow(STATUSCLASSNAME,0,WS_CHILD|WS_VISIBLE|SBARS_SIZEGRIP,0,0,0,0,hwnd,(HMENU) ID_SB,GetModuleHandle(0),NULL);
	SendMessage(GetDlgItem(hwnd,ID_SB), SB_SETTEXT, 0, (LPARAM)TEXT("slide to change the color of selected vertex."));
	
	SendMessage(GetDlgItem(hwnd,ID_GB_V),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);
	SendMessage(GetDlgItem(hwnd,ID_RB_V1),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);
	SendMessage(GetDlgItem(hwnd,ID_RB_V2),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);
	SendMessage(GetDlgItem(hwnd,ID_RB_V3),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);

	SendMessage(GetDlgItem(hwnd,ID_GB_C),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);
	SendMessage(GetDlgItem(hwnd,ID_SL_R),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);
	SendMessage(GetDlgItem(hwnd,ID_SL_G),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);
	SendMessage(GetDlgItem(hwnd,ID_SL_B),WM_SETFONT, (WPARAM) GetStockObject (DEFAULT_GUI_FONT),TRUE);
}

