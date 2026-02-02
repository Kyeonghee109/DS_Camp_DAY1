#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int score;
} Student;

double get_average(Student *list, int count);
Student* find_mvp(Student *list, int count);
void sort(Student *students, int n);

int main () {
    int size;
    printf("학생 수를 입력해주세요.\n");
    scanf("%d", &size);

    if (size <= 0) {
        printf("학생 수는 1명 이상이어야 합니다.\n");
        return 1;
    }

    Student* s = (Student*)malloc(sizeof(Student)*size);
    
    if(s == NULL){ //동적할당 실패 예외 처리
        return 1;
    }

    for(int i = 0; i < size; i++){ // 학생 정보 입력
        printf("[%d번째 학생]\n", i+1);
        printf("이름: ");
        scanf("%s", &s[i].name);
        printf("성적: ");
        scanf("%d", &s[i].score);
        printf("\n");
    }

    printf("\n---분석 결과---\n");
    double total_avg = get_average(s, size); // 평균 계산
    find_mvp(s, size); // 1등학생 출력

    printf("전체 평균: %.2f점\n", total_avg); // 
    sort(s, size); //중앙값 출력

    free(s);
    return 0;
}

double get_average(Student *list, int count){
    int sum = 0;
    for(int i = 0 ; i < count ; i++){
        sum += list[i].score;
    }
    double avg = (float)sum / count;
    return avg;
}

Student* find_mvp(Student *list, int count){
    if(count <= 0) return NULL;
    int mvp_idx = 0;
    for(int i = 0 ; i < count; i++){
        if(list[i].score > list[mvp_idx].score){
            mvp_idx = i;
        }
    }
    printf("1등 학생 - %s (%d점)\n",list[mvp_idx].name,list[mvp_idx].score);
}

void sort(Student *students, int n){
    for(int i=0; i<n-1; i++){
        for(int j= i +1; j<n; j++){
            if(students[i].score > students[j].score){
                Student temp =students[i];
                students[i] =students[j];
                students[j] =temp;
            }
        }
    }
    //중앙값 계산
    double middle;
    if(n%2==1){
        middle = students[n/2].score;
    }
    else{
        middle= students[n/2 -1].score + students[n/2 ].score/2;
    }
    printf("중앙값: %.2f점",middle);
}

