/*!
 * Copyright (c) 2012, 2013 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PushUtility.hpp"
#include <QObject>

void checkConnectResult(bool connectResult){
    // If any Q_ASSERT statement(s) indicate that the slot failed to connect to
    // the signal, make sure you know exactly why this has happened. This is not
    // normal, and will cause your app to stop working!!

    // This is only available in Debug builds.
    Q_ASSERT(connectResult);
}
