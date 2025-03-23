#include "ObjLine.h"
#include <QRegularExpression>
#include "Utility/Utility.h"

ObjLine::ObjLine() {}

QString ObjLine::getCliente() const
{
    return Cliente;
}

void ObjLine::setCliente(const QString &newCliente)
{
    QRegularExpression regex(R"(\s*\(https?:\/\/[^\)]+\))");

    QString clienteInput = newCliente;

    Cliente = clienteInput.replace(regex, "");
}

QDateTime ObjLine::getDataPrevistaConsegna() const
{
    return DataPrevistaConsegna;
}

void ObjLine::setDataPrevistaConsegna(const QString &newDataPrevistaConsegna)
{
    DataPrevistaConsegna = Utility::GetDateTimeDaStringa(newDataPrevistaConsegna);
}

QString ObjLine::getEffort() const
{
    return Effort;
}

void ObjLine::setEffort(const QString &newEffort)
{
    Effort = newEffort;
}

QString ObjLine::getOreProgetto() const
{
    return OreProgetto;
}

void ObjLine::setOreProgetto(const QString &newOreProgetto)
{
    OreProgetto = newOreProgetto;
}

QString ObjLine::getId() const
{
    return Id;
}

void ObjLine::setId(const QString &newId)
{
    Id = newId;
}

QString ObjLine::getProgetto() const
{
    return Progetto;
}

void ObjLine::setProgetto(const QString &newProgetto)
{
    Progetto = newProgetto;
}

QString ObjLine::getStato() const
{
    return Stato;
}

void ObjLine::setStato(const QString &newStato)
{
    Stato = newStato;
}

QString ObjLine::getEffortTotale() const
{
    return EffortTotale;
}

void ObjLine::setEffortTotale(const QString &newEffortTotale)
{
    EffortTotale = newEffortTotale;
}

QDateTime ObjLine::getDataInzio() const
{
    return DataInzio;
}

void ObjLine::setDataInzio(const QDateTime &newDataInzio)
{
    DataInzio = newDataInzio;
}

QDateTime ObjLine::getDataFine() const
{
    return DataFine;
}

void ObjLine::setDateLavoro(QString stringaDateLavoro)
{
    QStringList parts = stringaDateLavoro.split("→", Qt::SkipEmptyParts);

    QDateTime startDate, endDate;

    if (!parts.isEmpty())
    {
        startDate = Utility::GetDateTimeDaStringa(parts[0]);
    }
    if (parts.size() > 1)
    {
        endDate =  Utility::GetDateTimeDaStringa(parts[1]);
    }

    this->setDataInzio(startDate);

    this->setDataFine(endDate);
}

QString ObjLine::getTeam() const
{
    return Team;
}

void ObjLine::setTeam(const QString &newTeam)
{
    QRegularExpression regex(R"(\s*\(https?:\/\/[^\)]+\))");

    QString teamInput = newTeam;

    Team = teamInput.replace(regex, "");
}

void ObjLine::setDataFine(const QDateTime &newDataFine)
{
    DataFine = newDataFine;
}
