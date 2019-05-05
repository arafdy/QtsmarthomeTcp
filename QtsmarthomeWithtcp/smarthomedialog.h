#ifndef SMARTHOMEDIALOG_H
#define SMARTHOMEDIALOG_H

#include "ui_smarthomedialog.h"
#include <QTcpSocket>

class smarthomeDialog : public QDialog, private Ui::smarthomeDialog
{
    Q_OBJECT

    QTcpSocket m_tcp;

public:
    explicit smarthomeDialog(QWidget *parent = nullptr);
private slots:
    void on_connectButton_clicked();

    void OnTcpConnected();
    void OnTcpDisconnected();

    void on_RelayONpushButton_clicked();
    void on_RelayOffpushButton_clicked();
    void on_RelayOn2pushButton_clicked();
    void on_AllOnpushButton_clicked();
    void on_RelayOff2pushButton_clicked();
    void on_AllOffpushButton_clicked();
};

#endif // SMARTHOMEDIALOG_H
