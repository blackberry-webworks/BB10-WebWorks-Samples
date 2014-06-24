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

#ifndef APPHEADLESS_HPP
#define APPHEADLESS_HPP

#include "PushNotificationService.hpp"
#include "PushUtility.hpp"
#include "Configuration.hpp"

class AppHeadless : public QObject {
    Q_OBJECT
    public:
        AppHeadless();
        virtual ~AppHeadless();

        public Q_SLOTS:
            void onCreateSessionCompleted(const bb::network::PushStatus &status);
            void onCreateChannelCompleted(const bb::network::PushStatus &status, const QString &token);
            void onDestroyChannelCompleted(const bb::network::PushStatus &status);
            void onRegisterToLaunchCompleted(const bb::network::PushStatus &status);
            void onUnregisterFromLaunchCompleted(const bb::network::PushStatus &status);
            void onPIRegistrationCompleted(int code, const QString &description);
            void onPIDeregistrationCompleted(int code, const QString &description);
            void onPushTransportReady(bb::network::PushCommand::Type command);
            void onNoPushServiceConnection();
            void onPushAgentConnectionStatusChanged(bool isConnected);

    private:
        void sendStatus(const QString &status, const QString &message = "", int code = -1);

        PushNotificationService *m_pushNotificationService;

        // Stores configuration values
        Configuration *m_configuration;
};

#endif /* APPHEADLESS_HPP */
