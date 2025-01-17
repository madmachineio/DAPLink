/**
 * @file    mtb_stm32l475.c
 * @brief   board ID for the mtb_stm32l475
 *
 * DAPLink Interface Firmware
 * Copyright (c) 2009-2016, ARM Limited, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "target_config.h"
#include "flash_manager.h"
#include "swd_host.h"

const char *board_id = "0468";

target_cfg_t target_device;
extern target_cfg_t target_device_stm32l475;

void prerun_board_config(void)
{
    target_device = target_device_stm32l475;
    flash_manager_set_page_erase(true);
    swd_set_reset_connect(CONNECT_UNDER_RESET);
}
