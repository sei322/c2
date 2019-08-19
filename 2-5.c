#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    int stage, i;
    int a, b, c;    //加算する数値
    int ans;          //読み込んだ値
    int n;          //余白の幅
    clock_t cnt[10];
    double sum, dif;

    srand(time(NULL));

    printf("視野拡大暗算トレーニング開始!!\n");
    cnt[0] = time(NULL);

    for(stage = 0; stage < 10; stage++){
        a = 10 + rand() % 90;
        b = 10 + rand() % 90;
        c = 10 + rand() % 90;
        n = rand() % 17;

        printf("%d%*s+%*s%d%*s+%*s%d : ", a, n, "", n, "",  b, n, "", n, "", c);

        do{
            scanf("%d", &ans);
            if(ans == a + b + c){
                cnt[stage + 1] = time(NULL);
                break;
            }
            printf("違います。再入力してください。\n");
        }while(1);
    }

    for(i = 0; i < 10; i++){
        printf("%d問目は%.1f秒\n", i + 1, dif = difftime(cnt[i + 1], cnt[i]));
        sum += dif;
    }

    printf("平均%.1f秒かかってます。\n", sum / 10);

    return 0;
}
