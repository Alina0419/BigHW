/* 2350218 计科 陈佳怡 */
#pragma once
#define Size_max 10
#define DOWN 1
#define LEFT 2

/* 定义POP型菜单所需要的结构体 */
struct PopMenu {
	const char* title;	//标题
	int start_x;	//左上角x坐标
	int start_y;	//左上角y坐标
	int width;		//菜单宽度，不含左右边框（+4是显示的实际列数），必须是偶数
	int high;		//菜单高度，不含上下边框（+2是显示的实际行数），
	int bg_color;	//所用背景色（注：选中项background/foreground为反显）
	int fg_color;	//所用前景色
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