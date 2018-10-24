/*
 * Copyright (c) 2014-2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the QSimpleUpdater library, which is released under
 * the DBAD license, you can read a copy of it below:
 *
 * DON'T BE A DICK PUBLIC LICENSE TERMS AND CONDITIONS FOR COPYING,
 * DISTRIBUTION AND MODIFICATION:
 *
 * Do whatever you like with the original work, just don't be a dick.
 * Being a dick includes - but is not limited to - the following instances:
 *
 * 1a. Outright copyright infringement - Don't just copy this and change the
 *     name.
 * 1b. Selling the unmodified original with no work done what-so-ever, that's
 *     REALLY being a dick.
 * 1c. Modifying the original work to contain hidden harmful content.
 *     That would make you a PROPER dick.
 *
 * If you become rich through modifications, related works/services, or
 * supporting the original work, share the love.
 * Only a dick would make loads off this work and not buy the original works
 * creator(s) a pint.
 *
 * Code is provided with no warranty. Using somebody else's code and bitching
 * when it goes wrong makes you a DONKEY dick.
 * Fix the problem yourself. A non-dick would submit the fix back.
 */

#pragma once

#include "../dd_dll_global.h"

#include <QObject>

QT_FORWARD_DECLARE_CLASS(Downloader)
QT_FORWARD_DECLARE_CLASS(QNetworkReply)
QT_FORWARD_DECLARE_CLASS(QNetworkAccessManager)

/**
 * \brief Downloads and interprests the update definition file
 */
class DD_SHARED_EXPORT Updater : public QObject
{
    Q_OBJECT

signals:
    void updateAvailable(bool);
    void checkingFinished (const QString& url);
    void downloadFinished (const QString& url, const QString& filepath);
    void appcastDownloaded (const QString& url, const QByteArray& data);

public:
    Updater();
    ~Updater() override;

    QString url() const;
    QString openUrl() const;
    QString changelog() const;
    QString moduleName() const;
    QString fileName() const;
    QString downloadDir() const;
    QString downloadUrl() const;
    QString platformKey() const;
    QString moduleVersion() const;
    QString latestVersion() const;
    QString userAgentString() const;

    bool customAppcast() const;
    bool notifyOnUpdate() const;
    bool notifyOnFinish() const;
    bool isUpdateAvailable() const;
    bool downloaderEnabled() const;
    bool useCustomInstallProcedures() const;
    bool autoUpdate() const;

public slots:
    void checkForUpdates();
    void setAutoUpdate (bool enabled = true);
    void setUrl (const QString& url);
    void setModuleName (const QString& name);
    void setNotifyOnUpdate (const bool notify);
    void setNotifyOnFinish (const bool notify);
    void setUserAgentString (const QString& agent);
    void setModuleVersion (const QString& version);
    void setDownloaderEnabled (const bool enabled);
    void setPlatformKey (const QString& platformKey);
    void setUseCustomAppcast (const bool customAppcast);
    void setUseCustomInstallProcedures (const bool custom);

private slots:
    void onReply (QNetworkReply* reply);
    void setUpdateAvailable (const bool available);

private:
    QString m_url;
    QString m_userAgentString;

    bool m_customAppcast;
    bool m_notifyOnUpdate;
    bool m_notifyOnFinish;
    bool m_updateAvailable;
    bool m_downloaderEnabled;
    bool m_autoupdate;

    QString m_openUrl;
    QString m_platform;
    QString m_changelog;
    QString m_moduleName;
    QString m_downloadUrl;
    QString m_moduleVersion;
    QString m_latestVersion;

    Downloader* m_downloader;
    QNetworkAccessManager* m_manager;
};
