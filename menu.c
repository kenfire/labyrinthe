#include<stdio.h>
#include<stdlib.h>

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

void print_menu()
{
    printf("%s*********************************************\n", CYN);
    printf("**%s1) %sCréer un labyrinthe\n", YEL,BLU);
    printf("**%s2) %sCharger un labyrinthe\n", YEL,BLU);
    printf("**%s3) %sJouer\n", YEL,BLU);
    printf("**%s4) %sQuitter\n", YEL,BLU);
    printf("%s*********************************************\n",CYN);
    printf("%s", YEL);
}

int chose_menu()
{
    char buff[100];
    int opt = 0;

    do{
        scanf("%s", buff);
        opt = (int) strtol(buff, NULL, 10);
        printf("buff = %d\nopt = %d",buff[0], opt);
    } while(opt <1 || opt >4);

    return opt;
}
