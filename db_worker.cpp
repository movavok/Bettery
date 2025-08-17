#include "db_worker.h"

db_worker::db_worker(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasks.db");
    if (!db.open()) {
        qDebug() << "База не открылась:" << db.lastError().text();
    } else {

    }
}

db_worker::~db_worker()
{
    if (db.isOpen())
        db.close();
}

bool db_worker::createTable()
{
    QSqlQuery query(db);
    QString createTable =
        "CREATE TABLE IF NOT EXISTS tasks ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "day TEXT NOT NULL, "
        "done INTEGER NOT NULL DEFAULT 0"
        ")";
    if (!query.exec(createTable)) {
        qDebug() << "База не создалась:" << query.lastError().text();
        return false;
    }
    return true;
}

void db_worker::addTask(const QString &name, const QString &day, bool done)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO tasks (name, day, done) VALUES (?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(day);
    query.addBindValue(done ? 1 : 0);

    if (!query.exec()) {
        qDebug() << "Задача не добавлена в таблицу:" << query.lastError().text();
        return;
    }
}

