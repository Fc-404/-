/*
�Ŷӣ��˰����Ŷ�
��Ա����ͺ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<iostream>
//ȫ�ֱ�������
#include"declaration.h"
//��Ҫ�����Լ���/FORCE��������ļ�ʹ��ͬһ��ͷ�ļ�����
#include"keyboard.cpp"
#include"tool.cpp"
#include"start.cpp"
#include"tank.cpp"
#include"plane.cpp"
#include"egg.cpp"
//����������
void window();
//������ڣ�
int main() {
	window();
	mutex_temp = CreateMutex(NULL, FALSE, NULL);
	mutex_draw = CreateMutex(NULL, FALSE, NULL);//��������ʼ����
	mutex_esc = CreateMutex(NULL, FALSE, NULL);//esc����ʼ����
	mutex_map = CreateMutex(NULL, FALSE, NULL);//map����ʼ����
	mutex_scoring = CreateMutex(NULL, FALSE, NULL);//�Ʒ�����ʼ����

	DWORD th_kb;
	CloseHandle(CreateThread(NULL, 0, keyboard, NULL, 0, &th_kb));//�����̣߳�ʹ֮һֱ������

	start();

	Sleep(600000);
	return 0;
}
//���ڻ��ƣ�
void window() {
	system("cls");
	system("color 70");
	system("title ͯ������");

	HWND window = GetForegroundWindow();//��ȡ��ǰ���ڶ�������
	HANDLE window_io = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼��������

//	LPCTSTR title = "ͯ������";//������⣬��������Ŀ�����ַ���Ϊ��δ���á���
//	SetWindowText(window, title);//���ñ��⣻

	SetWindowPos(window, HWND_TOP, 0, 50, 0, 0, 0);//���ô���λ�ü���С��
	system("mode con cols=180 lines=50");

//	CONSOLE_SCREEN_BUFFER_INFO info;//����������Ϣ���ͣ�
//	GetConsoleScreenBufferInfo(window_io, &info);//��ȡ������Ϣ��
//	SMALL_RECT rect = info.srWindow;//������������ʾ��С��λ�ã�
//	COORD size = { rect.Right + 1, rect.Bottom + 1 };//���建������С��
//	SetConsoleScreenBufferSize(window_io, size);//���ô��ڻ�������С��ʵ���޹�������
	
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//��������Ϣ��
	SetConsoleCursorInfo(window_io, &cursor_info);//���ù����Ϣ��
}