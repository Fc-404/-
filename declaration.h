#pragma once
//�Ʒ����ͣ�
constexpr auto t_s = 1;
constexpr auto t_l = 2;
constexpr auto p_s = 3;
constexpr auto p_b = 4;
constexpr auto p_l = 5;
//ȫ�ֱ�����������
extern short map[48][48];//��Ϸ��ͼ����
extern short key, last_key;//����������Ϣ��
void egg();
void P(short = 0);//������
void V(short = 0);//����;
short state(short, short, short type = -1);
short draw(short x, short y, short f_color = 112, short c = 48);//���ƺ�����
short message(const char* ch, short color = 122, short delayed = 0, bool clear = 0);//��Ϣ��ʾ��
void tank_start();//̹�˴�ս��������
void plane_start();//�վ��ߺ���������
short scoring(short type, short score);//�Ʒֺ�����
void game_over();//��Ϸ����������

//����ṹ�壬���ڴ洢���������ꣻ
typedef struct coordinates{
	short X;
	short Y;
	short extend;//ǽ�������ʾ�����е�x����/�ӵ����䷽��
	coordinates* next;
}coordinates;