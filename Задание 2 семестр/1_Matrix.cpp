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

void Sedlo(int a[][N]){
    for(int x = 0; x < N;x++){
        int mx_m = 0;
        int point_m = 0;
        for(int i = 0; i < N;i++){
            if(point_m < a[x][i]) {
                mx_m = i;
                point_m = a[x][i];
            }
        }
        int mn_n = 0;
        int point_n = INT_MAX;
        for(int j = 0; j < N;j++){
            if(point_n >= a[j][mx_m]){
                point_n = a[j][mx_m];
                mn_n = j;
            }
        }

        if(a[x][mx_m] == a[mn_n][mx_m]){
            std::cout << mn_n <<"," << mx_m << "\n";
        }
    }
}

void Sum_matrixs(int a[][N],int b[N]){
    int sum[N] = {};

    for(int i = 0; i < N;i++){
        for(int j = 0; j < N;j++){
            sum[i] +=  a[i][j] * b[j];
        }
    }
    for(int i = 0;i < N;i++) std::cout << sum[i] << " ";
}

int main(){
    int a[N][N] = {{4,1,2,3},
                   {7,1,5,1},
                   {13,1,5,6},
                   {12,1,5,7}
                  };
    int b[N] = {1,2,3,4};
    //input(a);
    //output(a);

    //std::cout << "\n" << "Trans" << "\n";
    //tranc(a);
    //output(a);

    //std::cout << "\n" << "MAX_M" << "\n" << Max_m(a);
    //std::cout << "\nMIN_N" << "\n" << Min_n(a);

    //std::cout << "\nSedlo_point" << "\n";
    //Sedlo(a);

    Sum_matrixs(a,b);
}