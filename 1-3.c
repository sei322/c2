#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int ans, b;

    srand(time(NULL));
    ans = (rand() % 2000) - 1000;

    printf("-999から999の整数を当ててください。\n\n");

    do{
        printf("いくつかな: ");
        scanf("%d", &b);

        if(ans > b)
            printf("もっと大きいよ\n");
        else if(ans < b)
            printf("もっと小さいよ\n");

    }while(b != ans);

    printf("正解です\n");

    return 0;
}
