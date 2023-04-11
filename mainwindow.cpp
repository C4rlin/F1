#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      nomeDoArquivo("")
{
    ui->setupUi(this);
    ui->lineEditNomeDoArquivo->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonClassificacaoFinal_clicked()
{
    try {
        ce::ManipularArquivo dados(nomeDoArquivo);
        dados.buscarDadosNoArquivo();
        std::vector<ce::Piloto> colecaoPilotos = dados.getListaDePilotosF1();
        std::sort(colecaoPilotos.begin(), colecaoPilotos.end(), [](const ce::Piloto& p1, const ce::Piloto& p2)
        {
            return p1.getPontuacaoFinal() > p2.getPontuacaoFinal();
        });

        ui->tableWidgetSaida->setRowCount(colecaoPilotos.size());
        ui->tableWidgetSaida->setColumnCount(4);
        ui->tableWidgetSaida->setHorizontalHeaderLabels({"Código","Nome","Pontuação Final","Classificação"});

        int classificacaoFinal = 1;
        for(size_t i = 0; i < colecaoPilotos.size(); i++)
        {
            QTableWidgetItem *codigo = new QTableWidgetItem(QString::number(colecaoPilotos[i].getCodigo()));
            QTableWidgetItem *nome = new QTableWidgetItem(colecaoPilotos[i].getNome());
            QTableWidgetItem *pontuacaoFinal = new QTableWidgetItem(QString::number(colecaoPilotos[i].getPontuacaoFinal()));
            QTableWidgetItem *classificacao = new QTableWidgetItem(QString::number(classificacaoFinal));

            if (classificacaoFinal == 1)
            {
                classificacao->setText("Campeão");
                classificacao->setBackground(QColor(Qt::green));
            }
            if (classificacaoFinal == 2)
            {
                classificacao->setText("Vice-Campeão");
                classificacao->setBackground(QColor(Qt::yellow));
            }

            ui->tableWidgetSaida->setItem(i,0,codigo);
            ui->tableWidgetSaida->setItem(i,1,nome);
            ui->tableWidgetSaida->setItem(i,2,pontuacaoFinal);
            ui->tableWidgetSaida->setItem(i,3,classificacao);

            codigo->setTextAlignment(Qt::AlignCenter);
            nome->setTextAlignment(Qt::AlignCenter);
            pontuacaoFinal->setTextAlignment(Qt::AlignCenter);
            classificacao->setTextAlignment(Qt::AlignCenter);

            if(i < colecaoPilotos.size() - 1 && colecaoPilotos[i].getPontuacaoFinal() != colecaoPilotos[i+1].getPontuacaoFinal())
            {
                classificacaoFinal = i+2;
            }
        }

        ui->tableWidgetSaida->resizeColumnToContents(0);
        ui->tableWidgetSaida->resizeColumnToContents(1);
        ui->tableWidgetSaida->resizeColumnToContents(2);
        ui->tableWidgetSaida->resizeColumnToContents(3);
        ui->tableWidgetSaida->verticalHeader()->setVisible(false);


        for (int i = 0; i < ui->tableWidgetSaida->columnCount(); i++) {
            int width = ui->tableWidgetSaida->columnWidth(i);
            ui->tableWidgetSaida->setColumnWidth(i, width + 20);
        }

    } catch (QString &erro) {
        QMessageBox::information(this,"DADOS",erro);
    }
}

void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        nomeDoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo","C:/Users/c4rli/Documents/Faculdade","Arquivos Textos (*.csv *.txt *.*)");
        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo não foi selecionado");
        ui->lineEditNomeDoArquivo->setText(nomeDoArquivo);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

