#include "smarthomedialog.h"

smarthomeDialog::smarthomeDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    ipLine->setText("192.168.1.11");
    PortspinBox->setRange(1000,60000);
    PortspinBox->setValue(8888);
    RelayONpushButton->setEnabled(false);
    RelayOffpushButton->setEnabled(false);
    RelayOn2pushButton->setEnabled(false);
    RelayOff2pushButton->setEnabled(false);
    AllOnpushButton->setEnabled(false);
    AllOffpushButton->setEnabled(false);


    connect(&m_tcp, SIGNAL(connected()),
            this, SLOT(OnTcpConnected()));
    connect(&m_tcp, SIGNAL(disconnected()),
            this, SLOT(OnTcpDisconnected()));
}



void smarthomeDialog::on_connectButton_clicked()
{
    if (connectButton->text().startsWith("Connect"))
    {
        connectButton->setText("Disconnect");
        m_tcp.connectToHost(ipLine->text(),PortspinBox->value());
    }
    else {
       connectButton->setText("Connect");
       m_tcp.disconnectFromHost();
    }
}

void smarthomeDialog::OnTcpConnected()
{
    qDebug("OnTcpConnected");
    RelayONpushButton->setEnabled(true);
    RelayOffpushButton->setEnabled(true);
    RelayOn2pushButton->setEnabled(true);
    RelayOff2pushButton->setEnabled(true);
    AllOnpushButton->setEnabled(true);
    AllOffpushButton->setEnabled(true);

}

void smarthomeDialog::OnTcpDisconnected()
{
    RelayONpushButton->setEnabled(false);
    RelayOffpushButton->setEnabled(false);
    RelayOn2pushButton->setEnabled(false);
    RelayOff2pushButton->setEnabled(false);
    AllOnpushButton->setEnabled(false);
    AllOffpushButton->setEnabled(false);
}

void smarthomeDialog::on_RelayONpushButton_clicked()
{
    QString sta =  "a";
    m_tcp.write(sta.toLatin1(),sta.length());
}

void smarthomeDialog::on_RelayOffpushButton_clicked()
{
    QString sta =  "b";
    m_tcp.write(sta.toLatin1(),sta.length());
}

void smarthomeDialog::on_RelayOn2pushButton_clicked()
{
    QString sta =  "c";
    m_tcp.write(sta.toLatin1(),sta.length());
}

void smarthomeDialog::on_AllOnpushButton_clicked()
{
    QString sta =  "e";
    m_tcp.write(sta.toLatin1(),sta.length());
}

void smarthomeDialog::on_RelayOff2pushButton_clicked()
{
    QString sta =  "d";
    m_tcp.write(sta.toLatin1(),sta.length());
}

void smarthomeDialog::on_AllOffpushButton_clicked()
{
    QString sta =  "f";
    m_tcp.write(sta.toLatin1(),sta.length());
}
