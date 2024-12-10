// taskmodel.h
#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "task.h"

// Класс TaskModel, наследуемый от QAbstractTableModel
// Этот класс представляет модель данных для списка задач,
// которая используется в связке с QTableView.
class TaskModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    // Конструктор модели
    explicit TaskModel(QObject *parent = nullptr);

    // Метод для добавления новой задачи в модель
    void addTask(const Task &task);

    // Метод для удаления задачи из модели по индексу строки
    void removeTask(int row);

    // Метод для отметки задачи как выполненной
    void markComplete(int row);

    // Метод для получения количества строк (задач) в модели
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    // Метод для получения количества столбцов в модели
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Метод для получения данных для отображения в представлении
    QVariant data(const QModelIndex &index, int role) const override;

    // Метод для получения данных заголовков столбцов или строк
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    // Список задач, хранящийся в модели
    QList<Task> tasks;
};


#endif // TASKMODEL_H
