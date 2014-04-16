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

#include "AppHeadless.hpp"
#include <bb/network/PushErrorCode>

using namespace bb::network;

    AppHeadless::AppHeadless()
    : m_pushNotificationService(new PushNotificationService(this))
{
    m_configuration = Configuration::getInstance();

    // connect the push notification service signals and slots
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(createSessionCompleted(const bb::network::PushStatus&)),
                this, SLOT(onCreateSessionCompleted(const bb::network::PushStatus&))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(createChannelCompleted(const bb::network::PushStatus&, const QString)),
                this, SLOT(onCreateChannelCompleted(const bb::network::PushStatus&, const QString))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(destroyChannelCompleted(const bb::network::PushStatus&)),
                this, SLOT(onDestroyChannelCompleted(const bb::network::PushStatus&))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(registerToLaunchCompleted(const bb::network::PushStatus&)),
                this, SLOT(onRegisterToLaunchCompleted(const bb::network::PushStatus&))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(unregisterFromLaunchCompleted(const bb::network::PushStatus&)),
                this, SLOT(onUnregisterFromLaunchCompleted(const bb::network::PushStatus&))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(piRegistrationCompleted(int, const QString)),
                this, SLOT(onPIRegistrationCompleted(int, const QString))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(piDeregistrationCompleted(int, const QString)),
                this, SLOT(onPIDeregistrationCompleted(int, const QString))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(pushTransportReady(bb::network::PushCommand::Type)),
                this, SLOT(onPushTransportReady(bb::network::PushCommand::Type))));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(noPushServiceConnection()),
                this, SLOT(onNoPushServiceConnection())));
    Q_ASSERT(QObject::connect(m_pushNotificationService, SIGNAL(pushAgentConnectionStatusChanged(bool)),
                this, SLOT(onPushAgentConnectionStatusChanged(bool))));

    m_pushNotificationService->createSession();
    m_pushNotificationService->createChannel();
}

AppHeadless::~AppHeadless()
{
}

void AppHeadless::sendStatus(const QString &status, const QString &message, int code)
{
    //This sample will simply send a status to the console, but this can be changed
    //to send to the UI via a text file in the app sandbox.
    qDebug() << status << message << code;
}

void AppHeadless::onNoPushServiceConnection()
{
    sendStatus(PUSH_COLLECTOR_NO_PUSH_SERVICE_CONNECTION);
}

void AppHeadless::onPushAgentConnectionStatusChanged(bool isConnected)
{
    QString message;
    if (isConnected){
        message = tr("Push Service successfully reconnected to the Push Agent.");
    } else{
        message = tr("Error: Push Service could not reconnect to the Push Agent.");
    }

    sendStatus(PUSH_COLLECTOR_SHOW_TOAST, message);
}

void AppHeadless::onCreateSessionCompleted(const bb::network::PushStatus &status)
{

    QString message;
    if (status.code() == PushErrorCode::NoError) {
        if (m_configuration->launchApplicationOnPush()) {
            m_pushNotificationService->registerToLaunch();
        } else {
            m_pushNotificationService->unregisterFromLaunch();
        }
    }

    sendStatus(PUSH_COLLECTOR_CREATE_SESSION_COMPLETE, message, status.code());
}

void AppHeadless::onCreateChannelCompleted(const bb::network::PushStatus &status, const QString &token)
{
    qDebug()<< "creatChannelComplete status: " << status.code();
    qDebug()<< "createChannelComplete token: " << token;

    // Typically in your own application you wouldn't want to display this error to your users
    QString message = tr("Create channel failed with error code: %0").arg(status.code());

    switch(status.code()){
        case  PushErrorCode::NoError:

            if (!m_configuration->pushInitiatorUrl().isEmpty()) {
                // Now, attempt to subscribe to the Push Initiator
                message = tr("Subscribing to Push Initiator...");
                sendStatus(PUSH_COLLECTOR_REGISTER_WITH_PUSH_INITIATOR, message, status.code());

                // This is very important: the token returned in the create channel success event is what
                // the Push Initiator should use when initiating a push to the BlackBerry Push Service.
                // This token must be communicated back to the Push Initiator's server-side application.
                m_pushNotificationService->subscribeToPushInitiator(m_configuration->user(), token);
                return;
            } else {
                message = tr("Register succeeded.");
            }
            break;
        case  PushErrorCode::TransportFailure:
            message = tr("Create channel failed as the push transport is unavailable. "
                    "Verify your mobile network and/or Wi-Fi are turned on. "
                    "If they are on, you will be notified when the push transport is available again.");
            break;
        case PushErrorCode::SubscriptionContentNotAvailable:
            message = tr("Create channel failed as the PPG is currently returning a server error. "
                    "You will be notified when the PPG is available again.");
            break;
    }

    sendStatus(PUSH_COLLECTOR_CREATE_CHANNEL_COMPLETE, message, status.code());
}

