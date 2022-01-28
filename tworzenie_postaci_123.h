#ifndef TWORZENIE_POSTACI_123_H
#define TWORZENIE_POSTACI_123_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
QT_BEGIN_NAMESPACE
namespace Ui { class Tworzenie_Postaci_123; }
QT_END_NAMESPACE

class Tworzenie_Postaci_123 : public QMainWindow
{
    Q_OBJECT

public:
    Tworzenie_Postaci_123(QWidget *parent = nullptr);
    ~Tworzenie_Postaci_123();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_textEdit_textChanged();

    void on_pushButton_13_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_textBrowser_18_textChanged();

    void on_pushButton_14_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_20_clicked();

private:
    Ui::Tworzenie_Postaci_123 *ui;
    QSqlDatabase mydb;
};
#endif // TWORZENIE_POSTACI_123_H
