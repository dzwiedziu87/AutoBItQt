#include "download.h"

Download::Download(QNetworkAccessManager *manager, QObject *parent) : QObject(parent), manager(manager)
{
    connect(manager,&QNetworkAccessManager::finished,this,&Download::onDownloadFinished);
}

void Download::downloadFromUrl(QString url)
{
    auto urlData = QUrl(url);
    auto request = QNetworkRequest(urlData);
    manager->get(request);
}

void Download::onDownloadFinished(QNetworkReply *reply)
{
    auto data = reply->readAll();
    auto document = QJsonDocument::fromJson(data);
    auto variantData = document.toVariant();
    emit downloadedData(variantData);
}
