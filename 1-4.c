#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int ans, a;

    srand(time(NULL));
    ans =(rand() % 111) * 3;

    printf("３以上９９９以下の３の倍数の整数をあてよ\n\n");
    
    do{
        printf("いくつかな： ");
        scanf("%d", &a);

        if(a % 3 != 0)
            exit(1);
        else if (a > ans)
            printf("もっとちいさいよ\n");
        else if (a < ans)
            printf("もっと大きいよ\n");
    }while(a != ans && a % 3 == 0);

    if(a == ans)
        printf("正解です\n");

    return 0;
}
