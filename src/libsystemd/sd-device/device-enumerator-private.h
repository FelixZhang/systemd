/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

/***
  This file is part of systemd.

  Copyright 2015 Tom Gundersen <teg@jklm.no>
***/

#include "sd-device.h"

int device_enumerator_scan_devices(sd_device_enumerator *enumeartor);
int device_enumerator_scan_subsystems(sd_device_enumerator *enumeartor);
int device_enumerator_add_device(sd_device_enumerator *enumerator, sd_device *device);
int device_enumerator_add_match_is_initialized(sd_device_enumerator *enumerator);
sd_device *device_enumerator_get_first(sd_device_enumerator *enumerator);
sd_device *device_enumerator_get_next(sd_device_enumerator *enumerator);

#define FOREACH_DEVICE_AND_SUBSYSTEM(enumerator, device)       \
        for (device = device_enumerator_get_first(enumerator); \
             device;                                           \
             device = device_enumerator_get_next(enumerator))
