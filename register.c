#include <stdio.h>

typedef struct{
    char name[30];
    char number[30];
}User;

void reg_addr(User* ptr, int* num){
    printf("����� �̸�: ");
    scanf("%s", ptr[*num].name);
    printf("��ȭ��ȣ: ");
    scanf("%s", ptr[*num].number);
	(*num)++;

    printf("%s ���� ��� �Ϸ�!\n", ptr[*num-1].name);
}
