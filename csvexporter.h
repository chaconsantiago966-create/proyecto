#ifndef CSVEXPORTER_H
#define CSVEXPORTER_H

#include <QString>
#include "healthrecord.h"

class CSVExporter {
public:
    static bool exportRecords(const QVector<HealthRecord> &records,
                              const QString &path);
};

#endif // CSVEXPORTER_H
