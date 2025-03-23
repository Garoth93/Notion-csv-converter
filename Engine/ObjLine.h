#ifndef OBJLINE_H
#define OBJLINE_H

#include <QDateTime>
class ObjLine
{
public:
    ObjLine();

    QString getCliente() const;
    void setCliente(const QString &newCliente);

    QDateTime getDataPrevistaConsegna() const;
    void setDataPrevistaConsegna(const QString &newDataPrevistaConsegna);

    QString getEffort() const;
    void setEffort(const QString &newEffort);

    QString getOreProgetto() const;
    void setOreProgetto(const QString &newOreProgetto);

    QString getId() const;
    void setId(const QString &newId);

    QString getProgetto() const;
    void setProgetto(const QString &newProgetto);

    QString getStato() const;
    void setStato(const QString &newStato);

    QString getEffortTotale() const;
    void setEffortTotale(const QString &newEffortTotale);

    QDateTime getDataInzio() const;
    void setDataInzio(const QDateTime &newDataInzio);

    QDateTime getDataFine() const;

    void setDateLavoro(QString stringaDateLavoro);

    QString getTeam() const;
    void setTeam(const QString &newTeam);

    void setDataFine(const QDateTime &newDataFine);

private:

    QString Cliente = "";
    QDateTime DataPrevistaConsegna;
    QString Effort = "";
    QString OreProgetto = "";
    QString Id = "";
    QString Progetto = "";
    QString Team = "";
    QString Stato = "";
    QString EffortTotale = "";
    QDateTime DataInzio;
    QDateTime DataFine;
};

#endif // OBJLINE_H
