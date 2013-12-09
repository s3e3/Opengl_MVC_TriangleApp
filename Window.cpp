#include "Window.h"


Window::Window(HINSTANCE _hInstance,POINT _size,POINT _position,TCHAR *_title,HWND _parent,WNDPROC wndproc,Controller *_cntrl)
{
	phwnd=_parent;
	hInstance=_hInstance;
	wndName=_title;
	width=_size.x;
	height=_size.y;
	this->x=_position.x;
	this->y=_position.y;
	controller=_cntrl;
	//if(controller!=NULL) controller->EnableOpenGL(hwnd);

	wndClass.cbSize=sizeof(WNDCLASSEX);
	wndClass.style=0;
	wndClass.lpfnWndProc=wndproc;
	wndClass.cbClsExtra=0;
	wndClass.cbWndExtra=0;
	wndClass.hInstance =_hInstance ;
	wndClass.hIcon = LoadIcon (NULL, IDI_APPLICATION) ;
	wndClass.hIconSm       = LoadIcon(0, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor (NULL, IDC_ARROW) ;
	wndClass.hbrBackground = (HBRUSH) (COLOR_BTNFACE + 1) ;
	wndClass.lpszMenuName = NULL ;
	wndClass.lpszClassName =wndName ;

	quit=false;
	
}

void Window::createWindow(){

	if(!RegisterClassEx(&wndClass))	MessageBox(NULL,TEXT("window class is not registered!"),TEXT("ERROR!"),MB_ICONERROR);

	hwnd=CreateWindowEx(winStyleEx,wndName,wndName,winStyle,x,y,width,height,phwnd,(HMENU) id,hInstance,(LPVOID) controller);

	if(hwnd==NULL)	MessageBox(NULL,TEXT("window's handle is null!"),TEXT("ERROR!"),MB_ICONERROR);
}

void Window::showWindow(int _cmdShow){
	ShowWindow(hwnd,_cmdShow);
	UpdateWindow(hwnd);
}

void Window::MessageLoop(){
	while (msg.message!=WM_QUIT){
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)){
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
	}

}

Window::~Window(void)
{
	UnregisterClass(wndName,hInstance);
}



LRESULT CALLBACK WindowProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	HMENU hMenu;
	HMENU hMenuPopup;
	HDC hdc;
	PAINTSTRUCT ps;
	static Controller *ctrl;
	ctrl = (Controller*)::GetWindowLongPtr(hwnd, GWL_USERDATA);

	if(message==WM_NCCREATE){
        ctrl = (Controller*)(((CREATESTRUCT*)lParam)->lpCreateParams);
        SetWindowLongPtr(hwnd, GWL_USERDATA, (LONG_PTR)ctrl);
		return ::DefWindowProc(hwnd, message, wParam, lParam);
    }
	
	if(!ctrl)     return ::DefWindowProc(hwnd, message, wParam, lParam);

	switch(message){
	case WM_CREATE:
		ctrl->Create(hwnd);
		return 0;
	//case WM_PAINT:
	//	ctrl->Draw();
		//return 0;
	case WM_COMMAND:
		ctrl->Command(hwnd,wParam,lParam);
		return 0;
	case WM_HSCROLL:
		ctrl->handleHScroll(hwnd,wParam,lParam);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd,message,wParam,lParam);
}

LRESULT CALLBACK childWindowProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	HDC hdc;
	PAINTSTRUCT ps;
	static Controller *ctrl;
	ctrl = (Controller*)::GetWindowLongPtr(hwnd, GWL_USERDATA);

	if(message==WM_NCCREATE){
        ctrl = (Controller*)(((CREATESTRUCT*)lParam)->lpCreateParams);
        SetWindowLongPtr(hwnd, GWL_USERDATA, (LONG_PTR)ctrl);
		return ::DefWindowProc(hwnd, message, wParam, lParam);
	}
	
	if(!ctrl)     return ::DefWindowProc(hwnd, message, wParam, lParam);

	switch(message){
	case WM_CREATE:
		ctrl->EnableOpenGL(hwnd);
		//CreateWindow(L"BUTTON",L"vertex 3",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,25,25,70,20,hwnd,(HMENU) ID_RB_V3,NULL,NULL);
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hwnd,&ps);
		ctrl->Draw();
		EndPaint(hwnd,&ps);
        return 0;
	case WM_LBUTTONDOWN:
		//MessageBox(NULL,L"mouse L button clicked....",L"oohh",MB_OK);
		return 0;
	case WM_DESTROY:
		ctrl->DisableOpenGL(hwnd);
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd,message,wParam,lParam);
}

LRESULT CALLBACK WindowProc2 (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch(message){
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		MessageBox(NULL,L"mouse L button clicked....",L"oohh",MB_OK);
		return 0;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}
