/* 2350218 计科 陈佳怡 */
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
		cct_setfontsize("新宋体", 20);
		const char menu[][MAX_ITEM_LEN] = {
		"A.命令行找出可消除项并标识",
		"B.命令行完成一次消除（分步骤显示）",
		"C.命令行完成一关（分步骤显示）",
		"D.伪图形界面下用鼠标选择一个色块（无分隔线）",
		"E.伪图形界面下用鼠标选择一个色块（有分隔线）",
		"F.伪图形界面完成一次消除（分步骤）",
		"G.伪图形界面完整版",
		"Q.退出",
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
		parameter.title = "消灭星星菜单"; //标题是单数字符
		parameter.start_x = 10;
		parameter.start_y = 10;
		parameter.width = wide;	//不含菜单框左右框线
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