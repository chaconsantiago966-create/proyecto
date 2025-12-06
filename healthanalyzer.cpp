#include "healthanalyzer.h"

HealthAnalyzer::Stats HealthAnalyzer::calculateStats(const QVector<HealthRecord> &records) {
    Stats s;

    if (records.isEmpty()) return s;

    for (auto &r : records) {
        s.avgWeight += r.weight;
        s.avgSystolic += r.systolicPressure;
        s.avgDiastolic += r.diastolicPressure;
        s.avgGlucose += r.glucose;
    }

    int n = records.size();
    s.avgWeight /= n;
    s.avgSystolic /= n;
    s.avgDiastolic /= n;
    s.avgGlucose /= n;

    return s;
}
