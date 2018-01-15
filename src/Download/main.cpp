#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "download.h"

void debugData(QVariant data)
{
    qDebug() << data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    auto manager = new QNetworkAccessManager(qApp);
    auto downloader = new Download(manager,qApp);
    QObject::connect(downloader,&Download::downloadedData,debugData);

    downloader->downloadFromUrl("https://api.coinmarketcap.com/v1/ticker/bitcoin/?convert=PLN");
    downloader->downloadFromUrl("https://bitbay.net/API/Public/BTCPLN/all.json");

    return a.exec();
}
