// taskmodel.h
#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "task.h"

class TaskModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TaskModel(QObject *parent = nullptr);

    void addTask(const Task &task);
    void removeTask(int row);
    void markComplete(int row);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QList<Task> tasks;
};

#endif // TASKMODEL_H
