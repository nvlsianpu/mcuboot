/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2024 Nordic Semiconductor ASA
 *
 * Original license:
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/**
 * @file
 * @brief Transactional multi-image update scheme
 *
 * TBD
 */

#ifndef H_TRANSACTION_IMAGE
#define H_TRANSACTION_IMAGE

enum mcuboot_transacion_state {
    MTS_UNDEF = 0,
    MTS_INSTALLED,
    MTS_REQUEST,
    MTS_PRESERVE_MANIFEST,
    MTS_PRESERVE_MAIN_ENDING,
    MTS_SWAP_MAIN,
    MTS_SWAP_MNIFEST,
    MTS_SWAP_REST,
    MTS_TEST,
    MTS_REVERT_DETECION,
    MTS_REVERT_MAIN,
    MTS_REVERT_MANIFEST,
    MTS_REVERT_REST
};

/* Firmware Maifest
 *
 * Transaction package description: Firmware package description which describes firmware package requirements.
 * It starts with the header which is followed by TLVs.
 * TLVs encodes:
 * - images requiremnts
 * - manifest SHA, always second to last TLV, calculated over all manifest bytes before this TLV. Uses the sam format as image TLVs.
 * - manifest signature, the last TLV in the manifest. Uses the sam format as image TLVs.
 */

#define MANIFEST_MAGIC 0xeb437502

/** package description format */
struct transaction_manifest_header {
    uint32_t tm_magic;
    uint16_t tm_version;
    uint16_t tm_protected_size; /* size of manifest, includes all, but SHA and signature TLVs */
    uint16_t tm_size; /* size of manifest, includes all fields */
    uint16_t _pad1;
} __packed;


#define MANIFEST_TLV_SHA_REQ 0x16

struct img_sha_requrement_head {
    uint8_t image_id;  /* Image index (from 0) */
    uint8_t _pad1;
    uint16_t sha_type; /* IMAGE_TLV_SHA256, IMAGE_TLV_SHA38 (EXPECTED_HASH_TLV) */
    uint8_t sha[]; /* size associated with sha type */
} __packed;


#endif /*H_TRANSACTION_IMAGE*/
