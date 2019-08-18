#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STAGE 10

int main(void){
    int i, stage, no, ans, num[MAX_STAGE];
    int n = 0;

    srand(time(NULL));
    ans = rand() % 1000;

    printf("0〜999の正数を当ててください。\n\n");

    for(stage = 0; stage < MAX_STAGE; stage++){
        printf("残り%d回。いくつかな：", MAX_STAGE - stage);
        scanf("%d", &no);
        num[stage] = no;

        if(no > ans)
            printf("もっと小さいよ\n");
        else if(no < ans)
            printf("もっと大きいよ\n");
        else 
            break;
    }

    if(no != ans)
        printf("残念！正解は%dでした。\n", ans);
    else {
        printf("正解です\n");
        printf("%d回で当たりましたね\n", stage);
    }

    puts("\n--- 入力履歴 ---");
    for(i = 0; i < (stage - 1); i++)
        printf(" %2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);
    printf(" %2d : %4d %4d\n", i + 1, num[i], n);

    return 0;
}
