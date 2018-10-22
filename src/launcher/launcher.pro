include(../common.pri)
DESTDIR = $${BIN_DIR}
QMAKE_TARGET_PRODUCT = Launcher
QMAKE_TARGET_DESCRIPTION = Dynamic Desktop
RC_ICONS = ../resources/icons/color_palette.ico
TARGET = launcher
CONFIG(debug, debug|release): TARGET = $$join(TARGET,,,d)
TEMPLATE = app
CONFIG -= qt
CONFIG *= console
LIBS *= \
    -lShell32 \
    -lKernel32 \
    -lUser32
SOURCES += main.cpp
CONFIG(upx): include(../upx.pri)
CONFIG(build_installer): include(../installer.pri)
