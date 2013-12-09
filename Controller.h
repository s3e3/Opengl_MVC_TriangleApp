#pragma once
#include<Windows.h>
#include"openglModel.h"

class Controller
{
public:
	Controller(void);
	~Controller(void);

	virtual int EnableOpenGL(HWND hwnd){ return 0;}
	virtual int DisableOpenGL(HWND hwnd){ return 0;}
	virtual int Draw() { return 0;}
	virtual int Create(HWND) {return 0;}
	virtual int Command(HWND,WPARAM wParam,LPARAM lParam){return 0;}
	virtual int handleHScroll(HWND,WPARAM wParam,LPARAM lParam){return 0;}
	virtual int RenderFrame(HWND hwnd) {return 0;}
};

