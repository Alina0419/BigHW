/* �ƿ� 2350218 �¼��� */
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
                cct_showstr(ball_x, ball_y, "��", base[i][j], COLOR_BLACK);
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
                    cct_showstr(ball_x, ball_y, "��", base[i][j], COLOR_BLACK);
                    Sleep(5 * TIME);
                    cct_showstr(ball_x, ball_y, "��", base[i][j], COLOR_BLACK);
                }
                base[i][j] = '0';//���˵�����
                (*score)++;
                cct_showstr(ball_x, ball_y, "  ", COLOR_HWHITE, COLOR_BLACK);
            }
        }
    }
    void (*p)(int, int, char[Size_max][Size_max], bool[Size_max][Size_max],char,int,int,int);
    p = move_graph;
    p(row,col,base,highlight,'b',2,1,DOWN);
    //����״̬�����Ƶģ��пտ������Խ��graph��base
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
                cct_showstr(ball_x, ball_y, "��", base[i][j], COLOR_BLACK);
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "��ʼ���飺" << endl;
    output_base(row, col, base, 0, 0, false);//�޸߹�
    cout << "���س�����ʾͼ��..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("������", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 6+row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "��ʼ���飺" << endl;
    output_base(row, col, base, 0, 0, false);//�޸߹�
    cout << "���س�����ʾͼ��..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("������", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "��ʼ���飺" << endl;
    output_base(row, col, base, 0, 0, false);//�޸߹�
    cout << "���س�����ʾͼ��..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("������", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 6 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
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
                cct_showstr(ball_x, ball_y, "��", base[i][j], COLOR_BLACK);
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cout << endl;
    cout << "��ʼ���飺" << endl;
    output_base(row, col, base, 0, 0, false);//�޸߹�
    cout << "���س�����ʾͼ��..." << endl;
    while (_getch() != '\r')
        ;
    cct_cls();
    cct_setfontsize("������", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
    frame(row, col,0, 7);
    bool highlight[Size_max][Size_max] = { 0 };
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
    ball_painting(row, col, base, 7, 'b');
    int wenzi_x,wenzi_y;//�����·���ӡ���ֵ�λ��
    cct_getxy(wenzi_x,wenzi_y);
    int score = 0;
    while (1)
    {
        cct_setcolor();
        has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
        ball_789(row, col,base, highlight);

        if (!has_highlight)
        {
            cct_gotoxy(0, 0);
            cout << "��Ļ��" << lines << "��" << cols << "��(δ�ҵ���ʼ��������)";
            break;
        }
        //���ҿ��������û�п��������ˣ���һ��ֱ�������δ�ҵ���ʼ��������Ŀ��
        cct_setcolor();
        cct_gotoxy(0, wenzi_y);
        cout << "���س������������������0����...";//��ը+���䣬��¼���λ�ã�������һ��һ�е���
        while (_getch() != '\r')
            ;
        eliminate(row, col, base, highlight, &score);
        cct_setcolor();
        cct_gotoxy(0, wenzi_y);
        cout << "���س���������ֵ���...          ";//һ��һ�е���
        while (_getch() != '\r')
            ;
        fill_new(row, col, base, highlight);
    }
    cct_gotoxy(0, wenzi_y);
    cout << "���س�����ʾ������ʾ...";
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cct_cls();
    cct_setfontsize("������", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
    frame(row, col,0, 7);
    bool highlight[Size_max][Size_max] = { 0 };
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
    ball_painting(row, col, base, 7, 'b');
    int wenzi_x, wenzi_y;//�����·���ӡ���ֵ�λ��
    cct_getxy(wenzi_x, wenzi_y);
    int score = 0;
    while (1)
    {
        cct_setcolor();
        has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
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
    cout << "��Ļ��" << lines << "��" << cols << "��(��ǰ������0 �Ҽ��˳�)" ;//��Ŀ9���趨��score
    bool removable[Size_max][Size_max] = { 0 };
    hint(row, col, base, removable);
    hint_graph(row, col, base, removable,'b');
    cct_setcolor();
    cct_gotoxy(0, wenzi_y);
    cct_enable_mouse();//����ʹ�����
    int X = 0, Y = 0;
    int ret, maction,loop=1;
    int keycode1, keycode2;
    while (loop)
    {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//����������û�õ�
        if (ret == CCT_MOUSE_EVENT)
        {
            int weizhi_X = (X - 2) / 4;//X��j��Ӧ
            int weizhi_Y = (Y - 2) / 2;
            cct_gotoxy(0, wenzi_y);
            if (maction == MOUSE_ONLY_MOVED)
            {
                if ((X-2)%4==0&&(Y-2)%2==0)
                    cout << "[��ǰ���] " << char(weizhi_Y + 'A') << "��" << weizhi_X+1 << "��  ";
                else
                    cout << "[��ǰ���] λ�÷Ƿ�";
                continue;
            }
            switch (maction)
            {
                case MOUSE_LEFT_BUTTON_CLICK:			//�������
                {
                    if (((X - 2) % 4 == 0 && (Y - 2) % 2 == 0)&&removable[weizhi_Y][weizhi_X])
                    {
                        cout << "��ǰѡ��" << char(weizhi_Y + 'A') << "��" << weizhi_X + 1 << "��  ";
                    }
                    else if(((X - 2) % 4 == 0 && (Y - 2) % 2 == 0) && !removable[weizhi_Y][weizhi_X])
                        cout << "����ѡ��" << char(weizhi_Y + 'A') << "��" << weizhi_X + 1 << "��  ";
                    break;
                }
                case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
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

    for (int i = 0; i < row; i++) //��ʼ���
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');
    cct_cls();
    cct_setfontsize("������", 32 + 4 * (9 - (row + col) / 2));
    cct_setconsoleborder(40, 14 + row, 120, 9000);
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    cout << "��Ļ��" << lines << "��" << cols << "��" << endl;
    frame(row, col,0, 7);
    bool highlight[Size_max][Size_max] = { 0 };
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
    ball_painting(row, col, base, 7, 'b');
    int wenzi_x, wenzi_y;//�����·���ӡ���ֵ�λ��
    cct_getxy(wenzi_x, wenzi_y);
    int score_start = 0;
    while (1)
    {
        cct_setcolor();
        has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
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
    cout << "��Ļ��" << lines << "��" << cols << "��(��ǰ������" << score << " �Ҽ��˳�)";//��Ŀ9���趨��score
    while (1)//��Ϸ���̺���
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
            cout << "�޿��������Ϸ���������յ÷֣�" << score << "    ";
            break;
        }
        cct_setcolor();
        cct_gotoxy(0, 0);
        cout << "��Ļ��" << lines << "��" << cols << "��(��ǰ������" << score << " �Ҽ��˳�)";
        cct_gotoxy(0, wenzi_y);
        cct_enable_mouse();//����ʹ�����
        int X = 0, Y = 0;
        int ret, maction, loop = 1,mycontinue=1;
        int keycode1, keycode2;
        int removable_highlight = 0;
        int removable_highlight_col, removable_highlight_row;

        while (loop)
        {
            ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);//����������û�õ�
            if (ret == CCT_MOUSE_EVENT)
            {
                int weizhi_X = (X - 2) / 4;//X��j��Ӧ
                int weizhi_Y = (Y - 2) / 2;
                cct_gotoxy(0, wenzi_y);
                if (maction == MOUSE_ONLY_MOVED)
                {
                    if ((X - 2) % 4 == 0 && (Y - 2) % 2 == 0)//�пտ��Ը�һ�·�Χ
                        cout << "[��ǰ���] " << char(weizhi_Y + 'A') << "��" << weizhi_X + 1 << "��            ";
                    else
                        cout << "[��ǰ���] λ�÷Ƿ�          ";
                    continue;
                }
                switch (maction)
                {
                    case MOUSE_LEFT_BUTTON_CLICK:			//�������
                    {
                        if (((X - 2) % 4 == 0 && (Y - 2) % 2 == 0) && removable[weizhi_Y][weizhi_X])
                        {
                            if (!removable_highlight)
                            {
                                cct_showstr(X, Y, "��", base[weizhi_Y][weizhi_X], COLOR_HWHITE);
                                removable_highlight_row = weizhi_Y;
                                removable_highlight_col = weizhi_X;
                                removable_highlight = 1;
                            }
                            else if (removable_highlight)
                            {
                                if (removable_highlight_row == weizhi_Y && removable_highlight_col == weizhi_X)//ȡ��
                                {
                                    cct_showstr(X, Y, "��", base[weizhi_Y][weizhi_X], COLOR_BLACK);
                                    removable_highlight = 0;
                                }
                                else if (abs(weizhi_Y - removable_highlight_row) + abs(weizhi_X - removable_highlight_col) > 1)//��ѡ
                                {
                                    cct_showstr(X, Y, "��", base[weizhi_Y][weizhi_X], COLOR_HWHITE);
                                    cct_showstr(2 + 4 * removable_highlight_col, 2 + 2 * removable_highlight_row, "��", base[removable_highlight_row][removable_highlight_col], COLOR_BLACK);
                                    removable_highlight_row = weizhi_Y;
                                    removable_highlight_col = weizhi_X;
                                }
                                else if (abs(weizhi_Y - removable_highlight_row) + abs(weizhi_X - removable_highlight_col) <= 1)//�ж��Ƿ����
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
                                        cout << "���ܽ���" << char(weizhi_Y + 'A') << "��" << weizhi_X + 1 << "��  <=>  " << char(weizhi_Y + 'A') << "��" << weizhi_X + 1 << "��";
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
                            cout << "��ǰѡ��" << char(weizhi_Y + 'A') << "��" << weizhi_X + 1 << "��            ";
                        }
                        else if (((X - 2) % 4 == 0 && (Y - 2) % 2 == 0) && !removable[weizhi_Y][weizhi_X])
                            cout << "����ѡ��" << char(weizhi_Y + 'A') << "��" << weizhi_X + 1 << "��            ";
                        break;
                    }
                    case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
                        loop = mycontinue = 0;
                        break;
                    default:
                        break;
                } //end of switch(maction)
            } //end of if (CCT_MOUSE_EVENT)
        }
        if (loop == 0&&mycontinue==0)
            break;
        ball_painting(row, col, base, 7, 'b');//һ����
        while (1)
        {
            cct_setcolor();
            has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
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