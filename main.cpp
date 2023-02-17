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
  std::string monthsName[12] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
  bool loop = true;
  
  while (loop == true) {

    printf("Registro ou Exibição?\n");
    cin >> type;
    printf("\n");
    
    if (type == "Registro" || type == "registro") {
      printf("Informe um mês (1-12)\n");
      cin >> registerMonth;
      printf("\n");
      registerMonth -= 1;
  
      printf("Informe  o número de chamados recebidos no mês de %s:\n", monthsName[registerMonth].c_str());
      cin >> recebidos;
      printf("\n");
      printf("Informe  o número de chamados atendidos no mês de %s:\n", monthsName[registerMonth].c_str());
      cin >> atendidos;
      printf("\n");
  
      months[registerMonth][0] = recebidos;
      months[registerMonth][1] = atendidos;

  } else if (type == "Exibição" || type == "exibição") {
      printf("Informe 0 (zero) se quiser ver os  dados referentes a todos os meses, ou um número de 1 a 12, se desejar ver os dados de um mês específico:\n");
    cin >> selectedMonth;
    printf("\n");
    selectedMonth -= 1;

    if (selectedMonth == -1) {
      for (int i = 0; i < 12; i += 1) {
        printf("%s\n", monthsName[i].c_str());
        printf("Chamados recebidos: %d\n", months[i][0]);
        printf("Chamados atendidos: %d\n", months[i][1]);
        printf("\n");
      }

    } else {
      printf("Chamados recebidos no mês de %s foi de: %d\n", monthsName[selectedMonth].c_str(), months[selectedMonth][0]);
      printf("Chamados atendidos no mês de %s foi de: %d\n", monthsName[selectedMonth].c_str(), months[selectedMonth][1]);
      printf("\n");
    }
  }

  printf("Deseja continuar? S/N\n");
  cin >> continuar;
  printf("\n");
  if (continuar == "N") loop = false;
  }
  
  printf("Sua operação foi encerrada. Obrigado!\n");
  
  return 0;
}