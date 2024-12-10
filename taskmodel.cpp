#include "taskmodel.h"
#include <QVariant>

// Реализация модели TaskModel, наследуемой от QAbstractTableModel

// Конструктор модели
TaskModel::TaskModel(QObject *parent) : QAbstractTableModel(parent) {}

// Метод для добавления задачи в модель
void TaskModel::addTask(const Task &task)
{
    qDebug() << "TaskModel::addTask called"; // Логируем вызов метода
    // Уведомляем представление о начале вставки строк
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    tasks.append(task); // Добавляем задачу в список
    endInsertRows(); // Уведомляем представление о завершении вставки строк
}

// Метод для удаления задачи из модели
void TaskModel::removeTask(int row)
{
    // Уведомляем представление о начале удаления строки
    beginRemoveRows(QModelIndex(), row, row);
    tasks.removeAt(row); // Удаляем задачу из списка
    endRemoveRows(); // Уведомляем представление о завершении удаления строки
}

// Метод для отметки задачи как выполненной
void TaskModel::markComplete(int row)
{
    tasks[row].setStatus("Выполнено"); // Устанавливаем статус задачи
    // Уведомляем представление об изменении данных в соответствующей ячейке
    emit dataChanged(index(row, 4), index(row, 4));
}

// Метод, возвращающий количество строк в модели
int TaskModel::rowCount(const QModelIndex &parent) const
{
    return tasks.size(); // Количество строк равно количеству задач в списке
}

// Метод, возвращающий количество столбцов в модели
int TaskModel::columnCount(const QModelIndex &parent) const
{
    return 5; // В модели 5 столбцов
}

// Метод для предоставления данных модели
QVariant TaskModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) // Обрабатываем только роль отображения данных
    {
        const Task &task = tasks[index.row()]; // Получаем задачу по индексу строки
        switch (index.column()) // Возвращаем данные в зависимости от столбца
        {
        case 0: return task.getName(); // Название задачи
        case 1: return task.getCategory(); // Категория задачи
        case 2: return task.getPriority(); // Приоритет задачи
        case 3: return task.getDueDate().toString("dd.MM.yyyy"); // Срок задачи
        case 4: return task.getStatus(); // Статус задачи
        default: return QVariant(); // Для несуществующих столбцов возвращаем пустое значение
        }
    }
    return QVariant(); // Для других ролей возвращаем пустое значение
}

// Метод для предоставления заголовков модели
QVariant TaskModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) // Заголовки столбцов
    {
        switch (section)
        {
        case 0: return "Название"; // Заголовок для столбца с названием
        case 1: return "Категория"; // Заголовок для столбца с категорией
        case 2: return "Приоритет"; // Заголовок для столбца с приоритетом
        case 3: return "Срок"; // Заголовок для столбца со сроком
        case 4: return "Статус"; // Заголовок для столбца со статусом
        default: return QVariant(); // Пустой заголовок для несуществующих столбцов
        }
    }
    if (role == Qt::DisplayRole && orientation == Qt::Vertical) // Заголовки строк
    {
        return QVariant(); // Не задаем заголовки для строк
    }
    return QVariant(); // Пустое значение для других ролей
}
