#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int human;      //人間の手
int comp;       //コンピュータの手
int win_no;     //勝った回数
int lose_no;    //負けた回数
int draw_no;    //引き分けた回数
int cnt;          //何回勝負か？

char *hd[] = {"グー", "チョキ", "パー"};

//初期処理
void initialize(void){
    win_no = 0;
    lose_no = 0;
    draw_no = 0;

    srand(time(NULL));

    printf("何回勝負でじゃんけんしますか。");
    scanf("%d", &cnt);

    printf("じゃんけん開始\n");
}

//じゃんけんの手の読み込み・生成
void janken(void){
    int i;

    if(draw_no == 0 && lose_no == 0 && win_no == 0)
        comp = 0;
    else
        comp = rand() % 2;

    do{
        printf("\nじゃんけんぽん ...");
        for(i = 0; i < 3; i++)
            printf(" (%d)%s", i, hd[i]);
        printf(":");
        scanf("%d", &human);
    }while(human < 0 || human > 2);
}

int main(void){
    int judge;      //勝敗

    initialize();   //初期処理

    do{
        janken();   //  じゃんけん実行

        printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

        judge = (human - comp + 3) % 3;     //勝敗の判定

        switch(judge){
            case 0:         //引き分け
                draw_no++;
                puts("引き分けです。");
                break;  
            case 1:         //負け
                lose_no++;
                puts("あなたの負けです。");
                break; 
            case 2:         //勝ち 
                win_no++;
                puts("あなたの勝ちです。");
                break;
        }

    }while(win_no < cnt && lose_no < cnt);

    printf("%d勝%d敗%d引き分けでした。\n", win_no, lose_no, draw_no);

    return 0;
}
