#include <stdio.h>

typedef struct{
    char model[20];
    int temp;
}Boiler;

void heat_up(Boiler *b);
int main () {
    Boiler b = {"Toto", 20};
    heat_up(&b);
    heat_up(&b);
    heat_up(&b);
    return 0;
}

void heat_up(Boiler *b){
    b->temp++;
    printf("현재 온도: %d도 (난방 중...)\n",b->temp);
}