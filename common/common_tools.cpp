/* �ƿ� 2350218 �¼��� */
#define Size_max 10
#define TIME  10
#define DOWN 1
#define LEFT 2
#include<iostream>
#include<conio.h>
#include <windows.h>
#include"../include/cmd_console_tools.h"
using namespace std;

void input(int *row,int *col,int min,int max)
{
    while (1)
    {
        cout << "����������(" << min << "-" << max << "):" << endl;
        cin >> *row;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*row >= min && *row <= max)
            break;
    }
    while (1)
    {
        cout << "����������(" << min << "-" << max << "):" << endl;
        cin >> *col;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*col >= min && *col <= max)
            break;
    }
}

int tj_strcasecmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 == NULL)//���⴦��
        return 0;
    else if (s1 == NULL)
        return -1;
    else if (s2 == NULL)
        return 1;
    while (*s1 != '\0' && *s2 != '\0')
    {
        char n1 = *s1;
        char n2 = *s2;

        if (n1 >= 'A' && n1 <= 'Z')
            n1 = n1 + ('a' - 'A');
        if (n2 >= 'A' && n2 <= 'Z')
            n2 = n2 + ('a' - 'A');

        if (n1 != n2)
            return n1 - n2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void end() {
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cout << "��С�������������End����..." << endl;
    while (1) {
        char a[100] = { 0 };
        char* p;
        p = a;
        while ((*p = getchar()) != '\n')
            p++;
        *p = '\0';
        if (!tj_strcasecmp(a, "End"))
            break;
        cout << "�����������������" << endl;
    }
}

void output_base(int row, int col, char ball_base[Size_max][Size_max], bool color, bool highlight[Size_max][Size_max], bool has_highlight,bool star1=0)
{
    if (color && !has_highlight)
    {
        cout << "��ʼ���޿�������" << endl;
        return;
    }

cout << "  |  ";
for (int i = 0; i < col; i++)
{
    cout << i << "  ";
}
cout << endl;
cout << "--+--";
for (int i = 0; i < col; i++)
    cout << "---";
cout << endl;
if (star1)
{
    for (int i = 0; i < row; i++)
    {
        cout << char('A' + i);
        cout << " |  ";
        for (int j = 0; j < col; j++)
        {
            if (highlight[i][j])
                cout << '*';
            else
                cout << '0';
            cout << "  ";
        }
        cout << endl;
    }
    return;
}
for (int i = 0; i < row; i++)
{
    cout << char('A' + i);
    cout << " |  ";
    for (int j = 0; j < col; j++)
    {
        if (color && highlight[i][j])
            cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
        cout << ball_base[i][j];
        cct_setcolor();
        cout << "  ";
    }
    cout << endl;
}
cout << endl;
}

void zero_fall(int row, int col, char base[Size_max][Size_max], bool highlight[Size_max][Size_max], bool has_highlight, char type)
{
    //�������Ϊ0
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (highlight[i][j])
                base[i][j] = '0';
    if (type == 's')
        output_base(row, col, base, 1, highlight, true);
    if (has_highlight)
    {
        cout << "���س����������������0����..." << endl;
        while (_getch() != '\r')
            ;
    }
    else
        return;//�Ѿ�˵��û�и߹⣬���Ի���
    //����������
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (base[i][j] == '0')
                highlight[i][j] = false;

    cout << "�����0�������(��ͬɫ��ʶ):" << endl;
    //���������������Ϊ0
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (highlight[i][j])
            {
                highlight[i][j] = false;
                base[i][j] = '0';
            }
        }
    }
    //����,��֤position�ĵ�����0��position����i��
    for (int j = 0; j < col; j++)
    {
        int position = row - 1;
        for (int i = row - 1; i >= 0; i--)
        {
            if (base[i][j] != '0')
            {
                base[position][j] = base[i][j];
                if (position != i)
                {
                    base[i][j] = '0';
                }
                position--;
            }
        }
    }
    if(type == 's')
    {
        int n = 0;
        //����
        for (int j = 0; j < col-n; j++)//��Щ����ȫ0
        {
            bool check = true;
            for (int i = 0; i < row; i++)
            {
                if (base[i][j]!='0')
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                n++;
                for (int k = j + 1; k < col-n+1; k++)
                    for (int i = 0;i < row;i++)
                        base[i][k - 1] = base[i][k];
                for (int i = 0;i < row;i++)
                    base[i][col-n] = '0';
                j--;
            }
        }
    }

    //����״̬
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            if (base[i][j] == '0')
                highlight[i][j] = true;
        }
    }
    output_base(row, col, base, 1, highlight, has_highlight);
}

