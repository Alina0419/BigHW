/* �ƿ� 2350218 �¼��� */
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

    //��
    if (i > 0 && star[i - 1][j] == star[i][j] && !highlight[i - 1][j])
        find_star(row, col, char(letter - 1), num, star, highlight);

    //��
    if (i < row - 1 && star[i + 1][j] == star[i][j] && !highlight[i + 1][j])
        find_star(row, col, char(letter + 1), num, star, highlight);

    //��
    if (j > 0 && star[i][j - 1] == star[i][j] && !highlight[i][j - 1])
        find_star(row, col, letter, num - 1, star, highlight);

    //��
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
        cct_showstr(*x * number_x + start_x, *y * number_y + start_y, "�X�T�[", star[*y][*x] + 8, COLOR_BLACK);
        cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 1, "�U��U", star[*y][*x] + 8, COLOR_BLACK);
        cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 2, "�^�T�a", star[*y][*x] + 8, COLOR_BLACK);
    }
    *x = *x_this;
    *y = *y_this;
    cct_showstr(*x * number_x + start_x, *y * number_y + start_y, "�X�T�[", star[*y][*x] + 8, COLOR_HWHITE);
    cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 1, "�U��U", star[*y][*x] + 8, COLOR_HWHITE);
    cct_showstr(*x * number_x + start_x, *y * number_y + start_y + 2, "�^�T�a", star[*y][*x] + 8, COLOR_HWHITE);
}
 
