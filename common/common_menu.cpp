/* �ƿ� 2350218 �¼��� */
#include<iostream>
#include"../include/cmd_console_tools.h"
#include"../include/include_menu+tools.h"
using namespace std;

static void odd(int* number, int* odd)//д��p��û�У��ù������ҵ
{
    if (*number % 2 != 0)//len_title��֤��ż��
    {
        *odd = 1;
        (*number)++;
    }
}

static void print_2(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para, int choice, int wide_hanzi, int wide, int len_title, bool now, int weizhi)
{
    cct_setcolor(original_para->bg_color, original_para->fg_color);
    cct_gotoxy(original_para->start_x, original_para->start_y + weizhi);
    cout << "�U ";
    int len_menu = strlen(menu[choice - 1]);
    int j;
    wide_hanzi = wide;//�ֶ����±����˽㣬�������Һ���
    if (wide < len_title)
        wide_hanzi = len_title;
    int if_bufferlines = 0;
    if (now)
        cct_setcolor(original_para->fg_color, original_para->bg_color);
    for (j = 0;j < len_menu && j < wide_hanzi;)
    {
        if (!(unsigned int(unsigned char(menu[choice - 1][j])) >= 0xA1 && unsigned int(unsigned char(menu[choice - 1][j])) <= 0xFE))
        {
            cout << menu[choice - 1][j];
            j++;
        }
        else//�Ǻ���
        {
            int x, y, cols, lines, buffer_cols, buffer_lines;
            cct_getxy(x, y);
            cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
            if (x == buffer_cols - 1)
            {
                if_bufferlines = 1;
                cout << " ";
                continue;
            }
            else if (j == wide_hanzi - 1)
            {
                cout << " ";
                j++;
                break;
            }
            else
            {
                cout << menu[choice - 1][j] << menu[choice - 1][j + 1];
                j = j + 2;
            }
        }
    }
    if (if_bufferlines)
        j++;
    for (;j < wide_hanzi;j++)
        cout << " ";
    cct_setcolor(original_para->bg_color, original_para->fg_color);
    cout << "�U";
}

void print_whole_shang(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para, int choice, int wide_hanzi, int wide, int len_title)
{
    for (int i = 0;i < original_para->high;i++)
    {
        cct_setcolor(original_para->bg_color, original_para->fg_color);
        cct_showstr(original_para->start_x, original_para->start_y + i + 1, "�U");//���ﲻ��
        int len_menu = strlen(menu[i + choice - 1]);
        int j;
        wide_hanzi = wide;//�ֶ����±����˽㣬�������Һ���
        if (wide < len_title)
            wide_hanzi = len_title;
        int if_bufferlines = 0;
        if (i == 0)
        {
            cct_setcolor(original_para->fg_color, original_para->bg_color);
        }
        for (j = 0;j < len_menu && j < wide_hanzi;)
        {
            if (!(unsigned int(unsigned char(menu[i + choice - 1][j])) >= 0xA1 && unsigned int(unsigned char(menu[i + choice - 1][j])) <= 0xFE))
            {
                cout << menu[i + choice - 1][j];
                j++;
            }
            else//�Ǻ���
            {
                int x, y, cols, lines, buffer_cols, buffer_lines;
                cct_getxy(x, y);
                cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
                if (x == buffer_cols - 1)
                {
                    if_bufferlines = 1;
                    cout << " ";
                    continue;
                }
                else if (j == wide_hanzi - 1)
                {
                    cout << " ";
                    j++;
                    break;
                }
                else
                {
                    cout << menu[i + choice - 1][j] << menu[i + choice - 1][j + 1];
                    j = j + 2;
                }
            }
        }
        if (if_bufferlines)
            j++;
        for (;j < wide_hanzi;j++)
            cout << " ";
        cct_setcolor(original_para->bg_color, original_para->fg_color);
        cout << "�U ";
    }
}

void print_whole_xia(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para, int choice, int wide_hanzi, int wide, int len_title)
{
    for (int i = 0;i < original_para->high;i++)
    {
        cct_setcolor(original_para->bg_color, original_para->fg_color);
        cct_showstr(original_para->start_x, original_para->start_y + i + 1,"�U");//���´�ӡ
        int len_menu = strlen(menu[i + choice - original_para->high]);
        int j;
        wide_hanzi = wide;//�ֶ����±����˽㣬�������Һ���
        if (wide < len_title)
            wide_hanzi = len_title;
        int if_bufferlines = 0;
        if (i == original_para->high - 1)
        {
            cct_setcolor(original_para->fg_color, original_para->bg_color);
        }
        for (j = 0;j < len_menu && j < wide_hanzi;)
        {
            if (!(unsigned int(unsigned char(menu[i + choice - original_para->high][j])) >= 0xA1 && unsigned int(unsigned char(menu[i + choice - original_para->high][j])) <= 0xFE))
            {
                cout << menu[i + choice - original_para->high][j];
                j++;
            }
            else//�Ǻ���
            {
                int x, y, cols, lines, buffer_cols, buffer_lines;
                cct_getxy(x, y);
                cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
                if (x == buffer_cols - 1)
                {
                    if_bufferlines = 1;
                    cout << " ";
                    continue;
                }
                else if (j == wide_hanzi - 1)
                {
                    cout << " ";
                    j++;
                    break;
                }
                else
                {
                    cout << menu[i + choice - original_para->high][j] << menu[i + choice - original_para->high][j + 1];
                    j = j + 2;
                }
            }
        }
        if (if_bufferlines)
            j++;
        for (;j < wide_hanzi;j++)
            cout << " ";
        cct_setcolor(original_para->bg_color, original_para->fg_color);
        cout << "�U ";
    }
}

