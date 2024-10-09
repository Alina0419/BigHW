/* �ƿ� 2350218 �¼��� */
#define MAX_ITEM_LEN	80
#include<iostream>
#include"../include/cmd_console_tools.h"
#include"90-01-b2-magic_ball.h"
#include"../include/include_menu+tools.h"

using namespace std;

int main()
{
	while (1)
	{
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_setfontsize("������", 20);
		const char menu[][MAX_ITEM_LEN] = {
		"1.�ڲ����飬���ɳ�ʼ״̬��Ѱ���Ƿ��г�ʼ��������",
		"2.�ڲ����飬������ʼ����������0�����䲢��0���",
		"3.�ڲ����飬������ʼ������������������ʾ",
		"4.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬",
		"5.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬",
		"6.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬����ʼ��������",
		"7.n*n�Ŀ��(�зָ���)��������ʼ�����������ʾ������ʾ",
		"8.cmdͼ�ν���(�зָ��ߣ�����ƶ�ʱ��ʾ���꣬�Ҽ��˳�)",
		"9.cmdͼ�ν���������",
		"0.�˳�",
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
		parameter.title = "����˵�"; //�����ǵ����ַ�
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
			case(1):
			{  
				magic_1();
				break;
			}
			case(2):
			{
				magic_2();
				break;
			}
			case(3):
			{
				magic_3();
				break;
			}
			case(4):
			{
				magic_4();
				break;
			}
			case(5):
			{
				magic_5();
				break;
			}
			case(6):
			{
				magic_6();
				break;
			}
			case(7):
			{
				magic_7();
				break;
			}
			case(8):
			{
				magic_8();
				break;
			}
			case(9):
			{
				magic_9();
				break;
			}
			case(10):
			{
				return 0;
			}
		}
	}
}