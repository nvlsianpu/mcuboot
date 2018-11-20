/*
 * Copyright (c) 2018 Runtime Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __MCUBOOT_LOGGING_H__
#define __MCUBOOT_LOGGING_H__

#ifndef __BOOTSIM__

/*
 * When building for targets running Zephyr, delegate to its native
 * logging subsystem.
 *
 * In this case:
 *
 * - MCUBOOT_LOG_LEVEL determines LOG_LEVEL,
 * - MCUBOOT_LOG_ERR() and friends are LOG_ERR() etc.
 * - LOG_DOMAIN is unconditionally set to "MCUBOOT"
 */
#define MCUBOOT_LOG_LEVEL_OFF      LOG_LEVEL_OFF
#define MCUBOOT_LOG_LEVEL_ERROR    LOG_LEVEL_ERR
#define MCUBOOT_LOG_LEVEL_WARNING  LOG_LEVEL_WRN
#define MCUBOOT_LOG_LEVEL_INFO     LOG_LEVEL_INF
#define MCUBOOT_LOG_LEVEL_DEBUG    LOG_LEVEL_DBG

/* Treat MCUBOOT_LOG_LEVEL equivalently to LOG_LEVEL. */
#ifndef MCUBOOT_LOG_LEVEL
#define MCUBOOT_LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#elif (MCUBOOT_LOG_LEVEL < CONFIG_LOG_OVERRIDE_LEVEL)
#undef MCUBOOT_LOG_LEVEL
#define MCUBOOT_LOG_LEVEL CONFIG_LOG_OVERRIDE_LEVEL
#endif

#define LOG_LEVEL MCUBOOT_LOG_LEVEL

#undef LOG_DOMAIN
#define LOG_DOMAIN "MCUBOOT"

#define MCUBOOT_LOG_ERR(...) LOG_ERR(__VA_ARGS__)
#define MCUBOOT_LOG_WRN(...) LOG_WRN(__VA_ARGS__)
#define MCUBOOT_LOG_INF(...) LOG_INF(__VA_ARGS__)
#define MCUBOOT_LOG_DBG(...) LOG_DBG(__VA_ARGS__)

#include <logging/log.h>

#endif /* !__BOOTSIM__ */

#endif /* __MCUBOOT_LOGGING_H__ */
