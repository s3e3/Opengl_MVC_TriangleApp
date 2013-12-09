#include "openglView.h"


openglView::openglView(int w,int h)
{
	width=w;
	height=h;
	//InitOpenGL();
}


openglView::~openglView(void)
{

}

void openglView::InitOpenGL(){
	//MessageBox(NULL,TEXT("initializing openGL :)"),TEXT("Notification"),MB_OK);
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, 0.0, 1.0);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode (GL_MODELVIEW);
	
}

void openglView::DrawGL(){
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers(hdc);
}

void openglView::swapBuffers(){
	SwapBuffers(hdc);
}

void openglView::CreateContext(HWND hwnd){
	static  PIXELFORMATDESCRIPTOR pfd=                  // pfd Tells Windows How We Want Things To Be
	{
    sizeof(PIXELFORMATDESCRIPTOR),                  // Size Of This Pixel Format Descriptor
    1,                              // Version Number
    PFD_DRAW_TO_WINDOW |                        // Format Must Support Window
    PFD_SUPPORT_OPENGL |                        // Format Must Support OpenGL
    PFD_DOUBLEBUFFER,                       // Must Support Double Buffering
    PFD_TYPE_RGBA,                          // Request An RGBA Format
    16,                               // Select Our Color Depth
    0, 0, 0, 0, 0, 0,                       // Color Bits Ignored
    0,                              // No Alpha Buffer
    0,                              // Shift Bit Ignored
    0,                              // No Accumulation Buffer
    0, 0, 0, 0,                         // Accumulation Bits Ignored
    16,                             // 16Bit Z-Buffer (Depth Buffer)
    0,                              // No Stencil Buffer
    0,                              // No Auxiliary Buffer
    PFD_MAIN_PLANE,                         // Main Drawing Layer
    0,                              // Reserved
    0, 0, 0                             // Layer Masks Ignored
	};

	hdc=GetDC(hwnd);
	int PixelFormat=ChoosePixelFormat(hdc,&pfd);

	if(!SetPixelFormat(hdc,PixelFormat,&pfd))	MessageBox(NULL,TEXT("PixelFormat error!"),TEXT("ERROR!"),MB_ICONERROR);

	if(!(hrc=wglCreateContext(hdc)))	MessageBox(NULL,TEXT("HRC is null"),TEXT("ERROR!"),MB_ICONERROR);

	if(!wglMakeCurrent(hdc,hrc))	MessageBox(NULL,TEXT("could not make current !"),TEXT("ERROR!"),MB_ICONERROR);

	if(!ReleaseDC(hwnd,hdc))	MessageBox(NULL,TEXT("not able to release DC!"),TEXT("ERROR!"),MB_ICONERROR);
}
void openglView::DeleteContext(HWND hwnd){
	if(!wglMakeCurrent(NULL,NULL))	MessageBox(hwnd,TEXT("Release of DC and RC failed!"),TEXT("ERROR!"),MB_ICONERROR);
	wglDeleteContext(hrc);
	ReleaseDC(hwnd,hdc);

	hdc=0;
	hrc=0;
}
