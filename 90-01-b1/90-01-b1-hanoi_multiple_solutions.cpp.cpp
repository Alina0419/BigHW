/* 信01 2350218 陈佳怡 */
#define rowbase_X 20
#define rowbase_Y 25
#define pillarbase_X 1//柱子底部第一个地方
#define pillarbase_Y 15
#define Image_X 9
#define Image_Y 20

#include<iostream>
#include <iomanip>
#include<conio.h>
#include<Windows.h>
#include "../include/cmd_console_tools.h"
#include "90-01-b1-hanoi.h"

using namespace std;

static int step;
static int top[3] = { 0 };
static int zhan[3][10] = { 0,0,0 };
static int speed;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

void move(int n, char ws, char wt, char wd, int hanoi_i)
{
    if (hanoi_i == 7)
    {
        //第一根要移动的柱子定位x=1+ws*10+11,y=15-n,宽度3 (zhan[ws][top[ws]]*2+1)  //记得调整栈！！！！
        int x = pillarbase_X + ws * 30 + 11;
        int y = pillarbase_Y - (n - zhan[ws][top[ws]]);
        while (y > 1)
        {
            cct_gotoxy(x, y);
            if (y >= 3)
                cct_setcolor(COLOR_HYELLOW);
            else
                cct_setcolor();
            cct_setcursor(CURSOR_INVISIBLE);
            cout << " ";
            for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//删掉一个
            {
                cct_setcolor();
                cct_gotoxy(x - kuan, y);
                cout << " ";
                cct_gotoxy(x + kuan, y);
                cout << " ";
            }
            y--;
            cct_gotoxy(x, y);
            for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)
            {
                cct_setcolor(zhan[ws][top[ws]] + 1);//莫名对了，记一下
                cout << " ";
                cct_gotoxy(x - kuan, y);
                cout << " ";
                cct_gotoxy(x + kuan, y);
                cout << " ";
            }
            Sleep(100);//记得改数值
        }
        //平移
        if (n % 2 == 0)//src-tmp
        {
            int X_Max = x - (zhan[ws][top[ws]] + 1) + 30 * (wt - ws) + 1;//原地画了一个X_Max是平移到最后位置x的开头
            if (wt > ws)
            {
                /* 将一串字符从左向右移动 */
                for (x = x - (zhan[ws][top[ws]] + 1); x < X_Max; x++)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* 延时0.1秒 */
                    Sleep(100);

                    if (x < X_Max - 1) {
                        /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //下移
                int Max_Y = y + 3 + (10 - top[wt]);
                while (y < Max_Y)
                {
                    cct_gotoxy(X_Max, y);
                    if (y >= 3)
                        cct_setcolor(COLOR_HYELLOW);
                    else
                        cct_setcolor();
                    cct_setcursor(CURSOR_INVISIBLE);
                    cout << " ";
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//删掉一个
                    {
                        cct_setcolor();
                        cct_gotoxy(X_Max - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Max + kuan, y);
                        cout << " ";
                    }
                    y++;
                    cct_gotoxy(X_Max, y);
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)
                    {
                        cct_setcolor(zhan[ws][top[ws]] + 1);//莫名对了，记一下
                        cout << " ";
                        cct_gotoxy(x - kuan, y);
                        cout << " ";
                        cct_gotoxy(x + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//记得改数值
                }
            }
            if (wt < ws)
            {
                int X_Min = x - (zhan[ws][top[ws]] + 1) - 30 * (ws - wt) - 1;//原地画了一个
                /* 将一串字符从左向右移动 */
                for (x = x - (zhan[ws][top[ws]] + 1); x > X_Min; x--)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* 延时0.1秒 */
                    Sleep(100);

                    if (x > X_Min + 1) {
                        /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //下移
                int Max_Y = y + 3 + (10 - top[wt]);
                X_Min = 1 + 11 + 30 * wt;
                while (y < Max_Y)
                {
                    cct_gotoxy(X_Min, y);
                    if (y >= 3)
                        cct_setcolor(COLOR_HYELLOW);
                    else
                        cct_setcolor();
                    cct_setcursor(CURSOR_INVISIBLE);
                    cout << " ";
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//删掉一个
                    {
                        cct_setcolor();
                        cct_gotoxy(X_Min - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Min + kuan, y);
                        cout << " ";
                    }
                    y++;
                    cct_gotoxy(X_Min, y);
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)
                    {
                        cct_setcolor(zhan[ws][top[ws]] + 1);//莫名对了，记一下
                        cout << " ";
                        cct_gotoxy(X_Min - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Min + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//记得改数值
                }
            }
        }

        else//src-dst
        {
            if (wd > ws)
            {
                int X_Max = x - (zhan[ws][top[ws]] + 1) + 30 * (wd - ws) + 1;//原地画了一个
                /* 将一串字符从左向右移动 */
                for (x = x - (zhan[ws][top[ws]] + 1); x < X_Max; x++)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* 延时0.1秒 */
                    Sleep(100);

                    if (x < X_Max - 1) {
                        /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //下移
                int Max_Y = y + 3 + (10 - top[wd]);
                while (y < Max_Y)
                {
                    cct_gotoxy(X_Max, y);
                    if (y >= 3)
                        cct_setcolor(COLOR_HYELLOW);
                    else
                        cct_setcolor();
                    cct_setcursor(CURSOR_INVISIBLE);
                    cout << " ";
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//删掉一个
                    {
                        cct_setcolor();
                        cct_gotoxy(X_Max - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Max + kuan, y);
                        cout << " ";
                    }
                    y++;
                    cct_gotoxy(X_Max, y);
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)
                    {
                        cct_setcolor(zhan[ws][top[ws]] + 1);//莫名对了，记一下
                        cout << " ";
                        cct_gotoxy(x - kuan, y);
                        cout << " ";
                        cct_gotoxy(x + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//记得改数值
                }
            }
            if (wd < ws)
            {
                int X_Min = x - (zhan[ws][top[ws]] + 1) - 30 * (ws - wd) - 1;//原地画了一个
                /* 将一串字符从左向右移动 */
                for (x = x - (zhan[ws][top[ws]] + 1); x > X_Min; x--)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* 延时0.1秒 */
                    Sleep(100);

                    if (x > X_Min + 1) {
                        /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //下移
                int Max_Y = y + 3 + (10 - top[wd]);
                X_Min = 1 + 11 + 30 * wd;
                while (y < Max_Y)
                {
                    cct_gotoxy(X_Min, y);
                    if (y >= 3)
                        cct_setcolor(COLOR_HYELLOW);
                    else
                        cct_setcolor();
                    cct_setcursor(CURSOR_INVISIBLE);
                    cout << " ";
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//删掉一个
                    {
                        cct_setcolor();
                        cct_gotoxy(X_Min - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Min + kuan, y);
                        cout << " ";
                    }
                    y++;
                    cct_gotoxy(X_Min, y);
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)
                    {
                        cct_setcolor(zhan[ws][top[ws]] + 1);//莫名对了，记一下
                        cout << " ";
                        cct_gotoxy(X_Min - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Min + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//记得改数值
                }
            }
        }
        return;
    }
    int x = pillarbase_X + ws * 30 + 11;
    int y = pillarbase_Y -top[ws];
    while (y > 1)//上移
    {
        cct_gotoxy(x, y);
        if (y >= 3)
            cct_setcolor(COLOR_HYELLOW);
        else
            cct_setcolor();
        cct_setcursor(CURSOR_INVISIBLE);
        cout << " ";//删掉中间的
        for (int kuan = zhan[ws][top[ws] - 1];kuan > 0;kuan--)//删掉周围的
        {
            cct_gotoxy(x, y);
            cct_setcolor();
            cct_gotoxy(x - kuan, y);
            cout << " ";
            cct_gotoxy(x + kuan, y);
            cout << " ";
        }
        y--;
        cct_gotoxy(x, y);
        for (int kuan = zhan[ws][top[ws] - 1];kuan > 0;kuan--)
        {
            cct_gotoxy(x, y);//太关键了！！！找半天，我是弱智
            cct_setcolor(zhan[ws][top[ws] - 1]);
            cout << " ";
            cct_gotoxy(x - kuan, y);
            cout << " ";
            cct_gotoxy(x + kuan, y);
            cout << " ";
        }
        Sleep(100-speed*20);//记得改数值
    }
    //平移
    if (wd > ws)
    {
        int X_Max = x - (zhan[ws][top[ws] - 1]) + 30 * (wd - ws);
        /* 将一串字符从左向右移动 */
        for (x = x - (zhan[ws][top[ws] - 1]); x < X_Max+1; x++)
        {
            cct_showch(x, y, ' ', (zhan[ws][top[ws] - 1]), COLOR_WHITE, 2 * (zhan[ws][top[ws] - 1]) + 1);

            Sleep(100-speed*20);

            if (x < X_Max+1)
            {
                /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws] - 1]) + 1);
            }
        }
        //下移
        X_Max = X_Max + (zhan[ws][top[ws] - 1]);
        int Max_Y = y + 3 + (10 - top[wd]);
        while (y < Max_Y)
        {
            cct_gotoxy(X_Max, y);
            if (y >= 3)
                cct_setcolor(COLOR_HYELLOW);
            else
                cct_setcolor();
            cct_setcursor(CURSOR_INVISIBLE);
            cout << " ";
            for (int kuan = (zhan[ws][top[ws] - 1]);kuan > 0;kuan--)//删掉一个
            {
                cct_gotoxy(X_Max, y);
                cct_setcolor();
                cct_gotoxy(X_Max - kuan, y);
                cout << " ";
                cct_gotoxy(X_Max + kuan, y);
                cout << " ";
            }
            y++;
            cct_gotoxy(X_Max, y);
            for (int kuan = (zhan[ws][top[ws] - 1]);kuan > 0;kuan--)
            {
                cct_gotoxy(X_Max, y);
                cct_setcolor(zhan[ws][top[ws] - 1]);//莫名对了，记一下
                cout << " ";
                cct_gotoxy(X_Max - kuan, y);
                cout << " ";
                cct_gotoxy(X_Max + kuan, y);
                cout << " ";
            }
            Sleep(100 - speed * 20);//记得改数值
        }
    }
    if (wd < ws)
    {
        int X_Min = x - (zhan[ws][top[ws] - 1]) - 30 * (ws - wd);//原地画了一个
        /* 将一串字符从右向左移动 */
        for (x = x - (zhan[ws][top[ws] - 1]); x > X_Min-1; x--)
        {
            cct_showch(x, y, ' ', (zhan[ws][top[ws] - 1]), COLOR_WHITE, 2 * zhan[ws][top[ws] - 1]+1);

            Sleep(100 - speed * 20);

            if (x > X_Min-1 )
            {
                /* 清除显示(最后一次保留)，清除方法为用正常颜色+空格重画一遍刚才的位置 */
                cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * zhan[ws][top[ws] - 1] + 1);
            }
        }
        //下移
        int Max_Y = y + 3 + (10 - top[wd]);
        X_Min = 1 + 11 + 30 * wd;
        while (y < Max_Y)
        {
            cct_gotoxy(X_Min, y);
            if (y >= 3)
                cct_setcolor(COLOR_HYELLOW);
            else
                cct_setcolor();
            cct_setcursor(CURSOR_INVISIBLE);
            cout << " ";
            for (int kuan = (zhan[ws][top[ws] - 1]);kuan > 0;kuan--)//删掉一个
            {
                cct_gotoxy(X_Min, y);
                cct_setcolor();
                cct_gotoxy(X_Min - kuan, y);
                cout << " ";
                cct_gotoxy(X_Min + kuan, y);
                cout << " ";
            }
            y++;
            cct_gotoxy(X_Min, y);
            for (int kuan = (zhan[ws][top[ws] - 1]);kuan > 0;kuan--)
            {
                cct_gotoxy(X_Min, y);
                cct_setcolor(zhan[ws][top[ws] - 1]);
                cout << " ";
                cct_gotoxy(X_Min - kuan, y);
                cout << " ";
                cct_gotoxy(X_Min + kuan, y);
                cout << " ";
            }
            Sleep(100 - speed * 20);
        }
    }
}

void src_plate(int n,char src,char tmp,char dst)
{
    for (int i=0;i<n;i++)
    {

        cct_gotoxy(pillarbase_X + 30*(src - 'A'), pillarbase_Y - 1-i);
        for (int k=0;k<11-n+i;k++)//开头打印几个缺省空格
        {
            //恢复缺省颜色
            cct_setcolor();
            cout << " ";
        }
        for (int j = 0;j<(n-i)*2+1;j++)//打印几个彩色空格
        {
            //设置背景色
            cct_setcolor(n-i);//n-i为盘号
            cout << " ";
        }
        Sleep(100);
    }
}


void pillar()
{
    //画底座
    //相对位置，x相差30
    cct_gotoxy(pillarbase_X,pillarbase_Y);
    cct_setcolor(COLOR_HYELLOW);
    cct_setcursor(CURSOR_INVISIBLE);
    cct_gotoxy(pillarbase_X, pillarbase_Y);
    for (int i = 0;i <= 22;i++)
    {
        cout << " ";
    }
    Sleep(100);
    cct_gotoxy(pillarbase_X+30, pillarbase_Y);
    for (int i = 0;i <= 22;i++)
    {
        cout << " ";
    }
    Sleep(100);
    cct_gotoxy(pillarbase_X + 60, pillarbase_Y);
    for (int i = 0;i <= 22;i++)
    {
        cout << " ";
    }
    Sleep(100);
    //画三根柱子
    for (int i = 1;i <= 12; i++)//行
    {
        for (int j = 0;j < 3;j++)//列
        {
            cct_gotoxy(pillarbase_X + 11+30*j, pillarbase_Y - i);
            cout << " ";
            Sleep(100);
        }
    }

}

void printkong(int n)
{
    for (;10 - n > 0;n++)
        cout << "  ";
}

void printABC()
{
    cout << " A:";
    for (int i = 0;i < top[0];i++)
        cout << setw(2) << zhan[0][i];
    printkong(top[0]);
    cout << " B:";
    for (int i = 0;i < top[1];i++)
        cout << setw(2) << zhan[1][i];
    printkong(top[1]);
    cout << " C:";
    for (int i = 0;i < top[2];i++)
        cout << setw(2) << zhan[2][i];
    printkong(top[2]);
    cout << endl;
}

void image(int hanoi_i)//传参数定位置
{
    int n = 0;
    if (hanoi_i == 8||hanoi_i==9)
    {
        n = 10;
    }
    int x = 9;
    int y = 20+n;
    cct_gotoxy(x, y);
    cout << "==========================" << endl;
    cout << "           A         B         C";
    y = 19+n;
    for (int i = 0;i < top[0];i++)//打印竖着的数字
    {
        x = 10;
        cct_gotoxy(x, y--);
        cout << setw(2) << zhan[0][i];
    }
    for (int i = top[0];i < 10;i++)//打印竖着的空格
    {
        x = 10;
        cct_gotoxy(x, y--);
        cout << "  ";
    }
    y = 19+n;
    for (int i = 0;i < top[1];i++)
    {
        x = 20;
        cct_gotoxy(x, y--);
        cout << setw(2) << zhan[1][i];
    }
    for (int i = top[1];i < 10;i++)//打印竖着的空格
    {
        x = 20;
        cct_gotoxy(x, y--);
        cout << "  ";
    }
    y = 19+n;
    for (int i = 0;i < top[2];i++)
    {
        x = 30;
        cct_gotoxy(x, y--);
        cout << setw(2) << zhan[2][i];
    }
    for (int i = top[2];i < 10;i++)//打印竖着的空格
    {
        x = 30;
        cct_gotoxy(x, y--);
        cout << "  ";
    }
}

void shuru(int* n, char* src, char* tmp, char* dst,int hanoi_i)
{
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> *n;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*n >= 1 && *n <= 10)
            break;
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> *src;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*src == 'A' || *src == 'B' || *src == 'C')
            break;
        if (*src == 'a' || *src == 'b' || *src == 'c')
        {
            *src = *src - 32;
            break;
        }
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> *dst;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*dst == *src || *dst - 32 == *src)
        {
            cout << "目标柱(" << *src << ")不能与起始柱(" << *src << ")相同" << endl;
            continue;
        }
        else if (*dst == 'A' || *dst == 'B' || *dst == 'C')
            break;
        else if (*dst == 'a' || *dst == 'b' || *dst == 'c')
        {
            *dst = *dst - 32;
            break;
        }
    }
    *tmp = 'A' + 'B' + 'C' - *src - *dst;
    if (hanoi_i == 4|| hanoi_i == 8)
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> speed;
    }
}

