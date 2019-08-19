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

void gput(const char *s, int speed){
    while(*s != '\0'){
        putchar(*s++);
        fflush(stdout);
        sleep(speed);
    }
    putchar('\n');
}
int main(void){
    char str[100];
    int speed;

    printf("表示させたい文字列を入力してください。\n");
    scanf("%s", str);
    printf("表示速度を入力してください。\n単位はミリ秒です。\n");
    scanf("%d", &speed);

    gput(str, speed);

    return 0;
}
