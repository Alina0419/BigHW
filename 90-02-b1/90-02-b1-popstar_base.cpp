/* 计科 2350218 陈佳怡 */
#include<iostream>
#include <cstring>
#include"90-02-b1-popstar.h"
#include<conio.h>
#include <cstdlib>
#include"../include/include_menu+tools.h"
#include"../include/cmd_console_tools.h"

using namespace std;

void find_star(int row, int col,char letter,int num, char star[Size_max][Size_max],bool highlight[Size_max][Size_max])
{
    int i = letter - 'A';
    int j = num;

    highlight[i][j] = true;

    //上
    if (i > 0 && star[i - 1][j] == star[i][j] && !highlight[i - 1][j])
        find_star(row, col, char(letter - 1), num, star, highlight);

    //下
    if (i < row - 1 && star[i + 1][j] == star[i][j] && !highlight[i + 1][j])
        find_star(row, col, char(letter + 1), num, star, highlight);

    //左
    if (j > 0 && star[i][j - 1] == star[i][j] && !highlight[i][j - 1])
        find_star(row, col, letter, num - 1, star, highlight);

    //右
    if (j < col - 1 && star[i][j + 1] == star[i][j] && !highlight[i][j + 1])
        find_star(row, col, letter, num + 1, star, highlight);
}

bool has_choice(int row, int col,char star[Size_max][Size_max])
{
    for (int j = 0;j < col;j++)
    {
        for (int i = 0;i < row;i++)
        {
            if (star[i][j] == '0')
                continue;
            if (i > 0 && star[i - 1][j] == star[i][j])
                return true;
            if (i < row - 1 && star[i + 1][j] == star[i][j])
                return true;
            if (j > 0 && star[i][j - 1] == star[i][j])
                return true;
            if (j < col - 1 && star[i][j + 1] == star[i][j])
                return true;
        }
    }
    return false;
}

void change_weizhi(int* x, int* y, int* x_this, int* y_this, char star[Size_max][Size_max],int number_x,int number_y)
{
    int start_x = 4;
    int start_y = 3;
    if (star[*y][*x] != '0')
    {
        cct_showstr(*x * number_x + start_x, *y * number_y + start_y, "╔═╗", star[*y][*x] + 8, COLOR_BLACK);
        cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 1, "║★║", star[*y][*x] + 8, COLOR_BLACK);
        cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 2, "╚═╝", star[*y][*x] + 8, COLOR_BLACK);
    }
    *x = *x_this;
    *y = *y_this;
    cct_showstr(*x * number_x + start_x, *y * number_y + start_y, "╔═╗", star[*y][*x] + 8, COLOR_HWHITE);
    cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 1, "║★║", star[*y][*x] + 8, COLOR_HWHITE);
    cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 2, "╚═╝", star[*y][*x] + 8, COLOR_HWHITE);
}
 
void star_A()
{
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,8,10);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');

    cout << endl;
    cout << "当前数组：" << endl;
    output_base(row, col, star, 0, 0, false);//还没打高光
    cout << "请以字母+数字形式[例：c2]输入矩阵坐标：" << endl;
    
    bool highlight[Size_max][Size_max] = { 0 };//准备打
    char input[2];
    char letter;
    int num;
    while (1)
    {
        for (int i = 0;i < 2;i++)
        {
            cin >> input[i];
        }
        cin.clear();
        cin.ignore(65536, '\n');
        letter = input[0];
        num = input[1] - '0';
        if (letter >= 'a' && letter <= 'j')
            letter -= 'a' - 'A';
        if ((letter >= 'A' && letter < 'A' + row) && (num >= 0 && num < col))
        {
            find_star(row, col, letter, num, star, highlight);//是否有高光
            int n = 0;
            for (int i = 0;i < row;i++)
            {
                for (int j = 0;j < col;j++)
                {
                    if (highlight[i][j])
                        n++;
                    if (n > 1)
                        break;
                }
            }
            if (n > 1)
                break;
            else
            {
                cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
                for (int i = 0;i < row;i++)
                    for (int j = 0;j < col;j++)
                        highlight[i][j] = false;
            }
        }
        else
            cout << "输入错误，请重新输入" << endl;
    }
    cout << "查找结果数组：" << endl;
    output_base(row, col, star, 0, highlight, false, true);
    cout << endl;
    cout << "当前数组(不同色标识)：" << endl;
    output_base(row, col, star, 1, highlight, true);
    cout << endl;
    end();
}

