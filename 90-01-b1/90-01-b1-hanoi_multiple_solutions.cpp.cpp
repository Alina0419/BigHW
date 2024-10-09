/* ��01 2350218 �¼��� */
#define rowbase_X 20
#define rowbase_Y 25
#define pillarbase_X 1//���ӵײ���һ���ط�
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

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

void move(int n, char ws, char wt, char wd, int hanoi_i)
{
    if (hanoi_i == 7)
    {
        //��һ��Ҫ�ƶ������Ӷ�λx=1+ws*10+11,y=15-n,���3 (zhan[ws][top[ws]]*2+1)  //�ǵõ���ջ��������
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
            for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//ɾ��һ��
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
                cct_setcolor(zhan[ws][top[ws]] + 1);//Ī�����ˣ���һ��
                cout << " ";
                cct_gotoxy(x - kuan, y);
                cout << " ";
                cct_gotoxy(x + kuan, y);
                cout << " ";
            }
            Sleep(100);//�ǵø���ֵ
        }
        //ƽ��
        if (n % 2 == 0)//src-tmp
        {
            int X_Max = x - (zhan[ws][top[ws]] + 1) + 30 * (wt - ws) + 1;//ԭ�ػ���һ��X_Max��ƽ�Ƶ����λ��x�Ŀ�ͷ
            if (wt > ws)
            {
                /* ��һ���ַ����������ƶ� */
                for (x = x - (zhan[ws][top[ws]] + 1); x < X_Max; x++)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* ��ʱ0.1�� */
                    Sleep(100);

                    if (x < X_Max - 1) {
                        /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //����
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
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//ɾ��һ��
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
                        cct_setcolor(zhan[ws][top[ws]] + 1);//Ī�����ˣ���һ��
                        cout << " ";
                        cct_gotoxy(x - kuan, y);
                        cout << " ";
                        cct_gotoxy(x + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//�ǵø���ֵ
                }
            }
            if (wt < ws)
            {
                int X_Min = x - (zhan[ws][top[ws]] + 1) - 30 * (ws - wt) - 1;//ԭ�ػ���һ��
                /* ��һ���ַ����������ƶ� */
                for (x = x - (zhan[ws][top[ws]] + 1); x > X_Min; x--)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* ��ʱ0.1�� */
                    Sleep(100);

                    if (x > X_Min + 1) {
                        /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //����
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
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//ɾ��һ��
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
                        cct_setcolor(zhan[ws][top[ws]] + 1);//Ī�����ˣ���һ��
                        cout << " ";
                        cct_gotoxy(X_Min - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Min + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//�ǵø���ֵ
                }
            }
        }

        else//src-dst
        {
            if (wd > ws)
            {
                int X_Max = x - (zhan[ws][top[ws]] + 1) + 30 * (wd - ws) + 1;//ԭ�ػ���һ��
                /* ��һ���ַ����������ƶ� */
                for (x = x - (zhan[ws][top[ws]] + 1); x < X_Max; x++)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* ��ʱ0.1�� */
                    Sleep(100);

                    if (x < X_Max - 1) {
                        /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //����
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
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//ɾ��һ��
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
                        cct_setcolor(zhan[ws][top[ws]] + 1);//Ī�����ˣ���һ��
                        cout << " ";
                        cct_gotoxy(x - kuan, y);
                        cout << " ";
                        cct_gotoxy(x + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//�ǵø���ֵ
                }
            }
            if (wd < ws)
            {
                int X_Min = x - (zhan[ws][top[ws]] + 1) - 30 * (ws - wd) - 1;//ԭ�ػ���һ��
                /* ��һ���ַ����������ƶ� */
                for (x = x - (zhan[ws][top[ws]] + 1); x > X_Min; x--)
                {
                    cct_showch(x, y, ' ', (zhan[ws][top[ws]] + 1), COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);

                    /* ��ʱ0.1�� */
                    Sleep(100);

                    if (x > X_Min + 1) {
                        /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                        cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws]] + 1) + 1);
                    }
                }
                //����
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
                    for (int kuan = (zhan[ws][top[ws]] * 2 + 1);kuan > 0;kuan--)//ɾ��һ��
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
                        cct_setcolor(zhan[ws][top[ws]] + 1);//Ī�����ˣ���һ��
                        cout << " ";
                        cct_gotoxy(X_Min - kuan, y);
                        cout << " ";
                        cct_gotoxy(X_Min + kuan, y);
                        cout << " ";
                    }
                    Sleep(100);//�ǵø���ֵ
                }
            }
        }
        return;
    }
    int x = pillarbase_X + ws * 30 + 11;
    int y = pillarbase_Y -top[ws];
    while (y > 1)//����
    {
        cct_gotoxy(x, y);
        if (y >= 3)
            cct_setcolor(COLOR_HYELLOW);
        else
            cct_setcolor();
        cct_setcursor(CURSOR_INVISIBLE);
        cout << " ";//ɾ���м��
        for (int kuan = zhan[ws][top[ws] - 1];kuan > 0;kuan--)//ɾ����Χ��
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
            cct_gotoxy(x, y);//̫�ؼ��ˣ������Ұ��죬��������
            cct_setcolor(zhan[ws][top[ws] - 1]);
            cout << " ";
            cct_gotoxy(x - kuan, y);
            cout << " ";
            cct_gotoxy(x + kuan, y);
            cout << " ";
        }
        Sleep(100-speed*20);//�ǵø���ֵ
    }
    //ƽ��
    if (wd > ws)
    {
        int X_Max = x - (zhan[ws][top[ws] - 1]) + 30 * (wd - ws);
        /* ��һ���ַ����������ƶ� */
        for (x = x - (zhan[ws][top[ws] - 1]); x < X_Max+1; x++)
        {
            cct_showch(x, y, ' ', (zhan[ws][top[ws] - 1]), COLOR_WHITE, 2 * (zhan[ws][top[ws] - 1]) + 1);

            Sleep(100-speed*20);

            if (x < X_Max+1)
            {
                /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * (zhan[ws][top[ws] - 1]) + 1);
            }
        }
        //����
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
            for (int kuan = (zhan[ws][top[ws] - 1]);kuan > 0;kuan--)//ɾ��һ��
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
                cct_setcolor(zhan[ws][top[ws] - 1]);//Ī�����ˣ���һ��
                cout << " ";
                cct_gotoxy(X_Max - kuan, y);
                cout << " ";
                cct_gotoxy(X_Max + kuan, y);
                cout << " ";
            }
            Sleep(100 - speed * 20);//�ǵø���ֵ
        }
    }
    if (wd < ws)
    {
        int X_Min = x - (zhan[ws][top[ws] - 1]) - 30 * (ws - wd);//ԭ�ػ���һ��
        /* ��һ���ַ����������ƶ� */
        for (x = x - (zhan[ws][top[ws] - 1]); x > X_Min-1; x--)
        {
            cct_showch(x, y, ' ', (zhan[ws][top[ws] - 1]), COLOR_WHITE, 2 * zhan[ws][top[ws] - 1]+1);

            Sleep(100 - speed * 20);

            if (x > X_Min-1 )
            {
                /* �����ʾ(���һ�α���)���������Ϊ��������ɫ+�ո��ػ�һ��ղŵ�λ�� */
                cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * zhan[ws][top[ws] - 1] + 1);
            }
        }
        //����
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
            for (int kuan = (zhan[ws][top[ws] - 1]);kuan > 0;kuan--)//ɾ��һ��
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
        for (int k=0;k<11-n+i;k++)//��ͷ��ӡ����ȱʡ�ո�
        {
            //�ָ�ȱʡ��ɫ
            cct_setcolor();
            cout << " ";
        }
        for (int j = 0;j<(n-i)*2+1;j++)//��ӡ������ɫ�ո�
        {
            //���ñ���ɫ
            cct_setcolor(n-i);//n-iΪ�̺�
            cout << " ";
        }
        Sleep(100);
    }
}


