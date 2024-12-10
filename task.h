// task.h
#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>

class Task
{
public:
    Task(const QString &name, const QString &category, const QString &priority, const QDate &dueDate, const QString &status);

    QString getName() const;
    QString getCategory() const;
    QString getPriority() const;
    QDate getDueDate() const;
    QString getStatus() const;

    void setStatus(const QString &status);

private:
    QString name;
    QString category;
    QString priority;
    QDate dueDate;
    QString status;
};

#endif // TASK_H
