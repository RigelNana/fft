//
// Created by RigelShrimp on 2025/1/18.
//

#ifndef FFT_H
#define FFT_H
#include <Eigen/Dense>

namespace fft_library {
    Eigen::VectorXcd fft(const Eigen::VectorXcd& X);
    Eigen::VectorXcd fft(const Eigen::VectorXcd& X, long long n);
    Eigen::VectorXcd fft(const Eigen::VectorXcd& X, long long n, int dim);
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X);
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, long long n);
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd& X, long long n, int dim);

}
#endif //FFT_H
