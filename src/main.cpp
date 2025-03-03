#include "conv.h"
#include "fft.h"
#include "ifft.h"
#include <chrono>
#include <iomanip>
#include <iostream>

int main() {
    Eigen::MatrixXcd X(5, 4);

    X << std::complex<double>(0.1869, 0.6507), std::complex<double>(-0.1885, -0.4457), std::complex<double>(0.3966, 0.2162), std::complex<double>(0.7742, -0.0165),
         std::complex<double>(0.6094, 0.4624), std::complex<double>(1.2190, -0.6386), std::complex<double>(-0.1771, -0.0905), std::complex<double>(-0.7459, 0.3079),
         std::complex<double>(0.7320, -2.3504), std::complex<double>(-1.2757, 1.5673), std::complex<double>(1.3599, -0.1746), std::complex<double>(0.0246, 0.2454),
         std::complex<double>(2.3599, 0.0149), std::complex<double>(0.0103, -0.3397), std::complex<double>(1.3533, 1.3430), std::complex<double>(0.0377, -0.7045),
         std::complex<double>(-0.4316, -0.0704), std::complex<double>(0.8781, -1.5313), std::complex<double>(-0.4233, 0.6018), std::complex<double>(0.2675, -1.1114);

    auto time_start = std::chrono::high_resolution_clock::now();
    Eigen::MatrixXcd Y = fft_library::fft(X, 7, 1);
    std::cout << Y << "\n\n";
    auto time_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(time_end - time_start);
    std::cout << "Time: " << time_span.count() << " seconds." << std::endl;

    time_start = std::chrono::high_resolution_clock::now();
    Eigen::MatrixXcd Z = fft_library::ifft(X, 8, 1);
    time_end = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(time_end - time_start);

    std::cout << Z;
    std::cout << "Time: " << time_span.count() << " seconds." << std::endl;
    // // std::cout <<std::setprecision(10)
    //
    Eigen::VectorXd u(7);
    u << -1, 2, 3, -2, 0, 1, 2;
    std::cout << fft_library::ifft(static_cast<Eigen::VectorXcd>(u), 10) << "\n\n";
    //
    Eigen::VectorXd v(4);
    v << 2, 4, -1, 1;
    time_start = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd conv1 = fft_library::conv(u,v);
    time_end = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(time_end - time_start);
    std::cout << conv1 << "\n\n";
    std::cout << fft_library::fft(u,10) << "\n\n";
    std::cout << "Time: " << time_span.count() << " seconds." << std::endl;

    return 0;
}
