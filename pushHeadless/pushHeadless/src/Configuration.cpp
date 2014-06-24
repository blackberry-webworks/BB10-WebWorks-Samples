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

#include "Configuration.hpp"

Configuration* Configuration::instance= NULL;
bool Configuration::instanceFlag = false;

Configuration::Configuration()
    : m_usingPublicPushProxyGateway(true)
    , m_launchApplicationOnPush(true)
{
	//Initialize configuration from config.ini
	QSettings settings("app/native/assets/config.ini", QSettings::IniFormat);
	m_providerApplicationId = settings.value("ApplicationId").toString();
	m_invokeTargetId = settings.value("InvokeTargetId").toString();
	m_pushInitiatorUrl = settings.value("PushInitiatorUrl").toString();
	m_user = User();
	m_user.setUserId(settings.value("PushInitiatorUsername").toString());
	m_user.setPassword(settings.value("PushInitiatorPassword").toString());
	m_usingPublicPushProxyGateway = settings.value("UsingPublicPushProxyGateway").toBool();
	m_ppgUrl = settings.value("PPGUrl").toString();
	m_launchApplicationOnPush = settings.value("LaunchApplicationOnPush").toBool();
}

Configuration* Configuration::getInstance()
{
    if(! instanceFlag)
    {
        instance = new Configuration();
        instanceFlag = true;
        return instance;
    }
    else
    {
        return instance;
    }
}


bool Configuration::usingPublicPushProxyGateway() const
{
    return m_usingPublicPushProxyGateway;
}

QString Configuration::providerApplicationId() const
{
    return m_providerApplicationId;
}

QString Configuration::invokeTargetId() const
{
    return m_invokeTargetId;
}

QString Configuration::ppgUrl() const
{
    return m_ppgUrl;
}

QString Configuration::pushInitiatorUrl() const
{
    return m_pushInitiatorUrl;
}

bool Configuration::launchApplicationOnPush() const
{
    return m_launchApplicationOnPush;
}

User Configuration::user() const
{
	return m_user;
}
