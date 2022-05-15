#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    ui->settings->setDisabled(true);
    ui->comboBox->setDisabled(true);
    ui->pushButton->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->saveBackup->setDisabled(true);

    if (!backupDir.exists() || !defaultsDir.exists()) {
        QMessageBox::information(0,"Предупреждение", "Не найден каталог с исходными файлами или с файлами бэкапа. Они сейчас создадутся.\nБэкапы по умолчанию будут сохранятся в " + backupDir.path() + "\nИсходные файлы будут сохранены в " + defaultsDir.path());

            if (backupDir.mkpath("."))
                QMessageBox::information(0,"Успешно", "Папка с бэкапами создана и доступна по пути: " + backupDir.path());
            else
                QMessageBox::critical(0,"Ошибка", "Не удалось создать папку с бэкапами по пути: "+ backupDir.path());
            if (defaultsDir.mkpath(".")) {
                QMessageBox::information(0,"Успешно", "Папка с исходными файлами создана и доступна по пути: " + backupDir.path()+". Копируем текущие файлы...");
                QDir etcDir("/etc");
                QFileInfoList fileInfoList = etcDir.entryInfoList(QDir::Files);
                foreach(QFileInfo file, fileInfoList){
                    if (!QFile::copy(file.absoluteFilePath(), defaultsDir.path()+'/'+file.fileName()))
                        QMessageBox::critical(0,"Ошибка", "Файл "+ file.fileName() +" скопировать не удалось!");
                }
            }
            else
                QMessageBox::critical(0,"Ошибка", "Не удалось создать папку с исходниками по пути: "+ backupDir.path());   
    }


    QStringList filters;
    //filters << "*.conf" << "*.bashrc";
    model = new QFileSystemModel(this);

    model -> setFilter(QDir::Files | QDir::NoSymLinks);
    model -> setNameFilters(filters);
    model -> setRootPath("");
    model -> setNameFilterDisables(false);

    ui -> lvDir -> setModel(model);
    ui -> lvDir -> setRootIndex(model->index("/etc"));




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showDefaultText(const QFileSystemModel &model, const QModelIndex &index){
    QFile file(defaultsDir.path() + "/" + model.fileName(index));
    if (file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        ui -> settings_2 -> setText(in.readAll());
        file.close();
    }
    else {
        ui -> settings_2 -> setText("Сохраненный исходник файла не найден");
    }
}


void MainWindow::showBackupText(const QFileSystemModel &model, const QModelIndex &index){
    QFile file(backupDir.path() + "/" + model.fileName(index));
    if (file.open(QIODevice::ReadOnly)){
    QTextStream in(&file);
    ui -> settings_2 -> setText(in.readAll());
    file.close();
    }
    else {
        ui -> settings_2 -> setText("Бэкап файла не найден");
    }
}

void MainWindow::showMainText(const QFileSystemModel &model, const QModelIndex &index){
    QFile file(model.filePath(index));
    ui -> currentConf -> setText(model.fileName(index));
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    ui -> settings -> setText(in.readAll());
    file.close();
}

void MainWindow::on_lvDir_clicked(const QModelIndex &index)
{

    ui->pushButton_3->setDisabled(false);
    ui->pushButton_4->setDisabled(false);
    ui->saveBackup->setDisabled(false);

    ui->comboBox->setDisabled(false);
    if (ui->pushButton->isEnabled()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Предупреждение");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Все несохраненные изменения будут потеряны. Продолжить?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::No:
             ui->lvDir->setCurrentIndex(prevIndex);
             break;
        case QMessageBox::Yes:
        {
            showMainText(*model, index);
            if (ui->comboBox->currentIndex()==0) showBackupText(*model, index);
            else if (ui->comboBox->currentIndex()==0) showDefaultText(*model, index);

            ui ->settings->setDisabled(false);
            ui->pushButton->setDisabled(true);
            prevIndex = index;
            break;
        }
        default:
            break;
        }
    }
    else {
        showMainText(*model, index);
        if (ui->comboBox->currentIndex()==0) showBackupText(*model, index);
        else if (ui->comboBox->currentIndex()==1) showDefaultText(*model, index);

        ui -> settings -> setDisabled(false);
        ui -> pushButton -> setDisabled(true);
        prevIndex = index;
    }
}



void MainWindow::on_pushButton_clicked()
{

    QFile file(model->filePath(ui->lvDir->currentIndex()));
    QMessageBox msgBox;
    msgBox.setWindowTitle("Предупреждение");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Файл " + model->fileName(ui->lvDir->currentIndex()) + " будет перезаписан!");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        break;
    case QMessageBox::Ok:
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            QMessageBox::warning(0,"Ошибка","Файл " + model->fileName(ui->lvDir->currentIndex()) + " открыть не удалось.");
        else {
            QTextStream out(&file);
            out << ui->settings->toPlainText();
            if (out.status() != QTextStream::Ok)
                QMessageBox::critical(0,"Ошибка","Файл " + model->fileName(ui->lvDir->currentIndex()) + " перезаписать не удалось.");
            else {
                ui->pushButton->setDisabled(true);
                QMessageBox::information(0,"Успешно", "Файл " + model->fileName(ui->lvDir->currentIndex()) + " изменен.");
            }
            file.close();
        }
        break;
    default:
        break;
    }
}



