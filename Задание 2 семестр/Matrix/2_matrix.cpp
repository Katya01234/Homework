#include <iostream>

class Martix
{
    double** A;
    double* x;
    double* b;
    int size;

public:
    Martix(int N) : size(N){}
    void Generate(){
        A = new double *[size];
        x = new double[size];
        b = new double[size];

        for (int i = 0; i < size; i++)
        {
            A[i] = new double[size];
        }
    }

    void getMatrix_A_x_b(){
        double st;
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                std::cin >> st;
                A[i][j] = st;
            }
        }
        for(int j = 0;j < size;j++){
                std::cin >> st;
                x[j] = st;
        }
        for(int j = 0;j < size;j++){
                std::cin >> st;
                b[j] = st;
            }
    }
    
    void output_A_x_b(){
        std::cout << "A\n";
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                std::cout << A[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "x\n";
        for(int j = 0;j < size;j++){
                std::cout << x[j] << " ";
        }
        std::cout << "\nb\n";
        for(int j = 0;j < size;j++){
                std::cout << b[j] << " ";
            }
        std::cout << "\n";
    }
    
    double Matr_umn(){
        std::cout << "\nMax_value\n";
        double mx = 0.0;

        for(int i = 0;i < size;i++){
            double sum = 0.0;
            for(int j = 0;j < size;j++){
                sum += A[i][j] * x[j];
            }
            if(std::abs(sum - b[i]) > mx) mx = std::abs(sum - b[i]);
        }
        return  mx;
    }

    ~Martix(){
        delete[] x;
        delete[] b;

        for (int i = 0; i < size; i++)
        {
            delete[] A[i];
        }
        delete[] A;
    }
};

int main()
{
    int N;
    std::cin >> N;
    Martix a(N);
    a.Generate();
    a.getMatrix_A_x_b();
    a.output_A_x_b();

    /* 3 2 -5 |x1 = 3| -1
       2 -1 3 |x2 = 5| 13
       1 2 -1 |x3 = 4| 9

    */
    std::cout.precision(15);
    std::cout << a.Matr_umn() << "\n";
}