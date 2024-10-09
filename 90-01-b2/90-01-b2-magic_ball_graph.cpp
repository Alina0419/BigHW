/* 计科 2350218 陈佳怡 */
#define TIME  10
#define Size_max 10

#include<iostream>
#include<conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include"../include/cmd_console_tools.h"
#include"90-01-b2-magic_ball.h"
#include"../include/include_menu+tools.h"
using namespace std;

void ball_789(int row,int col,char base[Size_max][Size_max],bool highlight[Size_max][Size_max])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (highlight[i][j])
            {
                int ball_x, ball_y;
                ball_x = 2 + 4 * j;
                ball_y = 2 + 2 * i;
                cct_showstr(ball_x, ball_y, "●", base[i][j], COLOR_BLACK);
            }
        }
    }
}

void eliminate(int row, int col, char base[Size_max][Size_max], bool highlight[Size_max][Size_max],int *score)
{
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (highlight[i][j])
            {
                highlight[i][j] = false;
                int ball_x, ball_y;
                ball_x = 2 + 4 * j;
                ball_y = 2 + 2 * i;
                for (int t = 0;t < 5;t++)
                {
                    Sleep(5 * TIME);
                    cct_showstr(ball_x, ball_y, "¤", base[i][j], COLOR_BLACK);
                    Sleep(5 * TIME);
                    cct_showstr(ball_x, ball_y, "〇", base[i][j], COLOR_BLACK);
                }
                base[i][j] = '0';//爆了的置零
                (*score)++;
                cct_showstr(ball_x, ball_y, "  ", COLOR_HWHITE, COLOR_BLACK);
            }
        }
    }
    void (*p)(int, int, char[Size_max][Size_max], bool[Size_max][Size_max],char,int,int,int);
    p = move_graph;
    p(row,col,base,highlight,'b',2,1,DOWN);
    //更新状态，复制的，有空可以试试结合graph和base
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (base[i][j] == '0')
                highlight[i][j] = true;
        }
    }
}

void fill_new(int row, int col, char base[Size_max][Size_max], bool highlight[Size_max][Size_max])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (base[i][j] == '0')
            {
                base[i][j] = char(rand() % 9 + '1');
                int ball_x, ball_y;
                ball_x = 2 + 4 * j;
                ball_y = 2 + 2 * i;
                Sleep(10 * TIME);
                cct_showstr(ball_x, ball_y, "〇", base[i][j], COLOR_BLACK);
                highlight[i][j] = false;
            }
        }
    }
}

void magic_4()
{
    int row, col;
    char base[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,5,9);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "初始数组：" << endl;
    output_base(row, col, base, 0, 0, false);//无高光
    cout << "按回车键显示图形..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("新宋体", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 6+row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row,col,0,4);
    ball_painting(row, col, base, 4,'b');
    end();
}

void magic_5()
{
    int row, col;
    char base[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,5,9);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "初始数组：" << endl;
    output_base(row, col, base, 0, 0, false);//无高光
    cout << "按回车键显示图形..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("新宋体", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col,0, 5);
    ball_painting(row, col, base, 5, 'b');
    end();
}

void magic_6()
{
    int row, col;
    char base[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,5,9);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "初始数组：" << endl;
    output_base(row, col, base, 0, 0, false);//无高光
    cout << "按回车键显示图形..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("新宋体", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 6 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col,0, 6);
    ball_painting(row, col, base, 6, 'b');
    bool highlight[Size_max][Size_max] = { 0 };
    find_highlight(row, col, base, highlight);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (highlight[i][j])
            {
                int ball_x, ball_y;
                ball_x = 2 + 2 * j;
                ball_y = 2 + i;
                cct_showstr(ball_x, ball_y, "●", base[i][j], COLOR_BLACK);
            }
        }
    }
    cct_setcolor();
    cct_gotoxy(0, 4 + row);
    end();
}

void magic_7()
{
    int row, col;
    char base[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,5,9);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "初始数组：" << endl;
    output_base(row, col, base, 0, 0, false);//无高光
    cout << "按回车键显示图形..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("新宋体", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col,0, 7);
    bool highlight[Size_max][Size_max] = { 0 };
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//是否有高光
    ball_painting(row, col, base, 7, 'b');
    int wenzi_x,wenzi_y;//保留下方打印文字的位置
    cct_getxy(wenzi_x,wenzi_y);
    int score = 0;
    while (1)
    {
        cct_setcolor();
        has_highlight = find_highlight(row, col, base, highlight);//是否有高光
        ball_789(row, col,base, highlight);

        if (!has_highlight)
        {
            cct_gotoxy(0, 0);
            cout << "屏幕：" << lines << "行" << cols << "列(未找到初始可消除项)";
            break;
        }
        //查找可消除项，若没有可消除的了，第一行直接输出（未找到初始可消除项目）
        cct_setcolor();
        cct_gotoxy(0, wenzi_y);
        cout << "按回车键进行消除及下落除0操作...";//爆炸+下落，记录输出位置，下落是一列一列地落
        while (_getch() != '\r')
            ;
        eliminate(row, col, base, highlight, &score);
        cct_setcolor();
        cct_gotoxy(0, wenzi_y);
        cout << "按回车键进行新值填充...          ";//一行一行地填
        while (_getch() != '\r')
            ;
        fill_new(row, col, base, highlight);
    }
    cct_gotoxy(0, wenzi_y);
    cout << "按回车键显示消除提示...";
    while (_getch() != '\r')
        ;
    bool removable[Size_max][Size_max] = { 0 };
    hint(row, col, base, removable);
    hint_graph(row, col, base, removable,'b');
    cct_setcolor();
    cct_gotoxy(0, wenzi_y);
    end();
}

