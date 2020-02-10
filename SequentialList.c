#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100
#define BOOL int //�궨�岼������
#define TRUE 1
#define FALSE 0

typedef struct
{
	int data[MAXSIZE];
	int length;
}Sqlist;


/****************************** ���� *********************************/

//��ʼ��������
Sqlist init_List() {
	Sqlist list;
	list.length = 0;
	list.data[list.length] = NULL;
	return list;
}
//����˳������
Sqlist List_create() 
{
	int i=0;
	int temp_data;
	Sqlist List;
	printf("input data:\n");
	while (scanf_s("%d",&temp_data)==1)
	{	
		if (i > MAXSIZE ) {
			printf("List Full\n");
			break;
		}
		List.data[i] = temp_data;
		i++;
		List.length=i;
	}
	return List;
}

//����λ��ɾ��˳���Ԫ��
Sqlist delete_place(Sqlist List,int place){
	//λ�úϷ��Լ��
	if (place > List.length) {
		printf("place error!!!!\n");
		return List;
	}
	else if(place<0)
	{
		printf("wrong place!\n");
	}

	for (int i = place; i < List.length; i++)
	{
		List.data[i-1] = List.data[i];
	}

	List.length=List.length-1;
	return List;
}

//����Ԫ��ɾ��˳���Ԫ��
Sqlist delete_element(Sqlist List, int element){
	int count = 0;
	for (int i = 0; i < List.length; i++)
	{
		if (List.data[i] == element) {
			List=delete_place(List, i+1);
			count++;
		}
	}
	if (count == 0)
	{
		printf("Dont have this element!\n");
	}
	return List;
}
//��������Ԫ��
Sqlist add_place(Sqlist List,int place,int element) {
	//λ�úϷ��Լ��
	if (List.length == MAXSIZE) {
		printf("List Full!\n");
	}
	else if (place < 0) {
		printf("wrong place!\n");
	}
	//����ƶ�λ��
	for (int i = List.length; i >= place; i--)
	{
		List.data[i] = List.data[i-1];
	}
	//����Ԫ��
	List.data[place-1] = element;

	List.length++;
	return List;
}

//��ӡ����
void print_list(Sqlist List) {
	printf("List:\n");
	for (int i = 0; i < List.length; i++)
	{
		printf("%d ", List.data[i]);
		
	}
	printf("\n");
}

//����ɾ��
void delete_all() {}

//����
void print_window() {
	printf("*********************************\n");
	printf("**        A.��������           **\n");
	printf("**        B.����Ԫ��           **\n");
	printf("**        C.ɾ��Ԫ��           **\n");
	printf("**        D.��ӡ����           **\n");
	printf("*********************************\n");
	printf("********Enter your code**********:\n");
}

/**************************  main() **********************************/
/*int main()
{
	Sqlist List=init_List();      //List����
	char code;
	int place;
	int element;
	char state='E';
	printf("*********************************\n");
	printf("**          S.Start            **\n");
	printf("**          E.Exit             **\n");
	printf("*********************************:\n");
	scanf_s("%c", &state);
	print_window();
	while (state=='S')
	{
		scanf_s("%c", &code);
		switch (code)
		{
		case 'A': {
			List = List_create();
			print_window();
			break;
		}

		case 'B': {
			printf("*********************************\n");
			printf("**        Enter place          **\n");
			printf("**        Enter element        **\n");
			printf("*********************************:\n");

			scanf_s("%d", &place);
			scanf_s("%d", &element);
			List = add_place(List, place, element);
			print_window();
			break;
		}
		case 'C': {
			int code1;
			printf("*********************************\n");
			printf("**      1.Delete with place    **\n");
			printf("**      2.Delete with element  **\n");
			printf("*********************************:\n");
			scanf_s("%d", &code1);
			switch (code1)
			{
			case 1: {
				printf("*********************************\n");
				printf("**        Enter place          **\n");
				printf("*********************************:\n");
				scanf_s("%d", &place);
				List = delete_place(List, place);
				print_window();
				break;
			}
			case 2: {
				printf("*********************************\n");
				printf("**        Enter element        **\n");
				printf("*********************************:\n");
				scanf_s("%d", &element);
				List = delete_element(List, element);
				print_window();  
				break;
			}
			default:
				break;
			}
		    print_window();
		    break;
		}
		case 'D':
			print_list(List);
			print_window();
			break;
		default:
			break;
		}
	}
	
	return 0;
}