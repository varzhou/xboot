/*
 * resource/res-uart.c
 *
 * Copyright(c) 2007-2013 jianjun jiang <jerryjianjun@gmail.com>
 * official site: http://xboot.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <xboot.h>
#include <realview-uart.h>

static struct realview_uart_t rus[] = {
	[0] = {
		.baud		= B115200,
		.data		= DATA_BITS_8,
		.parity		= PARITY_NONE,
		.stop		= STOP_BITS_1,
		.base		= REALVIEW_UART0_BASE,
	},
	[1] = {
		.baud		= B115200,
		.data		= DATA_BITS_8,
		.parity		= PARITY_NONE,
		.stop		= STOP_BITS_1,
		.base		= REALVIEW_UART1_BASE,
	},
	[2] = {
		.baud		= B115200,
		.data		= DATA_BITS_8,
		.parity		= PARITY_NONE,
		.stop		= STOP_BITS_1,
		.base		= REALVIEW_UART2_BASE,
	},
	[3] = {
		.baud		= B115200,
		.data		= DATA_BITS_8,
		.parity		= PARITY_NONE,
		.stop		= STOP_BITS_1,
		.base		= REALVIEW_UART3_BASE,
	}
};

static struct resource_t res_uarts[] = {
	{
		.name		= "uart",
		.id			= 0,
		.data		= &rus[0],
	}, {
		.name		= "uart",
		.id			= 1,
		.data		= &rus[1],
	}, {
		.name		= "uart",
		.id			= 2,
		.data		= &rus[2],
	}, {
		.name		= "uart",
		.id			= 3,
		.data		= &rus[3],
	}
};

static __init void res_uart_init(void)
{
	u32_t i;

	for(i = 0; i < ARRAY_SIZE(res_uarts); i++)
	{
		if(register_resource(&res_uarts[i]))
			LOG("Register serial resource '%s.%d'", res_uarts[i].name, res_uarts[i].id);
		else
			LOG("Failed to register serial resource '%s.%d'", res_uarts[i].name, res_uarts[i].id);
	}
}

static __exit void res_uart_exit(void)
{
	u32_t i;

	for(i = 0; i < ARRAY_SIZE(res_uarts); i++)
	{
		if(unregister_resource(&res_uarts[i]))
			LOG("Unregister serial resource '%s.%d'", res_uarts[i].name, res_uarts[i].id);
		else
			LOG("Failed to unregister serial resource '%s.%d'", res_uarts[i].name, res_uarts[i].id);
	}
}

core_initcall(res_uart_init);
core_exitcall(res_uart_exit);
