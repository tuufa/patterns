// task.h
#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDate>

// Класс Task представляет одну задачу с основными аттрибутами,
// такими как название, категория, приоритет, дата выполнения и статус задачи.
class Task
{
public:
    // Конструктор для создания задачи с инициализацией всех атрибутов
    Task(const QString &name, const QString &category, const QString &priority, const QDate &dueDate, const QString &status);

    // Метод для получения названия задачи
    QString getName() const;

    // Метод для получения категории задачи
    QString getCategory() const;

    // Метод для получения приоритета задачи
    QString getPriority() const;

    // Метод для получения даты выполнения задачи
    QDate getDueDate() const;

    // Метод для получения статуса задачи
    QString getStatus() const;

    // Метод для установки нового статуса задачи
    void setStatus(const QString &status);

private:
    // Название задачи
    QString name;

    // Категория задачи (например, "Работа", "Личное" и т.д.)
    QString category;

    // Приоритет задачи (например, "Низкий", "Средний", "Высокий")
    QString priority;

    // Дата выполнения задачи
    QDate dueDate;

    // Статус задачи (например, "Не выполнено", "Выполнено")
    QString status;
};


#endif // TASK_H
