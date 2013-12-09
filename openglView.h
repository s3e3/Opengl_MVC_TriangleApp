#pragma once
#include<Windows.h>
#include <gl/gl.h>
#include <gl/glu.h>


class openglView
{
public:
	openglView(int w,int h);
	~openglView(void);

	void CreateContext(HWND hwnd);
	void DeleteContext(HWND hwnd);
	void InitOpenGL();
	void swapBuffers();
	void DrawGL();
private:
	HDC hdc;
	HGLRC hrc;
	int width;
	int height;

	//GLuint PixelFormat;
};

