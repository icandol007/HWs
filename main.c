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
		printf("1. ���    2. ��ü�˻�    3. Ư���ΰ˻�    4. ����\n");
    	scanf("%d", &input);

        if (input == 1){
            printf("��й�ȣ: ");
            scanf("%s", code);
            if (!strcmp(code, password)){
                reg_addr(user, &person);
            }
            else {
                while (1){
                    printf("��й�ȣ(%dȸ����): ", i+1);
                    scanf("%s", code);
                    if (!strcmp(code, password)){
                        i = 0;
                        reg_addr(user, &person);
                        break;
                    }
                    else
                        i++;
                        if (i == 2) {
                            printf("��й�ȣ(%dȸ����): ", i+1);
                            printf("����� �� ����!\n���α׷��� �����մϴ�.");
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
            printf("���α׷��� �����մϴ�.");
            return 0;
        }
        else
            printf("�߸��� �Է��Դϴ�\n");
    }
    return 0;
}

/*void reg_addr(User* ptr, int* num){
    printf("����� �̸�: ");
    scanf("%s", ptr[*num].name);
    printf("��ȭ��ȣ: ");
    scanf("%s", ptr[*num].number);
	(*num)++;

    printf("%s ���� ��� �Ϸ�!\n", ptr[*num-1].name);
}

int personalp(User* ptr, int* num){
    char name[30];
    int i;

    if (*num > 0){
    	printf("�˻��� �̸�: ");
        scanf("%s", name);

        for (i = 0; i < 50; i++){
            if (!strcmp(name, ptr[i].name)) {
				printf(" %s ", ptr[i].name);
                printf("\t %s \n", ptr[i].number);

                return 0;
               }
          }
          printf("����\n");

          return 0;
	}
}

void printAll(User* ptr, int* num){
    printf("  << ��ȭ��ȣ��� >> \n");
    int i = 0;
    if (*num > 0){
        for (i = 0; i < *num; i++){
            printf(" %s ", ptr[i].name);
            printf("\t %s \n", ptr[i].number);
    	}
	}
}*/
