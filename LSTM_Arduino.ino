  /*
Compile with:
g++ --std=c++11 -Wall -O3 test_cpp_model.cpp keras_model.cpp utils.cpp config.cpp -o output
*/

//#include <I2S.h>
#include <iostream>
#include "keras_model.h"
#include "utils.h"
#include "config.h"

int main() {
    // Initialize model.
    
    KerasModel model;
    model.LoadModel();

    // Create a 1D Tensor of shape (SEGMENT_TIME_SIZE, N_FEATURES) for input data.
    Tensor in(config::SEGMENT_TIME_SIZE, config::N_FEATURES);
    /*in.data_ = {-14.44,  -1.68,  -2.40,
                -14.44,  -1.68,  -2.40,
                -14.63,   3.36,  -2.35,
                -14.63,   3.36,  -2.35,
                -14.63,   3.36,  -2.35,
                 -8.21,   1.66,  -6.38,
                 -8.21,   1.66,  -6.38,
                 -2.88,  -0.87,  -4.96,
                 -2.88,  -0.87,  -4.96,
                 -2.88,  -0.87,  -4.96,
                 -2.88,  -0.87,  -4.96,
                 -1.91,  -4.10,  -3.47,
                 -1.91,  -4.10,  -3.47,
                 -1.91,  -4.10,  -3.47,
                 -7.67,   2.92,  -5.25,
                 -7.67,   2.92,  -5.25,
                 -7.67,   2.92,  -5.25,
                -20.00,  19.99, -12.99,
                -20.00,  19.99, -12.99,
                -20.00,  19.99, -12.99,
                -20.00,  19.99, -16.21,
                -20.00,  19.99, -16.21,
                 -7.29,   0.82,  -4.27,
                 -7.29,   0.82,  -4.27,
                 -7.29,   0.82,  -4.27,
                 -4.09,  -1.87,  -4.49,
                 -4.09,  -1.87,  -4.49,
                 -5.97,  -1.87,  -3.6 ,
                 -5.97,  -1.87,  -3.6 ,
                 -5.97,  -1.87,  -3.6 ,
                 -0.83,  -5.19,  -3.81,
                 -0.83,  -5.19,  -3.81,
                 -0.83,  -5.19,  -3.81,
                -20.00,  18.28, -10.44,
                -20.00,  18.28, -10.44,
                -20.00,  18.28, -10.44,
                -20.00,  16.40, -14.51,
                -20.00,  16.40, -14.51,
                -20.00,  16.40, -14.51,
                 -3.55,  -2.53,  -3.92,
                 };*/

     /*in.data_ = {
      
        -15.17,  -3.66,  -5.4 ,
       -15.17,  -3.66,  -5.4 ,
       -15.17,  -3.66,  -5.4 ,
       -12.39,   9.31,  -2.39,
       -12.39,   9.31,  -2.39,
       -12.39,   9.31,  -2.39,
       -11.68,   2.5 ,  -5.26,
       -11.68,   2.5 ,  -5.26,
       -11.68,   2.5 ,  -5.26,
       -11.68,   2.5 ,  -5.26,
       -13.57,  -8.73,  -7.18,
       -13.57,  -8.73,  -7.18,
       -10.4 ,   4.34,  -4.22,
       -10.4 ,   4.34,  -4.22,
       -10.4 ,   4.34,  -4.22,
       -10.4 ,   4.34,  -4.22,
       -11.4 ,   1.14,  -5.08,
       -11.4 ,   1.14,  -5.08,
       -11.4 ,   1.14,  -5.08,
       -12.09,  -2.82,  -6.34,
       -12.09,  -2.82,  -6.34,
       -12.09,  -2.82,  -6.34,
       -12.09,  -2.82,  -6.34,
       -14.21,   1.93,  -4.68,
       -14.21,   1.93,  -4.68,
       -14.21,   1.93,  -4.68,
       -12.23,   1.62,  -6.17,
       -12.23,   1.62,  -6.17,
       -12.23,   1.62,  -6.17,
       -13.59,  -2.79,  -4.46,
       -13.59,  -2.79,  -4.46,
       -13.59,  -2.79,  -4.46,
       -13.59,  -2.79,  -4.46,
       -14.87,  -0.09,  -5.75,
       -14.87,  -0.09,  -5.75,
       -14.87,  -0.09,  -5.75,
       -13.87,   2.81,  -6.8 ,
       -13.87,   2.81,  -6.8 ,
       -13.87,   2.81,  -6.8 ,
       -15.11,   2.23,  -4.86
      
      };*/

     /*in.data_ = {

         4.27,  -6.43,  -1.7,
         4.27,  -6.43,  -1.74,
         4.27,  -6.43,  -1.74,
         4.38,  -8.31,  -0.5 ,
         4.38,  -8.31,  -0.5 ,
         4.38,  -8.31,  -0.5 ,
         2.49,  -2.43,  -6.91,
         2.49,  -2.43,  -6.91,
         3.13,  -2.23,  -7.98,
         3.13,  -2.23,  -7.98,
         3.13,  -2.23,  -7.98,
         4.88,  -5.47,  -1.67,
        4.88,  -5.47,  -1.67,
         5.64,  -5.44,  -2.86,
         5.64,  -5.44,  -2.86,
         1.22,   1.35, -11.54,
         1.22,   1.35, -11.54,
         1.22,   1.35, -11.54,
         1.22,   1.35, -11.54,
         4.3 ,  -3.16,  -5.8 ,
         4.3 ,  -3.16,  -5.8 ,
        3.84,  -5.81,  -1.19,
        3.84,  -5.81,  -1.19,
         3.84,  -5.81,  -1.19,
        4.98,  -5.03,  -4.29,
         4.98,  -5.03,  -4.29,
         4.98,  -5.03,  -4.29,
        -0.78,   4.28, -14.14,
        -0.78,   4.28, -14.14,
        -0.78,   4.28, -14.14,
         6.02,  -4.14,  -4.04,
         6.02,  -4.14,  -4.04,
         3.52,  -7.26,   0.99,
         3.52,  -7.26,   0.99,
         3.52,  -7.26,   0.99,
         5.59,  -3.8 ,  -4.92,
         5.59,  -3.8 ,  -4.92,
         5.59,  -3.8 ,  -4.92,
         3.52,  -0.99,  -8.28,
         3.52,  -0.99,  -8.28
      
      };*/

/*in.data_ = {

         2.100e-01,  3.200e-01,  1.200e-01, -2.100e-01,  3.100e-01, 1.500e-01, -8.000e-02,
         
       -1.000e-02,  3.600e-01, -1.800e-01,  1.500e-01, -3.000e-02, 3.700e-01,  1.100e-01,
         
       -2.000e-02,  8.000e-02, -2.500e-01,  1.000e-01,  2.600e-01, 2.500e-01,  9.000e-02,
         
        3.000e-02,  1.200e-01,  2.900e-01,  1.600e-01, -5.000e-02, 2.300e-01,  1.800e-01,
         
       -4.000e-02,  1.000e-02,  1.300e-01,  3.400e-01,  1.600e-01, -7.000e-02,  2.200e-01,
        
       -8.000e-02, -1.100e-01,  1.200e-01,  2.300e-01,  1.800e-01, -3.000e-02,  2.000e-02,
        
        3.100e-01,  1.600e-01, -1.300e-01,  7.000e-02,  1.600e-01, 2.300e-01, -5.000e-02,
         
        3.000e-02,  3.300e-01,  1.300e-01, -6.000e-02,  1.100e-01, 1.600e-01,  2.800e-01,
        
       -4.000e-02,  1.000e-02,  1.800e-01,  8.000e-02, -5.000e-02, 3.200e-01,  4.000e-02,
         
       0.000e+00, -2.100e-01,  3.100e-01,  3.600e-01, -8.000e-02, -1.100e-01,  5.300e-01,
        
       -3.000e-02, -5.000e-02,  4.000e-02,  2.500e-01,  2.900e-01, -2.000e-01, -5.000e-02,
        
        6.200e-01,  1.000e-02, -2.100e-01,  5.000e-02,  2.200e-01, 2.100e-01, -7.000e-02,
         
        1.100e-01,  4.500e-01, -1.300e-01, -1.100e-01,  2.000e-02, 3.600e-01,  1.600e-01,
        
        9.000e-02, -1.800e-01,  1.700e-01,  1.000e-02, -2.400e-01, 4.800e-01,  2.200e-01,
         
       -1.000e-01, -1.400e-01,  5.000e-02,  4.100e-01, -2.000e-02, -1.300e-01, -1.600e-01,
        
        8.000e-02, -1.800e-01,  1.100e-01, -7.000e-02, -4.000e-02, -1.000e-02, -1.100e-01,
        
        1.600e-01, -2.000e-02, -2.000e-02,  7.000e-02, -1.800e-01, -2.000e-02, -1.000e-02,
        
        5.000e-02,  8.000e-02, -1.100e-01,  0.000e+00, -4.000e-02, 4.000e-02,  2.000e-02,
         
       -7.000e-02, -1.000e-01, -4.000e-02, -1.200e-01,  1.100e-01, -1.000e-02, -2.000e-02,
        
        0.000e+00, -6.000e-02, -6.000e-02,  1.100e-01, -7.000e-02, 0.000e+00,  6.000e-02,
         
        4.000e-02, -1.000e-02, -7.000e-02,  3.000e-02, -3.000e-02, 9.000e-02, -3.000e-02,
         
        1.000e-01, -5.000e-02,  3.000e-02,  2.000e-02, -2.000e-01, -6.000e-02,  7.000e-02,
        
        5.000e-02,  2.000e-02, -4.000e-02, -2.000e-02, -4.000e-02, -3.000e-02,  5.000e-02,
        
      -1.300e-01,  8.000e-02,  7.000e-02,  1.200e-01, -8.000e-02, 1.500e-01,  0.000e+00,
         
        3.000e-02, -4.000e-02,  3.000e-02,  0.000e+00, -1.000e-02, -1.200e-01, -4.000e-02,
        
       -1.000e-02, -3.000e-02,  1.000e-02, -7.000e-02,  1.000e-02, -1.800e-01,  1.300e-01,
        
        1.000e-02,  1.000e-02,  1.000e-02,  6.000e-02, -1.400e-01,  0.000e+00, -2.000e-02,
        
        3.000e-02,  7.000e-02,  0.000e+00,  2.000e-02, -8.000e-02, 4.000e-02, -1.400e-01,
         
       -7.000e-02, -1.400e-01,  1.900e-01, -1.000e-02,  1.600e-01, -1.200e-01, -5.000e-02,
        
       -1.000e-02, -1.600e-01, -5.000e-02, -5.000e-02, -7.000e-02, 8.100e-01,  8.400e-01,
         
        1.570e+00,  5.500e-01,  9.000e-01,  1.510e+00,  8.700e-01, 8.000e-01,  1.480e+00,
         
        7.300e-01,  8.600e-01,  1.130e+00,  8.800e-01,  1.270e+00, 1.150e+00,  1.030e+00,
         
        1.100e+00,  7.300e-01,  1.300e+00,  8.600e-01,  8.200e-01, 1.350e+00,  6.800e-01,
         
        1.070e+00,  1.210e+00,  8.000e-01,  1.120e+00,  9.400e-01, 8.100e-01,  1.000e+00,
         
        7.100e-01,  1.050e+00,  1.580e+00,  7.900e-01,  9.700e-01, 9.300e-01,  8.800e-01,
         
        1.320e+00,  9.200e-01,  1.230e+00,  1.320e+00,  7.400e-01, 1.030e+00,  1.010e+00,
         
        7.900e-01,  1.030e+00,  1.020e+00,  1.400e+00,  1.220e+00, 1.040e+00,  8.400e-01,
         
        9.600e-01,  7.800e-01,  1.080e+00,  1.140e+00,  1.430e+00, 1.270e+00,  9.300e-01,
         
       6.700e-01,  1.180e+00,  9.200e-01,  1.180e+00,  1.000e+00, 1.070e+00,  1.140e+00,
         
        6.800e-01,  1.030e+00,  1.010e+00,  4.300e-01,  1.120e+00, 1.470e+00,  1.130e+00,
         
        1.570e+00,  1.080e+00,  1.270e+00,  6.200e-01,  3.400e-01, 1.230e+00,  1.270e+00,
         
        1.220e+00,  1.280e+00,  1.120e+00,  9.600e-01,  1.160e+00, 5.800e-01,  1.390e+00,
         
        1.050e+00,  7.600e-01,  1.040e+00,  1.110e+00,  8.100e-01, 1.050e+00,  5.600e-01,
         
        1.140e+00,  1.190e+00,  1.020e+00,  1.470e+00,  1.340e+00, 8.000e-01,  7.200e-01,
         
        1.130e+00,  9.800e-01,  1.600e+00,  7.500e-01,  2.200e+00, 6.590e+00,  7.510e+00,
         
        5.310e+00,  6.770e+00,  3.050e+00,  8.360e+00, -5.500e-01, 1.074e+01,  1.340e+00,
         
        5.190e+00,  7.390e+00,  2.200e+00,  3.720e+00,  6.350e+00, 6.100e-01,  6.230e+00,
         
        6.100e-01,  5.070e+00,  2.500e+00,  2.380e+00,  6.230e+00, 2.080e+00,  2.810e+00,
         
        4.460e+00,  6.700e-01,  3.780e+00,  1.340e+00,  1.280e+00, 4.210e+00,  1.530e+00,
         
        2.200e+00,  4.460e+00,  2.500e+00, -3.100e-01,  5.740e+00, -4.300e-01,  4.210e+00,
        
        1.830e+00,  3.050e+00,  5.430e+00,  2.200e+00,  6.710e+00, 1.710e+00,  5.860e+00,
         
        3.100e-01,  7.870e+00, -1.460e+00,  5.190e+00,  7.900e-01, 4.270e+00,  1.200e-01,
         
        3.360e+00,  2.260e+00,  3.050e+00,  6.100e-01,  4.880e+00, 1.200e-01,  3.110e+00,
         
        3.660e+00,  9.200e-01,  4.820e+00,  3.110e+00,  3.660e+00, 1.650e+00,  6.040e+00,
         
       -8.500e-01,  7.200e+00, -3.700e-01,  7.080e+00,  9.800e-01, 4.640e+00,  1.040e+00,
         
        5.490e+00, -1.800e-01,  5.490e+00,  5.500e-01,  2.140e+00, 7.690e+00, -1.800e-01,
         
        5.860e+00,  2.810e+00,  1.460e+00,  2.990e+00,  5.190e+00, -7.300e-01,  8.360e+00,
        
       -1.950e+00,  7.260e+00, -5.500e-01,  4.150e+00,  1.950e+00, 1.530e+00,  1.890e+00,
         
        3.480e+00,  2.810e+00,  4.520e+00,  4.090e+00,  2.500e+00, 4.880e+00,  5.500e-01,
         
        2.140e+00,  3.050e+00,  2.380e+00, -2.080e+00, -3.540e+00, -7.300e-01, -3.660e+00,
        
       -1.100e+00, -3.600e+00, -6.900e+00, -3.720e+00, -7.930e+00, -5.680e+00, -6.410e+00,
        
       -8.500e-01, -3.910e+00, -3.480e+00, -5.190e+00, -8.180e+00, -4.940e+00, -9.090e+00,
        
       -4.090e+00, -5.620e+00, -5.430e+00, -1.220e+00, -4.210e+00, -2.990e+00, -5.130e+00,
        
       -7.450e+00, -5.680e+00, -7.390e+00, -9.890e+00, -4.700e+00, -6.710e+00, -4.820e+00,
        
       -5.920e+00, -9.030e+00, -7.510e+00, -6.100e+00, -1.025e+01, -5.190e+00, -1.019e+01,
        
       -1.007e+01, -1.044e+01, -1.135e+01, -6.290e+00, -8.180e+00, -7.140e+00, -3.230e+00,
        
       -4.700e+00, -7.750e+00, -8.910e+00, -9.640e+00, -6.710e+00, -6.710e+00, -4.880e+00,
        
       -3.660e+00, -4.330e+00, -1.019e+01, -8.610e+00, -1.331e+01, -8.540e+00, -1.190e+01,
        
       -8.670e+00, -8.420e+00, -1.007e+01, -1.196e+01, -7.260e+00, -9.030e+00, -7.930e+00,
        
       -5.800e+00, -6.470e+00, -3.360e+00, -2.620e+00, -9.700e+00, -9.830e+00, -1.202e+01,
        
       -1.245e+01, -1.239e+01, -8.790e+00, -5.800e+00, -5.250e+00, -1.141e+01, -7.570e+00,
        
      -1.190e+01, -8.730e+00, -1.099e+01, -7.080e+00, -7.570e+00, -5.190e+00, -1.093e+01,
        
       -3.110e+00, -4.460e+00, -7.750e+00, -8.120e+00, -6.290e+00,  -8.300e+00, -7.200e+00,
       
       -7.510e+00, -6.840e+00, -7.810e+00, -7.930e+00, -7.450e+00, -4.880e+00, -6.040e+00,
        
       -1.392e+01, -1.276e+01, -3.480e+00, -4.210e+00, -2.930e+00, -4.520e+00, -3.780e+00,
        
       -4.330e+00, -5.490e+00, -4.700e+00, -5.490e+00, -4.700e+00, -4.700e+00, -4.580e+00,
        
       -3.540e+00, -4.330e+00, -3.970e+00, -4.150e+00, -4.520e+00, -4.390e+00, -5.680e+00,
        
       -5.370e+00, -5.430e+00, -5.920e+00, -5.490e+00, -5.490e+00, -5.490e+00, -5.250e+00,
        
       -5.740e+00, -5.370e+00, -4.820e+00, -5.130e+00, -4.330e+00, -4.150e+00, -4.270e+00,
        
       -3.660e+00, -4.030e+00, -4.210e+00, -3.910e+00, -4.090e+00, -3.910e+00, -3.850e+00,
       
       -3.420e+00, -3.420e+00, -2.930e+00, -2.620e+00, -2.200e+00, -2.080e+00, -2.140e+00,
        
       -1.770e+00, -2.810e+00, -3.170e+00, -2.750e+00, -2.810e+00, -2.380e+00, -2.440e+00,
        
       -2.440e+00, -2.440e+00, -2.500e+00, -2.200e+00, -2.010e+00, -1.710e+00, -1.280e+00,
        
       -7.900e-01, -9.800e-01, -7.300e-01, -8.500e-01, -7.900e-01, -6.100e-01, -6.100e-01,
        
       -2.400e-01, -4.900e-01, -1.100e+00, -9.200e-01, -2.200e+00,  -2.440e+00, -1.590e+00,
       
       -2.560e+00, -7.900e-01, -9.800e-01, -5.500e-01, -6.000e-02, -6.100e-01, -1.160e+00,
        
       -6.700e-01, -1.770e+00, -1.100e+00, -1.040e+00, -1.340e+00, -9.800e-01, -1.280e+00,
        
       -1.460e+00, -1.400e+00, -1.460e+00, -1.460e+00, -1.100e+00, -1.710e+00, -1.340e+00,
        
       -1.770e+00, -1.590e+00, -1.950e+00, -2.140e+00, -1.400e+00, -1.530e+00, -1.950e+00,
        
       -2.010e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
          
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
          
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00,  2.790e+00, 2.790e+00,  2.790e+00,
         
        2.790e+00,  3.160e+00,  3.160e+00,  3.160e+00,  3.160e+00, 3.160e+00,  3.160e+00,
         
        3.160e+00,  3.160e+00,  3.160e+00,  3.160e+00,  3.160e+00, 3.160e+00,  3.160e+00,
         
        3.160e+00,  3.160e+00,  3.160e+00,  3.160e+00,  3.160e+00, 3.160e+00,  3.160e+00
         

                              };   */

in.data_ = {
  
         -5.500e-01,  1.700e-01,  2.100e-01, -2.000e-02, -9.000e-02, 1.500e-01,  3.900e-01,
          
        -1.800e-01,  8.000e-02,  1.800e-01,  3.000e-01,  5.000e-02,
          5.000e-02, -7.000e-02,
         3.800e-01, -9.000e-02,  1.600e-01, -2.100e-01,  9.000e-02,
         -3.100e-01, -1.000e-01,
         1.100e-01, -1.500e-01, -4.200e-01,  7.000e-02, -2.900e-01,
         -1.700e-01, -1.100e-01,
        -4.700e-01,  1.000e-02, -2.200e-01, -1.600e-01, -4.000e-02,
         -3.500e-01, -3.200e-01,
        -5.000e-02, -2.600e-01, -2.300e-01, -2.400e-01,  0.000e+00,
         -4.100e-01,  9.000e-02,
         1.000e-02, -3.900e-01, -9.000e-02, -3.100e-01, -3.100e-01,
         -1.500e-01,  3.000e-02,
        -2.100e-01, -1.000e-02, -1.900e-01, -2.500e-01, -5.000e-02,
         -2.600e-01, -4.300e-01,
        -6.000e-02, -8.000e-02, -4.600e-01,  1.000e-01, -4.300e-01,
         -3.000e-01, -4.000e-02,
        -3.100e-01, -2.600e-01, -9.000e-02, -3.700e-01, -1.000e-01,
         -1.400e-01, -2.000e-01,
        -6.000e-02, -6.000e-01, -8.000e-02, -7.000e-02, -4.400e-01,
          5.000e-02, -2.300e-01,
        -2.900e-01, -5.000e-02, -3.700e-01, -1.500e-01, -2.300e-01,
         -2.700e-01,  3.000e-02,
       -3.700e-01, -5.000e-02, -2.600e-01, -8.000e-02, -8.000e-02,
         -2.600e-01, -1.700e-01,
        -2.600e-01, -1.000e-01, -7.000e-02, -3.800e-01, -7.000e-02,
         -4.600e-01, -1.000e-02,
        -3.900e-01, -1.600e-01, -9.000e-02, -3.900e-01,  1.200e-01,
         -4.100e-01, -1.000e-02,
        -1.600e-01,  3.600e-01, -2.200e-01,  3.300e-01, -2.700e-01,
          2.700e-01, -3.300e-01,
         2.300e-01, -1.200e-01,  4.000e-02, -3.100e-01,  1.900e-01,
         -1.200e-01,  1.200e-01,
        -2.000e-01,  1.200e-01, -1.700e-01,  1.100e-01, -2.100e-01,
          1.600e-01, -6.000e-02,
        -9.000e-02, -7.000e-02,  9.000e-02, -2.300e-01,  0.000e+00,
          4.000e-02, -3.000e-02,
        -1.100e-01, -9.000e-02, -1.000e-02,  8.000e-02, -5.000e-02,
          4.000e-02, -5.000e-02,
        -7.000e-02, -2.000e-02,  4.000e-02, -1.000e-01,  1.000e-02,
         -1.400e-01, -1.100e-01,
        -5.000e-02, -1.000e-02, -1.000e-02, -2.000e-02, -3.000e-02,
         -8.000e-02, -5.000e-02,
        -3.000e-02,  6.000e-02, -4.000e-02, -4.000e-02, -1.000e-02,
          4.000e-02, -4.000e-02,
        -5.000e-02, -8.000e-02, -7.000e-02, -3.000e-02,  1.300e-01,
          8.000e-02,  8.000e-02,
         5.000e-02, -5.000e-02, -1.300e-01,  5.000e-02,  0.000e+00,
         -4.000e-02,  2.000e-02,
        -2.000e-02,  0.000e+00, -1.200e-01,  9.000e-02,  6.000e-02,
         -1.400e-01,  7.000e-02,
        -4.000e-02, -1.200e-01,  8.000e-02,  1.000e-02, -7.000e-02,
         -1.000e-02, -8.000e-02,
        7.000e-02, -1.200e-01,  5.000e-02, -2.000e-02, -3.000e-02,
          4.000e-02, -1.000e-02,
        -3.000e-02, -4.000e-02,  4.000e-02, -1.000e-02,  2.000e-02,
          5.000e-02, -3.000e-02,
        -6.000e-02, -5.000e-02,  8.000e-02, -1.000e-02,  1.000e-02,
          1.280e+00,  1.400e+00,
         1.610e+00,  1.360e+00,  1.460e+00,  1.630e+00,  1.250e+00,
          1.150e+00,  9.200e-01,
         1.100e+00,  7.700e-01,  1.140e+00,  7.500e-01,  1.040e+00,
          9.800e-01,  1.280e+00,
         8.900e-01,  1.050e+00,  1.150e+00,  1.110e+00,  9.700e-01,
          1.270e+00,  9.400e-01,
         1.130e+00,  8.100e-01,  1.270e+00,  8.000e-01,  1.100e+00,
          7.300e-01,  1.110e+00,
         1.270e+00,  9.900e-01,  1.330e+00,  1.100e+00,  6.300e-01,
          8.600e-01,  8.300e-01,
         8.700e-01,  9.000e-01,  1.320e+00,  1.150e+00,  1.040e+00,
          1.380e+00,  7.700e-01,
         1.020e+00,  1.120e+00,  7.800e-01,  1.090e+00,  9.600e-01,
          9.800e-01,  1.110e+00,
         1.160e+00,  8.900e-01,  1.030e+00,  9.500e-01,  8.300e-01,
          1.010e+00,  1.230e+00,
         8.200e-01,  1.310e+00,  1.140e+00,  8.900e-01,  1.270e+00,
          8.500e-01,  1.010e+00,
         7.600e-01,  9.800e-01,  1.000e+00,  9.700e-01,  1.030e+00,
          1.090e+00,  8.900e-01,
         9.000e-01,  1.330e+00,  8.700e-01,  1.080e+00,  1.120e+00,
          7.900e-01,  1.170e+00,
         8.400e-01,  1.080e+00,  1.070e+00,  1.030e+00,  1.120e+00,
          8.800e-01,  9.200e-01,
         1.080e+00,  9.200e-01,  1.200e+00,  8.700e-01,  1.040e+00,
          1.120e+00,  8.800e-01,
         1.080e+00,  7.700e-01,  1.160e+00,  8.500e-01,  1.090e+00,
          1.190e+00,  9.000e-01,
         1.320e+00,  8.100e-01,  1.170e+00,  8.600e-01,  1.447e+01,
          9.800e-01,  1.788e+01,
        -3.700e-01,  1.892e+01,  6.290e+00,  1.605e+01,  4.760e+00,
          1.514e+01,  9.030e+00,
         9.520e+00,  7.020e+00,  1.147e+01,  6.410e+00,  1.080e+01,
          6.960e+00,  1.508e+01,
         3.970e+00,  7.630e+00,  4.820e+00,  6.710e+00,  7.570e+00,
          2.560e+00,  6.350e+00,
         6.770e+00,  3.360e+00,  8.790e+00,  5.620e+00,  5.070e+00,
          5.680e+00,  2.010e+00,
         7.020e+00,  1.590e+00,  6.900e+00,  6.100e-01,  6.350e+00,
         -1.800e-01,  7.140e+00,
         4.900e-01,  5.800e+00,  3.050e+00,  4.580e+00,  5.500e-01,
          7.390e+00, -3.700e-01,
         4.820e+00,  2.690e+00,  4.460e+00,  2.080e+00,  3.910e+00,
          2.750e+00,  2.560e+00,
         2.750e+00,  2.200e+00,  3.050e+00,  2.750e+00,  1.890e+00,
          2.380e+00,  2.200e+00,
         2.140e+00,  8.500e-01,  4.700e+00,  1.400e+00,  3.480e+00,
          4.760e+00,  2.560e+00,
         1.830e+00,  3.780e+00,  1.530e+00,  3.110e+00, -3.700e-01,
          5.070e+00,  1.200e-01,
         1.460e+00,  3.480e+00,  4.090e+00, -2.440e+00,  6.960e+00,
          9.800e-01,  7.300e-01,
         4.210e+00,  2.990e+00,  7.900e-01,  3.110e+00,  1.100e+00,
          2.140e+00,  1.040e+00,
         2.010e+00,  2.440e+00,  1.200e-01,  3.600e+00,  9.800e-01,
          2.810e+00,  6.100e-01,
        4.700e+00,  7.900e-01,  2.260e+00,  3.540e+00,  9.800e-01,
          4.700e+00, -3.700e-01,
         5.740e+00,  1.460e+00,  2.380e+00, -1.471e+01, -2.325e+01,
         -2.014e+01, -2.783e+01,
        -2.710e+01, -3.455e+01, -3.180e+01, -3.339e+01, -3.296e+01,
         -2.972e+01, -2.710e+01,
        -2.356e+01, -2.271e+01, -1.886e+01, -1.752e+01, -1.971e+01,
         -2.106e+01, -2.002e+01,
        -6.100e+00, -5.620e+00, -5.370e+00, -5.310e+00, -8.120e+00,
         -6.900e+00, -9.640e+00,
        -6.710e+00, -7.320e+00, -6.290e+00, -2.260e+00, -2.690e+00,
         -3.110e+00, -5.800e+00,
        -8.910e+00, -1.038e+01, -1.202e+01, -1.001e+01, -8.000e+00,
         -5.980e+00, -6.410e+00,
        -3.780e+00, -4.390e+00, -8.360e+00, -8.180e+00, -8.910e+00,
         -1.099e+01, -1.056e+01,
        -9.640e+00, -9.950e+00, -8.730e+00, -6.900e+00, -8.060e+00,
         -5.070e+00, -7.630e+00,
        -6.900e+00, -4.700e+00, -4.210e+00, -4.460e+00, -2.990e+00,
         -5.550e+00, -7.200e+00,
        -7.630e+00, -9.400e+00, -7.930e+00, -1.044e+01, -5.550e+00,
         -6.100e+00, -5.250e+00,
        -3.540e+00, -2.690e+00, -8.120e+00, -6.590e+00, -4.520e+00,
         -9.160e+00, -4.520e+00,
        -5.310e+00, -6.840e+00, -6.650e+00, -5.800e+00, -5.860e+00,
         -6.960e+00, -5.000e+00,
        -4.640e+00, -7.200e+00, -6.040e+00, -6.290e+00, -7.020e+00,
         -5.250e+00, -6.770e+00,
        -5.980e+00, -7.810e+00, -6.590e+00, -7.200e+00, -8.060e+00,
         -7.260e+00, -6.350e+00,
        -6.530e+00, -5.370e+00, -5.860e+00, -5.130e+00, -7.390e+00,
         -7.320e+00, -7.200e+00,
        -8.910e+00, -8.420e+00,  2.209e+01,  2.197e+01,  2.234e+01,
          2.301e+01,  2.228e+01,
         2.411e+01,  2.313e+01,  2.478e+01,  2.332e+01,  2.411e+01,
          2.277e+01,  2.271e+01,
         2.179e+01,  2.252e+01,  2.032e+01,  2.124e+01,  2.002e+01,
          2.069e+01, -1.770e+00,
        -2.140e+00, -2.690e+00, -2.690e+00, -2.260e+00, -2.810e+00,
         -2.930e+00, -3.230e+00,
        -4.460e+00, -4.580e+00, -4.700e+00, -4.880e+00, -4.880e+00,
         -5.070e+00, -4.880e+00,
        -4.520e+00, -4.390e+00, -5.000e+00, -4.270e+00, -5.190e+00,
         -5.130e+00, -4.820e+00,
        -5.680e+00, -5.860e+00, -5.680e+00, -6.840e+00, -5.920e+00,
         -6.100e+00, -6.230e+00,
        -5.920e+00, -6.040e+00, -6.350e+00, -5.430e+00, -5.490e+00,
         -5.550e+00, -5.250e+00,
        -5.190e+00, -5.130e+00, -5.130e+00, -4.820e+00, -4.880e+00,
         -4.940e+00, -4.640e+00,
        -4.640e+00, -4.090e+00, -3.660e+00, -3.230e+00, -2.990e+00,
         -2.620e+00, -2.870e+00,
        -3.110e+00, -3.050e+00, -2.750e+00, -2.260e+00, -2.440e+00,
         -1.830e+00, -2.870e+00,
        -2.560e+00, -2.320e+00, -3.170e+00, -2.690e+00, -2.690e+00,
         -2.810e+00, -2.620e+00,
        -2.620e+00, -2.750e+00, -2.620e+00, -2.620e+00, -2.080e+00,
         -2.440e+00, -1.950e+00,
        -2.010e+00, -1.650e+00, -2.140e+00, -1.950e+00, -1.590e+00,
         -2.380e+00, -1.590e+00,
        -1.710e+00, -1.530e+00, -1.650e+00, -1.460e+00, -1.100e+00,
         -1.530e+00, -7.900e-01,
        -7.900e-01,  1.140e+00,  1.140e+00,  1.140e+00,  1.140e+00,
          1.140e+00,  1.140e+00,
         1.140e+00,  1.140e+00,  1.140e+00,  1.140e+00,  1.140e+00,
          1.140e+00,  1.140e+00,
         1.140e+00,  1.140e+00,  1.140e+00,  1.140e+00,  1.140e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
        6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00,
         6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,  6.600e+00,
          6.600e+00,  6.600e+00
  
  };

    Tensor out;
    model.Apply(&in, &out);
    // Returns "Jumping"
    std::cout << softmax_to_label(out.data_) << std::endl;
    //std::cout << &out << std::endl;
    return 0;
}

void setup(){
  
  Serial.begin(9600);
  
  }

void loop(){
  long int t1 = millis();
  Serial.print(main());
  long int t2 = millis();
  Serial.print("Time taken by the task: "); Serial.print(t2-t1); Serial.println(" milliseconds");
  }
