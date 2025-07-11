# Legend-of-the-Demon-Sword

これはターミナルだけで動くC言語のみの戦闘ゲームです。

---

## ゲーム性

### コード
```
void print(const char * std){
    for(int i = 0; std[i] != 0; i++){
        putchar(std[i]);
        fflush(stdout);
        Sleep(1);
    }
}
```
### RPGゲームのように文字の出力速度を変化させています
---
```
int e_HP = 1000;
int m_HP = 200;
```
e_HP = enemy_HP  
m_HP = my_HP  
自分と敵のHPの初期値を200（自分）,1000（敵）にしています

---

```

int damage = rand() % 51 + 100;// 100 ~ 150
e_HP -= damage;

```
剣のダメージを100 ~ 150dm ランダムに設定しています
