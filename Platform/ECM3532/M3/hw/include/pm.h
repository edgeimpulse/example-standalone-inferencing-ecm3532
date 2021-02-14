/*******************************************************************************
 *
 * Copyright (C) 2019 Eta Compute, Inc
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************/
#include <stdint.h>

#define DVFS_OPP 1
#define CPU_LOAD 2
#define CONFIG_PM_TIMER_CH_NO (3)

extern void send_mon_event(uint32_t ev, uint32_t param);
extern int init_mon_tasks(void);
int ecm35xx_pre_lpm(uint32_t sticks);
int ecm35xx_post_lpm(uint32_t sticks);
int ecm35xx_enter_lpm(uint32_t sticks);
unsigned long ecm35xx_get_curr_freq(void);
int ecm35xx_pwrg_init(int hw_tmr);