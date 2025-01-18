#include <iostream>


#include "fft.h"
int main() {
    Eigen::VectorXcd X(4);
    X << std::complex<double>(1, 0), std::complex<double>(2, 0), std::complex<double>(3, 0), std::complex<double>(4, 0);
    auto Y = fft_library::fft(X);
    std::cout << Y << std::endl;
    return 0;
}