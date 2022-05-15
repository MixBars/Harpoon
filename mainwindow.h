#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lvDir_clicked(const QModelIndex &index);

    void showMainText(const QFileSystemModel &model, const QModelIndex &index);

    void showBackupText(const QFileSystemModel &model, const QModelIndex &index);

    void showDefaultText(const QFileSystemModel &model, const QModelIndex &index);

    void on_saveBackup_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_settings_textChanged();

    void on_comboBox_activated(int index);

    void on_pushButton_4_clicked();

    void on_lvDir_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;

};
#endif // MAINWINDOW_H
