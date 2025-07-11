# Legend-of-the-Demon-Sword

これはターミナルだけで動くC言語のみの戦闘ゲームです。

---

## ゲーム制作

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
