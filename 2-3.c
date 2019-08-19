#include <stdio.h>
#include <time.h>

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;
    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

void bput(const char *s, int d, int e, int n){
    int j, k;

    for(k = 0; k < n; k++){
        int i = 0;

        for(j = 0; s[j] != '\0'; j++){
            putchar(s[j]);
            i++;
            fflush(stdout);
        }
        sleep(d);

        for(j = 0; j < i; j++){
            printf("\b \b");
            fflush(stdout);
        }
        sleep(e);
    }
}

int main(void){
    char *str;
    int d, e;
    int n;

    printf("文字列を入力してください。\n");
    scanf("%s", str);
    printf("何秒間表示しますか？(ミリ秒)\n");
    scanf("%d", &d);
    printf("何秒間表示を消しますか？(ミリ秒)\n");
    scanf("%d", &e);
    printf("何回繰り返しますか？\n");
    scanf("%d", &n);

    bput(str, d, e, n);

    return 0;
}
