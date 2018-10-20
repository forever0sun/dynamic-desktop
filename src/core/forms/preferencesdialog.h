#pragma once

#include <QtNiceFramelessWindow>
#include <QVariant>

QT_FORWARD_DECLARE_CLASS(IPCServer)
QT_FORWARD_DECLARE_CLASS(QSystemTrayIcon)
QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(AboutDialog)

QT_BEGIN_NAMESPACE
QT_FORWARD_DECLARE_CLASS(QWinTaskbarButton)
QT_FORWARD_DECLARE_CLASS(QWinTaskbarProgress)
QT_END_NAMESPACE

namespace Ui
{
    class PreferencesDialog;
}

class PreferencesDialog : public CFramelessWindow
{
    Q_OBJECT

signals:
    void sendCommand(QPair<QString, QVariant>);
    void setMute(bool);
    void muteChanged(bool);
    void about();
    //void requestUpdate();

public slots:
    void playerEcho(const QVariant& param);
    void updateVideoSlider(const QVariant& params);
    void updateVideoSliderUnit(const QVariant& params);
    void updateVideoSliderRange(const QVariant& params);
    void setSeekAreaEnabled(const QVariant& params);
    void setAudioAreaEnabled(const QVariant& params);
    void updateVideoTracks(const QVariant& params);
    void updateAudioTracks(const QVariant& params);
    void updateSubtitleTracks(const QVariant& params);
    void clearAllTracks(const QVariant& params);
    void setVolumeToolTip(const QVariant& params);
    void setVideoPositionText(const QVariant& params);
    void setVideoDurationText(const QVariant& params);

public:
    explicit PreferencesDialog(QWidget *parent = nullptr);
    ~PreferencesDialog() override;

public slots:
    void parseCommand(const QPair<QString, QVariant>& command);

public:
    bool setAutoStart(bool enable = true);
    bool isAutoStart(const QString &name = QStringLiteral("Dynamic Desktop Auto Start Service"));

protected:
    void changeEvent(QEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void initUI();
    void initConnections();
    void initIPC();
    void initTrayArea();
    void setDecoders();
    void setRatio();

private:
    Ui::PreferencesDialog *ui;
    bool audioAvailable = true;
    quint32 sliderUnit = 1000;
    QWinTaskbarButton *taskbarButton = nullptr;
    QWinTaskbarProgress *taskbarProgress = nullptr;
    IPCServer *ipcServer = nullptr;
    QSystemTrayIcon *trayIcon = nullptr;
    QMenu *trayMenu = nullptr;
    AboutDialog *aboutDialog = nullptr;
};