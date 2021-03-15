/**
 * @file    target_reset_mimxrt.c
 * @brief   Target reset for the i.MX RT series
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

#include "target_reset.h"
#include "swd_host.h"
#include "info.h"


void target_before_init_debug(void)
{
    // This is for the hardware conflict (the EVK are not consider >2 debugger connection
    // situation) with another external debugger(such as JLINK). Before drag&pull, issue a
    // hardware reset to bring the platform to a known state and also force
    // RESET pin to high state ensure a successfully access.

    volatile uint32_t i;
    uint32_t delay_count;

    #if defined(INTERFACE_K20D5)
    delay_count = 0x20000;
    #elif defined(INTERFACE_STM32F103XB)
    delay_count = 0x20000;
    #endif

    swd_set_target_reset(1);
    i = 0;
    while (i < delay_count) {
        i++;
    }
    
    swd_set_target_reset(0);
    i = 0;
    while (i < delay_count) {
        i++;
    }
}

void board_init(void)
{
}

uint8_t target_unlock_sequence(void)
{
    return 1;
}

uint8_t security_bits_set(uint32_t addr, uint8_t *data, uint32_t size)
{
    return 0;
}

uint8_t target_set_state(TARGET_RESET_STATE state)
{
    return swd_set_target_state_sw(state);
}
