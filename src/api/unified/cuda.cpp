/*******************************************************
 * Copyright (c) 2019, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include "symbol_manager.hpp"
#include <af/backend.h>

#define AF_DEFINE_CUDA_TYPES
#include <af/cuda.h>

af_err afcu_get_stream(cudaStream_t* stream, int id) {
    af_backend backend;
    af_get_active_backend(&backend);
    if(backend == AF_BACKEND_CUDA) {
        return CALL(stream, id);
    }
    return AF_ERR_NOT_SUPPORTED;
}

af_err afcu_get_native_id(int* nativeid, int id) {
    af_backend backend;
    af_get_active_backend(&backend);
    if(backend == AF_BACKEND_CUDA) {
        return CALL(nativeid, id);
    }
    return AF_ERR_NOT_SUPPORTED;
}


af_err afcu_set_native_id(int nativeid) {
    af_backend backend;
    af_get_active_backend(&backend);
    if(backend == AF_BACKEND_CUDA) {
        return CALL(nativeid);
    }
    return AF_ERR_NOT_SUPPORTED;
}


af_err afcu_cublasSetMathMode(cublasMath_t mode) {
    af_backend backend;
    af_get_active_backend(&backend);
    if(backend == AF_BACKEND_CUDA) {
        return CALL(mode);
    }
    return AF_ERR_NOT_SUPPORTED;
}
