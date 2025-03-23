#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileInfo>

#include "Utility/Utility.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->Init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    QString nomeFileCsv = Utility::SelectFile();

    Motore = new Engine(nomeFileCsv);

    Motore->leggiFile();

    Motore->stampaRighe();

    QFileInfo fileInfo(nomeFileCsv);

    QString outPutCsv = QString("%1/PRO-PROGETTI.csv").arg(fileInfo.absolutePath());

    Motore->scriviFileCsv(outPutCsv);

    exit(0);
}

