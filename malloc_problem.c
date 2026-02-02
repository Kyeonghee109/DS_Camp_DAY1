#include <stdio.h>
#include <stdlib.h>

int main () {
    int days;
    printf("분석할 영업일수를 입력하세요: ");
    scanf("%d", &days);

    int* revenue = (int*)malloc(sizeof(int)*days);
    if(revenue == NULL){
        return 0;
    }
    int sum = 0;
    for(int i = 0 ; i < days; i++){
        scanf("%d", &revenue[i]);
        sum += revenue[i];
        printf("%d일차 매출: %d\n", i+1, revenue[i]);
    }
    float avg = (float)sum / days;

    printf("\n--- 분석 결과 ---\n");
    printf("평균 매출: %.1f원\n", avg);
    for(int i = 0 ; i < days; i++){
        if(avg > revenue[i]){
            printf("[경고] %d일차 매출 부진 (%d원)\n", i+1, revenue[i]);
        }
    }
    free(revenue);
    revenue = NULL;
    return 0;
}