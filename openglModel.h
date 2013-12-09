#pragma once
#include<Windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include"Def.h"

class openglModel
{
public:
	openglModel(int w,int h);
	~openglModel(void);

	void setVertexColor(COLOR3);
	void drawTriangle();
	void rendermodel(HWND hwnd);
	void setSize(int w,int h){ width=w; height=h;}

	COLOR3 vcolor[3];
	//COLOR3 v2color;
	//COLOR3 v3color;
private:
	int width;
	int height;

};

