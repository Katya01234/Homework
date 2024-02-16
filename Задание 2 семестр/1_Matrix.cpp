#include<iostream>
#include<random>
#include<vector>

const int N = 4;

void input(int a[][N]){
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            a[i][j] = rand() % 10; 
        }
    }
}

void output(int a[][N]){
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            std::cout << a[i][j] << " "; 
        }
        std::cout << "\n"; 
    }
}

void tranc(int a[][N]){
    for(int i = 0; i < N;i++){
        for(int j = i+1; j < N;j++){
            std::swap(a[i][j],a[j][i]);
        }
    }
}

int Max_m(int a[][N]){
    int mx = 0, point = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            point += a[i][j]; 
        }
        if (point > mx) {mx = point;}
        point = 0;
    }
    return mx;
}

int Min_n(int a[][N]){
    int mn = INT_MAX, point = 0;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            point += a[j][i]; 
        }
        if (point < mn) {mn = point;}
        point = 0;
    }
    return mn;
}



int main(){
    int a[N][N] = {{7,6,5,4},
                   {2,5,3,3},
                   {9,8,7,2},
                   {1,2,9,1}};
    input(a);
    output(a);

    std::cout << "\n" << "Trans" << "\n";
    tranc(a);
    output(a);

    std::cout << "\n" << "MAX_M" << "\n" << Max_m(a);
    std::cout << "\nMIN_N" << "\n" << Min_n(a);

}