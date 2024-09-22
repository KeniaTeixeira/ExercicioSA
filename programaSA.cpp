#include <iostream>
/*
Aluno(a): Kênia Teixeira de Paula
---------- Descrição da atividade - Exercicio SA ----------
Faça um programa para o cálculo de uma folha de pagamento, sabendo que os
descontos são do Imposto de Renda, que depende do salário bruto (conforme
tabela abaixo) e 10% para o INSS e que o FGTS corresponde a 11% do Salário
Bruto, mas não é descontado (é a empresa que deposita).
O Salário Líquido corresponde ao Salário Bruto menos os descontos. O
programa deverá pedir ao usuário o valor da sua hora e a quantidade de horas
trabalhadas no mês.
Desconto do IR: Salário Bruto até 900 (inclusive) - isento Salário Bruto até 1500
(inclusive) - desconto de 5% Salário Bruto até 2500 (inclusive) - desconto de
10% Salário Bruto acima de 2500 - desconto de 20%
*/

using namespace std;
double calculaIR(double salarioBruto) {
    if (salarioBruto <= 900) {
        return 0;
    } else if (salarioBruto <= 1500) {
        return salarioBruto * 0.05;
    } else if (salarioBruto <= 2500) {
        return salarioBruto * 0.10;
    } else {
        return salarioBruto * 0.20;
    }
}
double calculaInss(double salario){return salario * 0.10; }
double caculaFgts(double salario){return salario * 0.11; }

int main() {
    double valorHora, horasTrabalhadas;
    double salarioBruto, ir, inss, fgts, desconto, salarioLiquido;

    cout << "Digite o valor da sua hora de trabalho: ";
    cin >> valorHora;
    cout << "Digite a quantidade de horas trabalhadas no mes: ";
    cin >> horasTrabalhadas;

    salarioBruto = valorHora * horasTrabalhadas;
    ir = calculaIR(salarioBruto);
    inss = calculaInss(salarioBruto);
    fgts = caculaFgts(salarioBruto);
    desconto = ir + inss;
    salarioLiquido = salarioBruto - desconto;

    //********************************
    cout << "\n\n********** Folha de Pagamento ********** \n\n";
    cout << "Salario Bruto: (" << valorHora << " * " << horasTrabalhadas << ") : R$ " << salarioBruto << endl;
    cout << "(-) IR (" << ((salarioBruto > 0) ? (ir/salarioBruto)*100 : 0) << "%) : R$ " << ir << endl;
    cout << "(-) INSS (10%) : R$ " << inss << endl;
    cout << "FGTS (11%) : R$ " << fgts << endl;
    cout << "Total de descontos : R$ " << desconto << endl;
    cout << "Salario Liquido : R$ " << salarioLiquido << endl;

    return 0;
}
