#include"file.h"

typedef struct user
{
	char ID[20] = "";
	char PWD[20] = "";
}USER;

void PutPwd(char* p)
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		p[i] = _getch();
		while (true)
		{
			if (p[i] == '\b'&&i >= 0)
			{
				printf("\b \b");
				if (i != 0) i--;
				p[i] = _getch();

			}
			else break;
		}
		if (p[i] == '\r'&&i >= 0) break;
		else
		{
			if (i >= 0) printf("*");
		}
	}
	p[i] = '\0';
	printf("\n");
}

void CreatFile()
{
	FILE* fp;
	if((fp = fopen("user.txt","rb"))==NULL)
	{
		if((fp = fopen("user.txt","wb"))==NULL)
		{
			printf("���ļ�ʧ��\n\n");
		}
	}
}

int Register()
{
	USER a,b;
	FILE* fp;
	char again[20];
	lable1:
	printf("�����������˺�:\n\n");
	scanf("%s",a.ID);
	fp = fopen("user.txt","r");
	fread(&b,sizeof(USER),1,fp);
	while(true)
	{
		if(strcmp(b.ID,a.ID))                            //������߲���� 
		{	
			if(!feof(fp)) fread(&b,sizeof(USER),1,fp);
			else break;   //���δ��ĩβ������� 
		}
		else
		{
			printf("���û����Ѵ���\n����������\n\n");
			fclose(fp);
			goto lable1;
		}
	}
	lable2:
	printf("����������:\n\n");
	PutPwd(a.PWD);
	printf("����������������:\n\n");
	PutPwd(again);
	if(strcmp(a.PWD,again)) 
	{
		printf("���벻һ�£�����������\n\n");
		goto lable2;
	}
	else 
	{
		fclose(fp);
		fp = fopen("user.txt","a");
		fwrite(&a,sizeof(USER),1,fp);
		fclose(fp);
		printf("�û�%sע��ɹ�o(*������*)o\n\n",a.ID);
	}
	return true;
}

int Login()
{
	USER a,b;
	FILE* fp;
	lable1:
	fp = fopen("user.txt","r");
	printf("�������û���:\n\n");
	scanf("%s",a.ID);
	fread(&b,sizeof(USER),1,fp);
	while(true)
	{
		if(strcmp(a.ID,b.ID)==0) break;
		else
		{
			if(!feof(fp)) fread(&b,sizeof(USER),1,fp);
			else 
			{
				printf("�û�������������������\n\n");
				fclose(fp);
				goto lable1;
			}
		}
	}
	lable2:
	printf("���������룺\n\n");
	PutPwd(a.PWD);
	if(strcmp(a.PWD,b.PWD)==0)
	{
		printf("��½�ɹ�O(��_��)O\n\n");
		fclose(fp);
		return true;
	}
	else
	{
		printf("�����������\n����������\n\n");
		goto lable2;
	}
}

void PrintAllID()
{
	FILE* fp = fopen("user.txt","r");
	USER a;
	fread(&a,sizeof(USER),1,fp);
	while(!feof(fp))
	{
		printf("%s\n",a.ID);
		fread(&a,sizeof(USER),1,fp);
	}
	fclose(fp);
}

int ClearFile()
{
	FILE* fp = fopen("user.txt", "w");
	if (fp == NULL)
	{
		printf("error\n\n");
		return false;
	}
	else return true;
}

