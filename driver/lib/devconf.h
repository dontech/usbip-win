#pragma once

#include <ntddk.h>
#include <usbdi.h>

#define NEXT_DESC(dsc)			(PUSB_COMMON_DESCRIPTOR)((PUCHAR)(dsc) + ((PUSB_COMMON_DESCRIPTOR)dsc)->bLength)
#define NEXT_DESC_INTF(dsc)		(PUSB_INTERFACE_DESCRIPTOR)NEXT_DESC(dsc)
#define NEXT_DESC_EP(dsc)		(PUSB_ENDPOINT_DESCRIPTOR)NEXT_DESC(dsc)

PUSB_INTERFACE_DESCRIPTOR
dsc_find_intf(PUSB_CONFIGURATION_DESCRIPTOR dsc_conf, UCHAR intf_num, USHORT alt_setting);

PUSB_ENDPOINT_DESCRIPTOR
dsc_next_ep(PUSB_CONFIGURATION_DESCRIPTOR dsc_conf, PVOID start);

ULONG
dsc_conf_get_n_intfs(PUSB_CONFIGURATION_DESCRIPTOR dsc_conf);