  //#include<Windows.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

#include"Window.h"
#define WIDTH 400
#define HEIGHT 580

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance,PSTR szCMLine, int iCmdShow){
	
	openglModel *model=new openglModel(100,100);
	
	POINT size;
	size.x=WIDTH;
	size.y=HEIGHT;
	POINT position;
	position.x=100; position.y=0;
	mainView *mainview=new mainView();
	mainController *maincntrl=new mainController(mainview,model);
	Window *window=new Window(hInstance,size,position,L"main",NULL,WindowProc,maincntrl);
	window->setWndProc(WindowProc);
	window->setStyle(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU  | WS_MINIMIZEBOX | WS_MAXIMIZEBOX);
	//window->setStyle(WS_OVERLAPPEDWINDOW);
	window->setStyleEx(WS_EX_WINDOWEDGE);
	window->setID(0);
	window->createWindow();
	window->showWindow(iCmdShow);

	RECT clientArea;
	GetClientRect(window->getHandle(),&clientArea);
	size.x=clientArea.right;	size.y=350;
	position.x=0;	position.y=0;

	openglView *viewgl=new openglView(size.x,size.y);
	model->setSize(size.x,size.y);
	openglController *glcntrl=new openglController(viewgl,model);
		
	Window *glwindow=new Window(hInstance,size,position,TEXT("static"),window->getHandle(),childWindowProc,glcntrl);
	glwindow->setStyle(WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_BORDER);
	glwindow->setStyleEx(NULL);
	glwindow->setClassStyle(CS_OWNDC);
	glwindow->setID(ID_CHILD);
	glwindow->createWindow();
	glwindow->showWindow(iCmdShow);
	

	/*size.x=300;	size.y=300;
	position.x=300; position.y=300;
	Window *window2=new Window(hInstance,size,position,L"main2",NULL,WindowProc2,NULL);
	window2->setWndProc(WindowProc2);
	window2->setStyle(WS_OVERLAPPEDWINDOW);
	window2->setStyleEx(WS_EX_WINDOWEDGE);
	window2->createWindow();
	window2->showWindow(iCmdShow);*/

	window->MessageLoop();
	/*while (window->msg.message!=WM_QUIT){
		if (PeekMessage(&(window->msg), window->getHandle(), NULL, NULL, PM_REMOVE)){
            TranslateMessage(&(window->msg));
            DispatchMessage(&(window->msg));
		}
	else{
		if(GetMessage(&(glwindow->msg),glwindow->getHandle(),NULL,NULL)){
			TranslateMessage(&(glwindow->msg));
            DispatchMessage(&(glwindow->msg));
		}
	}
	}*/
	delete model;
	delete maincntrl;
	delete glcntrl;
	delete glwindow;
	delete window;
	//glBegin();
}
