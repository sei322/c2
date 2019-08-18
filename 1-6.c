#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int ans, lv, a;

    srand(time(NULL));
    ans = rand();

    printf("レベルを選択してください\n");
    printf("[1]...1 ~ 9  [2]...1 ~ 99  [3]...1 ~ 999  [4]...1 ~ 9999\n");
    scanf("%d", &lv);

    do{
        switch(lv){
            case 1:
                ans %= 10;
                break;
            case 2:
                ans %= 100;
                break;
            case 3:
                ans %= 1000;
                break;
            case 4:
                ans %= 10000;
                break;
        }
    }while(ans == 0);

    do{
        printf("いくつかな：");
        scanf("%d", &a);

        if(a < ans)
            printf("もっと大きいよ\n");
        else if(a > ans)
            printf("もっと小さいよ\n");
    }while(a != ans);

    printf("正解だよ\n");

    return 0;
}
