#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int n1, n2, a, ans;

    srand(time(NULL));
    n1 = rand() % 10000;
    n2 = rand() % 100;
    
    do{
        ans = rand() % 10000;
    }while(ans > n1 && ans < n2);

    printf("%d以上%d以下の整数を当てよ。\n\n", n2, n1);

    do{
        printf("いくつかな：");
        scanf("%d", &a);

        if(a > ans)
            printf("もっと小さいよ\n");
        else if(a < ans)
            printf("もっと大きいよ\n");
    }while(a != ans);

    printf("正解だよ\n");

    return 0;
}
