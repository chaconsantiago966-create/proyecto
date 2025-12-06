#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "csvexporter.h"
#include <QMessageBox>
#include <QStandardItemModel>

MainWindow::MainWindow(const User &u, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , usuario(u)
{
    ui->setupUi(this);

    db = new DatabaseManager("data/health_tracker.db");
    cargarTabla();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnGuardar_clicked() {
    HealthRecord r;
    r.userId = usuario.id;
    r.weight = ui->spPeso->value();
    r.systolicPressure = ui->spSis->value();
    r.diastolicPressure = ui->spDia->value();
    r.glucose = ui->spGlu->value();
    r.timestamp = QDateTime::currentDateTime();

    db->addHealthRecord(r);
    cargarTabla();
}

void MainWindow::on_btnFiltrar_clicked() {
    cargarTabla();
}

void MainWindow::cargarTabla() {
    QDateTime ini = ui->fechaIni->dateTime();
    QDateTime fin = ui->fechaFin->dateTime();

    auto registros = db->getRecordsByUserAndDateRange(usuario.id, ini, fin);

    QStandardItemModel *model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"Peso", "Sis", "Dia", "Glucosa", "Fecha"});

    for (const auto &r : registros) {
        QList<QStandardItem*> fila;
        fila << new QStandardItem(QString::number(r.weight));
        fila << new QStandardItem(QString::number(r.systolicPressure));
        fila << new QStandardItem(QString::number(r.diastolicPressure));
        fila << new QStandardItem(QString::number(r.glucose));
        fila << new QStandardItem(r.timestamp.toString());
        model->appendRow(fila);
    }

    ui->tabla->setModel(model);
}

void MainWindow::on_btnExportar_clicked() {
    auto registros = db->getRecordsByUserAndDateRange(usuario.id,
                                                      ui->fechaIni->dateTime(),
                                                      ui->fechaFin->dateTime());
    CSVExporter::exportRecords(registros, "export.csv");
    QMessageBox::information(this, "Exportado", "Archivo exportado como export.csv");
}
