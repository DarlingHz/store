#include <stdio.h>

void n_read(int n,int *sc) {
	printf("������һ��������%dλ������\n",n);
	scanf("%d",sc);/*����һ������*/
	int n1=0;/*n1Ϊʵ��λ��*/
	while(*sc!=0) {
		*sc=*sc%10;
		n1++;
		if(n1>n) {
			printf("λ������%dλ������������\n",n);
			scanf("%d",sc);
			n1=0;
		}
	}
}

void s_read(int n,char a[]) {
	printf("�����볤�Ȳ�����%dλ���ַ���\n",n);
	for(int i=0; i<n; i++) {
		scanf("%c",&a[i]);
		i++;
		if(i==n||i>n) {
			printf("λ������%dλ������������\n",n);
			i=0;
		}
	}

}

void d_read(int n,float *sc) {
	printf("������һ���������ֲ�����%dλ�ĸ�����\n",n);
	scanf("%f",sc);
	int sc1=(int)*sc;/*��ȡ�����������������*/
	int n1=0;/*n1Ϊʵ��λ��*/
	while(sc1!=0) {
		sc1=sc1%10;
		n1++;
		if(n1>n) {
			printf("����λ������%dλ������������\n",n);
			scanf("%f",sc);
			n1=0;
		}
	}

}
