#pragma once
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include"declaration.h"
//ȫ�ֱ�����
short key = -1, old_key = -1, new_key = -1, last_key = -1;
//���������̣߳�
DWORD WINAPI keyboard(LPVOID lpParamter) {
	//printf("keyboard pass\n");

	while (1) {
		old_key=_getch();
		if (old_key == 224)//�ж������Ƿ�Ϊ�������Ҽ������������ӻ��������õ���Ϊ296����Ϊ304����Ϊ299����Ϊ301��
			old_key = old_key + _getch();
		key = old_key;
		last_key = new_key;//Ϊ�˱�����һ��key��
		
		new_key = _getch();
		if (new_key == 224)
			new_key = new_key + _getch();
		P();
		key = new_key;
		last_key = old_key;
		V();
	}
	return 0;
}