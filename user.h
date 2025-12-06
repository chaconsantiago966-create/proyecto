#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:
    int id;
    QString username;
    QString passwordHash;
};

#endif // USER_H
