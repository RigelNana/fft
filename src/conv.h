//
// Created by RigelShrimp on 2025/3/3.
//

#ifndef CONV_H
#define CONV_H
#include "fft.h"
#include "ifft.h"
namespace fft_library {
Eigen::VectorXd conv(const Eigen::VectorXd& u, const Eigen::VectorXd& v);

}
#endif //CONV_H
