#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int a;

    srand(time(NULL));  /*乱数の種を生成*/
    a = rand() % 7;     /*０から６の乱数を生成*/

    switch(a){
        case 0:
            printf("大吉\n");
            break;
        case 1:
            printf("中吉\n");
            break;
        case 2:
            printf("小吉\n");
            break;
        case 3:
            printf("吉\n");
            break;
        case 4:
            printf("末吉\n");
            break;
        case 5:
            printf("凶\n");
            break;
        case 6:
            printf("大凶\n");
            break;
    }

    return 0;
}
