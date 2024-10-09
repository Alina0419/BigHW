/* �ƿ� 2350218 �¼��� */
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

void fall(int row, int col, char base[Size_max][Size_max])
{

    while (1)
    {

        cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���..." << endl;
        while (_getch() != '\r')
            ;
        bool highlight[Size_max][Size_max] = { 0 };
        bool has_highlight = false;
        has_highlight = find_highlight(row, col, base, highlight);//��û�и߹�
        if(has_highlight)
            cout << "��ʼ��������(��ͬɫ��ʶ)" << endl;
        output_base(row, col, base, 1, highlight, has_highlight);//����У���ӡ�����û�У�return
        if (!has_highlight)
            return;
        zero_fall(row, col, base, highlight, has_highlight,'b');
        cout << "���س���������ֵ���..." << endl;
        while (_getch() != '\r')
            ;
        cout << "��ֵ���������(��ͬɫ��ʶ):" << endl;
        //���������䶥����0
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row; i++)
            {
                if (base[i][j] == '0')
                {
                    base[i][j] = char(rand() % 9 + '1');
                }
            }
        }

        output_base(row, col, base,1, highlight, has_highlight);
        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row; i++)
            {
                if (base[i][j] == '0')
                {
                    highlight[i][j] = false;
                }
            }
        }
    }
}

bool find_highlight(int row, int col, char ball_base[Size_max][Size_max], bool highlight[Size_max][Size_max])//��ʼ��һ�¾Ϳ�
{
    bool has_highlight = false;
    //����
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col - 2; j++) {
            if (ball_base[i][j] == ball_base[i][j + 1] && ball_base[i][j] == ball_base[i][j + 2])
            {
                highlight[i][j] = highlight[i][j + 1] = highlight[i][j + 2] = true;
                has_highlight = true;
                int k = j + 3;
                while (k < col && ball_base[i][k] == ball_base[i][j])
                {
                    highlight[i][k] = true;
                    k++;
                }
                j = k - 1;
            }
        }
    }

    //����
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row - 2; i++) {
            if (ball_base[i][j] == ball_base[i + 1][j] && ball_base[i][j] == ball_base[i + 2][j])
            {
                highlight[i][j] = highlight[i + 1][j] = highlight[i + 2][j] = true;
                has_highlight = true;
                int k = i + 3;
                while (k < row && ball_base[k][j] == ball_base[i][j])
                {
                    highlight[k][j] = true;
                    k++;
                }
                i = k - 1;
            }
        }
    }
    return has_highlight;
}

void hint(int row, int col, char base[Size_max][Size_max], bool removable[Size_max][Size_max])
{
    for (int i = 0;i < row;i++)
    {
        for (int j = 0;j < col;j++)
        {
            //��λ��Ϊ���ģ����������ĸ���������ͬɫ���򵥷���ɻ���
            if (i < row - 1 && j > 0 && j < col - 1 && base[i + 1][j] == base[i][j - 1] && base[i + 1][j] == base[i][j + 1])
                removable[i][j] = removable[i + 1][j] = 1;
            if (i < row - 1 && i > 0 && j < col - 1 && base[i + 1][j] == base[i - 1][j] && base[i + 1][j] == base[i][j + 1])
                removable[i][j] = removable[i][j + 1] = 1;
            if (i > 0 && j > 0 && j < col - 1 && base[i - 1][j] == base[i][j - 1] && base[i - 1][j] == base[i][j + 1])
                removable[i][j] = removable[i - 1][j] = 1;
            if (i < row - 1 && i > 0 && j > 0 && base[i + 1][j] == base[i - 1][j] && base[i + 1][j] == base[i][j - 1])
                removable[i][j] = removable[i][j - 1] = 1;
            //��λ��Ϊ���ģ�ĳ����������ͬɫ������������������һ����֮ͬɫ
            if (i > 0)//��֤�Ϸ�һ��
            {
                char a = base[i - 1][j];
                if ((j > 1 && a == base[i][j - 1] && a == base[i][j - 2]) ||
                    (i < row - 2 && a == base[i + 1][j] && a == base[i + 2][j]) ||
                    (j < col - 2 && a == base[i][j + 1] && a == base[i][j + 2]))
                    removable[i][j] = removable[i - 1][j] = 1;
            }
            if (i < row - 1)
            {
                char a = base[i + 1][j];
                if ((j > 1 && a == base[i][j - 1] && a == base[i][j - 2]) ||
                    (i > 1 && a == base[i - 1][j] && a == base[i - 2][j]) ||
                    (j < col - 2 && a == base[i][j + 1] && a == base[i][j + 2]))
                    removable[i][j] = removable[i + 1][j] = 1;
            }
            if (j > 0)
            {
                const char a = base[i][j - 1];
                if ((i > 1 && a == base[i - 1][j] && a == base[i - 2][j]) ||
                    (i < row - 2 && a == base[i + 1][j] && a == base[i + 2][j]) ||
                    (j < col - 2 && a == base[i][j + 1] && a == base[i][j + 2]))
                    removable[i][j] = removable[i][j - 1] = 1;
            }
            if (j < col - 1)
            {
                char a = base[i][j + 1];
                if ((i > 1 && a == base[i - 1][j] && a == base[i - 2][j]) ||
                    (i < row - 2 && a == base[i + 1][j] && a == base[i + 2][j]) ||
                    (j > 1 && a == base[i][j - 1] && a == base[i][j - 2]))
                    removable[i][j] = removable[i][j + 1] = 1;
            }

        }
    }
}

void magic_1()
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
    output_base(row, col, base, 0, 0, false);//��û��߹�
    cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���..." << endl;
    while (_getch() != '\r')
        ;

    bool highlight[Size_max][Size_max] = { 0 };//׼����
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//�Ƿ��и߹�
    output_base(row, col, base, 1, highlight, has_highlight);
    end();
}

void magic_2()
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
    output_base(row, col, base, 0, 0, false);
    fall(row, col, base);//��ΪҪ�ظ��ң����Բ���output_base���������
    end();
}

void magic_3()
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
    output_base(row, col, base, 0, 0, false);
    fall(row, col, base);//��ΪҪ�ظ��ң����Բ���output_base���������
    bool removable[Size_max][Size_max] = { 0 };
    cout << "��ѡ���������ʾ(��ͬɫ��ʶ):" << endl;
    hint(row, col, base,removable);
    output_base(row, col, base, 1, removable, 1);
    end();
}