void MainWindow::on_saveBackup_clicked()
{



    QFile file(backupDir.path() + "/" + model->fileName(ui->lvDir->currentIndex()));
    if (file.exists())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Предупреждение");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " уже существует и будет перезаписан.");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret = msgBox.exec();
        switch (ret) {
        case QMessageBox::Save:
            break;
        case QMessageBox::Ok:
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
                QMessageBox::warning(0,"Ошибка","Бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " открыть не удалось.");
            else {
                QTextStream out(&file);
                out << ui->settings->toPlainText();
                file.close();
                if (out.status() != QTextStream::Ok) {
                    QMessageBox::critical(0,"Ошибка","Создать бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " не удалось.");

                }
                else{

                    showMainText(*model, ui->lvDir->currentIndex());
                    showBackupText(*model, ui->lvDir->currentIndex());
                    ui->comboBox->setCurrentIndex(0);

                    QMessageBox::information(0,"Успешно", "Бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " создан.");
                    ui->pushButton->setDisabled(true);

                }

        }

        break;
    default:
        break;
        }
    }
    else {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            QMessageBox::warning(0,"Ошибка","Не удалось создать файл " + model->fileName(ui->lvDir->currentIndex()) + " для записи.");
        else {
            QTextStream out(&file);
            out << ui->settings->toPlainText();
            file.close();

            if (out.status() != QTextStream::Ok)
                QMessageBox::critical(0,"Ошибка","Создать бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " не удалось.");
            else{
                showMainText(*model, ui->lvDir->currentIndex());
                showBackupText(*model, ui->lvDir->currentIndex());
                ui->comboBox->setCurrentIndex(0);

                QMessageBox::information(0,"Успешно", "Бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " создан.");
                ui->pushButton->setDisabled(true);
            }
        }
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QFile file(model->filePath(ui->lvDir->currentIndex()));
    QFile backup(backupDir.path() + "/" + model->fileName(ui->lvDir->currentIndex()));
    QMessageBox msgBox;
    msgBox.setWindowTitle("Предупреждение");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Файл " + model->fileName(ui->lvDir->currentIndex()) + " будет заменен бэкапом!");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        break;
    case QMessageBox::Ok:
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            QMessageBox::warning(0,"Ошибка","Файл " + model->fileName(ui->lvDir->currentIndex()) + " открыть не удалось.");
        else if (!backup.open(QIODevice::ReadOnly | QIODevice::Text))
            QMessageBox::warning(0,"Ошибка","Бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " открыть не удалось.");
        else {
            QTextStream out(&file);
            ui->settings->setText(backup.readAll());
            out << ui->settings->toPlainText();
            if (out.status() != QTextStream::Ok)
                QMessageBox::critical(0,"Ошибка","Файл " + model->fileName(ui->lvDir->currentIndex()) + " восстановить из бэкапа не удалось.");
            else {
                ui->pushButton->setDisabled(true);

                QMessageBox::information(0,"Успешно", "Файл " + model->fileName(ui->lvDir->currentIndex()) + " восстановлен из бэкапа.");
            }
            file.close();
        }
        break;
    default:
        break;
    }
}


void MainWindow::on_settings_textChanged()
{
    ui->pushButton->setDisabled(false);

}


void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0) {
        showBackupText(*model, ui->lvDir->currentIndex());
    } else if (index == 1) {
        showDefaultText(*model, ui->lvDir->currentIndex());
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QFile file(model->filePath(ui->lvDir->currentIndex()));
    QFile backup(defaultsDir.path() + "/" + model->fileName(ui->lvDir->currentIndex()));
    QMessageBox msgBox;
    msgBox.setWindowTitle("Предупреждение");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Файл " + model->fileName(ui->lvDir->currentIndex()) + " будет заменен исходным сохраненным!");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        break;
    case QMessageBox::Ok:
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            QMessageBox::warning(0,"Ошибка","Файл " + model->fileName(ui->lvDir->currentIndex()) + " открыть не удалось.");
        else if (!backup.open(QIODevice::ReadOnly | QIODevice::Text))
            QMessageBox::warning(0,"Ошибка","Бэкап файла " + model->fileName(ui->lvDir->currentIndex()) + " открыть не удалось.");
        else {
            QTextStream out(&file);
            ui->settings->setText(backup.readAll());
            out << ui->settings->toPlainText();
            if (out.status() != QTextStream::Ok)
                QMessageBox::critical(0,"Ошибка","Файл " + model->fileName(ui->lvDir->currentIndex()) + " восстановить исходным не удалось.");
            else {
                ui->pushButton->setDisabled(true);

                QMessageBox::information(0,"Успешно", "Файл " + model->fileName(ui->lvDir->currentIndex()) + " восстановлен исходным.");
            }
            file.close();
        }
        break;
    default:
        break;
    }
}


void MainWindow::on_lvDir_activated(const QModelIndex &index)
{
    on_lvDir_clicked(index);
}