void frame(int row, int col, int num,int magic_number)//û��gotoxy����������ֱ�����
{
    if (num == 1)
    {
        cout << "    ";
        for (int j = 0;j < col;j++)
        {
            cout << "  " << j << "   ";
            if (magic_number == 15)
                cout << "  ";
        }
            cout << endl;
    }
    //����
    if (num == 1)
    {
        cct_setcolor();
        cout << "  ";
    }
    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
    if (magic_number<10)
        cout << "�X ";
    else if (magic_number > 10)//��һ������Ϊ1��ζʵ�Ŀ�
        cout << "�� ";
    for (int j = 0;j < col;j++)
    {
        if (magic_number == 4 || magic_number == 5||magic_number==14)
            Sleep(TIME);
        if (magic_number < 10)
            cout << "�T ";
        else if (magic_number > 10)//��һ������Ϊ1��ζʵ�Ŀ�
            cout << "�� �� �� ";

        if ((magic_number == 5 || magic_number == 7) && j < col - 1)
            cout << "�j ";
        else if (magic_number == 15 && j < col - 1)
            cout << "�� ";
    }
    if (magic_number == 4 || magic_number == 5)
        Sleep(TIME);
    if (magic_number < 10)
        cout << "�[ " << endl;
    else if (magic_number > 10)//��һ������Ϊ1��ζʵ�Ŀ�
        cout << "�� " << endl;

    //���

    if (magic_number == 4 || magic_number == 6)
    {
        for (int i = 0;i < row;i++)
        {
            cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
            if (magic_number == 4)
                Sleep(TIME);
            if (num == 0)
                cout << "�U ";
            cct_setcolor();
            for (int j = 0;j < col;j++)
            {
                if (magic_number == 4)
                    Sleep(TIME);
                cout << "  ";//һ������Ϊ���ַ�
            }
            cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
            if (magic_number == 4)
                Sleep(TIME);
            cout << "�U " << endl;
        }
    }
    else if (magic_number == 5 || magic_number == 7)
    {
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        for (int i = 0;i < row;i++)
        {
            if (magic_number == 5)
                Sleep(TIME);
            cout << "�U ";
            for (int j = 0;j < col;j++)
            {
                if (magic_number == 5)
                    Sleep(TIME);
                cout << "  ";//һ������Ϊ���ַ�
                if (j < col - 1)
                    cout << "�U ";
            }
            if (magic_number == 5)
                Sleep(TIME);
            cout << "�U " << endl;
            if (i < row - 1)
            {
                cout << "�d ";
                for (int j = 0;j < col - 1;j++)
                {
                    if (magic_number == 5)
                        Sleep(TIME);
                    cout << "�T �p ";
                }
                cout << "�T �g " << endl;
            }
        }
    }
    else if (magic_number == 14)
    {
        int k = 1;
        for (int i = 0;i < row*3;i++)
        {
            Sleep(TIME);
            k++;
            cct_setcolor();
            if (k % 3 == 0)
                cout << char('A' + i / 3) << " ";
            else
                cout << "  ";
            cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
            cout << "�� ";
            for (int j = 0;j < col;j++)
            {
                cout << "      ";
            }
            cout << "�� " << endl;
        }
    }
    else if (magic_number == 15)
    {
        int k = 1;
        for (int i = 0;i < row * 4-1;i++)
        {
            Sleep(TIME);
            k++;
            cct_setcolor();
            if ((k-3) % 4 == 0)
                cout << char('A' + i / 4) << " ";
            else
                cout << "  ";
            cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
            if ((k-1) % 4 != 0)
            {
                cout << "�� ";
                for (int j = 0;j < col;j++)
                {
                    cout << "      �� ";
                }
                cout << endl;
            }
            else if ((k-1) % 4 == 0 && i < row * 4 - 1)
            {
                cout << "�� ";
                for (int j = 0;j < col-1;j++)
                {
                    cout << "�� �� �� �� ";
                }
                cout << "�� �� �� �� ";
                cout << endl;
            }
        }
    }

    //����
    if (num == 1)
    {
        cct_setcolor();
        cout << "  ";
    }
    cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
    if (magic_number == 4 || magic_number == 5)
        Sleep(TIME);
    if (num == 0)
        cout << "�^ ";
    else if (num == 1)
        cout << "�� ";
    for (int j = 0;j < col;j++)
    {
        if (magic_number == 4 || magic_number == 5)
            Sleep(TIME);
        if (num == 0)
            cout << "�T ";
        else if (num == 1)
            cout << "�� �� �� ";
        if ((magic_number == 5 || magic_number == 7) && j < col - 1)
            cout << "�m ";
        else if(magic_number==15&&j<col-1)
            cout << "�� ";
    }
    if (magic_number == 4 || magic_number == 5)
        Sleep(TIME);
    if (num == 0)
        cout << "�a " << endl;
    else if(num == 1)
        cout << "�� " << endl;
    //������
}

