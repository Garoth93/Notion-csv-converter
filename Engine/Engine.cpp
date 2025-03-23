#include "Engine.h"
#include <QFile>
#include <QTextStream>
#include "Utility/Utility.h"

Engine::Engine(QString pathFile)
{
    PathFile = pathFile;
}

Engine::~Engine()
{
    pulisciMemoria();
}

bool Engine::leggiFile()
{
    QList<QMap<QString, QVariant> > ListaContenutoCsv = Utility::GetListaDaFileCsv(PathFile,",");

    for (int i = 0; i < ListaContenutoCsv.size(); ++i)
    {
        const QMap<QString, QVariant>& map = ListaContenutoCsv[i];

        ObjLine * newObjLine = new ObjLine();

        newObjLine->setCliente(map["Clienti"].toString());
        newObjLine->setDataPrevistaConsegna(map["Delivery date"].toString());
        newObjLine->setEffort(map["Developer effort"].toString());
        newObjLine->setEffortTotale(map["Total resource effort"].toString());
        newObjLine->setOreProgetto(map["Hours"].toString());
        newObjLine->setId(map["Id"].toString());
        newObjLine->setProgetto(map["Project name"].toString());
        newObjLine->setStato(map["Status"].toString());
        newObjLine->setTeam(map["Team members"].toString());
        newObjLine->setDateLavoro(map["Working days"].toString());

        Righe << newObjLine;
    }

    return true;
}

void Engine::stampaRighe()
{
    qDebug() << "=== Lista Righe ===";

    for (const ObjLine* obj : Righe)
    {
        if (!obj) continue;

        qDebug() << "--------------------------";
        qDebug() << "Cliente:" << obj->getCliente();
        qDebug() << "Progetto:" << obj->getProgetto();
        qDebug() << "ID:" << obj->getId();
        qDebug() << "Team:" << obj->getTeam();
        qDebug() << "Stato:" << obj->getStato();
        qDebug() << "Effort:" << obj->getEffort();
        qDebug() << "Effort Totale:" << obj->getEffortTotale();
        qDebug() << "Ore Progetto:" << obj->getOreProgetto();
        qDebug() << "Data Inizio:" << obj->getDataInzio().toString(Qt::ISODate);
        qDebug() << "Data Fine:" << obj->getDataFine().toString(Qt::ISODate);
        qDebug() << "Data Prevista Consegna:" << obj->getDataPrevistaConsegna().toString(Qt::ISODate);
    }

    qDebug() << "=== Fine Lista ===";
}

bool Engine::scriviFileCsv(QString pathFileOutput, QString separatore)
{
    QFile file(pathFileOutput);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Errore nell'aprire il file CSV:" << file.errorString();
        return false;
    }

    QTextStream stream(&file);

    // Scrive l'header del CSV
    stream << "Cliente" << separatore
           << "Progetto" << separatore
           << "ID" << separatore
           << "Team" << separatore
           << "Stato" << separatore
           << "Effort" << separatore
           << "Effort Totale" << separatore
           << "Ore Progetto" << separatore
           << "Data Inizio" << separatore
           << "Data Fine" << separatore
           << "Data Prevista Consegna"
           << "\n";

    // Scrive i dati della lista
    for (const ObjLine* obj : Righe) {
        if (!obj) continue; // Evita di scrivere oggetti nulli

        stream << obj->getCliente() << separatore
               << obj->getProgetto() << separatore
               << obj->getId() << separatore
               << obj->getTeam() << separatore
               << obj->getStato() << separatore
               << obj->getEffort() << separatore
               << obj->getEffortTotale() << separatore
               << obj->getOreProgetto() << separatore
               << obj->getDataInzio().toString("yyyy-MM-dd HH:mm:ss") << separatore
               << obj->getDataFine().toString("yyyy-MM-dd HH:mm:ss") << separatore
               << obj->getDataPrevistaConsegna().toString("yyyy-MM-dd HH:mm:ss")
               << "\n";
    }

    file.close();
    qDebug() << "CSV scritto con successo in:" << pathFileOutput;
    return true;
}

void Engine::pulisciMemoria()
{
    qDeleteAll(Righe);

    Righe.clear();
}
