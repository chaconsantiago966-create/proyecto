#include "csvexporter.h"
#include <QFile>
#include <QTextStream>

bool CSVExporter::exportRecords(const QVector<HealthRecord> &records,
                                const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);
    out << "Peso,Sis,Dia,Glucosa,Fecha\n";

    for (const auto &r : records) {
        out << r.weight << ","
            << r.systolicPressure << ","
            << r.diastolicPressure << ","
            << r.glucose << ","
            << r.timestamp.toString(Qt::ISODate) << "\n";
    }

    file.close();
    return true;
}
