/**
 * @file    target.c
 * @brief   Target information for the nrf51
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

// The file flash_blob.c must only be included in target.c
#include "flash_blob.c"

// target information
target_cfg_t target_device = {  // Default is nRF51
    .sector_size        = 1024,
    .sector_cnt         = (KB(256) / 1024),
    .flash_start        = 0,
    .flash_end          = KB(256),
    .ram_start          = 0x20000000,
    .ram_end            = 0x20004000,
    .flash_algo         = (program_target_t *) &flash,
    .erase_reset        = 1,
};

target_cfg_t target_device_nrf52 = {
    .sector_size        = 4096,
    .sector_cnt         = (KB(512) / 4096),
    .flash_start        = 0,
    .flash_end          = KB(512),
    .ram_start          = 0x20000000,
    .ram_end            = 0x20008000,
    .flash_algo         = (program_target_t *) &flash_nrf52,
    .erase_reset        = 1,
};

target_cfg_t target_device_nrf52840 = {
    .sector_size        = 4096,
    .sector_cnt         = (KB(1024) / 4096),
    .flash_start        = 0,
    .flash_end          = KB(1024),
    .ram_start          = 0x20000000,
    .ram_end            = 0x20008000,
    .flash_algo         = (program_target_t *) &flash_nrf52,
    .erase_reset        = 1,
};

target_cfg_t target_device_nrf52840_256 = {
    .sector_size        = 4096,
    .sector_cnt         = (KB(1024) / 4096),
    .flash_start        = 0,
    .flash_end          = KB(1024),
    .ram_start          = 0x20000000,
    .ram_end            = 0x20040000,
    .flash_algo         = (program_target_t *) &flash_nrf52,
    .erase_reset        = 1,
};

target_cfg_t target_device_nrf52_64 = {
    .sector_size        = 4096,
    .sector_cnt         = (KB(512) / 4096),
    .flash_start        = 0,
    .flash_end          = KB(512),
    .ram_start          = 0x20000000,
    .ram_end            = 0x20010000,
    .flash_algo         = (program_target_t *) &flash_nrf52,
    .erase_reset        = 1,
};