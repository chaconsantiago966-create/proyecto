#ifndef HEALTHANALYZER_H
#define HEALTHANALYZER_H

#include "healthrecord.h"

class HealthAnalyzer {
public:
    struct Stats {
        double avgWeight = 0;
        double avgSystolic = 0;
        double avgDiastolic = 0;
        double avgGlucose = 0;
    };

    static Stats calculateStats(const QVector<HealthRecord> &records);
};

#endif // HEALTHANALYZER_H