void hanoi_choice(int n, char src, char tmp, char dst, int hanoi_i, int weizhi)
{
    int ws, wd;//位置-src,位置-dst
    if (weizhi == 1)//是否打印步数/光标定位
    {
        if (hanoi_i == 4)
        {
            cct_gotoxy(rowbase_X, rowbase_Y);
        }
        else if (hanoi_i == 8)
        {
            //恢复缺省颜色
            cct_setcolor();
            //恢复光标
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cct_gotoxy(rowbase_X, rowbase_Y+10);//打印ABC
        }
        if (hanoi_i)
            cout << "第" << setw(4) << ++step << " 步";
        return;
    }
    else if (weizhi == 2)
    {
        if (hanoi_i == 3)
        {
            if (src == 'A')
            {
                ws = 0;
                wd = dst == 'B' ? 1 : 2;

            }
            else if (src == 'B')
            {
                ws = 1;
                wd = dst == 'A' ? 0 : 2;
            }
            else
            {
                ws = 2;
                wd = dst == 'A' ? 0 : 1;
            }
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            printABC();
        }
        else if (hanoi_i == 4)
        {
            if (src == 'A')
            {
                ws = 0;
                wd = dst == 'B' ? 1 : 2;

            }
            else if (src == 'B')
            {
                ws = 1;
                wd = dst == 'A' ? 0 : 2;
            }
            else
            {
                ws = 2;
                wd = dst == 'A' ? 0 : 1;
            }
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            printABC();
            if (speed != 0)
                Sleep(800 / speed);
            else if (speed == 0)
            {
                while (_getch() != '\r')
                    ;
            }
            image(4);
            if (speed != 0)
                Sleep(800 / speed);
            else if (speed == 0)
            {
                while (_getch() != '\r')
                    ;
            }
        }
        else if (hanoi_i == 8)
        {
            if (src == 'A')
            {
                ws = 0;
                wd = dst == 'B' ? 1 : 2;

            }
            else if (src == 'B')
            {
                ws = 1;
                wd = dst == 'A' ? 0 : 2;
            }
            else
            {
                ws = 2;
                wd = dst == 'A' ? 0 : 1;
            }
            //恢复缺省颜色
            cct_setcolor();
            //恢复光标
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            move(n, ws, 'A'+'B'+'C'-ws-wd, wd, hanoi_i);
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            //恢复缺省颜色
            cct_setcolor();
            //恢复光标
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cct_gotoxy(rowbase_X+18, rowbase_Y+10);
            printABC();
            image(8);
            if (speed != 0)
                Sleep(800 / speed);
            else if (speed == 0)
            {
                while (_getch() != '\r')
                    ;
            }
        }
        else
            cout << endl;
        return;

    }
    else if (weizhi == 3)
    {
        if (hanoi_i == 4)
        {
            cct_gotoxy(rowbase_X, rowbase_Y);
        }
        else if (hanoi_i == 8)
        {
            //恢复缺省颜色
            cct_setcolor();
            //恢复光标
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cct_gotoxy(rowbase_X, rowbase_Y + 10);//打印ABC
        }
        if (hanoi_i)
            cout << "第" << setw(4) << ++step << " 步";
        return;
    }
    else if (weizhi == 4)
    {
        if (hanoi_i == 3)
        {
            if (src == 'A')
            {
                ws = 0;
                wd = dst == 'B' ? 1 : 2;

            }
            else if (src == 'B')
            {
                ws = 1;
                wd = dst == 'A' ? 0 : 2;
            }
            else
            {
                ws = 2;
                wd = dst == 'A' ? 0 : 1;
            }
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            printABC();
        }
        else if (hanoi_i == 4)
        {
            if (src == 'A')
            {
                ws = 0;
                wd = dst == 'B' ? 1 : 2;

            }
            else if (src == 'B')
            {
                ws = 1;
                wd = dst == 'A' ? 0 : 2;
            }
            else
            {
                ws = 2;
                wd = dst == 'A' ? 0 : 1;
            }
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            printABC();
            if (speed != 0)
                Sleep(800 / speed);
            else if (speed == 0)
            {
                while (_getch() != '\r')
                    ;
            }
            image(4);
            if (speed != 0)
                Sleep(800 / speed);
            else if (speed == 0)
            {
                while (_getch() != '\r')
                    ;
            }
        }
        else if (hanoi_i == 8)
        {
            if (src == 'A')
            {
                ws = 0;
                wd = dst == 'B' ? 1 : 2;

            }
            else if (src == 'B')
            {
                ws = 1;
                wd = dst == 'A' ? 0 : 2;
            }
            else
            {
                ws = 2;
                wd = dst == 'A' ? 0 : 1;
            }
            //恢复缺省颜色
            cct_setcolor();
            //恢复光标
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            move(n, ws, 'A' + 'B' + 'C' - ws - wd, wd, hanoi_i);
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            //恢复缺省颜色
            cct_setcolor();
            //恢复光标
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cct_gotoxy(rowbase_X+18, rowbase_Y + 10);
            printABC();
            image(8);
            if (speed != 0)
                Sleep(800 / speed);
            else if (speed == 0)
            {
                while (_getch() != '\r')
                    ;
            }
        }
        else
            cout << endl;
        return;
    }

}

