#include "login.h"

//��¼ģ�� 
int login()
{
	int adm;
	
	FILE *user;
	if(user=fopen(".//users.txt","r")==NULL)		 
	{
			printf("δ��⵽�û����ݣ�");
		if(user=fopen(".//users.txt","w")==NULL)
		{			
			printf("�����û�����ʧ�ܣ����飡\n");
		}
		else
		{
			printf("���Զ�Ϊ����ʼ���û����ݣ�\n"); 
		}
	}
	else
	{
		char ch=getc(user);
		USER new;
		if(ch==EOF)
		{
			puts("δ��⵽�����û����Զ�Ϊ����������Ա�˻���");
			puts("�����������û�����");
			gets(new.name);
			puts("�������������룺��������16���ַ���");
			int i=0;		//�������� 
			do
			{
			    new.pwd[i]=getch();
				if(new.pwd[i]=='\b')
			    {
			        if(i==0)
			        {
			            continue;
			        }
			        i=i-1;
			        printf("\b");
				}
			    else
			    {
		            printf("*");
		        }
			}while(new.pwd[i++]!='\r' && new.pwd[i]!='\n' && i<16);			//Ϊʲô��windows��cmd�»س�����\r��T_T 
			fclose(user);
			user=fopen(".//users.txt","w");
			fprintf(user,"1 %s %s\n",new.name,new.pwd);
			fclose(user);
		}
		else
		{
			;
		}	
	}

	putchar('\n');
	adm=1;
	return adm;
}
