#include "sqlite3.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stock.h"
#include <QMessageBox>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SearchButton_clicked()
{
}

void MainWindow::getProduct(){

}


void MainWindow::on_stockButton_clicked()
{
}

void MainWindow::on_addButton_clicked()
{
}

void MainWindow::on_removeButton_clicked()
{
}

void MainWindow::on_cancelButton_clicked()
{
}

void MainWindow::on_finshButton_clicked()
{
}

void MainWindow::on_create_db_button_clicked()
{
   qDebug() << "on_create_db_button_clicked";

   sqlite3 *db;
   char *zErrMsg = 0;
   const char *dbName = DATABASE;

   int rc = sqlite3_open(dbName, &db);

   if (rc) {
       qDebug() << "Can't open database: " << sqlite3_errmsg(db) << endl;
       sqlite3_close(db);
       return;
   }

   const char *commands[] = {
       "create table tb_product(id integer primary key autoincrement, name text, price real)"
       , "create table tb_cart(id integer primary key autoincrement, creation datetime)"
       , "create table tb_product_cart(id integer primary key autoincrement, product_fk integer, cart_fk integer, quant integer)"
   };
   int size = sizeof (commands) / sizeof (const char *);

   for (int i = 0; i < size; i++) {
//        rc = sqlite3_exec(db, commands[i], myCallback, 0, &zErrMsg);
       rc = sqlite3_exec(db, commands[i], 0, 0, &zErrMsg);
       if (rc != SQLITE_OK) {
           qDebug() << "SQL error: " << zErrMsg << endl;
           sqlite3_free(zErrMsg);
       }
   }

   sqlite3_close(db);

}

// static
void processDB(sqlite3 *db, const char **commands, int size) {
    qDebug() << "== processDB()" << endl;
    char *zErrMsg = 0;
        for (int i = 0; i < size; i++) {
        int rc = sqlite3_exec(db, commands[i], 0, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            qDebug() << "SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
    }
    sqlite3_close(db);
}

// static
int myCallback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        const char *arg = argv[i] ? argv[i] : "NULL";
        qDebug() << azColName[i] << " = " << arg << " ; ";
    }
    qDebug() << endl;
    return 0;
}


void MainWindow::on_insert_product_clicked()
{
    qDebug() << "on_insert_product_clicked";
    sqlite3 *db;
    const char *dbName = DATABASE;
    int rc = sqlite3_open(dbName, &db);
    if (rc) {
        qDebug() << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    const char *commands[] = {
        "insert into tb_product (name, price) values (\"product name\",1.25)"
    };
    int size = sizeof (commands) / sizeof (const char *);
    processDB(db, commands, size);

}

void MainWindow::on_create_cart_clicked()
{
    qDebug () << "on_create_cart_clicked";
    qDebug() << "on_insert_product_clicked";
    sqlite3 *db;
    const char *dbName = DATABASE;
    int rc = sqlite3_open(dbName, &db);
    if (rc) {
        qDebug() << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    const char *commands[] = {
        "insert into tb_cart (creation) values (datetime('now','localtime'))"
    };
    int size = sizeof (commands) / sizeof (const char *);
    processDB(db, commands, size);

}

void MainWindow::on_product_to_cart_clicked()
{
    qDebug () << "on_product_to_cart_clicked";
    sqlite3 *db;
    const char *dbName = DATABASE;
    int rc = sqlite3_open(dbName, &db);
    if (rc) {
        qDebug() << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    const char *commands[] = {
        "insert into tb_product_cart (product_fk, cart_fk, quant) values (1,5,3)"
    };
    int size = sizeof (commands) / sizeof (const char *);
    processDB(db, commands, size);

}

void MainWindow::on_list_all_clicked()
{
    qDebug () << "on_list_all_clicked";

    sqlite3 *db;
    const char *dbName = DATABASE;
    int rc = sqlite3_open(dbName, &db);
    if (rc) {
        qDebug () << "Can't open database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    const char *commands[] = {
        "select * from tb_product"
        , "select * from tb_cart"
        , "select * from tb_product_cart"
    };
    int size = sizeof (commands) / sizeof (const char *);

    char *zErrMsg = 0;
    for (int i = 0; i < size; i++) {
        int rc = sqlite3_exec(db, commands[i], myCallback, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            qDebug () << "SQL error: " << zErrMsg << endl;
            sqlite3_free(zErrMsg);
        }
    }

    sqlite3_close(db);
}