void hanoi(int n, char src, char tmp, char dst, int hanoi_i)
{
    if (n == 1)
    {//加步数
        hanoi_choice(n, src, tmp, dst, hanoi_i, 1);
        cout << "(" << setw(2) << n << "# " << src << "-->" << dst << ")";
        hanoi_choice(n, src, tmp, dst, hanoi_i, 2);
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp, hanoi_i);
        hanoi_choice(n, src, tmp, dst, hanoi_i, 3);
        cout << "(" << setw(2) << n << "# " << src << "-->" << dst << ")";
        hanoi_choice(n, src, tmp, dst, hanoi_i, 4);
        hanoi(n - 1, tmp, src, dst, hanoi_i);
    }
}


//主函数输入1
void hanoi_1()
{
    cout << endl;
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n,&src,&tmp,&dst,1);
    hanoi(n, src, tmp, dst,0);
}

void hanoi_2()
{
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n, &src, &tmp, &dst,2);
    hanoi(n, src, tmp, dst,2);
    step = 0;
}

void hanoi_3()
{
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n, &src, &tmp, &dst,3);
    int n2 = n;
    int ws;
    if (src == 'A')
        ws = 0;
    else if (src == 'B')
        ws = 1;
    else
        ws = 2;
    while (top[ws] < 10)
    {
        zhan[ws][top[ws]++] = n2;
        n2--;
        if (n2 == 0)
            break;
    }
    hanoi(n, src, tmp, dst, 3);
    step = 0;
    for (int i = 0;i < 3;i++)
    {
        top[i] = 0;
    }
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;i < 10;i++)
        {
            zhan[i][j] = 0;
        }
    }
}
void hanoi_4()
{
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n, &src, &tmp, &dst,4);
    int n2 = n;
    int ws;
    if (src == 'A')
        ws = 0;
    else if (src == 'B')
        ws = 1;
    else
        ws = 2;
    while (top[ws] < 10)
    {
        zhan[ws][top[ws]++] = n2;
        n2--;
        if (n2 == 0)
            break;
    }
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed;
    hanoi(n, src, tmp, dst, 4);
    step=0;
    for (int i = 0;i < 3;i++)
    {
        top[i] = 0;
    }
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;i < 10;i++)
        {
            zhan[i][j] = 0 ;
        }
    }
    cct_gotoxy(rowbase_X, rowbase_Y+1);
}
void hanoi_5()
{
    //清屏
    cct_cls();
    pillar();
    //恢复缺省颜色
    cct_setcolor();
    //恢复光标
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_gotoxy(pillarbase_X, 30);
}
void hanoi_6()
{
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n, &src, &tmp, &dst, 6);
    cct_cls();
    cct_gotoxy(0, 0);
    cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层";
    pillar();

    src_plate(n, src, tmp, dst);

    //恢复缺省颜色
    cct_setcolor();
    //恢复光标
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_gotoxy(pillarbase_X, 30);
}

