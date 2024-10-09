/* 计科 2350218 陈佳怡 */
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

        cout << "按回车键进行寻找初始可消除项的操作..." << endl;
        while (_getch() != '\r')
            ;
        bool highlight[Size_max][Size_max] = { 0 };
        bool has_highlight = false;
        has_highlight = find_highlight(row, col, base, highlight);//有没有高光
        if(has_highlight)
            cout << "初始可消除项(不同色标识)" << endl;
        output_base(row, col, base, 1, highlight, has_highlight);//如果有，打印；如果没有，return
        if (!has_highlight)
            return;
        zero_fall(row, col, base, highlight, has_highlight,'b');
        cout << "按回车键进行新值填充..." << endl;
        while (_getch() != '\r')
            ;
        cout << "新值填充后的数组(不同色标识):" << endl;
        //用随机数填充顶部的0
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

bool find_highlight(int row, int col, char ball_base[Size_max][Size_max], bool highlight[Size_max][Size_max])//初始找一下就可
{
    bool has_highlight = false;
    //横向
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

    //纵向
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
            //以位置为中心，上下左右四个中有三个同色，则单方向可互换
            if (i < row - 1 && j > 0 && j < col - 1 && base[i + 1][j] == base[i][j - 1] && base[i + 1][j] == base[i][j + 1])
                removable[i][j] = removable[i + 1][j] = 1;
            if (i < row - 1 && i > 0 && j < col - 1 && base[i + 1][j] == base[i - 1][j] && base[i + 1][j] == base[i][j + 1])
                removable[i][j] = removable[i][j + 1] = 1;
            if (i > 0 && j > 0 && j < col - 1 && base[i - 1][j] == base[i][j - 1] && base[i - 1][j] == base[i][j + 1])
                removable[i][j] = removable[i - 1][j] = 1;
            if (i < row - 1 && i > 0 && j > 0 && base[i + 1][j] == base[i - 1][j] && base[i + 1][j] == base[i][j - 1])
                removable[i][j] = removable[i][j - 1] = 1;
            //以位置为中心，某方向有两个同色，其它三个方向中有一个与之同色
            if (i > 0)//保证上方一个
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

    for (int i = 0; i < row; i++) //初始填充
        for (int j = 0; j < col; j++)
            base[i][j] = char(rand() % 9 + '1');

    cout << endl;
    cout << "初始数组：" << endl;
    output_base(row, col, base, 0, 0, false);//还没打高光
    cout << "按回车键进行寻找初始可消除项的操作..." << endl;
    while (_getch() != '\r')
        ;

    bool highlight[Size_max][Size_max] = { 0 };//准备打
    bool has_highlight = false;
    has_highlight = find_highlight(row, col, base, highlight);//是否有高光
    output_base(row, col, base, 1, highlight, has_highlight);
    end();
}

void magic_2()
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
    output_base(row, col, base, 0, 0, false);
    fall(row, col, base);//因为要重复找，所以不用output_base这个函数了
    end();
}

void magic_3()
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
    output_base(row, col, base, 0, 0, false);
    fall(row, col, base);//因为要重复找，所以不用output_base这个函数了
    bool removable[Size_max][Size_max] = { 0 };
    cout << "可选择的消除提示(不同色标识):" << endl;
    hint(row, col, base,removable);
    output_base(row, col, base, 1, removable, 1);
    end();
}
