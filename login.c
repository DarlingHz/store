#include "login.h"

//��¼ģ�� 
int login()
{
	int adm=0;
	
	FILE *user;
	if( (user=fopen(".//users.txt","r")) == NULL)		 
	{
		printf("δ��⵽�û����ݣ�");
		if( (user=fopen(".//users.txt","w")) == NULL)
		{			
			printf("�����û�����ʧ�ܣ����飡\n");
		}
		else
		{
			printf("���Զ�Ϊ����ʼ���û����ݣ�\n"); 
		}
	}
	fclose(user);
	
	if((user=fopen(".//users.txt","a+"))!=NULL)
	{
		char ch=getc(user);
		rewind(user);
		//���û����� 
		if(ch==EOF)
		{
			
			puts("δ��⵽�����û����Զ�Ϊ����������Ա�˻���");
			USER new; 
			
			puts("�����������û�����");
			gets(new.name);
			
			puts("�������������룺��������16���ַ���");
			password(new.pwd);
			
			fclose(user);
			user=fopen(".//users.txt","w");
			fprintf(user,"1 %s %s\n",new.name,new.pwd);
		}
	}
	fclose(user);
		//�������û� 
	user=fopen(".//users.txt","a+");
			do
			{					
				puts("���¼ϵͳ��");
				USER_N *find;
				read_user(&find,user);
				
				USER_N *temp=find;
				while(temp!=NULL)
				{
					printf("%d %s %s\n",temp->user.adm,temp->user.name,temp->user.pwd);
					temp=temp->node;
				}
			 
				USER tmp;
				puts("�����������˺ţ�");
				gets(tmp.name);
				puts("�������������룺");
				password(tmp.pwd);
			
				adm=compare_user(tmp.name,tmp.pwd,find);
			}while(adm==0);

	putchar('\n');
	
	return adm;
}

//�������� 
void password(char *pwd)
{
	int i=0;		//�������� 
	do
	{
	    pwd[i]=getch();
		if(pwd[i]=='\b')
	    {
	       if(i==0)
	        {
	            continue;
	        }
	        pwd[i]='\0';
	        i=i-1;
	        printf("\b");
		}
	    else if(pwd[i]==' '||pwd[i]=='\r')
	    {
			continue;
		}
		else
	    {
            printf("*");
	    }
	}while(pwd[i++]!='\r' && i<16);			//Ϊʲô��windows��cmd�»س�����\r��T_T 
	pwd[i]='\0';
	putchar('\n');
}

//��ȡ�û�����û������� 

void read_user(USER_N **find,FILE *fp)
{
	USER_N *head=NULL;
	USER_N *previous,*current;
	while(!feof(fp))
	{
		current=(USER_N*)malloc(sizeof(USER_N));
		if(head==NULL)
		{
			head=current;
		}
		else
		{
			previous->node=current;
		}
		fscanf(fp,"%d %s %s",&current->user.adm,current->user.name,current->user.pwd);
		current->node=NULL;
		previous=current;
	}
	*find=head;
}

//Ѱ���ض����û� 
int compare_user(char *name,char *pwd, USER_N *target)
{
	USER_N *current;
	current=target;
	
	int p=1;			//�жϱ��� 
	while(current!=NULL)
	{
		int cmp_n=strcmp(name,current->user.name);			//�ȶ��û��� 
		if(cmp_n==0)
		{
			int cmp_p=strcmp(pwd,current->user.pwd);		//�ȶ����� 
			if(cmp_p!=0)
			{
				puts("�������");
				p=0; 
				break;
			}
			else
			{
				p=current->user.adm;		//��ȡ�û��ķ���Ȩ�� 
				break;
			}
		}
		else if(current->node==NULL)
		{
			puts("�Ҳ����û���");
			p=0; 
		}
		current=current->node;
	}
	return p;
} 
