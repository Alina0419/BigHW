/* 计科 2350218 陈佳怡 */
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
		/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_setfontsize("新宋体", 20);
		const char menu[][MAX_ITEM_LEN] = {
		"1.基本解",
		"2.基本解(步数记录)",
		"3.内部数组显示(横向)",
		"4.内部数组显示(纵向+横向)",
		"5.图形解-预备-画三个圆柱",
		"6.图形解-预备-在起始柱上画n个盘子",
		"7.图形解-预备-第一次移动",
		"8.图形解-自动移动版本",
		"9.图形解-游戏版",
		"0.退出",
		NULL
		};

		cct_cls();

		struct PopMenu parameter;
		parameter.title = "汉诺塔菜单"; //标题是单数字符
		parameter.start_x = 10;
		parameter.start_y = 10;
		parameter.width = 80;	//不含菜单框左右框线
		parameter.high = 15;	//不含菜单框上下框线，如果超过了菜单的实际项数，则缩为实际项数
		parameter.bg_color = COLOR_BLACK;	//背景色
		parameter.fg_color = COLOR_HWHITE; //前景色

		/* 调用pop_menu函数，返回选择的菜单项数（从1开始计数）*/
		int choice = pop_menu(menu, &parameter);

		cct_gotoxy(0, 0);
		cct_setcolor(); //恢复缺省颜色
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
		cout << "按回车键继续";
		while (_getch()!='\r')
		{
			;
		}
	}
	return 0;
}
