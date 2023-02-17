#include <iostream>
#include <locale.h>
#include <stdio.h>

using namespace std;

int main() {
  setlocale(LC_ALL,"Portuguese_Brazil");
  
  string type, continuar;
  int registerMonth, selectedMonth;
  int recebidos, atendidos;
  int months[12][2] = {{5, 3}, {4, 3}, {6, 6}, {2, 1}, {6, 3}, {9, 5}, {4, 1}, {7, 4}, {3, 0}, {4, 2}, {6, 2}, {4, 4}};
  string monthsName[12] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
  bool loop = true;
  
  while (loop == true) {

    cout << "Registro ou Exibição?" << endl;
    cin >> type;
    cout << endl;
    
    if (type == "Registro" || type == "registro") {
    cout << "Informe um mês (1-12)" << endl;
    cin >> registerMonth;
    cout << endl;
    registerMonth -= 1;

    cout << "Informe  o número de chamados recebidos no mês de " << monthsName[registerMonth] << ":" << endl;
    cin >> recebidos;
    cout << endl;
    cout << "Informe  o número de chamados atendidos no mês de " << monthsName[registerMonth] << ":" << endl;
    cin >> atendidos;
    cout << endl;

    months[registerMonth][0] = recebidos;
    months[registerMonth][1] = atendidos;

  } else if (type == "Exibição" || type == "exibição") {
    cout << "Informe 0 (zero) se quiser ver os  dados referentes a todos os meses, ou um número de 1 a 12, se desejar ver os dados de um mês específico" << endl;
    cin >> selectedMonth;
    cout << endl;
    selectedMonth -= 1;

    if (selectedMonth == -1) {
      for (int i = 0; i < 12; i += 1) {
        cout << monthsName[i] << ": " << endl;
        cout << "Chamados recebidos: " << months[i][0] << endl;
        cout << "Chamados atendidos: " << months[i][1] << endl;
        cout << endl;
      }

    } else {
      cout << "Chamados recebidos no mês de " << monthsName[selectedMonth] << " foi de: " << months[selectedMonth][0] << endl;
      cout << "Chamados atendidos no mês de " << monthsName[selectedMonth] << " foi de: " << months[selectedMonth][1] << endl;
    }
  }

  cout << "deseja continuar? S/N" << endl;
  cin >> continuar;
  cout << endl;
  if (continuar == "N") loop = false;
  }
  
  cout << "Sua operação foi encerrada. Obrigado!" << endl;
  
  return 0;
}