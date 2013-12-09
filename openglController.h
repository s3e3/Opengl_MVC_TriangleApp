#pragma once
#include"Controller.h"
#include"openglView.h"


class openglController : public Controller
{
public:
	openglController(openglView *view,openglModel *model);
	~openglController(void);
	openglView *view;
	openglModel *model;

	int EnableOpenGL(HWND hwnd);
	int DisableOpenGL(HWND hwnd);
	int Draw();
	int RenderFrame(HWND hwnd);
	
private:

};

