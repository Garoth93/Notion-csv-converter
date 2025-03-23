#ifndef ENGINE_H
#define ENGINE_H

#include <QList>
#include "Engine/ObjLine.h"

class Engine
{
public:
    Engine(QString pathFile);
    ~Engine();

    bool leggiFile();

    void stampaRighe();

    bool scriviFileCsv(QString pathFileOutput, QString separatore = ";");
private:
    QList<ObjLine*> Righe;

    QString PathFile = "";

    void pulisciMemoria();
};

#endif // ENGINE_H
