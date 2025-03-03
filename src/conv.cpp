//
// Created by RigelShrimp on 2025/3/3.
//

#include "conv.h"
#include <iostream>

namespace fft_library {
Eigen::VectorXd conv(const Eigen::VectorXd& u, const Eigen::VectorXd& v) {
    if (u.size() == 0 || v.size() == 0) {
        return Eigen::VectorXd{0};
    }
    const int max_size = u.size() + v.size() - 1;

    Eigen::VectorXcd u_fft = fft(u, max_size);
    Eigen::VectorXcd v_fft = fft(v, max_size);

    Eigen::VectorXcd prod = u_fft.cwiseProduct(v_fft);

    Eigen::VectorXcd result = ifft(prod, max_size);
    Eigen::VectorXd real_result(result.size());

    for (int i = 0; i < result.size(); ++i) {
        if (std::abs(result(i).imag()) < 1e-10) {
            result(i) = std::complex<double>(result(i).real(), 0.0);
        }
        if (std::abs(result(i).real()) < 1e-10) {
            result(i) = std::complex<double>(0.0, result(i).imag());
        }
        real_result(i) = result(i).real();
    }
    return real_result;
}
}
