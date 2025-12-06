#ifndef HEALTHRECORD_H
#define HEALTHRECORD_H

#include <QDateTime>

class HealthRecord {
public:
    int id;
    int userId;
    double weight;
    int systolicPressure;
    int diastolicPressure;
    double glucose;
    QDateTime timestamp;
};

#endif // HEALTHRECORD_H
