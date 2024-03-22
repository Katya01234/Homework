#include<iostream>
#include<random>
#include<fstream>

class Matrix
{
    double** A;
    double* x;
    double* b;
    int size = 0;
public:   
    Matrix(){
        info();
    }
    //case 1
    void get_N(){
        std::cin >> size;
    }       
    void Generate(){
        A = new double *[size]{};
        x = new double[size]{};
        b = new double[size]{};
        for (int i = 0; i < size; i++)
        {
            A[i] = new double[size];
        }
        //Заполнение матриц в зависимости от размера
        if(size <= 4){
            getMatrix_A_b();
        }
        else{
            random_A_b();
        }
    }
    void getMatrix_A_b(){
        double st;
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                std::cin >> st;
                A[i][j] = st;
            }
        }
        for(int j = 0;j < size;j++){
                std::cin >> st;
                b[j] = st;
            }
        std::cout << "------------------------------------------------\n";
        
    }
    void random_A_b(){
        for(int i = 0; i < size;i++){
            for(int j = 0; j < size;j++){
                A[i][j] = rand() % 20 - 10;
            } 
        }
        for(int i = 0; i < size;i++){
            b[i] = rand() % 20 - 10;
        }
    }
    void del(){
        if(size != 0){
            delete[] x;
            delete[] b;

            for (int i = 0; i < size; i++)
            {
                delete[] A[i];
            }
            delete[] A;
        }
    }
    //case 2
    void output_A_b(){
        std::cout << "A\n";
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                std::cout << A[i][j] << " ";
            }
            std::cout << "\n";
        }

        std::cout << "\nx\n";
        for(int j = 0;j < size;j++){
                std::cout << x[j] << " ";
            }    

        std::cout << "\nb\n";
        for(int j = 0;j < size;j++){
                std::cout << b[j] << " ";
            }
       
        std::cout << "\n------------------------------------------------\n";
    }
    
    // case 3
    void Gauss(){
        std::cout << "x\n";
        for(int j = 0;j < size;j++){
            for(int i = j+1;i < size;i++){
                double alpha = A[i][j]/A[j][j];
                for(int k = j;k < size;k++){
                    A[i][k] -= alpha * A[j][k];
                }
                b[i] -= alpha * b[j];
            }
        }
        for(int i = size-1;i >=0;i--){
            double sum = 0.0;
            for(int k = i + 1; k < size; k++){
                sum += x[k]*A[i][k];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
        
        for(int i = 0;i < size;i++) std::cout << x[i] << " ";
        std::cout << "\n------------------------------------------------\n";
    }
    
    // case 4
    void Gauss_try(){
        std::cout << "x\n";
        for(int j = 0;j < size;j++){
            Swap_max_value(j);
            for(int i = j+1;i < size;i++){
                double alpha = A[i][j]/A[j][j];
                for(int k = j;k < size;k++){
                    A[i][k] -= alpha * A[j][k];
                }
                b[i] -= alpha * b[j];
            }
        }
        for(int i = size-1;i >=0;i--){
            double sum = 0.0;
            for(int k = i + 1; k < size; k++){
                sum += x[k]*A[i][k];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
        
        for(int i = 0;i < size;i++) std::cout << x[i] << " ";
        std::cout << "\n------------------------------------------------\n";
    }
    void Swap_max_value(int j){
        double mx_A = A[j][j];
        int point = j;
        for(int i = j+1; i < size;i++){
            if(A[i][j] >  mx_A){
                mx_A = A[j][i];
                point = i;
            }
        }
        std::swap(A[point],A[j]);
        std::swap(b[point],b[j]);
            
    }
    
    //case 5
    void Matr_umn(){
        std::cout << "Max_value\n";
        double mx = 0.0;

        for(int i = 0;i < size;i++){
            double sum = 0.0;
            for(int j = 0;j < size;j++){
                sum += A[i][j] * x[j];
            }
            if(std::abs(sum - b[i]) > mx) mx = std::abs(sum - b[i]);
        }
        std::cout.precision(14);
        std::cout << mx;
        std::cout << "\n------------------------------------------------\n";
    }
    //case 6
    void save_matrix(){
        std::ofstream outp("matrix.txt");
        outp << size << "\n";
        for(int i = 0;i < size;i++){
            for(int j = 0;j < size;j++){
                outp << A[i][j] << " ";
            }
            outp << "\n";
        }
        for(int j = 0;j < size;j++){
                outp << x[j] << " ";
            }
        outp << "\n";
        for(int j = 0;j < size;j++){
                outp << b[j] << " ";
            }
        std::cout << "\n------------------------------------------------\n";
        outp.close();
    }
    //case 7
    void open_matrix(){
        std::ifstream  inp("matrix.txt");
        del();
        if(inp >> size){
            Generate();
            for(int i = 0;i < size;i++){
                for(int j = 0;j < size;j++){
                    inp >> A[i][j];
                }
            }
            for(int j = 0;j < size;j++){
                    inp >> x[j];
                }
            for(int j = 0;j < size;j++){
                    inp >> b[j];
                }
            std::cout << size <<"\n------------------------------------------------\n";
        }
        else std::cout << "File empty!";
        inp.close();
    }
    //case 8
    void info(){
        std::cout << "Info" << "\n"
        << "1.Create:" << "\n"
        << "2.Show:" << "\n"
        << "3.Gauss:" <<"\n"
        << "4.Gauss_zero:" <<"\n"
        << "5.Check:" <<"\n"
        << "6.Save:" <<"\n"
        << "7.Open" <<"\n"
        << "8.Info" <<"\n"
        << "9.Exit:" <<"\n";
    }

    

    ~Matrix(){
        delete[] x;
        delete[] b;

        for (int i = 0; i < size; i++)
        {
            delete[] A[i];
        }
        delete[] A;
    }
};


int main(){
    int flag = 1;
    int num_;
    Matrix m;
    while(flag){
        std::cin >> num_;
        switch(num_)
        {
        case 1:
            m.del();
            m.get_N();
            m.Generate();
            break;

        case 2:
            m.output_A_b();
            break;

        case 3:
            m.Gauss();
            break;

        case 4:
            m.Gauss_try();
            break;

        case 5:
            m.Matr_umn();
            break;

        case 6:
            m.save_matrix();
            break;
        
        case 7:
            m.open_matrix();
            break;

        case 8:
            m.info();
            break;

        case 9:
            flag = 0;
            break;
        }
    }
}