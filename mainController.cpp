#include "mainController.h"


mainController::mainController(mainView *_view,openglModel *_model)
{
	view=_view;
	model=_model;
}


mainController::~mainController(void)
{
}

int mainController::Draw(){
	return 1;
}

int mainController::Create(HWND hwnd){
	//MessageBox(NULL,TEXT("creating view! :)"),TEXT("NOTIFICATION"),MB_OK);
	
	view->createView(hwnd);
	return 1;
}

int mainController::Command(HWND hwnd,WPARAM wParam,LPARAM lParam){
	setButtonStates(hwnd,wParam,lParam);

	return 1;
}
int mainController::RenderFrame(HWND hwnd){
	return 1;
}

void mainController::setButtonStates(HWND hwnd,WPARAM wparam,LPARAM lparam){
	RECT clientArea;
	GetClientRect(hwnd,&clientArea);

	if( HIWORD(wparam)==BN_CLICKED){
		int statwidths[3]={clientArea.right/3,2*clientArea.right/3,-1};
		SendMessage(GetDlgItem(hwnd,ID_SB), SB_SETPARTS, sizeof(statwidths)/sizeof(int), (LPARAM)statwidths);
		SendMessage((HWND)lparam,BM_SETCHECK,1,0);
		if(LOWORD(wparam)==ID_RB_V1){
			SendMessage(GetDlgItem(hwnd,ID_RB_V2),BM_SETCHECK,0,0);
			SendMessage(GetDlgItem(hwnd,ID_RB_V3),BM_SETCHECK,0,0);
			setTrackbarPos(hwnd,0);
			statusBarInfo(hwnd,0);
		}
		if(LOWORD(wparam)==ID_RB_V2){
			SendMessage(GetDlgItem(hwnd,ID_RB_V1),BM_SETCHECK,0,0);
			SendMessage(GetDlgItem(hwnd,ID_RB_V3),BM_SETCHECK,0,0);
			setTrackbarPos(hwnd,1);
			statusBarInfo(hwnd,1);
		}
		if(LOWORD(wparam)==ID_RB_V3){
			SendMessage(GetDlgItem(hwnd,ID_RB_V1),BM_SETCHECK,0,0);
			SendMessage(GetDlgItem(hwnd,ID_RB_V2),BM_SETCHECK,0,0);
			setTrackbarPos(hwnd,2);
			statusBarInfo(hwnd,2);
		}
	}
}

void mainController::setTrackbarPos(HWND hwnd,int i){
	SendMessage(GetDlgItem(hwnd,ID_SL_R),TBM_SETPOS,TRUE,model->vcolor[i].r*255);
	SendMessage(GetDlgItem(hwnd,ID_SL_G),TBM_SETPOS,TRUE,model->vcolor[i].g*255);
	SendMessage(GetDlgItem(hwnd,ID_SL_B),TBM_SETPOS,TRUE,model->vcolor[i].b*255);
}

void mainController::statusBarInfo(HWND hwnd,int i){
	//char *info="R: ";
	//MessageBox(NULL,L"dd","dd",MB_OK);
	std::string info="R: ";
	std::ostringstream ss;
	ss<<(int)(model->vcolor[i].r*255);
	std::string str = ss.str();
	info+=str;
	std::wstring stemp = std::wstring(info.begin(), info.end());
	LPCWSTR sw = stemp.c_str();
	SendMessage(GetDlgItem(hwnd,ID_SB), SB_SETTEXT, 0, (LPARAM) sw);

	std::string info2="G: ";
	std::ostringstream ss2;
	ss2<<(int)(model->vcolor[i].g*255);
	std::string str2 = ss2.str();
	info2+=str2;
	std::wstring stemp2 = std::wstring(info2.begin(), info2.end());
	LPCWSTR sw2 = stemp2.c_str();
	SendMessage(GetDlgItem(hwnd,ID_SB), SB_SETTEXT, 1, (LPARAM) sw2);

	std::string info3="B: ";
	std::ostringstream ss3;
	ss3<<(int)(model->vcolor[i].b*255);
	std::string str3 = ss3.str();
	info3+=str3;
	std::wstring stemp3 = std::wstring(info3.begin(), info3.end());
	LPCWSTR sw3 = stemp3.c_str();
	SendMessage(GetDlgItem(hwnd,ID_SB), SB_SETTEXT, 2, (LPARAM) sw3);
}

int mainController::handleHScroll(HWND hwnd,WPARAM wparam,LPARAM lparam){
	if(SendMessage(GetDlgItem(hwnd,ID_RB_V1),BM_GETCHECK,0,0)==BST_CHECKED){
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_R))			model->vcolor[0].r=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
		
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_G))			model->vcolor[0].g=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
			
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_B))			model->vcolor[0].b=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
			
		setTrackbarPos(hwnd,0);
		statusBarInfo(hwnd,0);
	}

	if(SendMessage(GetDlgItem(hwnd,ID_RB_V2),BM_GETCHECK,0,0)==BST_CHECKED){
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_R))			model->vcolor[1].r=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
		
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_G))			model->vcolor[1].g=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
			
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_B))			model->vcolor[1].b=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
			
		setTrackbarPos(hwnd,1);
		statusBarInfo(hwnd,1);
	}

	if(SendMessage(GetDlgItem(hwnd,ID_RB_V3),BM_GETCHECK,0,0)==BST_CHECKED){
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_R))			model->vcolor[2].r=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
		
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_G))			model->vcolor[2].g=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
			
		if((HWND) lparam==GetDlgItem(hwnd,ID_SL_B))			model->vcolor[2].b=(float) (SendMessage((HWND) lparam,TBM_GETPOS,0,0))/255;
			
		setTrackbarPos(hwnd,2);
		statusBarInfo(hwnd,2);
	}
		
	SendMessage(GetDlgItem(hwnd,ID_CHILD),WM_PAINT,0,0);
	return 1;
}

LPCWSTR mainController::stringtoL(std::string str, int num){
	std::ostringstream ss;
	ss<<(int)(num);
	std::string str1 = ss.str();
	str+=str1;
	std::wstring stemp = std::wstring(str.begin(),str.end());
	return stemp.c_str();
}
