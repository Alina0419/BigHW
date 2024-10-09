/* �ƿ� 2350218 �¼��� */
#define MAX_ITEM_LEN	80
#include<iostream>
#include<conio.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"
#include"../include/include_menu+tools.h"
using namespace std;

int main()
{
	cct_cls();
	while (1)
	{
		/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_setfontsize("������", 20);
		const char menu[][MAX_ITEM_LEN] = {
		"1.������",
		"2.������(������¼)",
		"3.�ڲ�������ʾ(����)",
		"4.�ڲ�������ʾ(����+����)",
		"5.ͼ�ν�-Ԥ��-������Բ��",
		"6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������",
		"7.ͼ�ν�-Ԥ��-��һ���ƶ�",
		"8.ͼ�ν�-�Զ��ƶ��汾",
		"9.ͼ�ν�-��Ϸ��",
		"0.�˳�",
		NULL
		};

		cct_cls();

		struct PopMenu parameter;
		parameter.title = "��ŵ���˵�"; //�����ǵ����ַ�
		parameter.start_x = 10;
		parameter.start_y = 10;
		parameter.width = 80;	//�����˵������ҿ���
		parameter.high = 15;	//�����˵������¿��ߣ���������˲˵���ʵ������������Ϊʵ������
		parameter.bg_color = COLOR_BLACK;	//����ɫ
		parameter.fg_color = COLOR_HWHITE; //ǰ��ɫ

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int choice = pop_menu(menu, &parameter);

		cct_gotoxy(0, 0);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		cct_cls();
		switch (choice)
		{
			case(1):
			{
				hanoi_1();
				break;
			}
			case(2):
			{
				hanoi_2();
				break;
			}
			case(3):
			{
				hanoi_3();
				break;
			}
			case(4):
			{
				hanoi_4();
				break;
			}
			case(5):
			{
				hanoi_5();
				break;
			}
			case(6):
			{
				hanoi_6();
				break;
			}
			case(7):
			{
				hanoi_7();
				break;
			}
			case(8):
			{
				hanoi_8();
				break;
			}
			case(9):
			{
				hanoi_9();
				break;
			}
			case(10):
			{
				return 0;
			}
		}
		cout << endl;
		cout << "���س�������";
		while (_getch()!='\r')
		{
			;
		}
	}
	return 0;
}