void pillar()
{
    //������
    //���λ�ã�x���30
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
    //����������
    for (int i = 1;i <= 12; i++)//��
    {
        for (int j = 0;j < 3;j++)//��
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

void image(int hanoi_i)//��������λ��
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
    for (int i = 0;i < top[0];i++)//��ӡ���ŵ�����
    {
        x = 10;
        cct_gotoxy(x, y--);
        cout << setw(2) << zhan[0][i];
    }
    for (int i = top[0];i < 10;i++)//��ӡ���ŵĿո�
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
    for (int i = top[1];i < 10;i++)//��ӡ���ŵĿո�
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
    for (int i = top[2];i < 10;i++)//��ӡ���ŵĿո�
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
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> *n;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*n >= 1 && *n <= 10)
            break;
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
        cin >> *dst;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*dst == *src || *dst - 32 == *src)
        {
            cout << "Ŀ����(" << *src << ")��������ʼ��(" << *src << ")��ͬ" << endl;
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
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> speed;
    }
}

void hanoi_choice(int n, char src, char tmp, char dst, int hanoi_i, int weizhi)
{
    int ws, wd;//λ��-src,λ��-dst
    if (weizhi == 1)//�Ƿ��ӡ����/��궨λ
    {
        if (hanoi_i == 4)
        {
            cct_gotoxy(rowbase_X, rowbase_Y);
        }
        else if (hanoi_i == 8)
        {
            //�ָ�ȱʡ��ɫ
            cct_setcolor();
            //�ָ����
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cct_gotoxy(rowbase_X, rowbase_Y+10);//��ӡABC
        }
        if (hanoi_i)
            cout << "��" << setw(4) << ++step << " ��";
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
            //�ָ�ȱʡ��ɫ
            cct_setcolor();
            //�ָ����
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            move(n, ws, 'A'+'B'+'C'-ws-wd, wd, hanoi_i);
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            //�ָ�ȱʡ��ɫ
            cct_setcolor();
            //�ָ����
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
            //�ָ�ȱʡ��ɫ
            cct_setcolor();
            //�ָ����
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            cct_gotoxy(rowbase_X, rowbase_Y + 10);//��ӡABC
        }
        if (hanoi_i)
            cout << "��" << setw(4) << ++step << " ��";
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
            //�ָ�ȱʡ��ɫ
            cct_setcolor();
            //�ָ����
            cct_setcursor(CURSOR_VISIBLE_NORMAL);
            move(n, ws, 'A' + 'B' + 'C' - ws - wd, wd, hanoi_i);
            zhan[wd][top[wd]++] = zhan[ws][--top[ws]];
            zhan[ws][top[ws]] = 0;
            //�ָ�ȱʡ��ɫ
            cct_setcolor();
            //�ָ����
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
    {//�Ӳ���
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


//����������1
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
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed;
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
    //����
    cct_cls();
    pillar();
    //�ָ�ȱʡ��ɫ
    cct_setcolor();
    //�ָ����
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
    cout << "�� " << src << " �ƶ��� " << dst << ",�� " << n << " ��";
    pillar();

    src_plate(n, src, tmp, dst);

    //�ָ�ȱʡ��ɫ
    cct_setcolor();
    //�ָ����
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
    cout << "�� " << src << " �ƶ��� " << dst << ",�� " << n << " ��";
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

    //�ָ�ȱʡ��ɫ
    cct_setcolor();
    //�ָ����
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
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed;

    pillar();
    src_plate(n, src, tmp, dst);

    if (speed != 0)
        Sleep(800 / speed);
    else if (speed == 0)
    {
        while (_getch() != '\r')
            ;
    }
    //�ָ�ȱʡ��ɫ
    cct_setcolor();
    //�ָ����
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    hanoi(n, src, tmp, dst, 8);


    //�ָ�ȱʡ��ɫ
    cct_setcolor();
    //�ָ����
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
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);//����ĵط�
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
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
    pillar();
    src_plate(n, src, tmp, dst);
    cct_gotoxy(rowbase_X, rowbase_Y + 10);
    //�ָ�ȱʡ��ɫ
    cct_setcolor();
    //�ָ����
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cout << "��ʼ��            ";
    printABC();
    image(9);
    //����Ϊ��ʼ��ͼ���ᡢ��
    while (1)
    {
        cct_gotoxy(rowbase_X, rowbase_Y + 10+1);
        cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�)��";
        int x=shuru_9(&ws,&wd);
        if (x == 1)
        {
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "��Ϸ��ֹ";
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
            cout << "Դ��Ϊ��";
            Sleep(800);
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);//�ڶ���
            cout << "                    ";
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);//����ĵط�
            cout << "                    ";
            cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);
            continue;

        }
        if (zhan[ws][top[ws] - 1] > zhan[wd][top[wd] - 1]&& zhan[wd][top[wd] - 1]!=0)
        {
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "����ѹС��";
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
        //�ָ�ȱʡ��ɫ
        cct_setcolor();
        //�ָ����
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        cct_gotoxy(rowbase_X, rowbase_Y + 10);
        cout << "��" << setw(4) << ++step << " ��";
        cct_gotoxy(rowbase_X + 18, rowbase_Y + 10);
        printABC();
        image(9);
        //�ָ�ȱʡ��ɫ

        if (top[wd] == n)
        {
            cct_gotoxy(rowbase_X, rowbase_Y + 10 + 2);
            cout << "��Ϸʤ��,�����ð�������";
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
        //�ָ����
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        cct_gotoxy(rowbase_X+59, rowbase_Y + 10 + 1);
        cout << "                    ";
        cct_gotoxy(rowbase_X + 59, rowbase_Y + 10 + 1);
    }

    //�ָ�ȱʡ��ɫ
    cct_setcolor();
    //�ָ����
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