void star_B()
{
    int score = 0;
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col, 8, 10);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');

    cout << endl;
    cout << "当前数组：" << endl;
    output_base(row, col, star, 0, 0, false);//还没打高光
    cout << "请以字母+数字形式[例：c2]输入矩阵坐标：" << endl;

    bool highlight[Size_max][Size_max] = { 0 };//准备打
    char input[2];
    char letter;
    int num;
    int n;
    while (1)
    {
        for (int i = 0;i < 2;i++)
        {
            cin >> input[i];
        }
        cin.clear();
        cin.ignore(65536, '\n');
        letter = input[0];
        num = input[1] - '0';
        if (letter >= 'a' && letter <= 'j')
            letter -= 'a' - 'A';
        if ((letter >= 'A' && letter < 'A' + row) && (num >= 0 && num < col))
        {
            cout << "输入为" << letter << "行" << num << "列" << endl;
            find_star(row, col, letter, num, star, highlight);//是否有高光
            n = 0;
            for (int i = 0;i < row;i++)
            {
                for (int j = 0;j < col;j++)
                {
                    if (highlight[i][j])
                        n++;//有几个可消，方便计算分数
                }
            }
            if (n > 1)
                break;
            else
            {
                cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
                for (int i = 0;i < row;i++)
                    for (int j = 0;j < col;j++)
                        highlight[i][j] = false;
            }
        }
        else
            cout << "输入错误，请重新输入" << endl;
    }
    cout << "查找结果数组：" << endl;
    output_base(row, col, star, 0, highlight, false, true);
    cout << endl;
    cout << "当前数组(不同色标识)：" << endl;
    output_base(row, col, star, 1, highlight, true);
    cout << endl;
    char enter;
    const char enters[] = "yYnNqQ";
    while (1)
    {
        cout << "请确认是否把" << letter << num << "及周围的相同值消除(Y/N/Q)：";
        cin >> enter;
        if (strchr(enters, enter))
        {
            if (enter == 'q' || enter == 'Q'|| enter == 'n' || enter == 'N')
            {
                end();
                return;
            }
            else if (enter == 'y' || enter == 'Y')
            {
                break;
            }
        }
    }
    score += n * n * 5;
    cout << endl;
    cout << "相同值归并后的数组(不同色标识)：" << endl;
    cout << "本次得分：" << n * n * 5 << " 总得分：" << score << endl;
    zero_fall(row, col, star, highlight, 1, 's');
    cin.ignore(65536, '\n');
    end();
}

