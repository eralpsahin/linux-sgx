/*
 * Copyright (C) 2011-2019 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _MM_VRD_UTIL_H_
#define _MM_VRD_UTIL_H_

#include <stddef.h>         // for size_t
#include <stdbool.h>
#include "arch.h"           // si_flags_t
#include "se_types.h"
#include "sgx_error.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline void tedmm_set_error(sgx_status_t* var, sgx_status_t value)
{
    if (var)
        *var = value;
}

si_flags_t convert_protect_to_si_flags(uint32_t protect, bool modified, bool pending, bool perm_reduced);
uint32_t convert_si_flags_to_protect(si_flags_t si);

int accept_modified_pages(void* addr, size_t n_pages, si_flags_t si_flags);
int accept_pending_pages(void* addr, size_t n_pages);
int emodpe_pages(void* addr, size_t n_pages, si_flags_t si_flags);

#ifdef __cplusplus
}
#endif

#endif

