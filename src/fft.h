//
// Created by RigelShrimp on 2025/1/18.
//

#ifndef FFT_H
#define FFT_H
#include <Eigen/Dense>
#include <unsupported/Eigen/FFT>
#include <complex>

namespace fft_library {
    Eigen::MatrixXcd fft(const Eigen::MatrixXcd &X, int n = -1, int dim = 1);

}
#endif //FFT_H