void magic_8()
{
    int row, col;
    char base[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,5,9);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cct_cls();
    cct_setfontsize("新宋体", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col,0, 7);
    bool highlight[Size_max][Size_max] = { 0 };
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//是否有高光
    ball_painting(row, col, base, 7, 'b');
    int wenzi_x, wenzi_y;//保留下方打印文字的位置
    cct_getxy(wenzi_x, wenzi_y);
    int score = 0;
    while (1)
    {
        cct_setcolor();
        has_highlight = find_highlight(row, col, base, highlight);//是否有高光
        ball_789(row, col, base, highlight);

        if (!has_highlight)
        {
            cct_gotoxy(0, 0);
            break;
        }
        eliminate(row, col, base, highlight,&score);
        fill_new(row, col, base, highlight);
    }
    cct_gotoxy(0,0);
    cout << "屏幕：" << lines << "行" << cols << "列(当前分数：0 右键退出)" ;//题目9中需定义score
    bool removable[Size_max][Size_max] = { 0 };
    hint(row, col, base, removable);
    hint_graph(row, col, base, removable,'b');
    cct_setcolor();
    cct_gotoxy(0, wenzi_y);
    cct_enable_mouse();//允许使用鼠标
    int X = 0, Y = 0;
    int ret, maction,loop=1;
    int keycode1, keycode2;
    while (loop)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//后面两个都没用的
        if (ret == CCT_MOUSE_EVENT)
        {
            int weizhi_X = (X - 2) / 4;//X和j对应
            int weizhi_Y = (Y - 2) / 2;
            cct_gotoxy(0, wenzi_y);
            if (maction == MOUSE_ONLY_MOVED)
            {
                if ((X-2)%4==0&&(Y-2)%2==0)
                    cout << "[当前光标] " << char(weizhi_Y + 'A') << "行" << weizhi_X+1 << "列  ";
                else
                    cout << "[当前光标] 位置非法";
                continue;
            }
            switch (maction)
            {
                case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
                {
                    if (((X - 2) % 4 == 0 && (Y - 2) % 2 == 0)&&removable[weizhi_Y][weizhi_X])
                    {
                        cout << "当前选择" << char(weizhi_Y + 'A') << "行" << weizhi_X + 1 << "列  ";
                    }
                    else if(((X - 2) % 4 == 0 && (Y - 2) % 2 == 0) && !removable[weizhi_Y][weizhi_X])
                        cout << "不能选择" << char(weizhi_Y + 'A') << "行" << weizhi_X + 1 << "列  ";
                    break;
                }
                case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
                    loop = 0;
                    break;
                default:
                    break;
            } //end of switch(maction)
        } //end of if (CCT_MOUSE_EVENT)
    }
    cct_gotoxy(0, wenzi_y);
    end();
}

