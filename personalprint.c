#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    char number[30];
}User;

int personalp(User* ptr, int* num){
    char name[30];
    int i;

    if (*num > 0){
    	printf("검색할 이름: ");
        scanf("%s", name);

        for (i = 0; i < 50; i++){
            if (!strcmp(name, ptr[i].name)) {
				printf(" %s ", ptr[i].name);
                printf("\t %s \n", ptr[i].number);

                return 0;
               }
          }
          printf("없음\n");

          return 0;
	}
}
