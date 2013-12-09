#pragma once
//#include<Windows.h>
#include"openglController.h"
#include"mainController.h"
//#include <gl/gl.h>
//#include <gl/glu.h>


LRESULT CALLBACK WindowProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK childWindowProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WindowProc2 (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

class Window
{
public:
	Window(HINSTANCE _hInstance,POINT _size,POINT _position,TCHAR *_title,HWND parent,WNDPROC wndproc,Controller *_controller);
	~Window(void);

	void createWindow();
	void showWindow(int _cmdShow);
	void MessageLoop();

	void setClassStyle(UINT style){ wndClass.style = style; }
	void setWndProc(WNDPROC wndproc){ wndClass.lpfnWndProc=wndproc; }
	void setStyle(DWORD _style){ winStyle=_style;}
	void setStyleEx(DWORD _style){ winStyleEx=_style;}

	void setID(int _id){id=_id;}
	int getID() {return id;}
	HWND getHandle(){ return hwnd;}
	HWND hwnd;
	MSG msg;

private:
	bool quit;
	int id;
	TCHAR *wndName;
	TCHAR *wndclassName;
	HINSTANCE hInstance;
	

	WNDCLASSEX wndClass;
	DWORD winStyle;                    
    DWORD winStyleEx; 
	DWORD classStyle;
	int x;
	int y;
	int width;
	int height;

	HWND phwnd;

	Controller *controller;
};