void star_A()
{
    int row, col;
    char star[Size_max][Size_max] = { 0 };
    srand((unsigned int)(time(0)));
    input(&row, &col,8,10);

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');

    cout << endl;
    cout << "��ǰ���飺" << endl;
    output_base(row, col, star, 0, 0, false);//��û��߹�
    cout << "������ĸ+������ʽ[����c2]����������꣺" << endl;
    
    bool highlight[Size_max][Size_max] = { 0 };//׼����
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
            find_star(row, col, letter, num, star, highlight);//�Ƿ��и߹�
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
                cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
                for (int i = 0;i < row;i++)
                    for (int j = 0;j < col;j++)
                        highlight[i][j] = false;
            }
        }
        else
            cout << "�����������������" << endl;
    }
    cout << "���ҽ�����飺" << endl;
    output_base(row, col, star, 0, highlight, false, true);
    cout << endl;
    cout << "��ǰ����(��ͬɫ��ʶ)��" << endl;
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');

    cout << endl;
    cout << "��ǰ���飺" << endl;
    output_base(row, col, star, 0, 0, false);//��û��߹�
    cout << "������ĸ+������ʽ[����c2]����������꣺" << endl;

    bool highlight[Size_max][Size_max] = { 0 };//׼����
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
            cout << "����Ϊ" << letter << "��" << num << "��" << endl;
            find_star(row, col, letter, num, star, highlight);//�Ƿ��и߹�
            n = 0;
            for (int i = 0;i < row;i++)
            {
                for (int j = 0;j < col;j++)
                {
                    if (highlight[i][j])
                        n++;//�м�������������������
                }
            }
            if (n > 1)
                break;
            else
            {
                cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
                for (int i = 0;i < row;i++)
                    for (int j = 0;j < col;j++)
                        highlight[i][j] = false;
            }
        }
        else
            cout << "�����������������" << endl;
    }
    cout << "���ҽ�����飺" << endl;
    output_base(row, col, star, 0, highlight, false, true);
    cout << endl;
    cout << "��ǰ����(��ͬɫ��ʶ)��" << endl;
    output_base(row, col, star, 1, highlight, true);
    cout << endl;
    char enter;
    const char enters[] = "yYnNqQ";
    while (1)
    {
        cout << "��ȷ���Ƿ��" << letter << num << "����Χ����ֵͬ����(Y/N/Q)��";
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
    cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
    cout << "���ε÷֣�" << n * n * 5 << " �ܵ÷֣�" << score << endl;
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cout << endl;
    cout << "��ǰ���飺" << endl;
    output_base(row, col, star, 0, 0, false);//��û��߹�
    while (1)
    {
        cout << "������ĸ+������ʽ[����c2]����������꣺" << endl;

        bool highlight[Size_max][Size_max] = { 0 };//׼����
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
                cout << "����Ϊ" << letter << "��" << num << "��" << endl;
                if ((letter - 'A')>=0&& (letter - 'A')<=9&& num >= 0 && num <= 9&&star[letter - 'A'][num] != '0')
                {
                    find_star(row, col, letter, num, star, highlight);//�Ƿ��и߹�
                    n = 0;
                    for (int i = 0;i < row;i++)
                    {
                        for (int j = 0;j < col;j++)
                        {
                            if (highlight[i][j])
                                n++;//�м�������������������
                        }
                    }
                    if (n > 1)
                        break;
                    else
                    {
                        cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
                        for (int i = 0;i < row;i++)
                            for (int j = 0;j < col;j++)
                                highlight[i][j] = false;
                    }
                }
                else if ((letter - 'A') >= 0 && (letter - 'A') <= 9 && num >= 0 && num <= 9 && star[letter - 'A'][num] == '0')
                    cout << "����ľ�������λ��Ϊ0�Ƿ�λ�ã�������������" << endl;
            }
            else
                cout << "�����������������" << endl;
        }
        cout << "���ҽ�����飺" << endl;
        output_base(row, col, star, 0, highlight, false, true);
        cout << endl;
        cout << "��ǰ����(��ͬɫ��ʶ)��" << endl;
        output_base(row, col, star, 1, highlight, true);
        cout << endl;
        char enter;
        const char enters[] = "yYnNqQ";
        while (1)
        {
            cout << "��ȷ���Ƿ��" << letter << num << "����Χ����ֵͬ����(Y/N/Q)��";
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
        cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
        cout << "���ε÷֣�" << n * n * 5 << " �ܵ÷֣�" << score << endl;
        zero_fall(row, col, star, highlight, 1, 's');
        cout << "�����������������س���������һ�ε�����..." << endl;
        while (_getch() != '\r')
            ;
        cout << endl;
        cout << "��ǰ���飺" << endl;
        output_base(row, col, star, 1, highlight, 1);
        //������޿�����
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
            cout << "ʣ��" << left << "��������������ؽ�����" << endl;
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cct_cls();
    cct_setfontsize("������", 24 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(30 + 4 * col, 16 + 2 * row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
    frame(row, col, 1, 14);
    ball_painting(row, col, star, 14, 's');

    cct_enable_mouse();//����ʹ�����
    int X = 0, Y = 0;
    int ret, maction, loop = 1;
    int keycode1, keycode2;
    int wenzi = 4 + 3 * row;
    cct_showstr(0, wenzi, "��ͷ��/����ƶ����س���/�������ѡ�񲢽���");
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
        // ���λ�ü���
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
                        cout << "[��ǰ���] " << char(weizhi_Y_mouse + 'A') << "��" << weizhi_X_mouse << "��  ";
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star,6,3);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    else
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[��ǰ���] λ�÷Ƿ�";
                    }
                    break;
                case MOUSE_LEFT_BUTTON_CLICK:			//�������
                    if (X > 3 && X <= 3 + 6 * col && Y > 2 && Y <= 2 + row * 3)
                    {
                        loop = 0;
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "ѡ����" << char(weizhi_Y_mouse + 'A') << "��" << weizhi_X_mouse << "��        " << endl;
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                    cout << "ѡ����" << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��        " << endl;
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cct_cls();
    cct_setfontsize("������", 20 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(24 + 6 * col, 16 + 4 * row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
    frame(row, col, 1, 15);
    ball_painting(row, col, star, 15, 's');

    cct_enable_mouse();//����ʹ�����
    int X = 0, Y = 0;
    int ret, maction, loop = 1;
    int keycode1, keycode2;
    int wenzi = 4 + 4 * row;
    cct_showstr(0, wenzi, "��ͷ��/����ƶ����س���/�������ѡ�񲢽���");
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
        // ���λ�ü���
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
                        cout << "[��ǰ���] " << char(weizhi_Y_mouse + 'A') << "��" << weizhi_X_mouse << "��  ";
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star,8,4);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    else
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[��ǰ���] λ�÷Ƿ�";
                    }
                    break;
                case MOUSE_LEFT_BUTTON_CLICK:			//�������
                    if (X > 3 && X < start_x + 8 * col && (X - start_x) % 8 < 6 && Y > 2 && Y < start_y + 4 * row && (Y - start_y) % 4 < 3)
                    {
                        loop = 0;
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "ѡ����" << char(weizhi_Y_mouse + 'A') << "��" << weizhi_X_mouse << "��        " << endl;
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                    cout << "ѡ����" << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��        " << endl;
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            star[i][j] = char(rand() % 5 + '1');
    cct_cls();
    cct_setfontsize("������", 20 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(30 + 4 * col, 16 + 2 * row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
    frame(row, col, 1, 14);
    ball_painting(row, col, star, 14, 's');

    cct_enable_mouse();//����ʹ�����
    int X = 0, Y = 0;
    int ret, maction, loop = 1;
    int keycode1, keycode2;
    const int wenzi = 4 + 3 * row;
    cct_showstr(0, wenzi, "��ͷ��/����ƶ����س���/�������ѡ��");
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
        //������ѡ
        hint_graph(row, col, star, highlight, 's', 6,3,COLOR_BLACK);
        // ���λ�ü���
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
                            cout << "[��ǰ���] " << char(weizhi_Y_mouse + 'A') << "��" << weizhi_X_mouse << "��                                  ";
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 6, 3);
                        }
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;
                    }
                    else
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        cout << "[��ǰ���] λ�÷Ƿ�                                  ";
                    }
                    break;
                case MOUSE_LEFT_BUTTON_CLICK:			//�������
                    if (X > 3 && X <= 3 + 6 * col && Y > 2 && Y <= 2 + row * 3)
                    {
                        cct_gotoxy(0, wenzi);
                        cct_setcolor();
                        if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                            change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 6, 3);
                        weizhi_X_keyboard = weizhi_X_mouse;
                        weizhi_Y_keyboard = weizhi_Y_mouse;

                        find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//�Ƿ��и߹�
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
                            cct_showstr(0, wenzi, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
                            waiting_for_confirmation = true;
                        }
                        else
                            cct_showstr(0, wenzi, "��Χ����ֵͬ����ͷ��/����ƶ�ȡ����ǰѡ��");
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��                                    ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��                                    ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��                                    ";
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
                                cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��                                    ";
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
                    find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//�Ƿ��и߹�
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
                        cct_showstr(0, wenzi, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
                        waiting_for_confirmation = true;
                    }
                    else
                        cct_showstr(0, wenzi, "��Χ����ֵͬ����ͷ��/����ƶ�ȡ����ǰѡ��");
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
    cout << "���ε÷�:" << n * n * 5 << " " << "�ܷ�:" << score;
    cct_showstr(0, wenzi, "�ϳ���ϣ��س���/�����������0                  ");
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
    cct_showstr(0, wenzi, "���κϳɽ�������C/�������������һ�εĺϳ�");
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
        for (int i = 0; i < row; i++) //��ʼ���
            for (int j = 0; j < col; j++)
                star[i][j] = char(rand() % 5 + '1');
        cct_cls();
        cct_setfontsize("������", 20 + 4 * (9 - (row + col) / 2));
        cct_setconsoleborder(24 + 6 * col, 16 + 4 * row, 120, 9000);
        int cols, lines, buffer_cols, buffer_lines;
        cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
        cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
        frame(row, col, 1, 15);
        ball_painting(row, col, star, 15, 's');
        int wenzi = 4 + 4 * row;
        bool bigger_loop = true;
        while (bigger_loop)
        {
            cct_enable_mouse();//����ʹ�����
            int X = 0, Y = 0;
            int ret, maction, loop = 1;
            int keycode1, keycode2;
            cct_showstr(0, wenzi, "��ͷ��/����ƶ����س���/�������ѡ��,Q/�����Ҽ�����");
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
                //������ѡ
                hint_graph(row, col, star, highlight, 's', 8, 4, COLOR_BLACK);
                cct_showstr(0, wenzi, "                                                          ");
                // ���λ�ü���
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
                                cout << "[��ǰ���] " << char(weizhi_Y_mouse + 'A') << "��" << weizhi_X_mouse << "��  ";
                                if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                                    change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 8, 4);
                                weizhi_X_keyboard = weizhi_X_mouse;
                                weizhi_Y_keyboard = weizhi_Y_mouse;
                            }
                            else
                            {
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                cout << "[��ǰ���] λ�÷Ƿ�";
                            }
                            break;
                        case MOUSE_LEFT_BUTTON_CLICK:			//�������
                            if (X > 3 && X < start_x + 8 * col && (X - start_x) % 8 < 6 && Y > 2 && Y < start_y + 4 * row && (Y - start_y) % 4 < 3 && star[(Y - start_y) / 4][(X - start_x) / 8] != '0')
                            {
                                cct_gotoxy(0, wenzi);
                                cct_setcolor();
                                if (weizhi_X_now != weizhi_X_mouse || weizhi_Y_now != weizhi_Y_mouse)
                                    change_weizhi(&weizhi_X_now, &weizhi_Y_now, &weizhi_X_mouse, &weizhi_Y_mouse, star, 8, 4);
                                weizhi_X_keyboard = weizhi_X_mouse;
                                weizhi_Y_keyboard = weizhi_Y_mouse;

                                find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//�Ƿ��и߹�
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
                                    cct_showstr(0, wenzi, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
                                    waiting_for_confirmation = true;
                                }
                                else
                                    cct_showstr(0, wenzi, "��Χ����ֵͬ����ͷ��/����ƶ�ȡ����ǰѡ��");
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
                                        cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                        cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                        cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                                        cout << "[��ǰ����] " << char(weizhi_Y_keyboard + 'A') << "��" << weizhi_X_keyboard << "��  ";
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
                            find_star(row, col, weizhi_Y_now + 'A', weizhi_X_now, star, highlight);//�Ƿ��и߹�
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
                                cct_showstr(0, wenzi, "��ͷ��/����ƶ�ȡ����ǰѡ�񣬻س���/��������ϳ�");
                                waiting_for_confirmation = true;
                            }
                            else
                                cct_showstr(0, wenzi, "��Χ����ֵͬ����ͷ��/����ƶ�ȡ����ǰѡ��");
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
            cout << "���ε÷�:" << n * n * 5 << " " << "�ܷ�:" << score;
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
                cout << "�����÷�:" << (10 - left_stars) * 180 << " �ܷ�:" << score;
                cct_showstr(0, wenzi, "                                                      ");
                cct_gotoxy(0, wenzi - 1);
                cct_setcolor(COLOR_BLACK,COLOR_HYELLOW);
                cout << "ʣ��" << left_stars << "�����ǣ��޿���������ؽ�����";
                cct_setcolor();
                cout << "�س�������һ��";
                while (_getch() != '\r')
                    ;
                break;
            }
        }//end_of_biggerloopһ����Ϸ
    }//game
}