#include"file.h"
#include<stdio.h>
int main()
{
	char c;
	CreatFile();
	printf("����Ҫע�ỹ�ǵ�½:\nע��������1\n��½������2\nԤ�������û���3\n�˳�0\n���4\n\n");
	while ((c = getchar()) != '0')
	{
		if (c == '1') Register();
		if (c == '2') Login();
		if (c == '3') PrintAllID();
		if (c == '4')
		{
			if (!ClearFile())
			{
				printf("���ʧ��\n\n");
				break;
			}
		}
	}
	system("pause");
	return 0;
}