void hanoi_7()
{
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n, &src, &tmp, &dst, 7);
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << ",共 " << n << " 层";
    pillar();

    src_plate(n, src, tmp, dst);
    Sleep(800);
    int ws, wd, wt;
    if (src == 'A')
    {
        ws = 0;
        wd = dst == 'B' ? 1 : 2;

    }
    else if (src == 'B')
    {
        ws = 1;
        wd = dst == 'A' ? 0 : 2;
    }
    else
    {
        ws = 2;
        wd = dst == 'A' ? 0 : 1;
    }
    wt = 0 + 1 + 2 - ws - wd;
    move(n, ws, wt, wd,7);

    //恢复缺省颜色
    cct_setcolor();
    //恢复光标
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_gotoxy(pillarbase_X, 30);
}
void hanoi_8()
{
    cct_setconsoleborder(120, 55);
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n, &src, &tmp, &dst, 8);
    int n2 = n;
    int ws;
    if (src == 'A')
        ws = 0;
    else if (src == 'B')
        ws = 1;
    else
        ws = 2;
    while (top[ws] < 10)
    {
        zhan[ws][top[ws]++] = n2;
        n2--;
        if (n2 == 0)
            break;
    }
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed;

    pillar();
    src_plate(n, src, tmp, dst);

    if (speed != 0)
        Sleep(800 / speed);
    else if (speed == 0)
    {
        while (_getch() != '\r')
            ;
    }
    //恢复缺省颜色
    cct_setcolor();
    //恢复光标
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    hanoi(n, src, tmp, dst, 8);


    //恢复缺省颜色
    cct_setcolor();
    //恢复光标
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_gotoxy(pillarbase_X, 50);

    step = 0;
    for (int i = 0;i < 3;i++)
    {
        top[i] = 0;
    }
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;i < 10;i++)
        {
            zhan[i][j] = 0;
        }
    }
    cct_gotoxy(pillarbase_X, 50);

}

