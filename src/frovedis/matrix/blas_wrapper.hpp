#ifndef _BLAS_WRAPPER_
#define _BLAS_WRAPPER_

#include "sliced_vector.hpp"

extern "C" {

void sswap_(int *N,
            float *X, int *INCX,
            float *Y, int *INCY);

void dswap_(int *N,
            double *X, int *INCX,
            double *Y, int *INCY);

void sgemv_(char *TRANS,
            int *M, int *N,
            float *ALPHA,
            float *A, int *LDA,
            float *X, int *INCX,
            float *BETA,
            float *Y, int *INCY);

void dgemv_(char *TRANS,
            int *M, int *N,
            double *ALPHA,
            double *A, int *LDA,
            double *X, int *INCX,
            double *BETA,
            double *Y, int *INCY);

void sger_(int *M,
           int *N,
           float *ALPHA,
           float *X, int *INCX,
           float *Y, int *INCY,
           float *A, int *LDA);

void dger_(int *M,
           int *N,
           double *ALPHA,
           double *X, int *INCX,
           double *Y, int *INCY,
           double *A, int *LDA);

void sgemm_(char *TRANSA,
            char *TRANSB,
            int *M, int *N, int *K,
            float *ALPHA,
            float *A, int *LDA,
            float *B, int *LDB,
            float *BETA,
            float *C, int *LDC);

void dgemm_(char *TRANSA,
            char *TRANSB,
            int *M, int *N, int *K,
            double *ALPHA,
            double *A, int *LDA,
            double *B, int *LDB,
            double *BETA,
            double *C, int *LDC);

}


namespace frovedis {

  template <class T>
  void swap(const sliced_colmajor_vector_local<T>& vec1,
            const sliced_colmajor_vector_local<T>& vec2);
   
  template <>
  void swap(const sliced_colmajor_vector_local<float>& vec1,
            const sliced_colmajor_vector_local<float>& vec2);
   
  template <>
  void swap(const sliced_colmajor_vector_local<double>& vec1,
            const sliced_colmajor_vector_local<double>& vec2);

  template <class T>
  void scal(const sliced_colmajor_vector_local<T>& vec,
            T alpha);
  
  template <>
  void scal(const sliced_colmajor_vector_local<float>& vec,
            float alpha);

  template <>
  void scal(const sliced_colmajor_vector_local<double>& vec,
            double alpha);
   
  
  template <class T>
  void axpy(const sliced_colmajor_vector_local<T>& inVec,
            const sliced_colmajor_vector_local<T>& outVec,
            T alpha = 1.0);
  
  template <>
  void axpy(const sliced_colmajor_vector_local<float>& inVec,
            const sliced_colmajor_vector_local<float>& outVec,
            float alpha);

  template <>
  void axpy(const sliced_colmajor_vector_local<double>& inVec,
            const sliced_colmajor_vector_local<double>& outVec,
            double alpha);

    
  template <class T>
  void copy(const sliced_colmajor_vector_local<T>& inVec,
            const sliced_colmajor_vector_local<T>& outVec);
  
  template <>
  void copy(const sliced_colmajor_vector_local<float>& inVec,
            const sliced_colmajor_vector_local<float>& outVec);

  template <>
  void copy(const sliced_colmajor_vector_local<double>& inVec,
            const sliced_colmajor_vector_local<double>& outVec);

  
  template <class T>
  T dot(const sliced_colmajor_vector_local<T>& inVec1,
        const sliced_colmajor_vector_local<T>& inVec2);
  
  template <>
  float dot(const sliced_colmajor_vector_local<float>& inVec1,
            const sliced_colmajor_vector_local<float>& inVec2);

  template <>
  double dot(const sliced_colmajor_vector_local<double>& inVec1,
             const sliced_colmajor_vector_local<double>& inVec2);

    
  template <class T>
  T nrm2(const sliced_colmajor_vector_local<T>& inVec);
  
  template <>
  float nrm2(const sliced_colmajor_vector_local<float>& inVec);

  template <>
  double nrm2(const sliced_colmajor_vector_local<double>& inVec);

  
  template <class T>
  void gemv(const sliced_colmajor_matrix_local<T>& inMat,
            const sliced_colmajor_vector_local<T>& inVec,
            const sliced_colmajor_vector_local<T>& outVec,
            char TRANS = 'N',
            T alpha = 1.0,
            T beta = 0.0);
  
  template <>
  void gemv(const sliced_colmajor_matrix_local<float>& inMat,
            const sliced_colmajor_vector_local<float>& inVec,
            const sliced_colmajor_vector_local<float>& outVec,
            char TRANS,
            float alpha,
            float beta);

  template <>
  void gemv(const sliced_colmajor_matrix_local<double>& inMat,
            const sliced_colmajor_vector_local<double>& inVec,
            const sliced_colmajor_vector_local<double>& outVec,
            char TRANS,
            double alpha,
            double beta);

  
  template <class T>
  void ger(const sliced_colmajor_vector_local<T>& inVec1,
           const sliced_colmajor_vector_local<T>& inVec2,
           const sliced_colmajor_matrix_local<T>& outMat,
           T alpha = 1.0);
  
  template <>
  void ger(const sliced_colmajor_vector_local<float>& inVec1,
           const sliced_colmajor_vector_local<float>& inVec2,
           const sliced_colmajor_matrix_local<float>& outMat,
           float alpha);

