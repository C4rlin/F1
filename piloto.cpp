#include "piloto.h"

namespace ce {
int Piloto::getCodigo() const
{
    return codigo;
}

void Piloto::setCodigo(int newCodigo)
{
    codigo = newCodigo;
}

const QString &Piloto::getNome() const
{
    return nome;
}

void Piloto::setNome(const QString &newNome)
{
    nome = newNome;
}

const QString &Piloto::getPais() const
{
    return pais;
}

void Piloto::setPais(const QString &newPais)
{
    pais = newPais;
}

int Piloto::getIdade() const
{
    return idade;
}

void Piloto::setIdade(int newIdade)
{
    idade = newIdade;
}

const QString &Piloto::getEquipe() const
{
    return equipe;
}

void Piloto::setEquipe(const QString &newEquipe)
{
    equipe = newEquipe;
}

const QString &Piloto::getMotor() const
{
    return motor;
}

void Piloto::setMotor(const QString &newMotor)
{
    motor = newMotor;
}

int Piloto::getPontuacaoFinal() const
{
    return pontuacaoFinal;
}

void Piloto::setPontuacaoFinal(int newPontuacaoFinal)
{
    pontuacaoFinal = newPontuacaoFinal;
}

Piloto::Piloto():
    codigo(0),
    nome(""),
    pais(""),
    idade(0),
    equipe(""),
    motor(""),
    classificacao(),
    pontuacaoFinal(0)
{
}
Piloto::Piloto(int codigo,QString nome, QString pais, int idade, QString equipe, QString motor, int classificacao[7]):
    codigo(codigo),
    nome(nome),
    pais(pais),
    idade(idade),
    equipe(equipe),
    motor(motor),
    classificacao(),
    pontuacaoFinal(0)
{
    for(int pos=0;pos<7;pos++){
        this->classificacao[pos] = classificacao[pos];
    }
}
void Piloto::setClassificacao(int array[7]){
    for(int pos=0;pos<7;pos++){
        classificacao[pos] = array[pos];
    }
}
void Piloto::calcularPontuacaoFinal(){
    for(int pos=0;pos<7;pos++){
        if(classificacao[pos] == 1) pontuacaoFinal = pontuacaoFinal + 40;
        if(classificacao[pos] == 2) pontuacaoFinal = pontuacaoFinal + 30;
        if(classificacao[pos] == 3) pontuacaoFinal = pontuacaoFinal + 25;
        if(classificacao[pos] == 4) pontuacaoFinal = pontuacaoFinal + 20;
        if(classificacao[pos] == 5) pontuacaoFinal = pontuacaoFinal + 15;
        if(classificacao[pos] == 6) pontuacaoFinal = pontuacaoFinal + 10;
    }
}


QString Piloto::toString()const{
    QString saida = "{ ";
    saida += "Codigo: " + QString::number(codigo) +  "\n";
    saida += "Nome: " + nome + "\n";
    saida += "Pais: " + pais + "\n";
    saida += "Idade: " + QString::number(idade) + "\n";
    saida += "Equipe: " + equipe + "\n";
    saida += "Motor: " + motor + "\n";
    saida += "1 - Classificação => "+ QString::number(classificacao[0]) + "\n";
    saida += "2 - Classificação => "+ QString::number(classificacao[1]) + "\n";
    saida += "3 - Classificação => "+ QString::number(classificacao[2]) + "\n";
    saida += "4 - Classificação => "+ QString::number(classificacao[3]) + "\n";
    saida += "5 - Classificação => "+ QString::number(classificacao[4]) + "\n";
    saida += "6 - Classificação => "+ QString::number(classificacao[5]) + "\n";
    saida += "7 - Classificação => "+ QString::number(classificacao[6]) + "\n";
    saida += "Pontuação Final: " + QString::number(pontuacaoFinal) + "\n";
    return saida;
}


}
