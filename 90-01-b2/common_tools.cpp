/* �ƿ� 2350218 �¼��� */
#include<iostream>
#include"../include/cmd_console_tools.h"

using namespace std;

void input(int *row,int *col)
{
    while (1)
    {
        cout << "����������(5-9):" << endl;
        cin >> *row;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*row >= 5 && *row <= 9)
            break;
    }
    while (1)
    {
        cout << "����������(5-9):" << endl;
        cin >> *col;
        cin.clear();
        cin.ignore(65536, '\n');
        if (*col >= 5 && *col <= 9)
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