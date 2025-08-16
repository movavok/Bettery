#ifndef DB_WORKER_H
#define DB_WORKER_H

#include <QMainWindow>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

struct Task
{
    int id = 0;
    QString name;
    QString day;
    bool done = false;
};

class db_worker : public QObject
{
    Q_OBJECT
public:
    explicit db_worker(QObject *parent = nullptr);
    ~db_worker();
    bool createTable();
    void addTask(const QString, const QString, bool);
private:
    QSqlDatabase db;
};

#endif // DB_WORKER_H
