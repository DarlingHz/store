#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

#define MAX 200

typedef struct Goods{
	int type;			//��Ʒ���� 
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
		int adm=login();			//��¼			
	
		int cho=1;
		while(cho)			//�û�����0��ʱ���˳����� 
		{
			title();
			if(adm) admin();	//����Ա��������˵� 
			
			cho=menu();		//�򿪲����˵� 

		}
	}
	return 0;
}