void magic_9()
{
    int row, col;
    char base[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,5,9);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cct_cls();
    cct_setfontsize("新宋体", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col,0, 7);
    bool highlight[Size_max][Size_max] = { 0 };
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//是否有高光
    ball_painting(row, col, base, 7, 'b');
    int wenzi_x, wenzi_y;//保留下方打印文字的位置
    cct_getxy(wenzi_x, wenzi_y);
    int score_start = 0;
    while (1)
    {
        cct_setcolor();
        has_highlight = find_highlight(row, col, base, highlight);//是否有高光
        ball_789(row, col, base, highlight);

        if (!has_highlight)
        {
            cct_gotoxy(0, 0);
            break;
        }
        eliminate(row, col, base, highlight,&score_start);
        fill_new(row, col, base, highlight);
    }
    cct_gotoxy(0,0);
    int score = 0;
    cout << "屏幕：" << lines << "行" << cols << "列(当前分数：" << score << " 右键退出)";//题目9中需定义score
    while (1)//游戏过程函数
    {
        bool removable[Size_max][Size_max] = { 0 };
        hint(row, col, base, removable);
        hint_graph(row, col, base, removable,'b');
        int has_removable = 0;
        for (int i = 0;i < row;i++)
        {
            for (int j = 0;j < col;j++)
            {
                if (removable[i][j])
                {
                    has_removable = 1;
                    break;
                }
                if (has_removable)
                    break;
            }
        }
        if (!has_removable)
        {
            cct_setcolor();
            cct_gotoxy(0, 0);
            cout << "无可消除项，游戏结束！最终得分：" << score << "    ";
            break;
        }
        cct_setcolor();
        cct_gotoxy(0, 0);
        cout << "屏幕：" << lines << "行" << cols << "列(当前分数：" << score << " 右键退出)";
        cct_gotoxy(0, wenzi_y);
        cct_enable_mouse();//允许使用鼠标
        int X = 0, Y = 0;
        int ret, maction, loop = 1,mycontinue=1;
        int keycode1, keycode2;
        int removable_highlight = 0;
        int removable_highlight_col, removable_highlight_row;

        while (loop)
        {
            ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//后面两个都没用的
            if (ret == CCT_MOUSE_EVENT)
            {
                int weizhi_X = (X - 2) / 4;//X和j对应
                int weizhi_Y = (Y - 2) / 2;
                cct_gotoxy(0, wenzi_y);
                if (maction == MOUSE_ONLY_MOVED)
                {
                    if ((X - 2) % 4 == 0 && (Y - 2) % 2 == 0)//有空可以改一下范围
                        cout << "[当前光标] " << char(weizhi_Y + 'A') << "行" << weizhi_X + 1 << "列            ";
                    else
                        cout << "[当前光标] 位置非法          ";
                    continue;
                }
                switch (maction)
                {
                    case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
                    {
                        if (((X - 2) % 4 == 0 && (Y - 2) % 2 == 0) && removable[weizhi_Y][weizhi_X])
                        {
                            if (!removable_highlight)
                            {
                                cct_showstr(X, Y, "◎", base[weizhi_Y][weizhi_X], COLOR_HWHITE);
                                removable_highlight_row = weizhi_Y;
                                removable_highlight_col = weizhi_X;
                                removable_highlight = 1;
                            }
                            else if (removable_highlight)
                            {
                                if (removable_highlight_row == weizhi_Y && removable_highlight_col == weizhi_X)//取消
                                {
                                    cct_showstr(X, Y, "◎", base[weizhi_Y][weizhi_X], COLOR_BLACK);
                                    removable_highlight = 0;
                                }
                                else if (abs(weizhi_Y - removable_highlight_row) + abs(weizhi_X - removable_highlight_col) > 1)//换选
                                {
                                    cct_showstr(X, Y, "◎", base[weizhi_Y][weizhi_X], COLOR_HWHITE);
                                    cct_showstr(2 + 4 * removable_highlight_col, 2 + 2 * removable_highlight_row, "◎", base[removable_highlight_row][removable_highlight_col], COLOR_BLACK);
                                    removable_highlight_row = weizhi_Y;
                                    removable_highlight_col = weizhi_X;
                                }
                                else if (abs(weizhi_Y - removable_highlight_row) + abs(weizhi_X - removable_highlight_col) <= 1)//判断是否可消
                                {
                                    char change;
                                    change = base[removable_highlight_row][removable_highlight_col];
                                    base[removable_highlight_row][removable_highlight_col] = base[weizhi_Y][weizhi_X];
                                    base[weizhi_Y][weizhi_X] = change;
                                    has_highlight = find_highlight(row, col, base, highlight);
                                    if (has_highlight)
                                    {
                                        loop = 0;
                                        break;
                                    }
                                    else
                                    {
                                        cct_gotoxy(0, wenzi_y);
                                        cout << "不能交换" << char(weizhi_Y + 'A') << "行" << weizhi_X + 1 << "列  <=>  " << char(weizhi_Y + 'A') << "行" << weizhi_X + 1 << "列";
                                        Sleep(50 * TIME);
                                        char change;
                                        change = base[removable_highlight_row][removable_highlight_col];
                                        base[removable_highlight_row][removable_highlight_col] = base[weizhi_Y][weizhi_X];
                                        base[weizhi_Y][weizhi_X] = change;
                                    }
                                }
                            }
                            cct_setcolor();
                            cct_gotoxy(0, wenzi_y);
                            cout << "当前选择" << char(weizhi_Y + 'A') << "行" << weizhi_X + 1 << "列            ";
                        }
                        else if (((X - 2) % 4 == 0 && (Y - 2) % 2 == 0) && !removable[weizhi_Y][weizhi_X])
                            cout << "不能选择" << char(weizhi_Y + 'A') << "行" << weizhi_X + 1 << "列            ";
                        break;
                    }
                    case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
                        loop = mycontinue = 0;
                        break;
                    default:
                        break;
                } //end of switch(maction)
            } //end of if (CCT_MOUSE_EVENT)
        }
        if (loop == 0&&mycontinue==0)
            break;
        ball_painting(row, col, base, 7, 'b');//一样的
        while (1)
        {
            cct_setcolor();
            has_highlight = find_highlight(row, col, base, highlight);//是否有高光
            ball_789(row, col, base, highlight);

            if (!has_highlight)
            {
                cct_gotoxy(0, 0);
                break;
            }
            eliminate(row, col, base, highlight,&score);
            fill_new(row, col, base, highlight);
        }
    }
    cct_gotoxy(0, wenzi_y);
    end();
}