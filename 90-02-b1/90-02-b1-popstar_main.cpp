/* 2350218 �ƿ� �¼��� */
#include <iostream>
#include "../include/cmd_console_tools.h"
#include"../include/include_menu+tools.h"
#include"90-02-b1-popstar.h"

using namespace std;

int main()
{
	while (1)
	{
		cct_setconsoleborder(120, 35, 120, 9000);
		cct_setfontsize("������", 20);
		const char menu[][MAX_ITEM_LEN] = {
		"A.�������ҳ����������ʶ",
		"B.���������һ���������ֲ�����ʾ��",
		"C.���������һ�أ��ֲ�����ʾ��",
		"D.αͼ�ν����������ѡ��һ��ɫ�飨�޷ָ��ߣ�",
		"E.αͼ�ν����������ѡ��һ��ɫ�飨�зָ��ߣ�",
		"F.αͼ�ν������һ���������ֲ��裩",
		"G.αͼ�ν���������",
		"Q.�˳�",
		NULL
		};

		cct_cls();

		unsigned int wide = 0;
		for (int i = 0;i < 10;i++)
		{
			if (wide < strlen(menu[i]))
				wide = strlen(menu[i]);
		}

		struct PopMenu parameter;
		parameter.title = "�������ǲ˵�"; //�����ǵ����ַ�
		parameter.start_x = 10;
		parameter.start_y = 10;
		parameter.width = wide;	//�����˵������ҿ���
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
			case(0):
				return 0;
			case(1):
			{
				star_A();
				break;
			}
			case(2):
			{
				star_B();
				break;
			}
			case(3):
			{
				star_C();
				break;
			}
			case(4):
			{
				star_D();
				break;
			}
			case(5):
			{
				star_E();
				break;
			}
			case(6):
			{
				star_F();
				break;
			}
			case(7):
			{
				star_G();
				break;
			}
			case(8):
			{
				return 0;
			}
		}
	}
}