#include "manipulararquivo.h"

namespace ce{

const std::vector<Piloto> ManipularArquivo::getListaDePilotosF1() const
{
    return listaDePilotosF1;
}

ManipularArquivo::ManipularArquivo(QString nomeDoArquivo):
    nomeDoArquivo(nomeDoArquivo)
{
    if(nomeDoArquivo.isEmpty()) throw QString("Nome do Arquivo esta vazio");
    this->nomeDoArquivo = nomeDoArquivo;
}
void ManipularArquivo::buscarDadosNoArquivo(){
    try {
        std::ifstream arquivo;
        arquivo.open(nomeDoArquivo.toStdString().c_str());
        if(!arquivo.is_open()) throw "O arquivo não pode ser aberto!";

        std::string linha;

        getline(arquivo, linha);

        while(!arquivo.eof()){
            QString texto = QString::fromStdString(linha);
            QStringList strList = texto.split(';');
            int codigo = strList[0].toInt();
            QString nome = strList[1];
            QString pais = strList[2];
            int idade = strList[3].toInt();
            QString equipe = strList[4];
            QString motor = strList[5];
            int arrayClassificacao[7];
            arrayClassificacao[0] = strList[6].toInt();
            arrayClassificacao[1] = strList[7].toInt();
            arrayClassificacao[2] = strList[8].toInt();
            arrayClassificacao[3] = strList[9].toInt();
            arrayClassificacao[4] = strList[10].toInt();
            arrayClassificacao[5] = strList[11].toInt();
            arrayClassificacao[6] = strList[12].toInt();
            Piloto p(codigo, nome, pais, idade, equipe, motor, arrayClassificacao);
            p.calcularPontuacaoFinal();
            this->listaDePilotosF1.push_back(p);
            getline(arquivo,linha);
        }
        arquivo.close();
    }
    catch (QString &erro) {
        throw erro;
    }
}

}
