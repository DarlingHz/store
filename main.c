#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

#define MAX 200

typedef struct Goods{
	char type[MAX];		//��Ʒ���� 
	char name[MAX];		//��Ʒ���� 
	int num;			//��Ʒ�������� 
	double price;		//��Ʒ�۸�
	int time;			//����ʱ��
	int sold;			//��Ʒ���� 
}GOO;
//��Ʒ�ṹ�� 

typedef struct Goods_Node{
	GOO goods;			//��Ʒ�ṹ������ 
	struct Goods_Node *node;	//�ṹ��ָ�� 
}GOO_N;
//��Ʒ������ṹ�� 

typedef struct Customer{
	char name[MAX];		//�˿����� 
	int star;			//�˿��Ǽ� 
	double cost;		//���Ѷ� 
}CUS;
//�˿���Ϣ�ṹ�� 

typedef struct Customer_Node{
	CUS customer;		//�˿ͽṹ������ 
	struct Customer_Node *node;//�ṹ��ָ�� 
}CUS_N;
//�˿���Ϣ������ṹ�� 

int main(void) {
	
	FILE *user;
	if(user=fopen(".//users.txt","r")==NULL)		//���û���Ϣ�����ļ� 
		printf("��ʼ���������飡");
	else
	{
//		login();			//��¼
	
		int cho=1;
		while(cho)			//�û�����0��ʱ���˳����� 
		{
			cho=menu();		//�򿪲����˵� 
/*			switch(cho)
			{
				case 1:goods_in();break;
				case 2:add_cus();break;
				case 3:sell();break;
				default:break;
			}
*/
		}
	}
	system("pause");
	return 0;
}
