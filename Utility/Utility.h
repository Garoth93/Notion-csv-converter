#ifndef UTILITY_H
#define UTILITY_H

#include <QList>
#include <QMap>
#include <QString>
#include <QVariant>
#include <QDateTime>

class Utility
{
public:
    static QList< QMap<QString,QVariant> > GetListaDaFileCsv(QString pathFileName,QString delimitatore = ";");
    static QString SelectFile();
    static QDateTime GetDateTimeDaStringa(QString dataStringa);
private:
    Utility();
};

#endif // UTILITY_H