void ball_painting(int row, int col, char base[Size_max][Size_max], int magic_number,char type)
{
    int start_x=0;
    int start_y=0;
    if (type == 'b')
    {
        start_x = 2;
        start_y = 2;
    }
    else if (type == 's')
    {
        start_x = 4;
        start_y = 3;
    }
    if (magic_number == 4 || magic_number == 6 || magic_number == 5 || magic_number == 7)
    {
        int x = 0, y = 0;
        for (int i = 0;i < row;i++)
        {
            for (int j = 0;j < col;j++)
            {
                if (magic_number == 4)
                    Sleep(TIME);
                cct_showstr(x + start_x, y + start_y, "��", base[i][j], COLOR_BLACK);
                if (magic_number == 4 || magic_number == 6)
                    x = x + 2;
                else if (magic_number == 5 || magic_number == 7)
                    x = x + 4;
            }
            x = 0;
            if (magic_number == 4 || magic_number == 6)
                y++;
            else if (magic_number == 5 || magic_number == 7)
                y += 2;
            cct_gotoxy(start_x, y + start_y);
        }
    }
    else if (magic_number == 14|| magic_number == 15)
    {
        int x = 0, y = 0;
        for (int i = 0;i < row;i++)
        {
            for (int j = 0;j < col;j++)
            {
                Sleep(TIME);
                cct_showstr(x + start_x, y + start_y, "�X�T�[", base[i][j]+8, COLOR_BLACK);
                cct_showstr(x + start_x, y + start_y + 1, "�U��U", base[i][j]+8, COLOR_BLACK);
                cct_showstr(x + start_x, y + start_y + 2, "�^�T�a", base[i][j]+8, COLOR_BLACK);
                if (magic_number == 14)
                    x = x + 2 * 3;
                else if (magic_number == 15)
                    x = x + 2 * 4;
            }
            x = 0;
            if (magic_number == 14)
                y += 3;
            else if (magic_number == 15)
                y += 4;
            cct_gotoxy(start_x, y + start_y);
        }
    }
    cout << endl;
    cct_setcolor();
}

void hint_graph(int row, int col, char base[Size_max][Size_max], bool removable[Size_max][Size_max],char type, int number_x=0, int number_y=0,int color= COLOR_HWHITE)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (removable[i][j]&&type=='b')
            {
                int ball_x, ball_y;
                ball_x = 2 + 4 * j;
                ball_y = 2 + 2 * i;
                cct_showstr(ball_x, ball_y, "��", base[i][j], COLOR_BLACK);
            }
            else if (removable[i][j] && type == 's')
            {
                int ball_x, ball_y;
                ball_x = 4 + number_x * j;
                ball_y = number_y * i + 3;
                cct_showstr(ball_x, ball_y, "�X�T�[", base[i][j] + 8, color);
                cct_showstr(ball_x, ball_y + 1, "�U��U", base[i][j] + 8, color);
                cct_showstr(ball_x, ball_y + 2, "�^�T�a", base[i][j] + 8, color);
                Sleep(TIME);
            }
            else if (removable[i][j] && type == 'k')
            {
                removable[i][j] = false;
                int ball_x, ball_y;
                ball_x = 4 + number_x * j;
                ball_y = number_y * i + 3;
                base[i][j] = '0';
                cct_showstr(ball_x, ball_y, "      ", COLOR_HWHITE, COLOR_HWHITE);
                cct_showstr(ball_x, ball_y + 1, "      ", COLOR_HWHITE, COLOR_HWHITE);
                cct_showstr(ball_x, ball_y + 2, "      ", COLOR_HWHITE, COLOR_HWHITE);
            }
        }
    }
}

