/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2019-2020 Intel Corporation
 */

#ifndef _IGC_LOGS_H_
#define _IGC_LOGS_H_

#include <rte_log.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int igc_logtype_init;
extern int igc_logtype_driver;
#define RTE_LOGTYPE_IGC_DRIVER igc_logtype_driver

#define PMD_INIT_LOG(level, fmt, args...) \
	rte_log(RTE_LOG_ ## level, igc_logtype_init, \
		"%s(): " fmt "\n", __func__, ##args)

#define PMD_INIT_FUNC_TRACE() PMD_INIT_LOG(DEBUG, " >>")

#ifdef RTE_ETHDEV_DEBUG_RX
#define PMD_RX_LOG(level, fmt, args...) \
	RTE_LOG(level, IGC_DRIVER, "%s(): " fmt "\n", __func__, ## args)
#else
#define PMD_RX_LOG(level, fmt, args...) do { } while (0)
#endif

#ifdef RTE_ETHDEV_DEBUG_TX
#define PMD_TX_LOG(level, fmt, args...) \
	RTE_LOG(level, IGC_DRIVER, "%s(): " fmt "\n", __func__, ## args)
#else
#define PMD_TX_LOG(level, fmt, args...) do { } while (0)
#endif

#define PMD_DRV_LOG(level, fmt, args...) \
	RTE_LOG(level, IGC_DRIVER, "%s(): " fmt "\n", __func__, ## args)

#ifdef __cplusplus
}
#endif

#endif /* _IGC_LOGS_H_ */