int shuru_9(int *ws,int *wd)
{
    char n1, n2;
    while (1)
    {
        cin >> n1;
        cin >> n2;
        cin.clear();
        cin.ignore(65536, '\n');
        int x = 0;
        if (n1 == 'Q' || n1 == 'q')
        {
            x = 1;
            return x;
        }
        if (n1 == 'a' || n1 == 'b' || n1 == 'c')
        {
            n1 = n1 - 32;
        }
        if (n2 == 'a' || n2 == 'b' || n2 == 'c')
        {
            n2 = n2 - 32;
        }
        
        if (n1 == 'A' || n1 == 'B' || n1 == 'C'&&n2 == 'A' || n2 == 'B' || n2 == 'C'&&n1!=n2)
            break;
        else
        {
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);//输入的地方
            cout << "                    ";
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);
            continue;
        }
    }
    if (n1 == 'A')
    {
        *ws = 0;
        if (n2 == 'B')
            *wd = 1;
        else
            *wd = 2;

    }
    else if (n1 == 'B')
    {
        *ws = 1;
        *wd = n2 == 'A' ? 0 : 2;
    }
    else
    {
        *ws = 2;
        *wd = n2 == 'A' ? 0 : 1;
    }
}

void hanoi_9()
{
    cct_setconsoleborder(120, 55);
    int n;
    char src;
    char tmp;
    char dst;
    shuru(&n, &src, &tmp, &dst, 9);
    int n2 = n;
    int ws,wd;
    if (src == 'A')
    {
        ws = 0;
        wd = dst == 'B' ? 1 : 2;

    }
    else if (src == 'B')
    {
        ws = 1;
        wd = dst == 'A' ? 0 : 2;
    }
    else
    {
        ws = 2;
        wd = dst == 'A' ? 0 : 1;
    }
    while (top[ws] < 10)
    {
        zhan[ws][top[ws]++] = n2;
        n2--;
        if (n2 == 0)
            break;
    }
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
    pillar();
    src_plate(n, src, tmp, dst);
    cct_gotoxy(rowbase_X, rowbase_Y + 10);
    //恢复缺省颜色
    cct_setcolor();
    //恢复光标
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cout << "初始：            ";
    printABC();
    image(9);
    //以上为初始的图、横、纵
    while (1)
    {
        cct_gotoxy(rowbase_X, rowbase_Y + 10+1);
        cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出)：";
        int x=shuru_9(&ws,&wd);
        if (x == 1)
        {
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "游戏中止";
            step = 0;
            for (int i = 0;i < 3;i++)
            {
                top[i] = 0;
            }
            for (int i = 0;i < 3;i++)
            {
                for (int j = 0;i < 10;i++)
                {
                    zhan[i][j] = 0;
                }
            }
            cct_gotoxy(pillarbase_X, 50);
            return;
        }
        if (top[ws] == 0)
        {
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "源柱为空";
            Sleep(800);
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);//第二行
            cout << "                    ";
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);//输入的地方
            cout << "                    ";
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);
            continue;

        }
        if (zhan[ws][top[ws] - 1] > zhan[wd][top[wd] - 1]&& zhan[wd][top[wd] - 1]!=0)
        {
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "大盘压小盘";
            Sleep(800);
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "                    ";
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);
            cout << "                    ";
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);
            continue;
        }
        move(n, ws, 'A' + 'B' + 'C' - ws - wd, wd, 9);
        zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
        //恢复缺省颜色
        cct_setcolor();
        //恢复光标
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        cct_gotoxy(rowbase_X, rowbase_Y + 10);
        cout << "第" << setw(4) << ++step << " 步";
        cct_gotoxy(rowbase_X + 18, rowbase_Y + 10);
        printABC();
        image(9);
        //恢复缺省颜色

        if (top[wd] == n)
        {
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "游戏胜利,宝宝好棒！！！";
            step = 0;
            for (int i = 0;i < 3;i++)
            {
                top[i] = 0;
            }
            for (int i = 0;i < 3;i++)
            {
                for (int j = 0;i < 10;i++)
                {
                    zhan[i][j] = 0;
                }
            }
            cct_gotoxy(pillarbase_X, 50);
            return;
        }

        cct_setcolor();
        //恢复光标
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        cct_gotoxy(rowbase_X+59, rowbase_Y + 10 + 1);
        cout << "                    ";
        cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);
    }

    //恢复缺省颜色
    cct_setcolor();
    //恢复光标
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_gotoxy(pillarbase_X, 50);
    step = 0;
    for (int i = 0;i < 3;i++)
    {
        top[i] = 0;
    }
    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;i < 10;i++)
        {
            zhan[i][j] = 0;
        }
    }
    cct_gotoxy(pillarbase_X, 50);
}