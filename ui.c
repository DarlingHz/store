//չʾ���ֽ��� 
#include <string.h>
#include "ui.h"

void title(void)
{
	puts("********************************");
	puts("*                              *");
	puts("*     С����Ʒ��Ϣ����ϵͳ     *");
	puts("*                              *");
	puts("********************************");
	putchar('\n');
}

void admin(void)
{
	puts("********************************");
	puts("*        ����Ա�����˵�        *");
	puts("*        11) ¼�������        *");
	puts("*        12) �Ǽ��ͻ�����      *");
	puts("*        13) ���ݹ���          *");
}

int menu(void)
{
	puts("********************************");
	puts("*        1) �ۻ�ģʽ           *");
	puts("*        2) ����               *");
	puts("*        0) �˳�����           *");
	puts("********************************");
	putchar('\n');
	puts("��������еĲ�����ţ�"); 
	int cus;
	scanf("%d",&cus);
	return cus;
}

int login(void)		//��ûд�� 
{
	int p;
	p=1;
	return p;
}

void goods_in(void){
	
}
