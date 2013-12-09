#include "openglController.h"


openglController::openglController(openglView *_view,openglModel *_model)
{
	view=_view;
	model=_model;
}


openglController::~openglController(void)
{
}

int openglController::EnableOpenGL(HWND hwnd){
	//MessageBox(NULL,L"enabling openGL",L"notification!",MB_OK);

	view->CreateContext(hwnd);
	view->InitOpenGL();
	return 1;
}

int openglController::DisableOpenGL(HWND hwnd){
	//MessageBox(NULL,L"disabling openGL",L"notification!",MB_OK);
	view->DeleteContext(hwnd);
	return 1;
}

int openglController::Draw(){
	//view->DrawGL();
	model->drawTriangle();
	view->swapBuffers();
	return 1;
}

int openglController::RenderFrame(HWND hwnd){
	//view->DrawGL();
	//model->drawTriangle();
	//MessageBox(NULL,L"renderframe is running!",L"gg",MB_OK);
	model->vcolor[0].r=0;
	SendMessage(hwnd,WM_PAINT,0,0);
	//SwapBuffers(hdc);
	return 1;
}