  template <>
  void ger(const sliced_colmajor_vector_local<double>& inVec1,
           const sliced_colmajor_vector_local<double>& inVec2,
           const sliced_colmajor_matrix_local<double>& outMat,
           double alpha);

  
  template <class T>
  void gemm(const sliced_colmajor_matrix_local<T>& inMat1,
            const sliced_colmajor_matrix_local<T>& inMat2,
            const sliced_colmajor_matrix_local<T>& outMat,
            char TRANS_M1 = 'N',
            char TRANS_M2 = 'N',
            T alpha = 1.0,
            T beta = 0.0);
  
  template <>
  void gemm(const sliced_colmajor_matrix_local<float>& inMat1,
            const sliced_colmajor_matrix_local<float>& inMat2,
            const sliced_colmajor_matrix_local<float>& outMat,
            char TRANS_M1,
            char TRANS_M2,
            float alpha,
            float beta);

  template <>
  void gemm(const sliced_colmajor_matrix_local<double>& inMat1,
            const sliced_colmajor_matrix_local<double>& inMat2,
            const sliced_colmajor_matrix_local<double>& outMat,
            char TRANS_M1,
            char TRANS_M2,
            double alpha,
            double beta);

  // This routine can be used to perform the below operation:
  //   (*) rowmajor_matrix_local * rowmajor_matrix_local
  template <class T>
  rowmajor_matrix_local<T> 
  operator* (const rowmajor_matrix_local<T>& inMat1,
             const rowmajor_matrix_local<T>& inMat2){

    sliced_colmajor_matrix_local<T> sm1(inMat1.val);
    sm1.ldm = inMat1.local_num_col;
    sm1.sliced_num_row = inMat1.local_num_col;
    sm1.sliced_num_col = inMat1.local_num_row;
    sliced_colmajor_matrix_local<T> sm2(inMat2.val);
    sm2.ldm = inMat2.local_num_col;
    sm2.sliced_num_row = inMat2.local_num_col;
    sm2.sliced_num_col = inMat2.local_num_row;

    auto out = sm2 * sm1;
    rowmajor_matrix_local<T> ret(out.val);
    ret.set_local_num(inMat1.local_num_row, inMat2.local_num_col);

    return ret;
  }

  // This routine can be used to perform the below operation:
  //   (*) colmajor_matrix_local * colmajor_matrix_local
  template <class T>
  colmajor_matrix_local<T> 
  operator* (const colmajor_matrix_local<T>& inMat1,
             const colmajor_matrix_local<T>& inMat2){

    sliced_colmajor_matrix_local<T> sm1(inMat1);
    sliced_colmajor_matrix_local<T> sm2(inMat2);
    return sm1 * sm2;
  }

  // This routine can be used to perform the below operation:
  //   (*) colmajor_matrix_local * sliced_matrix_local
  template <class T>
  colmajor_matrix_local<T> 
  operator* (const colmajor_matrix_local<T>& inMat1,
             const sliced_colmajor_matrix_local<T>& inMat2){

    sliced_colmajor_matrix_local<T> sm1(inMat1);
    return sm1 * inMat2;
  }

  // This routine can be used to perform the below operation:
  //   (*) sliced_matrix_local * colmajor_matrix_local
  template <class T>
  colmajor_matrix_local<T> 
  operator* (const sliced_colmajor_matrix_local<T>& inMat1,
             const colmajor_matrix_local<T>& inMat2){

    sliced_colmajor_matrix_local<T> sm2(inMat2);
    return inMat1 * sm2;
  }

  // This routine can be used to perform the below operation:
  //   (*) sliced_matrix_local * sliced_matrix_local
  template <class T>
  colmajor_matrix_local<T> 
  operator* (const sliced_colmajor_matrix_local<T>& inMat1,
             const sliced_colmajor_matrix_local<T>& inMat2){

   if(!inMat1.is_valid() || !inMat2.is_valid())
     REPORT_ERROR(USER_ERROR,"Invalid input matrix!!\n");

   if(inMat1.sliced_num_col != inMat2.sliced_num_row)
     REPORT_ERROR(USER_ERROR,
        "Incompatible input sizes: Matrix-multiplication not possible!!\n");

   colmajor_matrix_local<T> res_mat(inMat1.sliced_num_row,
                                    inMat2.sliced_num_col);
   gemm<T>(inMat1,inMat2,res_mat);

   return res_mat;
  }

  template <class T>
  colmajor_matrix_local<T>
  operator~ (const colmajor_matrix_local<T>& inMat) {
     sliced_colmajor_matrix_local<T> s_mat(inMat);
     return ~s_mat;
  }

  template <class T>
  colmajor_matrix_local<T>
  operator~ (const sliced_colmajor_matrix_local<T>& inMat) {

    size_t nrow = inMat.sliced_num_row;
    size_t ncol = inMat.sliced_num_col;
    colmajor_matrix_local<T> ret(ncol,nrow);

    T* retp = &ret.val[0];
    const T* valp = inMat.data;

    // 'inMat' is a sliced colmajor matrix. Therefore the stride between 
    // two consecutive elements in a row can be large in some cases.
    // So, loop interchange is performed for better performance.
    for(size_t j = 0; j < ncol; j++) 
      for(size_t i = 0; i < nrow; i++) 
        retp[j + ncol * i] = valp[i + inMat.ldm * j];

    return ret;
  }

}

#endif
