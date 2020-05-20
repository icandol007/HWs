#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    char number[30];
}User;

const char password[9] = "qwer1234";

extern void reg_addr(User* ptr, int* num);
extern int personalp(User* ptr, int* num);
extern void printAll(User* ptr, int* num);

int main(void){
    int input;
    User user[50];
    int person = 0;
    int i = 0;
    char code[50];

    while (1){
		printf("1. 등록    2. 전체검색    3. 특정인검색    4. 종료\n");
    	scanf("%d", &input);

        if (input == 1){
            printf("비밀번호: ");
            scanf("%s", code);
            if (!strcmp(code, password)){
                reg_addr(user, &person);
            }
            else {
                while (1){
                    printf("비밀번호(%d회실패): ", i+1);
                    scanf("%s", code);
                    if (!strcmp(code, password)){
                        i = 0;
                        reg_addr(user, &person);
                        break;
                    }
                    else
                        i++;
                        if (i == 2) {
                            printf("비밀번호(%d회실패): ", i+1);
                            printf("등록할 수 없음!\n프로그램을 종료합니다.");
                            exit(1);
                        }
                }
            }
        }
        else if (input == 2){
            printAll(user, &person);
        }
        else if (input == 3){
            personalp(user, &person);
        }
        else if (input == 4){
            printf("프로그램을 종료합니다.");
            return 0;
        }
        else
            printf("잘못된 입력입니다\n");
    }
    return 0;
}

/*void reg_addr(User* ptr, int* num){
    printf("등록할 이름: ");
    scanf("%s", ptr[*num].name);
    printf("전화번호: ");
    scanf("%s", ptr[*num].number);
	(*num)++;

    printf("%s 정보 등록 완료!\n", ptr[*num-1].name);
}

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

void printAll(User* ptr, int* num){
    printf("  << 전화번호목록 >> \n");
    int i = 0;
    if (*num > 0){
        for (i = 0; i < *num; i++){
            printf(" %s ", ptr[i].name);
            printf("\t %s \n", ptr[i].number);
    	}
	}
}*/
