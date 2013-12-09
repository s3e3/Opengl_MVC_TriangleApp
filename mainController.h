#pragma once
#include"Controller.h"
#include"mainView.h"
#include<string>
#include<iostream>
#include<sstream>
class mainController : public Controller
{
public:
	mainController(mainView *_view,openglModel *_model);
	~mainController(void);
	int Draw();
	int Create(HWND hwnd);
	int Command(HWND hwnd,WPARAM wParam,LPARAM lParam);
	int handleHScroll(HWND hwnd,WPARAM wParam,LPARAM lParam);
	int RenderFrame(HWND hwnd);

	void setButtonStates(HWND hwnd,WPARAM wParam,LPARAM lParam);
	void setTrackbarPos(HWND,int);
	void statusBarInfo(HWND,int);
	//ID_SB;
	openglModel *model;
	mainView *view;

private:
	HWND handle;
	WPARAM wParam;
	LPARAM lParam;

	LPCWSTR stringtoL(std::string, int);
};

