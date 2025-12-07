#include "databasemanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

DatabaseManager::DatabaseManager(QString path) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    db.open();
    initTables();
}

void DatabaseManager::initTables() {
    QSqlQuery q;
    q.exec("CREATE TABLE IF NOT EXISTS users ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT, "
           "username TEXT UNIQUE, "
           "password_hash TEXT)");

    q.exec("CREATE TABLE IF NOT EXISTS health_records ("
           "id INTEGER PRIMARY KEY AUTOINCREMENT, "
           "user_id INTEGER, weight REAL, systolic INTEGER, "
           "diastolic INTEGER, glucose REAL, timestamp TEXT)");
}

std::optional<User> DatabaseManager::getUserByUsername(const QString &username) {
    QSqlQuery q;
    q.prepare("SELECT id, username, password_hash FROM users WHERE username=?");
    q.addBindValue(username);
    q.exec();

    if (q.next()) {
        User u;
        u.id = q.value(0).toInt();
        u.username = q.value(1).toString();
        u.passwordHash = q.value(2).toString();
        return u;
    }
    return std::nullopt;
}

bool DatabaseManager::createUser(const QString &username, const QString &pass) {
    QSqlQuery q;
    q.prepare("INSERT INTO users (username, password_hash) VALUES (?,?)");
    q.addBindValue(username);
    q.addBindValue(pass);
    return q.exec();
}

bool DatabaseManager::addHealthRecord(const HealthRecord &r) {
    QSqlQuery q;
    q.prepare("INSERT INTO health_records "
              "(user_id, weight, systolic, diastolic, glucose, timestamp) "
              "VALUES (?,?,?,?,?,?)");
    q.addBindValue(r.userId);
    q.addBindValue(r.weight);
    q.addBindValue(r.systolicPressure);
    q.addBindValue(r.diastolicPressure);
    q.addBindValue(r.glucose);
    q.addBindValue(r.timestamp.toString(Qt::ISODate));
    return q.exec();
}

QVector<HealthRecord> DatabaseManager::getRecordsByUserAndDateRange(
        int userId, QDateTime ini, QDateTime fin)
{
    QVector<HealthRecord> lista;

    QSqlQuery q;
    q.prepare("SELECT id, weight, systolic, diastolic, glucose, timestamp "
              "FROM health_records WHERE user_id=? "
              "AND timestamp BETWEEN ? AND ?");
    q.addBindValue(userId);
    q.addBindValue(ini.toString(Qt::ISODate));
    q.addBindValue(fin.toString(Qt::ISODate));
    q.exec();

    while (q.next()) {
        HealthRecord r;
        r.id = q.value(0).toInt();
        r.weight = q.value(1).toDouble();
        r.systolicPressure = q.value(2).toInt();
        r.diastolicPressure = q.value(3).toInt();
        r.glucose = q.value(4).toDouble();
        r.timestamp = QDateTime::fromString(q.value(5).toString(), Qt::ISODate);
        lista.append(r);
    }

    return lista;
}
