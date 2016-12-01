#include"AddressBook.h"


void menu()
{
	printf("###########################\n");
	printf("#1.add############2.delete#\n");
	printf("#3.find###########4.modiyf#\n");
	printf("#5.print###########6.clear#\n");
	printf("#7.sort###########0.quit##\n");
	printf("###########################\n");

}





void add_peo(Pseqlist message)
{
	assert(message);
	if (message->count > MAX_PEOPLES)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("������>");
	scanf("%s",message->per_mesg[message->count].name);
	printf("����:>");
	scanf("%d",&message->per_mesg[message->count].age);
	printf("�Ա�>");
	scanf("%s",message->per_mesg[message->count].sex);
	printf("�绰��>");
	scanf("%s",message->per_mesg[message->count].telephone);
	printf("��ַ��>");
	scanf("%s",message->per_mesg[message->count].address);
	
	message->count++;

}

void print_people_message(Pseqlist message)
{
	assert(message);
	for (int i = 0; i < message->count; i++)
	{
		printf("name : %s  ",message->per_mesg[i].name );
		printf("age : %d  ",message->per_mesg[i].age );
		printf("sex : %s  ",message->per_mesg[i].sex);
		printf("telephone : %s  ",message->per_mesg [i].telephone);
		printf("address : %s  ",message->per_mesg [i].address);
		printf("\n");
	}
}

static int find_peo(Pseqlist message,char *name)
{
	assert(message);
	assert(name);
	int i = 0;
	for (i = 0; i < message->count; i++)
	{
		if (strcmp(name,message->per_mesg[i].name ) == 0)
		{
			return i;
		}
	}
	return -1;
}




void delete_peo_message(Pseqlist message)
{
	assert(message);
	if ( message->count <= 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return ;
	}
	printf("������Ҫɾ������ϵ������:>");
	char name[10];
	scanf("%s",name);
	int ret = find_peo(message,name);
	if (ret != -1)
	{
		for (int j = ret; j < message->count; j++)
		{
			message->per_mesg[j] = message->per_mesg[j+1];
		}
		printf("ɾ���ɹ�\n");
		message->count--;
		return ;
	}
	else
	{
		printf("ͨѶ¼��û��Ҫɾ������ϵ��\n");
	}
}	

void find(Pseqlist message)
{
	assert(message);
	if ( message->count <= 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return ;
	}
	printf("��������Ҫ������ϵ�˵�����:>");
	char name[10];
	scanf("%s",name);
	int ret = find_peo(message,name);
	if (ret != -1)
	{
		printf("name : %s age: %d sex : %s telephone : %s address %s\n",\
				message->per_mesg[ret].name,message->per_mesg[ret].age,message->per_mesg[ret].sex,\
				message->per_mesg[ret].telephone,message->per_mesg[ret].address);
	}	
	else
	{
		printf("û���ҵ�����ϵ��\n");
	}
}

void modify(Pseqlist message)
{
	assert(message);
	if ( message->count <= 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return ;
	}
	printf("������Ҫ�޸���ϵ�˵�����:>");
	char name[10];
	scanf("%s",name);
	int ret = find_peo(message,name);
	if (ret != -1)
	{
		printf("������Ҫ�޸ĺ�����֣�>");
		scanf("%s",message->per_mesg[ret].name);

		printf("�������޸ĺ�����䣺>");
		scanf("%d",&message->per_mesg[ret].age);
		
		printf("�������޸ĺ���Ա�>");
		scanf("%s",message->per_mesg[ret].sex);
		
		printf("�������޸ĺ�ĵ绰��>");
		scanf("%s",message->per_mesg[ret].telephone);
		
		printf("������Ҫ�޸ĺ�ĵ�ַ:>");
		scanf("%s",message->per_mesg[ret].address);
		printf("�޸ĳɹ���\n");

	}
	else
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
	}
}

void clearall(Pseqlist message)
{
	assert(message);
	memset(message->per_mesg,0,sizeof(message->per_mesg));
}


void sort(Pseqlist message)
{
	//ð������
	assert(message);
	if ( message->count <= 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return ;
	}
	for (int i = 0; i < message->count-1; i++)
	{
		int flag = 1;
		for (int j = 0; j < message->count-1-i; j++)
		{
			if (strcmp(message->per_mesg[j].name,message->per_mesg[j+1].name) > 0)
			{
				flag  = 0;
				People_t tmp = message->per_mesg[j];
				message->per_mesg[j] = message->per_mesg[j+1];
				message->per_mesg[j+1] =tmp;
			}
		}
		if (flag)
		{
			break;
		}
	}
}