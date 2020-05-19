#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
    QTcpSocket socket;
    int port;
    QByteArray request;

    Q_OBJECT
public:
    explicit Client(int port, QObject *parent = nullptr);

    void sendRequest(QByteArray);

signals:
    void gotResponse(QByteArray);

public slots:
    void onConnected();
    void onReadyRead();
    void onBytesWritten(qint64);
    void onDisconnected();
};

#endif // CLIENT_H
