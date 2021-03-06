#pragma once

#ifndef DD_NO_CSS

#include <QtCore>

class SkinsManager
{
public:
    static SkinsManager *getInstance();

public:
    QString currentSkinName() const;
    QString currentSkinPath() const;
    bool setSkin(const QString &skin = QStringLiteral("Default"));

private:
    QString curSkinName;
    QString curSkinPath;
};

#endif
