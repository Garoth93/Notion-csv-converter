#include "Utility.h"

#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QStandardPaths>
#include <QRegularExpression>

QStringList parseCsvLine(const QString &line, const QString delimitatore = ",")
{
    QStringList result;
    bool insideQuotes = false;
    QString currentField;
    QChar delim = delimitatore.at(0); // Usa il primo carattere del delimitatore

    for (int i = 0; i < line.length(); ++i)
    {
        QChar c = line[i];

        if (c == '"')
        {
            // Se troviamo un doppio apice all'interno di virgolette, aggiungiamo solo uno
            if (insideQuotes && i + 1 < line.length() && line[i + 1] == '"')
            {
                currentField.append('"');
                ++i; // Salta il prossimo doppio apice
            } else
            {
                insideQuotes = !insideQuotes; // Cambia stato
            }
        } else if (c == delim && !insideQuotes)
        {
            // Se troviamo il delimitatore fuori dalle virgolette, è la fine di un campo
            result.append(currentField.trimmed());
            currentField.clear();
        } else
        {
            currentField.append(c);
        }
    }

    result.append(currentField.trimmed()); // Aggiunge l'ultimo campo
    return result;
}

QString removeSpecialPrefix(const QString& input)
{
    QString trimmed = input.trimmed();
    QRegularExpression regex("^[^a-zA-Z0-9]+(.*)"); // Cerca caratteri non alfanumerici iniziali

    QRegularExpressionMatch match = regex.match(trimmed);

    return match.hasMatch() ? match.captured(1) : trimmed;
}

QList<QMap<QString, QVariant> > Utility::GetListaDaFileCsv(QString pathFileName, QString delimitatore)
{
    QList< QMap<QString,QVariant> > data;

    QFile file(pathFileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return data;

    QTextStream in(&file);

    QString line = in.readLine();
    QStringList headers = line.split(delimitatore);

    std::transform(headers.begin(), headers.end(), headers.begin(), removeSpecialPrefix);

    while (!in.atEnd())
    {
        line = in.readLine();

        //QStringList fields = line.split(delimitatore);

        QStringList fields =  parseCsvLine(line,delimitatore);

        if (fields.size() == headers.size())
        {
            QMap<QString, QVariant> row;

            //for (int i = 0; i < fields.size(); ++i) row[headers.at(i)] = Utility::SistemaValore(fields.at(i));
            for (int i = 0; i < fields.size(); ++i) row[headers.at(i)] = fields.at(i);

            data.append(row);
        }
    }

    file.close();

    return data;
}

QString Utility::SelectFile()
{
    return QFileDialog::getOpenFileName(nullptr, "Seleziona un file CSV", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "File CSV (*.csv);;Tutti i file (*.*)");
}

QDateTime Utility::GetDateTimeDaStringa(QString dataStringa)
{
    dataStringa = dataStringa.trimmed();

    QLocale locale(QLocale::English); // Imposta il locale in inglese per riconoscere i nomi dei mesi
    QDate date = locale.toDate(dataStringa, "MMMM d, yyyy");

    if (!date.isValid())
    {
        return QDateTime();
    }

    return QDateTime(date, QTime(0, 0));
}

Utility::Utility()
{
}
