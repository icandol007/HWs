#include <stdio.h>

typedef struct{
    char name[30];
    char number[30];
}User;

void printAll(User* ptr, int* num){
    printf("  << 전화번호목록 >> \n");
    int i = 0;
    if (*num > 0){
        for (i = 0; i < *num; i++){
            printf(" %s ", ptr[i].name);
            printf("\t %s \n", ptr[i].number);
    	}
	}
}
