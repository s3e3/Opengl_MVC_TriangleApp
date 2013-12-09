#include "openglModel.h"


openglModel::openglModel(int w,int h)
{
	width=w;
	height=h;

	vcolor[0].r=1;	vcolor[0].g=0;	vcolor[0].b=0;
	vcolor[1].r=0;	vcolor[1].g=1;	vcolor[1].b=0;
	vcolor[2].r=0;	vcolor[2].g=0;	vcolor[2].b=1;
}


openglModel::~openglModel(void)
{
}

void openglModel::drawTriangle(){
	//MessageBox(NULL,L"drawTriangle is running",L"Notification",MB_OK);

	glClear(GL_COLOR_BUFFER_BIT);
		
	glBegin(GL_TRIANGLES);
	
	setVertexColor(vcolor[0]);
	glVertex2f((float) width/2,20.0);  

	setVertexColor(vcolor[1]);
    glVertex2f(20.0,(float) (height-20));  

	setVertexColor(vcolor[2]);
    glVertex2f((float) (width-20),(float) (height-20));  
	
	glEnd();   
}

void openglModel::rendermodel(HWND hwnd){
	//SendMessage(hwnd,WM_PAINT,0,0);
}

void openglModel::setVertexColor(COLOR3 color){
	glColor3f(color.r,color.g,color.b);
}