void star_C()
{
    int score = 0;
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col, 8, 10);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cout << endl;
    cout << "当前数组：" << endl;
    output_base(row, col, star, 0, 0, false);//还没打高光
    while (1)
    {
        cout << "请以字母+数字形式[例：c2]输入矩阵坐标：" << endl;

        bool highlight[Size_max][Size_max] = { 0 };//准备打
        char input[2];
        char letter=0;
        int num=0;
        int n=0;
        while (1)
        {
            for (int i = 0;i < 2;i++)
            {
                cin >> input[i];
            }
            cin.clear();
            cin.ignore(65536, '\n');
            letter = input[0];
            num = input[1] - '0';
            if (letter >= 'a' && letter <= 'j')
                letter -= 'a' - 'A';
            if ((letter >= 'A' && letter < 'A' + row) && (num >= 0 && num < col))
            {
                cout << "输入为" << letter << "行" << num << "列" << endl;
                if ((letter - 'A')>=0&& (letter - 'A')<=9&& num >= 0 && num <= 9&&star[letter - 'A'][num] != '0')
                {
                    find_star(row, col, letter, num, star, highlight);//是否有高光
                    n = 0;
                    for (int i = 0;i < row;i++)
                    {
                        for (int j = 0;j < col;j++)
                        {
                            if (highlight[i][j])
                                n++;//有几个可消，方便计算分数
                        }
                    }
                    if (n > 1)
                        break;
                    else
                    {
                        cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
                        for (int i = 0;i < row;i++)
                            for (int j = 0;j < col;j++)
                                highlight[i][j] = false;
                    }
                }
                else if ((letter - 'A') >= 0 && (letter - 'A') <= 9 && num >= 0 && num <= 9 && star[letter - 'A'][num] == '0')
                    cout << "输入的矩阵坐标位置为0非法位置），请重新输入" << endl;
            }
            else
                cout << "输入错误，请重新输入" << endl;
        }
        cout << "查找结果数组：" << endl;
        output_base(row, col, star, 0, highlight, false, true);
        cout << endl;
        cout << "当前数组(不同色标识)：" << endl;
        output_base(row, col, star, 1, highlight, true);
        cout << endl;
        char enter;
        const char enters[] = "yYnNqQ";
        while (1)
        {
            cout << "请确认是否把" << letter << num << "及周围的相同值消除(Y/N/Q)：";
            cin >> enter;
            if (strchr(enters, enter))
            {
                if (enter == 'q' || enter == 'Q' || enter == 'n' || enter == 'N')
                {
                    cin.ignore(65536, '\n');
                    end();
                    return;
                }
                else if (enter == 'y' || enter == 'Y')
                {
                    break;
                }
            }
        }
        score += n * n * 5;
        cout << endl;
        cout << "相同值归并后的数组(不同色标识)：" << endl;
        cout << "本次得分：" << n * n * 5 << " 总得分：" << score << endl;
        zero_fall(row, col, star, highlight, 1, 's');
        cout << "本次消除结束，按回车键继续新一次的消除..." << endl;
        while (_getch() != '\r')
            ;
        cout << endl;
        cout << "当前数组：" << endl;
        output_base(row, col, star, 1, highlight, 1);
        //检查有无可消项
        int left = 0;
        if (!has_choice(row,col,star))
        {
            for (int j = 0;j < col;j++)
            {
                for (int i = 0;i < row;i++)
                {
                    if (star[i][j] == '0')
                        continue;
                    left++;
                }
            }
            cout << "剩余" << left << "个不可消除项，本关结束！" << endl;
            break;
        }
    }
    cin.ignore(65536, '\n');
    end();
}

void star_D()
{
    int score = 0;
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col, 8, 10);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cct_cls();
    cct_setfontsize("新宋体", 24 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(30 + 4 * col, 16 + 2 * row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col, 1, 14);
    ball_painting(row, col, star, 14, 's');

    cct_enable_mouse();//允许使用鼠标
    int X = 0, Y = 0;
    int ret, maction, loop = 1;
    int keycode1, keycode2;
    int wenzi = 4 + 3 * row;
    cct_showstr(0, wenzi, "箭头键/鼠标移动，回车键/单机左键选择并结束");
    int weizhi_X_keyboard = 0;
    int weizhi_Y_keyboard = 0;
    int weizhi_X_now=0;
    int weizhi_Y_now=0;
    int start_x = 4;
    int start_y = 3;
    while (loop)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        cct_showstr(0, wenzi, "                                                          ");
        // 鼠标位置计算
        int weizhi_X_mouse = (X - 4) / 6;
        int weizhi_Y_mouse = (Y - 3) / 3;
        if (ret == CCT_MOUSE_EVENT)
        {
            switch (maction)
            {
                case MOUSE_ONLY_MOVED:
                    if (X > 3 && X <= 3 + 6 * col && Y > 2 && Y <= 2 + row * 3)
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[当前鼠标] " << char(weizhi_Y_mouse + 'A') << "行" << weizhi_X_mouse << "列  ";
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star,6,3);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    else
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[当前鼠标] 位置非法";
                    }
                    break;
                case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
                    if (X > 3 && X <= 3 + 6 * col && Y > 2 && Y <= 2 + row * 3)
                    {
                        loop = 0;
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "选中了" << char(weizhi_Y_mouse + 'A') << "行" << weizhi_X_mouse << "列        " << endl;
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 6, 3);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    break;
                default:
                    break;
            } //end of switch(maction)
        } //end of if (CCT_MOUSE_EVENT)
        else if (ret == CCT_KEYBOARD_EVENT)
        {
            switch (keycode1)
            {
                case 224:
                    switch (keycode2)
                    {
                        case KB_ARROW_UP:
                            if (weizhi_Y_keyboard == 0)
                                weizhi_Y_keyboard = row-1;
                            else
                                weizhi_Y_keyboard--;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star,6,3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        case KB_ARROW_DOWN:
                            if (weizhi_Y_keyboard == row-1)
                                weizhi_Y_keyboard = 0;
                            else
                                weizhi_Y_keyboard++;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star,6,3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        case KB_ARROW_LEFT:
                            if (weizhi_X_keyboard == 0)
                                weizhi_X_keyboard = col-1;
                            else
                                weizhi_X_keyboard--;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star,6,3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        case KB_ARROW_RIGHT:
                            if (weizhi_X_keyboard == col-1)
                                weizhi_X_keyboard = 0;
                            else
                                weizhi_X_keyboard++;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star,6, 3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                    loop = 0;
                    if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                        change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 6, 3);
                    cct_gotoxy(0, wenzi);
                    cct_setcolor();
                    cout << "选中了" << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列        " << endl;
                    break;
                default:
                    break;
            }//end of swicth(keycode1)
        }
    }
    cct_setcolor();
    cct_gotoxy(0, wenzi);
    end();
}

