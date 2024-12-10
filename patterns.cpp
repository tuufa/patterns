#include "patterns.h"
#include "ui_patterns.h"
#include "task.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>

patterns::patterns(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::patterns),
    taskModel(new TaskModel(this))
{
    ui->setupUi(this);

    ui->taskTable->setModel(taskModel);
}

patterns::~patterns()
{
    delete ui;
}

void patterns::on_addTaskButton_clicked()
{
    qDebug() << "Добавление задачи";
    QString name = ui->taskNameInput->text().trimmed();
    if (name.isEmpty())
    {
        QMessageBox::warning(this, "Ошибка", "Название задачи не может быть пустым.");
        return;
    }

    QString category = ui->categoryInput->currentText();
    QString priority = ui->priorityInput->currentText();
    QDate dueDate = ui->dueDateInput->date();
    QString status = "Не выполнено";

    Task newTask(name, category, priority, dueDate, status);
    taskModel->addTask(newTask);

    ui->taskNameInput->clear();
}



void patterns::on_removeTaskButton_clicked()
{
    QModelIndex index = ui->taskTable->currentIndex();
    if (index.isValid())
    {
        taskModel->removeTask(index.row());
    }
    else
    {
        QMessageBox::warning(this, "Удаление задачи", "Пожалуйста, выберите задачу для удаления.");
    }
}

void patterns::on_markCompleteButton_clicked() {
    QModelIndex index = ui->taskTable->currentIndex();
    if (index.isValid())
    {
        taskModel->markComplete(index.row());
    }
    else
    {
        QMessageBox::warning(this, "Отметить выполненной", "Пожалуйста, выберите задачу для отметки.");
    }
}

void patterns::on_saveTasksButton_clicked()
{
    // Получаем выбранный формат
    QString selectedFormat = ui->saveFormatInput->currentText();

    // Выбираем файл для сохранения
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить задачи", "",
                                                    (selectedFormat == "CSV") ? "CSV Files (*.csv)" : "JSON Files (*.json)");

    if (fileName.isEmpty())
    {
        return; // Пользователь отменил выбор файла
    }

    if (selectedFormat == "CSV")
    {
        saveTasksToCSV(fileName);
    }
    else if (selectedFormat == "JSON")
    {
        saveTasksToJSON(fileName);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Неизвестный формат сохранения.");
    }
}

// Метод для сохранения в CSV
void patterns::saveTasksToCSV(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }

    QTextStream out(&file);
    out << "Название,Категория,Приоритет,Срок,Статус\n"; // Заголовок

    for (int row = 0; row < taskModel->rowCount(); ++row)
    {
        QStringList rowData;
        for (int col = 0; col < taskModel->columnCount(); ++col)
        {
            QVariant data = taskModel->data(taskModel->index(row, col), Qt::DisplayRole);
            rowData << data.toString().replace("\"", "\"\""); // Экранируем кавычки
        }
        out << "\"" << rowData.join("\",\"") << "\"\n";
    }

    file.close();
    QMessageBox::information(this, "Сохранение", "Задачи успешно сохранены в CSV.");
}

// Метод для сохранения в JSON
void patterns::saveTasksToJSON(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл для записи.");
        return;
    }

    QJsonArray tasksArray;
    for (int row = 0; row < taskModel->rowCount(); ++row)
    {
        QJsonObject taskObject;
        taskObject["name"] = taskModel->data(taskModel->index(row, 0), Qt::DisplayRole).toString();
        taskObject["category"] = taskModel->data(taskModel->index(row, 1), Qt::DisplayRole).toString();
        taskObject["priorety"] = taskModel->data(taskModel->index(row, 2), Qt::DisplayRole).toString();
        taskObject["date"] = taskModel->data(taskModel->index(row, 3), Qt::DisplayRole).toString();
        taskObject["status"] = taskModel->data(taskModel->index(row, 4), Qt::DisplayRole).toString();
        tasksArray.append(taskObject);
    }

    QJsonDocument doc(tasksArray);
    file.write(doc.toJson());
    file.close();
    QMessageBox::information(this, "Сохранение", "Задачи успешно сохранены в JSON.");
}

void patterns::on_importTasksButton_clicked()
{
    QString selectedFormat = ui->saveFormatInput->currentText();

    QString fileName = QFileDialog::getOpenFileName(this, "Импорт задач", "",
                                                    (selectedFormat == "CSV") ? "CSV Files (*.csv)" : "JSON Files (*.json)");

    if (fileName.isEmpty())
    {
        return;
    }

    if (selectedFormat == "CSV")
    {
        importTasksFromCSV(fileName);
    }
    else if (selectedFormat == "JSON")
    {
        importTasksFromJSON(fileName);
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Неизвестный формат файла.");
    }
}


void patterns::importTasksFromCSV(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть CSV файл.");
        return;
    }

    QTextStream in(&file);
    QString headerLine = in.readLine(); // Пропускаем заголовок

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList columns = line.split(',');

        if (columns.size() != 5)
        {
            QMessageBox::warning(this, "Ошибка", "Некорректный формат строки в CSV файле.");
            continue;
        }

        QString name = columns[0].trimmed().remove('"');
        QString category = columns[1].trimmed().remove('"');
        QString priority = columns[2].trimmed().remove('"');
        QDate dueDate = QDate::fromString(columns[3].trimmed().remove('"'), "dd.MM.yyyy");
        QString status = columns[4].trimmed().remove('"');

        if (!dueDate.isValid())
        {
            QMessageBox::warning(this, "Ошибка", "Некорректная дата: " + columns[3]);
            continue;
        }

        Task task(name, category, priority, dueDate, status);
        taskModel->addTask(task);
    }

    file.close();
    QMessageBox::information(this, "Импорт", "Задачи успешно импортированы из CSV.");
}

void patterns::importTasksFromJSON(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть JSON файл.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);
    if (!doc.isArray())
    {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат JSON файла.");
        return;
    }

    QJsonArray tasksArray = doc.array();
    for (const QJsonValue &value : tasksArray)
    {
        if (!value.isObject())
        {
            QMessageBox::warning(this, "Ошибка", "Некорректная структура JSON файла.");
            continue;
        }

        QJsonObject taskObject = value.toObject();

        QString name = taskObject["name"].toString();
        QString category = taskObject["category"].toString();
        QString priority = taskObject["priorety"].toString();
        QDate dueDate = QDate::fromString(taskObject["date"].toString(), "dd.MM.yyyy");
        QString status = taskObject["status"].toString();

        if (name.isEmpty() || !dueDate.isValid())
        {
            QMessageBox::warning(this, "Ошибка", "Пропущены обязательные поля или некорректная дата.");
            continue;
        }

        Task task(name, category, priority, dueDate, status);
        taskModel->addTask(task);
    }

    QMessageBox::information(this, "Импорт", "Задачи успешно импортированы из JSON.");
}