void move_graph(int row, int col, char base[Size_max][Size_max], bool highlight[Size_max][Size_max],char type, int number_x, int number_y,int direction=DOWN)
{
    if(type == 'b') 
    {
        for (int j = 0; j < col; j++)
        {
            for (int i = row - 1; i >= 0; i--)
            {
                if (base[i][j] == '0')//�ҵ�Ҫ����λ��
                {
                    for (int N = i - 1;N >= 0;N--)
                    {
                        if (base[N][j] != '0')//�ҵ���һ������0��������,Nֻ��һ��
                        {
                            //���䵽position=i;
                            int ball_x, ball_y;
                            ball_x = 2 + 4 * j;
                            ball_y = 2 + 2 * N;
                            for (int n = ball_y;n != 2 + 2 * i;)
                            {
                                Sleep(5 * TIME);
                                cct_showstr(ball_x, n, "  ", COLOR_HWHITE, COLOR_BLACK);
                                n++;
                                cct_showstr(ball_x, n, "��", base[N][j], COLOR_BLACK);
                                Sleep(5 * TIME);
                                cct_showstr(ball_x, n, "�T", COLOR_HWHITE, COLOR_BLACK);
                                n++;
                                cct_showstr(ball_x, n, "��", base[N][j], COLOR_BLACK);
                            }
                            base[i][j] = base[N][j];
                            base[N][j] = '0';
                            break;
                        }
                    }
                }
            }
        }
    }
    else if (type == 's')
    {
        switch (direction)
        {
            case DOWN:
                for (int j = 0; j < col; j++)
                {
                    for (int i = row - 1; i >= 0; i--)
                    {
                        if (base[i][j] == '0')//�ҵ�Ҫ����λ��
                        {
                            for (int N = i - 1;N >= 0;N--)
                            {
                                if (base[N][j] != '0')//�ҵ���һ������0��������,Nֻ��һ��
                                {
                                    int ball_x, ball_y;
                                    ball_x = 4 + number_x * j;
                                    ball_y = 3 + number_y * N;
                                    for (int n = ball_y;n < 3 + number_y * i;)
                                    {
                                        Sleep(TIME);
                                        cct_showstr(ball_x, n, "      ", COLOR_HWHITE, COLOR_BLACK);
                                        if (number_x == 8 && (n - 2) % 4 == 0)
                                            cct_showstr(ball_x, n, "������", COLOR_HWHITE, COLOR_BLACK);
                                        n++;
                                        cct_showstr(ball_x, n, "�X�T�[", base[N][j] + 8, COLOR_BLACK);
                                        cct_showstr(ball_x, n + 1, "�U��U", base[N][j] + 8, COLOR_BLACK);
                                        cct_showstr(ball_x, n + 2, "�^�T�a", base[N][j] + 8, COLOR_BLACK);
                                    }
                                    base[i][j] = base[N][j];
                                    base[N][j] = '0';
                                    break;
                                }
                            }
                        }
                    }
                }
                break;
            case LEFT:
                int n = 0;
                for (int j = 0; j < col - n; j++)//��Щ����ȫ0
                {
                    bool check = true;
                    for (int i = 0; i < row; i++)
                    {
                        if (base[i][j] != '0')
                        {
                            check = false;
                            break;
                        }
                    }
                    if (check)//��������+������
                    {
                        n++;
                        for (int k = j + 1; k < col - n + 1; k++)
                            for (int i = 0;i < row;i++)
                            {
                                base[i][k - 1] = base[i][k];
                                int ball_x, ball_y;
                                ball_x = 4 + number_x * k;
                                ball_y = 3 + number_y * i;
                                for (int n = ball_x;n > 4 + number_x * (k-1);)
                                {
                                    if (base[i][k] == '0')
                                        break;
                                    Sleep(TIME);
                                    cct_showstr(n+4, ball_y, "  ", COLOR_HWHITE, COLOR_BLACK);
                                    cct_showstr(n + 4, ball_y+1, "  ", COLOR_HWHITE, COLOR_BLACK);
                                    cct_showstr(n + 4, ball_y+2, "  ", COLOR_HWHITE, COLOR_BLACK);
                                    if (number_x == 8 && ((n - 4) % 8 ==1|| (n - 4) % 8 == 2))
                                    {
                                        cct_showstr(n + 4, ball_y, "��", COLOR_HWHITE, COLOR_BLACK);
                                        cct_showstr(n + 4, ball_y + 1, "��", COLOR_HWHITE, COLOR_BLACK);
                                        cct_showstr(n + 4, ball_y + 2, "��", COLOR_HWHITE, COLOR_BLACK);
                                    }
                                    n-=2;
                                    cct_showstr(n, ball_y, "�X�T�[", base[i][k] + 8, COLOR_BLACK);
                                    cct_showstr(n, ball_y + 1, "�U��U", base[i][k] + 8, COLOR_BLACK);
                                    cct_showstr(n, ball_y + 2, "�^�T�a", base[i][k] + 8, COLOR_BLACK);
                                }
                            }
                        for (int i = 0;i < row;i++)
                            base[i][col - n] = '0';
                        j--;
                    }
                }

        }
    }
}