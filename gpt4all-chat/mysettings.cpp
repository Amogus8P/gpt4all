#include "mysettings.h"

#include <QSettings>

class MyPrivateSettings: public MySettings { };
Q_GLOBAL_STATIC(MyPrivateSettings, settingsInstance)
MySettings *MySettings::globalInstance()
{
    return settingsInstance();
}

MySettings::MySettings()
    : QObject{nullptr}
{
}

bool MySettings::forceMetal() const
{
    return m_forceMetal;
}

void MySettings::setForceMetal(bool enabled)
{
    if (m_forceMetal == enabled)
        return;
    m_forceMetal = enabled;
    emit forceMetalChanged(enabled);
}