void star_E()
{
    int score = 0;
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col, 8, 10);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cct_cls();
    cct_setfontsize("新宋体", 20 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(24 + 6 * col, 16 + 4 * row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col, 1, 15);
    ball_painting(row, col, star, 15, 's');

    cct_enable_mouse();//允许使用鼠标
    int X = 0, Y = 0;
    int ret, maction, loop = 1;
    int keycode1, keycode2;
    int wenzi = 4 + 4 * row;
    cct_showstr(0, wenzi, "箭头键/鼠标移动，回车键/单机左键选择并结束");
    int weizhi_X_keyboard = 0;
    int weizhi_Y_keyboard = 0;
    int weizhi_X_now = 0;
    int weizhi_Y_now = 0;
    int start_x = 4;
    int start_y = 3;
    while (loop)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        cct_showstr(0, wenzi, "                                                          ");
        // 鼠标位置计算
        int weizhi_X_mouse = (X - start_x) / 8;
        int weizhi_Y_mouse = (Y - start_y) / 4;
        if (ret == CCT_MOUSE_EVENT)
        {
            switch (maction)
            {
                case MOUSE_ONLY_MOVED:
                    if (X>3&&X<start_x+8*col&&(X-start_x)%8<6&&Y>2&&Y<start_y+4*row&&(Y-start_y)%4<3)
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[当前鼠标] " << char(weizhi_Y_mouse + 'A') << "行" << weizhi_X_mouse << "列  ";
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star,8,4);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    else
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[当前鼠标] 位置非法";
                    }
                    break;
                case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
                    if (X > 3 && X < start_x + 8 * col && (X - start_x) % 8 < 6 && Y > 2 && Y < start_y + 4 * row && (Y - start_y) % 4 < 3)
                    {
                        loop = 0;
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "选中了" << char(weizhi_Y_mouse + 'A') << "行" << weizhi_X_mouse << "列        " << endl;
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 8, 4);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    break;
                default:
                    break;
            } //end of switch(maction)
        } //end of if (CCT_MOUSE_EVENT)
        else if (ret == CCT_KEYBOARD_EVENT)
        {
            switch (keycode1)
            {
                case 224:
                    switch (keycode2)
                    {
                        case KB_ARROW_UP:
                            if (weizhi_Y_keyboard == 0)
                                weizhi_Y_keyboard = row - 1;
                            else
                                weizhi_Y_keyboard--;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        case KB_ARROW_DOWN:
                            if (weizhi_Y_keyboard == row - 1)
                                weizhi_Y_keyboard = 0;
                            else
                                weizhi_Y_keyboard++;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        case KB_ARROW_LEFT:
                            if (weizhi_X_keyboard == 0)
                                weizhi_X_keyboard = col - 1;
                            else
                                weizhi_X_keyboard--;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        case KB_ARROW_RIGHT:
                            if (weizhi_X_keyboard == col - 1)
                                weizhi_X_keyboard = 0;
                            else
                                weizhi_X_keyboard++;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                    loop = 0;
                    if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                        change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                    cct_gotoxy(0, wenzi);
                    cct_setcolor();
                    cout << "选中了" << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列        " << endl;
                    break;
                default:
                    break;
            }//end of swicth(keycode1)
        }
    }
    cct_setcolor();
    cct_gotoxy(0, wenzi);
    end();
}

