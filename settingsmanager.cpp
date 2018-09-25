﻿#include "settingsmanager.h"

#include <QCoreApplication>
#include <QDir>
#include <QUrl>
#include <QFileInfo>
#include <QSettings>

SettingsManager *SettingsManager::getInstance()
{
    static SettingsManager settingsManager;
    return &settingsManager;
}

void SettingsManager::unregAutostart()
{
    const QString key = QStringLiteral("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
    QSettings set(key, QSettings::NativeFormat);
    if (set.contains(QStringLiteral("Dynamic Desktop")))
        set.remove(QStringLiteral("Dynamic Desktop"));
}

bool SettingsManager::regAutostart()
{
    unregAutostart();
    const QString key = QStringLiteral("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
    QSettings set(key, QSettings::NativeFormat);
    if (set.status() != QSettings::NoError)
        return false;
    QString value = QLatin1Char('"') + QCoreApplication::applicationFilePath() + QLatin1Char('"');
    set.setValue(QStringLiteral("Dynamic Desktop"), QDir::toNativeSeparators(value));
    return true;
}

/*bool SettingsManager::hasNvidiaCard() const
{
    const QString key = QStringLiteral("HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\services\\nvlddmkm\\Device0");
    QSettings set(key, QSettings::NativeFormat);
    if (set.status() != QSettings::NoError)
        return false;
    QString description = set.value(QStringLiteral("Device Description")).toString();
    return description.contains(QStringLiteral("NVIDIA"), Qt::CaseInsensitive);
}

bool SettingsManager::hasAmdCard() const
{
    const QString key = QStringLiteral("HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\amdkmdap\\Device0");
    QSettings set(key, QSettings::NativeFormat);
    if (set.status() != QSettings::NoError)
        return false;
    QString description = set.value(QStringLiteral("Device Description")).toString();
    return description.contains(QStringLiteral("AMD"), Qt::CaseInsensitive);
}

bool SettingsManager::hasIntelCard() const
{
    const QString key = QStringLiteral("HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Services\\igfx\\Device0");
    QSettings set(key, QSettings::NativeFormat);
    if (set.status() != QSettings::NoError)
        return false;
    QString description = set.value(QStringLiteral("Device Description")).toString();
    return description.contains(QStringLiteral("Intel"), Qt::CaseInsensitive);
}*/

QStringList SettingsManager::defaultDecoders() const
{
    QStringList decoders;
    //if (hasNvidiaCard())
        decoders << QStringLiteral("CUDA");
    //if (hasNvidiaCard() || hasAmdCard() || hasIntelCard())
        decoders << QStringLiteral("D3D11") << QStringLiteral("DXVA");
    decoders << QStringLiteral("FFmpeg");
    return decoders;
}

QString SettingsManager::getUrl() const
{
    QSettings settings(iniPath, QSettings::IniFormat);
    QString path = settings.value(QStringLiteral("dd/url"), QString()).toString();
    if (QFileInfo(path).isDir())
        return QString();
    if (!QFileInfo::exists(path))
    {
        QUrl url(path);
        if (!url.isValid())
            return QString();
        if (url.isLocalFile())
            return url.toLocalFile();
        return QUrl::fromPercentEncoding(url.toEncoded());
    }
    return path;
}

bool SettingsManager::getMute() const
{
    QSettings settings(iniPath, QSettings::IniFormat);
    return settings.value(QStringLiteral("dd/mute"), false).toBool();
}

unsigned int SettingsManager::getVolume() const
{
    QSettings settings(iniPath, QSettings::IniFormat);
    int vol = settings.value(QStringLiteral("dd/volume"), 9).toInt();
    if (vol < 0)
        vol = 0;
    if (vol > 99)
        vol = 99;
    return static_cast<unsigned int>(vol);
}

bool SettingsManager::getAutostart() const
{
    QSettings settings(iniPath, QSettings::IniFormat);
    return settings.value(QStringLiteral("dd/autostart"), false).toBool();
}

bool SettingsManager::getHwdec() const
{
    QSettings settings(iniPath, QSettings::IniFormat);
    return settings.value(QStringLiteral("dd/hwdec"), true).toBool();
}

QStringList SettingsManager::getDecoders() const
{
    QSettings settings(iniPath, QSettings::IniFormat);
    QStringList decoders = settings.value(QStringLiteral("dd/decoders"), defaultDecoders()).toStringList();
    /*for (auto& decoder : decoders)
    {
        if (decoder != QStringLiteral("CUDA")
                && decoder != QStringLiteral("D3D11")
                && decoder != QStringLiteral("DXVA")
                && decoder != QStringLiteral("FFmpeg"))
        {
            decoder.clear();
            continue;
        }
        if (decoder == QStringLiteral("CUDA") && !hasNvidiaCard())
        {
            decoder.clear();
            continue;
        }
        if ((decoder == QStringLiteral("D3D11")
             || decoder == QStringLiteral("DXVA"))
                && (!hasNvidiaCard() && !hasAmdCard() && !hasIntelCard()))
        {
            decoder.clear();
            continue;
        }
    }
    decoders.removeAll(QString());
    if (!decoders.contains(QStringLiteral("FFmpeg")))
        decoders << QStringLiteral("FFmpeg");*/
    return decoders;
}

bool SettingsManager::getLocalize() const
{
    QSettings settings(iniPath, QSettings::IniFormat);
    return settings.value(QStringLiteral("dd/localize"), true).toBool();
}

void SettingsManager::setUrl(const QString &url)
{
    QSettings settings(iniPath, QSettings::IniFormat);
    settings.setValue(QStringLiteral("dd/url"), url);
}

void SettingsManager::setMute(bool mute)
{
    QSettings settings(iniPath, QSettings::IniFormat);
    settings.setValue(QStringLiteral("dd/mute"), mute);
}

void SettingsManager::setVolume(unsigned int volume)
{
    unsigned int vol = volume;
    if (vol > 99)
        vol = 99;
    QSettings settings(iniPath, QSettings::IniFormat);
    settings.setValue(QStringLiteral("dd/volume"), vol);
}

void SettingsManager::setAutostart(bool enable)
{
    QSettings settings(iniPath, QSettings::IniFormat);
    settings.setValue(QStringLiteral("dd/autostart"), enable);
}

void SettingsManager::setHwdec(bool enable)
{
    QSettings settings(iniPath, QSettings::IniFormat);
    settings.setValue(QStringLiteral("dd/hwdec"), enable);
}

void SettingsManager::setDecoders(const QStringList &decoders)
{
    /*QStringList newDecoders;
    if (hasNvidiaCard() && decoders.contains(QStringLiteral("CUDA")))
        newDecoders << QStringLiteral("CUDA");
    if ((hasNvidiaCard() || hasAmdCard() || hasIntelCard())
            && decoders.contains(QStringLiteral("D3D11")))
        newDecoders << QStringLiteral("D3D11");
    if ((hasNvidiaCard() || hasAmdCard() || hasIntelCard())
            && decoders.contains(QStringLiteral("DXVA")))
        newDecoders << QStringLiteral("DXVA");
    newDecoders << QStringLiteral("FFmpeg");*/
    QSettings settings(iniPath, QSettings::IniFormat);
    settings.setValue(QStringLiteral("dd/decoders"), /*newDecoders*/decoders);
}

void SettingsManager::setLocalize(bool enable)
{
    QSettings settings(iniPath, QSettings::IniFormat);
    settings.setValue(QStringLiteral("dd/localize"), enable);
}

SettingsManager::SettingsManager()
{
    iniPath = QCoreApplication::applicationFilePath();
    if (iniPath.endsWith(QStringLiteral(".exe"), Qt::CaseInsensitive))
        iniPath = iniPath.remove(iniPath.lastIndexOf(QLatin1Char('.')), 4);
    iniPath += QStringLiteral(".ini");
}
