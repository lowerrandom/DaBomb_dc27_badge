/*-
 * Copyright (c) 2017-2019
 *      Bill Paul <wpaul@windriver.com>.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Bill Paul.
 * 4. Neither the name of the author nor the names of any co-contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "ch.h"
#include "hal.h"
#include "flash.h"

#include <string.h>

void
flashStart (void)
{
	while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
		;
	return;
}

void
flashErase (uint8_t * buf)
{
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Een;
	NRF_NVMC->ERASEPAGE = (uint32_t)buf;
	while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
		;
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren;
	return;
}

void
flashProgram (uint8_t * src, uint8_t * dst)
{
	uint32_t * s;
	uint32_t * d;
	unsigned i;

	s = (uint32_t *)src;
	d = (uint32_t *)dst;

	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Wen;

	for (i = 0; i < (FLASH_PAGE_SIZE / sizeof(uint32_t)); i++)
		d[i] = s[i];

	while (NRF_NVMC->READY == NVMC_READY_READY_Busy)
		;
	NRF_NVMC->CONFIG = NVMC_CONFIG_WEN_Ren;
	return;
}