void star_F()
{
    int score = 0;
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col, 8, 10);

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cct_cls();
    cct_setfontsize("新宋体", 20 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(30 + 4 * col, 16 + 2 * row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "屏幕：" << lines << "行" << cols << "列" << endl;
    frame(row, col, 1, 14);
    ball_painting(row, col, star, 14, 's');

    cct_enable_mouse();//允许使用鼠标
    int X = 0, Y = 0;
    int ret, maction, loop = 1;
    int keycode1, keycode2;
    const int wenzi = 4 + 3 * row;
    cct_showstr(0, wenzi, "箭头键/鼠标移动，回车键/单机左键选择");
    int weizhi_X_keyboard = 0;
    int weizhi_Y_keyboard = 0;
    int weizhi_X_now = 0;
    int weizhi_Y_now = 0;
    int start_x = 4;
    int start_y = 3;
    bool highlight[Size_max][Size_max] = { 0 };
    bool waiting_for_confirmation = false;
    while (loop)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (waiting_for_confirmation)
        {
            if (ret == CCT_KEYBOARD_EVENT && keycode1 == 13)
                break;
            while (ret != CCT_KEYBOARD_EVENT&&(X - 4) / 6 == weizhi_X_now && (Y - 3) / 3 == weizhi_Y_now)
            {
                ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
                if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK)
                {
                    loop = 0;
                    break;
                }
            }
            if (loop == 0)
                break;
            waiting_for_confirmation = false;
        }
        //继续挑选
        hint_graph(row, col, star, highlight, 's', 6,3,COLOR_BLACK);
        // 鼠标位置计算
        int weizhi_X_mouse = (X - 4) / 6;
        int weizhi_Y_mouse = (Y - 3) / 3;
        for (int i = 0;i < row;i++)
        {
            for (int j = 0;j < col;j++)
            {
                highlight[i][j] = false;
            }
        }
        if (ret == CCT_MOUSE_EVENT)
        {
            switch (maction)
            {
                case MOUSE_ONLY_MOVED:
                    if (X > 3 && X <= 3 + 6 * col && Y > 2 && Y <= 2 + row * 3)
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                        {
                            cout << "[当前鼠标] " << char(weizhi_Y_mouse + 'A') << "行" << weizhi_X_mouse << "列                                  ";
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 6, 3);
                        }
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    else
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[当前鼠标] 位置非法                                  ";
                    }
                    break;
                case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
                    if (X > 3 && X <= 3 + 6 * col && Y > 2 && Y <= 2 + row * 3)
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 6, 3);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;

                        find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//是否有高光
                        int n = 0;
                        for (int i = 0;i < row;i++)
                        {
                            for (int j = 0;j < col;j++)
                            {
                                if (highlight[i][j])
                                    n++;
                            }
                        }
                        if (n > 1)
                        {
                            hint_graph(row, col, star, highlight, 's',6,3);
                            cct_showstr(0, wenzi, "箭头键/鼠标移动取消当前选择，回车键/单机左键合成");
                            waiting_for_confirmation = true;
                        }
                        else
                            cct_showstr(0, wenzi, "周围无相同值，箭头键/鼠标移动取消当前选择");
                    }
                    break;
                default:
                    break;
            } //end of switch(maction)
        } //end of if (CCT_MOUSE_EVENT)
        else if (ret == CCT_KEYBOARD_EVENT)
        {
            switch (keycode1)
            {
                case 224:
                    switch (keycode2)
                    {
                        case KB_ARROW_UP:
                            if (weizhi_Y_keyboard == 0)
                                weizhi_Y_keyboard = row - 1;
                            else
                                weizhi_Y_keyboard--;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 6, 3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列                                    ";
                            }
                            break;
                        case KB_ARROW_DOWN:
                            if (weizhi_Y_keyboard == row - 1)
                                weizhi_Y_keyboard = 0;
                            else
                                weizhi_Y_keyboard++;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 6, 3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列                                    ";
                            }
                            break;
                        case KB_ARROW_LEFT:
                            if (weizhi_X_keyboard == 0)
                                weizhi_X_keyboard = col - 1;
                            else
                                weizhi_X_keyboard--;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 6, 3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列                                    ";
                            }
                            break;
                        case KB_ARROW_RIGHT:
                            if (weizhi_X_keyboard == col - 1)
                                weizhi_X_keyboard = 0;
                            else
                                weizhi_X_keyboard++;
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                            {
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 6, 3);
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列                                    ";
                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                {
                    if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                        change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 6, 3);
                    cct_gotoxy(0, wenzi);
                    cct_setcolor();
                    find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//是否有高光
                    int n = 0;
                    for (int i = 0;i < row;i++)
                    {
                        for (int j = 0;j < col;j++)
                        {
                            if (highlight[i][j])
                                n++;
                        }
                    }
                    if (n > 1)
                    {
                        hint_graph(row, col, star, highlight, 's',6,3);
                        cct_showstr(0, wenzi, "箭头键/鼠标移动取消当前选择，回车键/单机左键合成");
                        waiting_for_confirmation = true;
                    }
                    else
                        cct_showstr(0, wenzi, "周围无相同值，箭头键/鼠标移动取消当前选择");
                }
                default:
                    break;
            }//end of swicth(keycode1)
        }

    }
    int n = 0;
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            if (highlight[i][j])
                n++;
        }
    }
    score += n * n * 5;
    hint_graph(row, col, star, highlight, 'k',6,3);
    cct_gotoxy(0, 0);
    cct_setcolor();
    cout << "本次得分:" << n * n * 5 << " " << "总分:" << score;
    cct_showstr(0, wenzi, "合成完毕，回车键/单击左键下落0                  ");
    while (1)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT && keycode1 == 13)
            break;
        if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK)
            break;
    }
    move_graph(row, col, star, highlight, 's',6,3);
    cct_setcolor();
    cct_showstr(0, wenzi, "本次合成结束，按C/单机左键继续新一次的合成");
    while (1)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT && (keycode1 == 'C' || keycode1 == 'c'))
            break;
        if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK)
            break;
    }
    cct_showstr(0, wenzi, "                                                      ");
    cct_gotoxy(0, wenzi);
    end();
    
}

