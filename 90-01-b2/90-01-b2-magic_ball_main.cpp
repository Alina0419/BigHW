/* 计科 2350218 陈佳怡 */
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
		cct_setfontsize("新宋体", 20);
		const char menu[][MAX_ITEM_LEN] = {
		"1.内部数组，生成初始状态，寻找是否有初始可消除项",
		"2.内部数组，消除初始可消除项后非0项下落并用0填充",
		"3.内部数组，消除初始可消除项后查找消除提示",
		"4.n*n的框架(无分隔线)，显示初始状态",
		"5.n*n的框架(有分隔线)，显示初始状态",
		"6.n*n的框架(无分隔线)，显示初始状态及初始可消除项",
		"7.n*n的框架(有分隔线)，消除初始可消除项后显示消除提示",
		"8.cmd图形界面(有分隔线，鼠标移动时显示坐标，右键退出)",
		"9.cmd图形界面完整版",
		"0.退出",
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
		parameter.title = "彩球菜单"; //标题是单数字符
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