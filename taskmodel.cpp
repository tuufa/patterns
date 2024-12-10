#include "taskmodel.h"
#include <QVariant>

TaskModel::TaskModel(QObject *parent) : QAbstractTableModel(parent) {}

void TaskModel::addTask(const Task &task)
{
    qDebug() << "TaskModel::addTask called";
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    tasks.append(task);
    endInsertRows();
}


void TaskModel::removeTask(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    tasks.removeAt(row);
    endRemoveRows();
}

void TaskModel::markComplete(int row)
{
    tasks[row].setStatus("Выполнено");
    emit dataChanged(index(row, 4), index(row, 4));
}

int TaskModel::rowCount(const QModelIndex &parent) const
{
    return tasks.size();
}

int TaskModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        const Task &task = tasks[index.row()];
        switch (index.column())
        {
        case 0: return task.getName();
        case 1: return task.getCategory();
        case 2: return task.getPriority();
        case 3: return task.getDueDate().toString("dd.MM.yyyy");
        case 4: return task.getStatus();
        default: return QVariant();
        }
    }
    return QVariant();
}

QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section) {
        case 0: return "Название";
        case 1: return "Категория";
        case 2: return "Приоритет";
        case 3: return "Срок";
        case 4: return "Статус";
        default: return QVariant();
        }
    }
    // Не задаем заголовки для строк
    if (role == Qt::DisplayRole && orientation == Qt::Vertical)
    {
        return QVariant();
    }
    return QVariant();
}