void AppHeadless::onPIRegistrationCompleted(int code, const QString &description)
{
    QString message;
    if (code == 200) {
        message = tr("Register succeeded.");
    } else {
        // Typically in your own application you wouldn't want to display this error to your users
        message = tr("Subscribe to the Push Initiator failed with error code: %0. Reason: %1").arg(QString::number(code), description);
    }

    sendStatus(PUSH_COLLECTOR_REGISTER_WITH_PUSH_INITIATOR_COMPLETE, message, code);
}

void AppHeadless::onDestroyChannelCompleted(const bb::network::PushStatus &status)
{
    qDebug() << "onDestroyChannelCompleted: " << status.code();

    // Typically in your own application you wouldn't want to display this error to your users
    QString message = tr("Destroy channel failed with error code: %0").arg(status.code());

    switch(status.code()){
        case  PushErrorCode::NoError:
            if (!m_configuration->pushInitiatorUrl().isEmpty()) {
                // The Push Service SDK will be used to unsubscribe to the Push Initiator's server-side application since a
                // Push Initiator URL was specified
                message = tr("Unsubscribing from Push Initiator...");
                sendStatus(PUSH_COLLECTOR_DEREGISTER_WITH_PUSH_INITIATOR, message, status.code());

                // Now, attempt to unsubscribe from the Push Initiator
                m_pushNotificationService->unsubscribeFromPushInitiator(m_configuration->user());
                return;
            } else {
                message = tr("Unregister succeeded.");
            }
            break;
        case  PushErrorCode::TransportFailure:
            message = tr("Destroy channel failed as the push transport is unavailable. "
                    "Verify your mobile network and/or Wi-Fi are turned on. "
                    "If they are on, you will be notified when the push transport is available again.");
            break;
        case PushErrorCode::SubscriptionContentNotAvailable:
            message = tr("Destroy channel failed as the PPG is currently returning a server error. "
                    "You will be notified when the PPG is available again.");
            break;
    }

    sendStatus(PUSH_COLLECTOR_DESTROY_CHANNEL_COMPLETE, message, status.code());
}

void AppHeadless::onPIDeregistrationCompleted(int code, const QString &description)
{
    QString message;
    if (code == 200) {
        message = tr("Unregister succeeded.");
    } else {
        // Typically in your own application you wouldn't want to display this error to your users
        message = tr("Unsubscribe from the Push Initiator failed with error code: %0. Reason: %1").arg(QString::number(code), description);
    }

    sendStatus(PUSH_COLLECTOR_DEREGISTER_WITH_PUSH_INITIATOR_COMPLETE, message, code);
}

void AppHeadless::onRegisterToLaunchCompleted(const bb::network::PushStatus &status)
{
    if (status.code() != PushErrorCode::NoError) {
        // Typically in your own application you wouldn't want to display this error to your users
        QString message(tr("Register to launch failed with error code: %0.").arg(status.code()));
        sendStatus(PUSH_COLLECTOR_REGISTER_TO_LAUNCH_COMPLETE, message, status.code());
    }
}

void AppHeadless::onUnregisterFromLaunchCompleted(const bb::network::PushStatus &status)
{
    if (status.code() != PushErrorCode::NoError) {
        // Typically in your own application you wouldn't want to display this error to your users
        QString message(tr("Unregister from launch failed with error code: %0.").arg(status.code()));
        sendStatus(PUSH_COLLECTOR_UNREGISTER_FROM_LAUNCH_COMPLETE, message, status.code());
    }
}

void AppHeadless::onPushTransportReady(bb::network::PushCommand::Type command)
{
    if (command == PushCommand::CreateChannel){
        m_pushNotificationService->createChannel();
    } else {
        m_pushNotificationService->destroyChannel();
    }
}
