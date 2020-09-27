

#include <iostream>
#include <cmath>

double func(double x){
    return std::sqrt(x) * std::sin(x * 0.5) * (-2);
}

int main(int argc, const char * argv[]) {
    double a_k = 2;
    double b_k = 6;
    double l = b_k - a_k;
    const double e = 0.1;
    const double t = (std::sqrt(5) + 1) / 2;
    double x_k1 = a_k + (1 - 1 / t) * b_k;
    double x_k2 = a_k + b_k / t;
    double f_k1 = func(x_k1);
    double f_k2 = func(x_k2);
    std::cout << "Golden ration method" << std::endl;
    while (l > e){
        std::cout << "a = " << a_k << " b = " << b_k << " l = " << l << std::endl;
        if (f_k1 < f_k2){
            b_k = x_k2;
            x_k2 = a_k + b_k - x_k1;
            f_k2 = func(x_k2);
        } else {
            a_k = x_k1;
            x_k1 = a_k + b_k - x_k2;
            f_k1 = func(x_k1);
        }
        if (x_k1 > x_k2){
            std::swap(x_k1, x_k2);
            std::swap(f_k1, f_k2);
        }
        l = b_k - a_k;
    }
    std::cout << "a = " << a_k << " b = " << b_k << " l = " << l << std::endl;
    double s = 0.5 * (b_k - a_k);
    double x_sol = (a_k + b_k) / 2;
    std::cout << "Minimum x = " << x_sol << " +- " << s << " l = " << l << std::endl;
    
    a_k = 2;
    b_k = 6;
    double pres = (b_k - a_k) / 2;
    int n = 1;
    std::cout << "Passive search method" << std::endl;
    
    while(pres >= e){
        double x, x_min, func_curr;
        double func_min = func(a_k);
        for (auto i = 1; i <= n; i++){
            x = (b_k - a_k) * i / (n + 1) + a_k;
            func_curr = func(x);
            if (func_curr < func_min){
                func_min = func_curr;
                x_min = x;
            }
        }
        std::cout << "n = " << n << " minimun x = " << x_min << " +- " << pres << std::endl;
        n++;
        pres = (b_k - a_k) / (n + 1);
    }
    return 0;
}
