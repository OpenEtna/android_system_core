/*
 * Copyright (C) 2008 The Android Open Source Project
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

#define LOG_TAG "SupplicantConnectionTimeoutEvent"
#include <cutils/log.h>

#include "SupplicantConnectionTimeoutEvent.h"

SupplicantConnectionTimeoutEvent::SupplicantConnectionTimeoutEvent(int level, char *event,
                                                   size_t len) :
                          SupplicantEvent(SupplicantEvent::EVENT_CONNECTIONTIMEOUT,
                                          level) {
    // 00:13:46:40:40:aa timed out.'
    mBssid = (char *) malloc(18);
    strncpy(mBssid, event, 17);
    mBssid[17] = '\0';
}

SupplicantConnectionTimeoutEvent::~SupplicantConnectionTimeoutEvent() {
    if (mBssid)
        free(mBssid);
}

