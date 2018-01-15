#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

void debug(QNetworkReply *reply)
{
    auto data = reply->readAll();
    auto document = QJsonDocument::fromJson(data);
    auto array = document.array();
    auto variant = array.toVariantList();
    qDebug() << variant;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    auto manager = new QNetworkAccessManager(qApp);
    QObject::connect(manager,&QNetworkAccessManager::finished,debug);

    auto url = QUrl("https://api.coinmarketcap.com/v1/ticker/bitcoin/?convert=PLN");
    auto request = QNetworkRequest(url);
    manager->get(request);

    return a.exec();
}
