#ifndef		_DEF_
#define		_DEF_

#pragma once

typedef struct _COLOR
{
	float r;
	float g;
	float b;
	float a;
}COLOR;

COLOR RGBA(float r,float g,float b,float a);
	
typedef struct _COLOR3
{
	float r;
	float g;
	float b;
}COLOR3;

COLOR3 RGBvalue(float r,float g,float b);

#define ID_CHILD	2011

#endif

