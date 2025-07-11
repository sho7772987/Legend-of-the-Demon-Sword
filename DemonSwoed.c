#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void print(const char * std){
    for(int i = 0; std[i] != 0; i++){
        putchar(std[i]);
        fflush(stdout);
        Sleep(1);
    }
}
//HPバー表示関数（最大バー長 = 20）
void print_bar(int hp, int max_hp){
    int bars = (hp * 20) / max_hp;
    for(int i = 0; i < bars; i++){
        print("■");
    }
    for(int i = bars; i < 20; i++){
        print(" ");
    }
}
//以下からmain
int main(void){
    char input[100];
    int attack;
    int N;
    srand((unsigned int)time(NULL)); // 乱数の種
    print("「「魔剣伝説」」\n");
    print("    戦う：【１】\n");
    print("やめとく：【０】\n");
    scanf("%d",&N);

    if(N == 1){
        int e_HP = 1000;
        int m_HP = 200;
        int e_HP_max = 1000;
        int m_HP_max = 200;

        print("戦闘開始！\n");
        while(e_HP > 0 && m_HP > 0){
            //状況の場所
            print("\n=== 現在の状況 ===\n");
            char buf1[100];
            snprintf(buf1,sizeof(buf1),"    敵のHP：%4d [", e_HP);
            print(buf1);
            print_bar(e_HP, e_HP_max);
            print("]\n");
            char buf2[100];
            snprintf(buf2,sizeof(buf2),"あなたのHP：%4d [", m_HP);
            print(buf2);
            print_bar(m_HP, m_HP_max);
            print("]\n");

            //自分の行動
            print("\n何を使いますか？\n剣(100 ~ 150dm)：【０】    魔法(0 ~ 250dm)：【１】   回復(30 ~ 120)：【２】\n");
            scanf("%d", &attack);

            if(attack == 0){ // 剣
                int damage = rand() % 51 + 100;// 100 ~ 150
                e_HP -= damage;
                if(e_HP < 0) e_HP = 0;
                char buf3[100];
                snprintf(buf3,sizeof(buf3),"剣で攻撃！ %d のダメージを与えた！\n",damage);
                print(buf3);
            }else if(attack == 1){ // 魔法
                char buf4[100];
                int damage = rand() % 251; // 0～350
                e_HP -= damage;
                if(e_HP < 0) e_HP = 0;
                if(damage == 0){
    print("敵に魔法が効かなかった！\n");
}else{
    if(damage >= 160 && damage < 200){
        print("大ダメージ！\n");
    }else if(damage >= 200){
        print("絶ダメージ！\n");
    }
    snprintf(buf4,sizeof(buf4),"魔法攻撃！ %d のダメージを与えた！\n",damage);
    print(buf4);
}

            }else if(attack == 2){ // 回復
                int heal = rand() % 91 + 30; // 30～150
                m_HP += heal;
                if(m_HP > m_HP_max) m_HP = m_HP_max;
                char buf5[100];
                if(m_HP == 200){
                    char buf7[100];
                    snprintf(buf7,sizeof(buf7),"全回復！ HPが %d 回復した！\n",heal);
                    print(buf7);
                }else{
                snprintf(buf5,sizeof(buf5),"回復魔法！ HPが %d 回復した！\n", heal);
                print(buf5);
                }
            }else if(attack == 777){//隠しコマンド
                int damage = 777;
                e_HP -= damage;
                char buf8[100];
                snprintf(buf8,sizeof(buf8),"[隠しコマンド]チート攻撃！ %d ダメージ与えた！\n",damage);
                print(buf8);
            }

            //敵のターん（生きていれば）
            if(e_HP > 0){
                int e_attack = rand() % 71 + 30; // 30～100
                m_HP -= e_attack;
                if(m_HP < 0) m_HP = 0;
                char buf6[100];
                snprintf(buf6,sizeof(buf6),"敵の攻撃！ %d のダメージを受けた！\n",e_attack);
                print(buf6);
            }
        }

        //勝敗
        print("\n=== 結果 ===\n");
        if(m_HP <= 0)
            print("あなたは倒れてしまった… Game Over\n");
        else
            print("敵を倒した！ 勝利！！\n");

    }else if(N == 0){
        print("また今度冒険しよう\n");
    }else if(N == 6){//裏ボス
        int e_HP = 10000;
        int m_HP = 200;
        int e_HP_max = 10000;
        int m_HP_max = 200;

        print("戦闘開始！\n");
        while(e_HP > 0 && m_HP > 0){
            //(裏)状況の場所
            print("\n=== 現在の状況 ===\n");
            char buf1[100];
            snprintf(buf1,sizeof(buf1)," (裏)敵のHP：%4d [", e_HP);
            print(buf1);
            print_bar(e_HP, e_HP_max);
            print("]\n");
            char buf2[100];
            snprintf(buf2,sizeof(buf2)," あなたのHP：%4d [", m_HP);
            print(buf2);
            print_bar(m_HP, m_HP_max);
            print("]\n");

            //(裏)自分の行動
            print("\n何を使いますか？\n剣(？dm)：【０】    魔法(？dm)：【１】   回復(？)：【２】\n");
            scanf("%d", &attack);

            if(attack == 0){ // 剣
                int damage = rand() % 301 + 200;// 200 ~ 500
                e_HP -= damage;
                if(e_HP < 0) e_HP = 0;
                char buf3[100];
                snprintf(buf3,sizeof(buf3),"剣で攻撃！ %d のダメージを与えた！\n",damage);
                print(buf3);
            }else if(attack == 1){ // 魔法
                char buf4[100];
                int damage = rand() % 1001; // 0～1000
                e_HP -= damage;
                if(e_HP < 0) e_HP = 0;
                if(damage == 0){
    print("敵に魔法が効かなかった！\n");
}else{
    if(damage >= 600 && damage < 700){
        print("大ダメージ！\n");
    }else if(damage >= 700){
        print("絶ダメージ！\n");
    }
    snprintf(buf4,sizeof(buf4),"魔法攻撃！ %d のダメージを与えた！\n",damage);
    print(buf4);
}

            }else if(attack == 2){ // 回復
                int heal = rand() % 501;
                m_HP += heal;
                if(m_HP > m_HP_max) m_HP = m_HP_max;
                char buf5[100];
                if(m_HP == 200){
                    char buf7[100];
                    snprintf(buf7,sizeof(buf7),"全回復！ HPが %d 回復した！\n",heal);
                    print(buf7);
                }else{
                snprintf(buf5,sizeof(buf5),"回復魔法！ HPが %d 回復した！\n", heal);
                print(buf5);
                }
            }else if(attack == 777){//隠しコマンド
                int damage = 777;
                e_HP -= damage;
                char buf8[100];
                snprintf(buf8,sizeof(buf8),"[隠しコマンド]チート攻撃！ %d ダメージ与えた！\n",damage);
                print(buf8);
            }

            //敵のターん（生きていれば）
            if(e_HP > 0){
                int e_attack = rand() % 251; //0 ~ 200
                m_HP -= e_attack;
                if(m_HP < 0) m_HP = 0;
                char buf6[100];
                snprintf(buf6,sizeof(buf6),"敵の攻撃！ %d のダメージを受けた！\n",e_attack);
                print(buf6);
            }
        }

        //勝敗
        print("\n=== 結果 ===\n");
        if(m_HP <= 0)
            print("あなたは倒れてしまった… Game Over\n");
        else
            print("裏敵を倒した！ 勝利！！\n");
    }
    return 0;
}