int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    cct_setcursor(CURSOR_INVISIBLE);
    cct_gotoxy(original_para->start_x, original_para->start_y);
    int len_title = strlen(original_para->title);
    int wide = original_para->width;
    int odd_title = 0, odd_width = 0, odd_menu = 0;
    odd(&len_title, &odd_title);
    odd(&wide, &odd_width);
    cct_setcolor(original_para->bg_color, original_para->fg_color);
    cout << "�X ";
    int half = (wide - len_title) / 2;
    if (half % 2 != 0)
        half--;
    for (int i = 0;i < half / 2;i++)
        cout << "�T ";
    cout << original_para->title;
    if (odd_title)
    {
        cout << " ";
    }
    for (int i = 0;i < (wide - len_title - half) / 2;i++)
        cout << "�T ";
    cout << "�[ " << endl;
    int choice = 1;//ѡ��
    int high_menu = 0;
    int wide_hanzi = 0;
    for (int i = 0;i < original_para->high && strlen(menu[i]) != 0;i++)
    {
        high_menu++;//��ӡ�ײ�����
        cct_setcolor(original_para->bg_color, original_para->fg_color);
        cct_gotoxy(original_para->start_x, original_para->start_y + i + 1);
        cout << "�U ";
        int len_menu = strlen(menu[i]);
        int j;
        wide_hanzi = wide;//�ֶ����±����˽㣬�������Һ���
        if (wide < len_title)
            wide_hanzi = len_title;
        int if_bufferlines = 0;
        if (i + 1 == choice)
        {
            cct_setcolor(original_para->fg_color, original_para->bg_color);
        }
        for (j = 0;j < len_menu && j < wide_hanzi;)
        {
            if (!(unsigned int(unsigned char(menu[i][j])) >= 0xA1 && unsigned int(unsigned char(menu[i][j])) <= 0xFE))
            {
                cout << menu[i][j];
                j++;
            }
            else//�Ǻ���
            {
                int x, y, cols, lines, buffer_cols, buffer_lines;
                cct_getxy(x, y);
                cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
                if (x == buffer_cols - 1)
                {
                    if_bufferlines = 1;
                    cout << " ";
                    continue;
                }
                else if (j == wide_hanzi - 1)
                {
                    cout << " ";
                    j++;
                    break;
                }
                else
                {
                    cout << menu[i][j] << menu[i][j + 1];
                    j = j + 2;
                }
            }
        }
        if (if_bufferlines)
            j++;
        for (;j < wide_hanzi;j++)
            cout << " ";
        cct_setcolor(original_para->bg_color, original_para->fg_color);
        cout << "�U ";
    }
    cct_gotoxy(original_para->start_x, original_para->start_y + high_menu + 1);
    cout << "�^ ";
    for (int i = 0;i < wide_hanzi;i = i + 2)
        cout << "�T ";
    cout << "�a ";
    int X, Y, maction, keycode1, keycode2, ret;
    int loop = 1;
    int weizhi = 1;
    while (loop)
    {
        /* �����/���̣�����ֵΪ���������е�ĳһ��, ��ǰ���λ����<X,Y>�� */
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT && keycode1 == '\r')
            break;
        if (ret == CCT_KEYBOARD_EVENT && keycode1 == 224)
        {
            switch (keycode2)
            {
                case KB_ARROW_UP:
                    if (choice == 1)//������
                        continue;
                    else if (choice != 1 && weizhi == 1)//���Ϲ���λ�ò��䣬choice��
                    {
                        choice--;
                        print_whole_shang(menu, original_para, choice, wide_hanzi, wide, len_title);
                    }
                    else
                    {
                        print_2(menu, original_para, choice, wide_hanzi, wide, len_title, 0, weizhi);
                        choice--;
                        weizhi--;
                        print_2(menu, original_para, choice, wide_hanzi, wide, len_title, 1, weizhi);
                    }
                    break;
                case KB_ARROW_DOWN:
                    if (strlen(menu[choice]) == 0)//������
                        continue;
                    else if (strlen(menu[choice]) != 0 && weizhi == original_para->high)//���¹�
                    {
                        choice++;
                        print_whole_xia(menu, original_para, choice, wide_hanzi, wide, len_title);
                    }
                    else
                    {
                        print_2(menu, original_para, choice, wide_hanzi, wide, len_title, 0, weizhi);
                        choice++;
                        weizhi++;
                        print_2(menu, original_para, choice, wide_hanzi, wide, len_title, 1, weizhi);
                    }
                    break;
                    break;
            }//end of swicth(keycode1)
        }//end of else if(ret == CCT_KEYBOARD_EVENT��
    } //end of while(1)
    return choice; //���践��
}
//choice == original_para->high 