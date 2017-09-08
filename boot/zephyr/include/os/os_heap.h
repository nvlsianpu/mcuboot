/*
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

#ifndef H_OS_HEAP_
#define H_OS_HEAP_

#ifdef __ZEPHYR__
#include <zephyr.h>
#else
#include <stddef.h>
#endif // __ZEPHYR__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __ZEPHYR__

#define os_malloc k_malloc
#define os_free k_free
#define os_realloc k_realloc

#else

void *os_malloc(size_t size);
void os_free(void *mem);
void *os_realloc(void *ptr, size_t size);

#endif // __ZEPHYR__

#ifdef __cplusplus
}
#endif


#endif

