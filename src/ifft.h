//
// Created by RigelShrimp on 2025/3/3.
//

#ifndef IFFT_H
#define IFFT_H
#include <Eigen/Dense>
#include <unsupported/Eigen/FFT>
namespace fft_library {
    Eigen::VectorXcd ifft(const Eigen::VectorXcd& X, int n = -1);
    Eigen::MatrixXcd ifft(const Eigen::MatrixXcd& X, int n = -1, int dim = 1);

}
#endif //IFFT_H