void star_G()
{
    int score = 0;
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col, 8, 10);
    while (1)
    {
        for (int i = 0; i < row; i++) //初始填充
            for (int j = 0; j < col; j++)
                star[i][j] = char(rand() % 5 + '1');
        cct_cls();
        cct_setfontsize("新宋体", 20 + 4 * (9 - (row + col) / 2));
        cct_setconsoleborder(24 + 6 * col, 16 + 4 * row, 120, 9000);
        int cols, lines, buffer_cols, buffer_lines;
        cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
        cout << "屏幕：" << lines << "行" << cols << "列" << endl;
        frame(row, col, 1, 15);
        ball_painting(row, col, star, 15, 's');
        int wenzi = 4 + 4 * row;
        bool bigger_loop = true;
        while (bigger_loop)
        {
            cct_enable_mouse();//允许使用鼠标
            int X = 0, Y = 0;
            int ret, maction, loop = 1;
            int keycode1, keycode2;
            cct_showstr(0, wenzi, "箭头键/鼠标移动，回车键/单机左键选择,Q/单机右键结束");
            int weizhi_X_keyboard = 0;
            int weizhi_Y_keyboard = 0;
            for (int i = 0;i < row;i++)
            {
                if (star[i][0] == '0')
                    weizhi_Y_keyboard++;
                else
                    break;
            }
            int weizhi_X_now = 0;
            int weizhi_Y_now = 0;
            int start_x = 4;
            int start_y = 3;
            bool highlight[Size_max][Size_max] = { 0 };
            bool waiting_for_confirmation = false;
            while (loop)
            {
                ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
                if (waiting_for_confirmation)
                {
                    if (ret == CCT_KEYBOARD_EVENT && keycode1 == 13)
                        break;
                    while (ret != CCT_KEYBOARD_EVENT && (X - 4) / 8 == weizhi_X_now && (Y - 3) / 4 == weizhi_Y_now && (X - 4) % 8 < 6 && (Y - 3) % 4 < 3)
                    {
                        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
                        if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK)
                        {
                            loop = 0;
                            break;
                        }
                    }
                    if (ret == CCT_KEYBOARD_EVENT && (keycode1 == 'Q' || keycode1 == 'q') || ret == CCT_MOUSE_EVENT && maction == MOUSE_RIGHT_BUTTON_CLICK)
                    {
                        cct_gotoxy(0,wenzi);
                        end();
                        return;
                    }
                    if (loop == 0)
                        break;
                    waiting_for_confirmation = false;
                }
                //继续挑选
                hint_graph(row, col, star, highlight, 's', 8, 4, COLOR_BLACK);
                cct_showstr(0, wenzi, "                                                          ");
                // 鼠标位置计算
                int weizhi_X_mouse = (X - start_x) / 8;
                int weizhi_Y_mouse = (Y - start_y) / 4;
                for (int i = 0;i < row;i++)
                {
                    for (int j = 0;j < col;j++)
                    {
                        highlight[i][j] = false;
                    }
                }
                if (ret == CCT_KEYBOARD_EVENT && (keycode1 == 'Q' || keycode1 == 'q') || ret == CCT_MOUSE_EVENT && maction == MOUSE_RIGHT_BUTTON_CLICK)
                {
                    cct_gotoxy(0, wenzi);
                    end();
                    return;
                }
                if (ret == CCT_MOUSE_EVENT)
                {
                    switch (maction)
                    {
                        case MOUSE_ONLY_MOVED:
                            if (X > 3 && X < start_x + 8 * col && (X - start_x) % 8 < 6 && Y > 2 && Y < start_y + 4 * row && (Y - start_y) % 4 < 3 && star[(Y - start_y) / 4][(X - start_x) / 8] != '0')
                            {
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前鼠标] " << char(weizhi_Y_mouse + 'A') << "行" << weizhi_X_mouse << "列  ";
                                if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                                    change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 8, 4);
                                weizhi_X_keyboard = weizhi_X_mouse;
                                weizhi_Y_keyboard = weizhi_Y_mouse;
                            }
                            else
                            {
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[当前鼠标] 位置非法";
                            }
                            break;
                        case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
                            if (X > 3 && X < start_x + 8 * col && (X - start_x) % 8 < 6 && Y > 2 && Y < start_y + 4 * row && (Y - start_y) % 4 < 3 && star[(Y - start_y) / 4][(X - start_x) / 8] != '0')
                            {
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                                    change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 8, 4);
                                weizhi_X_keyboard = weizhi_X_mouse;
                                weizhi_Y_keyboard = weizhi_Y_mouse;

                                find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//是否有高光
                                int n = 0;
                                for (int i = 0;i < row;i++)
                                {
                                    for (int j = 0;j < col;j++)
                                    {
                                        if (highlight[i][j])
                                            n++;
                                    }
                                }
                                if (n > 1)
                                {
                                    hint_graph(row, col, star, highlight, 's', 8, 4);
                                    cct_showstr(0, wenzi, "箭头键/鼠标移动取消当前选择，回车键/单机左键合成");
                                    waiting_for_confirmation = true;
                                }
                                else
                                    cct_showstr(0, wenzi, "周围无相同值，箭头键/鼠标移动取消当前选择");
                            }
                            break;
                        default:
                            break;
                    } //end of switch(maction)
                } //end of if (CCT_MOUSE_EVENT)
                else if (ret == CCT_KEYBOARD_EVENT)
                {
                    switch (keycode1)
                    {
                        case 224:
                            switch (keycode2)
                            {
                                case KB_ARROW_UP:
                                    while (1)
                                    {
                                        if (weizhi_Y_keyboard == 0)
                                            weizhi_Y_keyboard = row - 1;
                                        else
                                            weizhi_Y_keyboard--;
                                        if (star[weizhi_Y_keyboard][weizhi_X_keyboard] != '0')
                                            break;
                                    }
                                    if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                                    {
                                        change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                        cct_gotoxy(0, wenzi);
                                        cct_setcolor();
                                        cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                                    }
                                    break;
                                case KB_ARROW_DOWN:
                                    while (1)
                                    {
                                        if (weizhi_Y_keyboard == row - 1)
                                            weizhi_Y_keyboard = 0;
                                        else
                                            weizhi_Y_keyboard++;
                                        if (star[weizhi_Y_keyboard][weizhi_X_keyboard] != '0')
                                            break;
                                    }
                                    if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                                    {
                                        change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                        cct_gotoxy(0, wenzi);
                                        cct_setcolor();
                                        cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                                    }
                                    break;
                                case KB_ARROW_LEFT:
                                    while (1)
                                    {
                                        if (weizhi_X_keyboard == 0)
                                            weizhi_X_keyboard = col - 1;
                                        else
                                            weizhi_X_keyboard--;
                                        if (star[weizhi_Y_keyboard][weizhi_X_keyboard] != '0')
                                            break;
                                    }
                                    if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                                    {
                                        change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                        cct_gotoxy(0, wenzi);
                                        cct_setcolor();
                                        cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                                    }
                                    break;
                                case KB_ARROW_RIGHT:
                                    while (1)
                                    {
                                        if (weizhi_X_keyboard == col - 1)
                                            weizhi_X_keyboard = 0;
                                        else
                                            weizhi_X_keyboard++;
                                        if (star[weizhi_Y_keyboard][weizhi_X_keyboard] != '0')
                                            break;
                                    }
                                    if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                                    {
                                        change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                                        cct_gotoxy(0, wenzi);
                                        cct_setcolor();
                                        cout << "[当前键盘] " << char(weizhi_Y_keyboard + 'A') << "行" << weizhi_X_keyboard << "列  ";
                                    }
                                    break;
                                default:
                                    break;
                            }
                            break;
                        case 13:
                            if (weizhi_X_now != weizhi_X_keyboard || weizhi_Y_now != weizhi_Y_keyboard)
                                change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_keyboard, &weizhi_Y_keyboard, star, 8, 4);
                            cct_gotoxy(0, wenzi);
                            cct_setcolor();
                            find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//是否有高光
                            int n = 0;
                            for (int i = 0;i < row;i++)
                            {
                                for (int j = 0;j < col;j++)
                                {
                                    if (highlight[i][j])
                                        n++;
                                }
                            }
                            if (n > 1)
                            {
                                hint_graph(row, col, star, highlight, 's', 8, 4);
                                cct_showstr(0, wenzi, "箭头键/鼠标移动取消当前选择，回车键/单机左键合成");
                                waiting_for_confirmation = true;
                            }
                            else
                                cct_showstr(0, wenzi, "周围无相同值，箭头键/鼠标移动取消当前选择");
                    }//end of swicth(keycode1)
                }
            }
            int n = 0;
            for (int i = 0;i < row;i++)
            {
                for (int j = 0;j < col;j++)
                {
                    if (highlight[i][j])
                        n++;
                }
            }
            score += n * n * 5;
            hint_graph(row, col, star, highlight, 'k', 8, 4);
            cct_gotoxy(0, 0);
            cct_setcolor();
            cout << "本次得分:" << n * n * 5 << " " << "总分:" << score;
            move_graph(row, col, star, highlight, 's', 8, 4);
            move_graph(row, col, star, highlight, 's', 8, 4, LEFT);
            int left_stars = 0;
            if (!has_choice(row, col, star))
            {
                for (int j = 0;j < col;j++)
                {
                    for (int i = 0;i < row;i++)
                    {
                        if (star[i][j] == '0')
                            continue;
                        left_stars++;
                    }
                }
                if (left_stars < 10)
                    score += (10 - left_stars) * 180;
                cct_gotoxy(0, 0);
                cct_setcolor();
                cout << "奖励得分:" << (10 - left_stars) * 180 << " 总分:" << score;
                cct_showstr(0, wenzi, "                                                      ");
                cct_gotoxy(0, wenzi - 1);
                cct_setcolor(COLOR_BLACK,COLOR_HYELLOW);
                cout << "剩余" << left_stars << "个星星，无可消除项，本关结束！";
                cct_setcolor();
                cout << "回车继续下一关";
                while (_getch() != '\r')
                    ;
                break;
            }
        }//end_of_biggerloop一局游戏
    }//game
}