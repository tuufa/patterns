#ifndef PATTERNS_H
#define PATTERNS_H

#include <QMainWindow>
#include <QTableView>
#include "taskmodel.h"
#include <QJsonObject>

namespace Ui
{
class patterns;
}

class patterns : public QMainWindow
{
    Q_OBJECT

public:
    explicit patterns(QWidget *parent = nullptr);
    ~patterns();

private slots:
    void on_addTaskButton_clicked();
    void on_removeTaskButton_clicked();
    void on_markCompleteButton_clicked();
    void on_saveTasksButton_clicked();
    void on_importTasksButton_clicked();

private:
    void saveTasksToCSV(const QString &fileName);
    void saveTasksToJSON(const QString &fileName);
    void importTasksFromCSV(const QString &fileName);
    void importTasksFromJSON(const QString &fileName);

    Ui::patterns *ui;
    TaskModel *taskModel;
};

#endif // PATTERNS_H
