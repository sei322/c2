#include <stdio.h>
#include <time.h>
#include <string.h>

int sleep(unsigned long x){
    clock_t c1 = clock(), c2;
    do{
        if((c2 = clock()) == (clock_t)-1)
            return 0;
    }while(1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

void telop(const char *s, int direction, int speed, int n){
    int i, k, cnt = 0;
    int str_len = strlen(s);

    if(direction == 0){         //左方向に流す
        for(i = 0; i < n; i++){
            putchar('\r');

            for(k = 0; k < str_len; k++){
                if(cnt + k < str_len)
                    putchar(s[cnt + k]);
                else
                    putchar(s[cnt + k - str_len]);
            }
            fflush(stdout);
            sleep(speed);

            if(cnt < str_len - 1)   //一文字後ろから表示
                cnt++;
            else                    //先頭文字から表示
                cnt = 0;
        }
    }else if(direction == 1){   //右方向に流す
        for(i = 0; i < n; i++){
            putchar('\r');

            for(k = 0; k < str_len; k++){
                if(cnt - k > 0)
                    putchar(s[str_len - cnt + k]);
                else
                    putchar(s[k - cnt]);
            }
            fflush(stdout);
            sleep(speed);

            if(cnt < str_len - 1)
                cnt++;
            else 
                cnt = 0;
        }
    }
}

int main(void){
    char *s;
    int direction, speed, n;

    printf("文字列を入力してください。\n");
    scanf("%s", s);
    printf("右方向...1  左方向...0\n");
    scanf("%d", &direction);
    printf("表示速度(ミリ秒)\n");
    scanf("%d", &speed);
    printf("表示回数\n");
    scanf("%d", &n);

    telop(s, direction, speed, n);
    putchar('\n');

    return 0;
}
