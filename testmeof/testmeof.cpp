#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class mas {
private:
    int n; int m[];
public:
    mas(int in = 0) {
        n = in; 
        int* m = (int*)malloc(sizeof(int) * n);
    }
    void lin() {
        for (int i = 0; i < n; i++) {
            int t; std::cin >> t;
            m[i] = t;
        }
    }
    void lout(){
        for (int i = 0; i < n; i++) {
            std::cout << std::setw(5) << m[i] << std::right;
        }
    }
    void reverse(){
        for (int i = 0; i <= n/2; i++) {
            int t; 
            t = m[i];
            m[i] = m[n - i - 1];
            m[n - i - 1] = t;
        }
    }
    int len() {return n;}
};

int main(){
    int n; std::cin >> n;
    mas f(n);
    f.lin();
    std::cout << "N = " << n << std::endl;
    f.lout();
    std::cout << std::endl;
    f.reverse();
    f.lout(); 
    return 0;
}

