#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDebug>
#include <QMainWindow>

#define DATABASE "../database/QtRetail.db"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_SearchButton_clicked();

    void on_stockButton_clicked();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_cancelButton_clicked();

    void on_finshButton_clicked();

    void on_create_db_button_clicked();

    void on_insert_product_clicked();

    void on_create_cart_clicked();

    void on_product_to_cart_clicked();

    void on_list_all_clicked();

private:
    Ui::MainWindow *ui;
    void getProduct();
};

#endif // MAINWINDOW_H
