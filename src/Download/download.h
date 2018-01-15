#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QObject>

class Download : public QObject
{
    Q_OBJECT
public:
    explicit Download(QNetworkAccessManager *manager, QObject *parent = nullptr);

signals:
    void downloadedData(QVariant data);

public slots:
    void downloadFromUrl(QString url);

private slots:
    void onDownloadFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
};

#endif // DOWNLOAD_H
