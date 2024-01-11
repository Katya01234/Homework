/*
Задача1.Дан массив.  Нужно нули перекинуть в конец,
не изменяя порядок следования не нулевых элементов.
Пр.  1 3 0 4 5 6 0 => 1 3 4 5 6 0 0.  Пр. 0 0 1 2 0 4 => 1 2 4 0 0 0 .
Время O(N) Память O(1).
Можно попробовать за время O(N^2).
Если сложно за линейное. 
*/
/*
#include<stdio.h>

void input_mas(int*mas, int N){
    for(int i = 0;i < N;i++){
        int x;
        scanf("%d",&x);
        mas[i] = x;
    }
}

void last_zero(int*mas, int N){
    int l = 0, r = 0;
    int need_digit = 0;
    while(r < N){
        if(mas[l] == need_digit && mas[r] != need_digit){
            mas[l] = mas[r];
            mas[r] = need_digit;
        }
        if(mas[l] != need_digit) l++;
        r++;
    }
}
void last_zero_upgrate(int*mas, int N){//Этот алгоритм в лучшем случае работает слегка меньше, чем O(N), потому что указатели идут навстречу друг другу, но выводим не в отсортированном порядке
    int l = 0, r = N - 1;
    int need_digit = 0;
    while(l <= r){
        if(mas[l] == need_digit && mas[r] != need_digit){
            mas[l] = mas[r];
            mas[r] = need_digit;
        }
        if(mas[l] != need_digit) l++;
        if(mas[r] == need_digit) r--;
    }
}

int main(){
    int N; 
    scanf("%d",&N);
    int initial_mas[N];

    input_mas(initial_mas, N);

    last_zero(initial_mas, N);

    for(int i = 0; i < N; i++) printf("%d ",initial_mas[i]);
}
*/


/*
Задача 2.   Дан всегда отсортированный массив, нужно вернуть 1 ,
если есть любые два элемента которые в сумме дают число N,
что передается методу вызова или 0. Не важно на каких позициях стоят эти два элемента.
Важно что они есть или их нет.
Пр,.  2 4 6 8 9 13 20 , N = 19 => 1 . Пр. 10 20 30 40 50 60 , N = 70  => 1.
Время O(N). Память O(1), массив менять нельзя.
Если сложно по времени за O(N), можно O(N^2). 
*/
/*
#include<stdio.h>

void input_mas(int*mas, int N){
    for(int i = 0;i < N;i++){
        int x;
        scanf("%d",&x);
        mas[i] = x;
    }
}

int sum_a_b(int*mas, int N, int Need){
    int l = 0,r = N -1;
    while(l < r){
        if((mas[l] + mas[r]) < Need) l++;
        else if ((mas[l] + mas[r]) > Need) r--;
        else{
            return 1;
        }
    }
    return 0;
}

int main(){
    int N, Need;
    scanf("%d",&N);
    scanf("%d", &Need);
    int initial_mas[N];

    input_mas(initial_mas, N);
    printf("%d",sum_a_b(initial_mas, N, Need));
}
*/





/*
Задача: Дан одномерный массив размером N.
Написать функцию, которая вернет 1 если массив уже отсортирован по возрастанию.
2 - по убыванию. 0 - все элементы одинаковые,   -1  во всех остальных случаях.
Массив изменять нельзя. Доп память создавать нельзя.O(1),
Сложность по времени, желательно Линейная , O(N).
*/
/*
#include<stdio.h>

void input_mas(int*mas, int N){
    for(int i = 0;i < N;i++){
        int x;
        scanf("%d",&x);
        mas[i] = x;
    }
}

int is_sorted(int* mas, int N){
    int point = 0;
    int dublicat = 1;
    
    for(int i = 0; i < N - 1;i++){
        if(mas[i] < mas[i+1]){
            point++;
        }
        else if(mas[i] > mas[i+1]){
            point--;
        }
        else dublicat++;
    }
    
    if(dublicat == N) return 0;
    
    else if(point > 0 && point+dublicat == N) return 1;
    
    else if(point < 0 && (-1) * point + dublicat == N) return 2;
    
    return -1;
    
}

int main(){
    int N;
    scanf("%d",&N);
    int initial_mas[N];

    input_mas(initial_mas, N);
    printf("%d",is_sorted(initial_mas, N));
    
    return 0;
}
*/
