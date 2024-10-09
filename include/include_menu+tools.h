/* 2350218 �ƿ� �¼��� */
#pragma once
#define Size_max 10
#define DOWN 1
#define LEFT 2

/* ����POP�Ͳ˵�����Ҫ�Ľṹ�� */
struct PopMenu {
	const char* title;	//����
	int start_x;	//���Ͻ�x����
	int start_y;	//���Ͻ�y����
	int width;		//�˵���ȣ��������ұ߿�+4����ʾ��ʵ����������������ż��
	int high;		//�˵��߶ȣ��������±߿�+2����ʾ��ʵ����������
	int bg_color;	//���ñ���ɫ��ע��ѡ����background/foregroundΪ���ԣ�
	int fg_color;	//����ǰ��ɫ
};

#define MAX_ITEM_LEN	80
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* para);
void end();
int tj_strcasecmp(const char* s1, const char* s2);
void input(int* row, int* col, int min,int max);
void zero_fall(int row, int col, char base[Size_max][Size_max], bool highlight[Size_max][Size_max], bool has_highlight, char type);
void frame(int row, int col, int num, int magic_number);
void ball_painting(int row, int col, char base[Size_max][Size_max], int magic_number, char type);
void hint_graph(int row, int col, char base[Size_max][Size_max], bool removable[Size_max][Size_max], char type, int number_x = 0, int number_y = 0, int color = 15);
void move_graph(int row, int col, char base[Size_max][Size_max], bool highlight[Size_max][Size_max], char type, int number_x, int number_y, int direction = DOWN);
void output_base(int row, int col, char ball_base[Size_max][Size_max], bool color, bool highlight[Size_max][Size_max], bool has_highlight, bool star1 = false);