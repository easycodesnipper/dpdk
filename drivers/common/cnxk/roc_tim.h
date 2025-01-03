/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(C) 2021 Marvell.
 */

#ifndef _ROC_TIM_H_
#define _ROC_TIM_H_

#include "roc_platform.h"

enum roc_tim_clk_src {
	ROC_TIM_CLK_SRC_10NS = 0,
	ROC_TIM_CLK_SRC_GPIO,
	ROC_TIM_CLK_SRC_GTI,
	ROC_TIM_CLK_SRC_PTP,
	ROC_TIM_CLK_SRC_SYNCE,
	ROC_TIM_CLK_SRC_BTS,
	ROC_TIM_CLK_SRC_EXT_MIO,
	ROC_TIM_CLK_SRC_EXT_GTI,
	ROC_TIM_CLK_SRC_INVALID,
};

struct roc_tim_hwwqe_cfg {
	uint8_t grp_ena;
	uint8_t hwwqe_ena;
	uint8_t flw_ctrl_ena;
	uint16_t grp_tmo_cyc;
	uint16_t result_offset;
	uint16_t event_count_offset;
};

struct roc_tim {
	struct roc_sso *roc_sso;
	/* Public data. */
	uint16_t nb_lfs;
	struct tim_feat_info feat;
	/* Private data. */
#define TIM_MEM_SZ (1 * 1024)
	uint8_t reserved[TIM_MEM_SZ] __plt_cache_aligned;
} __plt_cache_aligned;

int __roc_api roc_tim_init(struct roc_tim *roc_tim);
void __roc_api roc_tim_fini(struct roc_tim *roc_tim);

/* TIM config */
int __roc_api roc_tim_lf_enable(struct roc_tim *roc_tim, uint8_t ring_id,
				uint64_t *start_tsc, uint32_t *cur_bkt);
int __roc_api roc_tim_lf_disable(struct roc_tim *roc_tim, uint8_t ring_id);
int __roc_api roc_tim_lf_config(struct roc_tim *roc_tim, uint8_t ring_id,
				enum roc_tim_clk_src clk_src, uint8_t ena_periodic, uint8_t ena_dfb,
				uint32_t bucket_sz, uint32_t chunk_sz, uint64_t interval,
				uint64_t intervalns, uint64_t clockfreq);
int __roc_api roc_tim_lf_config_hwwqe(struct roc_tim *roc_tim, uint8_t ring_id,
				      struct roc_tim_hwwqe_cfg *cfg);
int __roc_api roc_tim_lf_interval(struct roc_tim *roc_tim,
				  enum roc_tim_clk_src clk_src,
				  uint64_t clockfreq, uint64_t *intervalns,
				  uint64_t *interval);
int __roc_api roc_tim_lf_alloc(struct roc_tim *roc_tim, uint8_t ring_id,
			       uint64_t *clk);
int __roc_api roc_tim_lf_free(struct roc_tim *roc_tim, uint8_t ring_id);
uintptr_t __roc_api roc_tim_lf_base_get(struct roc_tim *roc_tim,
					uint8_t ring_id);
int roc_tim_capture_counters(struct roc_tim *roc_tim, uint64_t *counters, uint8_t nb_cntrs);

#endif
