include(../common.pri)
DESTDIR = $${BIN_DIR}
QMAKE_TARGET_PRODUCT = Dynamic Desktop Updater Module
QMAKE_TARGET_DESCRIPTION = Dynamic Desktop Updater
RC_ICONS = ../resources/icons/color_palette.ico
TARGET = updater
CONFIG(debug, debug|release): TARGET = $$join(TARGET,,,d)
TEMPLATE = app
QT *= widgets
include(../settingsmanager/settingsmanager.pri)
include(../qsimpleupdater/qsimpleupdater.pri)
include(../utils/utils.pri)
SOURCES += updater.cpp
include(../deploy.pri)