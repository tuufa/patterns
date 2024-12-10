#ifndef PATTERNS_H
#define PATTERNS_H

#include <QMainWindow>
#include <QTableView>
#include "taskmodel.h"
#include <QJsonObject>


namespace Ui
{
class patterns;  // Указание на класс интерфейса для окна "patterns"
}


class patterns : public QMainWindow
{
    Q_OBJECT  // Макрос для использования сигналов и слотов в Qt

public:
    // Конструктор класса patterns, принимающий указатель на родительский элемент (по умолчанию nullptr)
    explicit patterns(QWidget *parent = nullptr);

    // Деструктор класса patterns, который очищает ресурсы интерфейса
    ~patterns();

private slots:
    // Слот, который вызывается при нажатии на кнопку добавления задачи
    void on_addTaskButton_clicked();

    // Слот, который вызывается при нажатии на кнопку удаления задачи
    void on_removeTaskButton_clicked();

    // Слот, который вызывается при нажатии на кнопку для отметки задачи как выполненной
    void on_markCompleteButton_clicked();

    // Слот, который вызывается при нажатии на кнопку сохранения задач
    void on_saveTasksButton_clicked();

    // Слот, который вызывается при нажатии на кнопку импорта задач
    void on_importTasksButton_clicked();

private:
    // Метод для сохранения задач в CSV файл
    void saveTasksToCSV(const QString &fileName);

    // Метод для сохранения задач в JSON файл
    void saveTasksToJSON(const QString &fileName);

    // Метод для импорта задач из CSV файла
    void importTasksFromCSV(const QString &fileName);

    // Метод для импорта задач из JSON файла
    void importTasksFromJSON(const QString &fileName);

    // Указатель на интерфейс, который управляет элементами UI
    Ui::patterns *ui;

    // Указатель на модель данных задач (TaskModel), которая управляет списком задач
    TaskModel *taskModel;
};


#endif // PATTERNS_H
