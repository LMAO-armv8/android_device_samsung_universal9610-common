/*
 * Copyright (C) 2020 LineageOS
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _BDROID_BUILDCFG_H
#define _BDROID_BUILDCFG_H

#pragma push_macro("PROPERTY_VALUE_MAX")

#include <cutils/properties.h>
#include <string.h>

static inline const char* BtmGetDefaultName()
{
    char product_device[PROPERTY_VALUE_MAX];
    property_get("ro.product.device", product_device, "");

    if (strstr(product_device, "a51"))
        return "Galaxy A51";
    if (strstr(product_device, "m21"))
        return "Galaxy M21";
    if (strstr(product_device, "f41"))
        return "Galaxy F41";
    if (strstr(product_device, "m31s"))
        return "Galaxy M31s";
    else if (strstr(product_device, "m31"))
        return "Galaxy M31";

    // Fallback to Default
    return "Samsung Galaxy";
}

#define BTM_DEF_LOCAL_NAME BtmGetDefaultName()

#define BTM_WBS_INCLUDED TRUE       /* Enable WBS */
#define BTIF_HF_WBS_PREFERRED FALSE /* Don't prefer WBS    */

#define BLE_VND_INCLUDED TRUE

#define BTM_SCO_ENHANCED_SYNC_ENABLED FALSE

#pragma pop_macro("PROPERTY_VALUE_MAX")

#endif
