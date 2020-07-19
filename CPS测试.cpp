
#include<iostream>
#include<windows.h>
#include<vector>

#include <time.h>
using namespace std;
#define KEY_DOWN(vk_code)(GetAsyncKeyState(vk_code)&0X8000)?1:0
/*

By MicroBlock

*/ 
vector<HWND> hwnd;
HWND hwndm;
int main() {
	POINT p;
	hwndm=GetForegroundWindow();

	int count=1;
	cout<<"##CPS就是鼠标每秒点击的次数##\n" ;
	cout<<"*将会从第一次点击后开始计数\n*已锁定鼠标，请随意发挥\n\n\n----------------------\n\n";
	while(!KEY_DOWN(MOUSE_MOVED))SetCursorPos(6000,-50);;
	while(KEY_DOWN(MOUSE_MOVED))SetCursorPos(6000,-50);;
	time_t myt=time(NULL),rt=myt,lasttimest=myt,maxcps=0,nowcps=0;

	while((rt+10)>myt) {
		if(lasttimest<myt){
			lasttimest=myt;
			cout<<"瞬时CPS："<<nowcps<<endl;
			maxcps=max(nowcps,maxcps);nowcps=0;
		}
		while(!KEY_DOWN(MOUSE_MOVED)) {
			SetCursorPos(6000,-50);
			if((rt+10)<myt) {
				break;
			} else {
				myt=time(NULL);
			}
		};
		while(KEY_DOWN(MOUSE_MOVED)) {
			SetCursorPos(6000,-50);
			if((rt+10)<myt) {
				break;				myt=time(NULL);

			} else {
			}
		};
		count++;nowcps++;
		SetCursorPos(6000,-50);
		Sleep(10);
	}
	ShowWindow(hwndm,SW_SHOW);
	cout<<"CPS:"<<(double)count/10<<endl<<"最高CPS："<<maxcps;
	cout<<"\n按下任意键退出\n";
	getchar();
	return 0;
}

