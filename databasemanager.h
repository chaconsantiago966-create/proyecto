#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <optional>
#include "user.h"
#include "healthrecord.h"

class DatabaseManager {
public:
    DatabaseManager(QString path);

    std::optional<User> getUserByUsername(const QString &username);
    bool createUser(const QString &username, const QString &pass);

    bool addHealthRecord(const HealthRecord &r);
    QVector<HealthRecord> getRecordsByUserAndDateRange(int userId,
                                                       QDateTime ini,
                                                       QDateTime fin);

private:
    QSqlDatabase db;
    void initTables();
};

#endif // DATABASEMANAGER_H
