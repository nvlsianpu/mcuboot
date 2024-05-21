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

#include <stddef.h>
#include <stdint.h>

#include "bootutil/transaction_image.h"

bool manifest_validate(const struct flash_area *fap, uint32_t off)
{

	struct transaction_manifest_header hdr;
	int rc;

	rc = flash_area_read(fap, off, hdr, sizeof hdr);

	if (hdr.tm_magic != MANIFEST_MAGIC) {
		return false;
	}

}