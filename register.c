#include <stdio.h>

typedef struct{
    char name[30];
    char number[30];
}User;

void reg_addr(User* ptr, int* num){
    printf("등록할 이름: ");
    scanf("%s", ptr[*num].name);
    printf("전화번호: ");
    scanf("%s", ptr[*num].number);
	(*num)++;

    printf("%s 정보 등록 완료!\n", ptr[*num-1].name);
}
