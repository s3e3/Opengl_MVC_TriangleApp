#pragma once
#include<Windows.h>
#include<Commctrl.h>

#define ID_GB_V  1010		//id for group box of vertices
#define ID_GB_C  1011		//id for group box for colors
#define ID_RB_V1 1012		//id for radio button for vertex1.
#define ID_RB_V2 1013
#define ID_RB_V3 1014
#define ID_SL_R  1015		//id for slider of Red color.
#define ID_SL_G  1016
#define ID_SL_B  1017
#define ID_SB	 1018		//id for status bar.
#define ID_M	 1019		//id for main menu
#define ID_ME	 1020		//id for menu popup (exit.)


class mainView
{
public:
	mainView(void);
	~mainView(void);

	void createView(HWND hwnd);
	//void setButtonStates(HWND hwnd,WPARAM wParam,LPARAM lParam);
};

