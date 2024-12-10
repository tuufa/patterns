// task.cpp
#include "task.h"

Task::Task(const QString &name, const QString &category, const QString &priority, const QDate &dueDate, const QString &status)
    : name(name), category(category), priority(priority), dueDate(dueDate), status(status) {}

QString Task::getName() const { return name; }
QString Task::getCategory() const { return category; }
QString Task::getPriority() const { return priority; }
QDate Task::getDueDate() const { return dueDate; }
QString Task::getStatus() const { return status; }

void Task::setStatus(const QString &status) {this->status = status;}
