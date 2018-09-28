#include "MyCar.h"
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QPluginLoader>
#include <QList>

#include "IDevice.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyCar w;
    w.show();



    QDir dir("/home/vishal/Documents/Bins");
    QStringList entries = dir.entryList();
    int size = entries.size();

    QList<QObject*>libs;
    for(int i=0;i<size;i++)
    {
        QString fileName = entries.at(i);
        qDebug() << "File Name ="<<entries.at(i)<<endl;
       // QPluginLoader carLoader(entries.at(i));
         QPluginLoader carLoader(dir.absoluteFilePath(fileName));
       // carLoader.setFileName(entries.at(i));
        carLoader.load();
        if(carLoader.isLoaded())
        {
            qDebug() <<"Loaded Successfully "<<endl;
            carLoader.instance();
            libs.append(carLoader.instance());
        }
        qDebug() <<libs.size()<<endl;
        for (int i=0;i<libs.size();i++)
        {
            IDevice *dev = qobject_cast<IDevice*>(libs.at(i));
            dev->readData();
        }

    }

    return a.exec();
}
