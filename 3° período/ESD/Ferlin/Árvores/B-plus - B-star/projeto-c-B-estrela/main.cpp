#include "BStarTree.h"
#include <fstream>
#include <iostream>
#include <clocale>
using namespace std;

/*
Esse código é de autoria de: stnikola13
link do repositório: https://github.com/stnikola13/b-star-trees/   

AVISO: Use apenas números abaixo de 100 para um resultado mais preciso, quando for usar números abaixo de 10, use um 0 antes.
exemplo: 05, 08.

OBS: O código tem a preferência de pegar o menor da direita, logo, o 2-3 split será da direita para a esquerda
*/
int loadFromSTD(
    string &key) { // Função para inserir um par de palavras da entrada padrão.
  cout << "Digite a palavra: ";
  string word;
  cin >> word;
  if (word == "X")
    return 0;
  else {
    key = word;
    return 1;
  }
}

int loadFromFile(
    string fileName, string *keys,
    int &noOfWords) { // Função para ler uma lista de pares de palavras de um arquivo.
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "Erro ao trabalhar com arquivo!" << endl;
    return 0;
  }
  int count = 0;
  string word;
  while (getline(file, word)) {
    keys[count] = word;
    count++;
  }
  noOfWords = count;
  file.close();
  return 1;
}

int main() {
  setlocale(LC_ALL, ".UTF-8");
  BStarTree tree;
  string keys[100], fileName = "", key = "", word = "";
  int i = 0, n = 0, noOfWords = 0, j = 0, red = 0, added = 0, removed = 0,
      less = 0;
  bool cycle = true, isActive = false;

  while (cycle) {
    cout << endl
         << "- - - - - - - - - - Menu - - - - - - - - - -" << endl
         << "1. Formação de árvores" << endl
         << "2. Pesquisa chave" << endl
         << "3. Inserindo a chave" << endl
         << "4. Excluindo a chave" << endl
         << "5. Imprima a árvore" << endl
         << "6. Número de chaves menor que o dado" << endl
         << "7. Fim do programa" << endl
         << endl
         << "Digite o número de série da opção desejada: ";
    cin >> n;
    if (n <= 0 || n > 7) {
      cout << "Opção digitada incorretamente. Por favor, tente novamente!" << endl;
      continue;
    }

    switch (n) {
    case 1:
      if (isActive) {
        cout << "A árvore já foi criada! Escolha outra opção."
             << endl;
        continue;
      } else {
        while (true) {
          cout << "Digite a linha da árvore: ";
          cin >> red;
          if (red < 3 || red > 10)
            cout << "A ordem da árvore deve estar entre 3 e 10!" << endl;
          else {
            isActive = true;
            break;
          }
        }
      }
      int m;
      cout << "1. Entrada padrão" << endl
           << "2. Arquivo" << endl
           << "Insira a opção de fonte de dados: ";
      cin >> m;
      if (m <= 0 || m > 2) {
        cout << "Opção digitada incorretamente. Por favor, tente novamente!" << endl;
        continue;
      }
      switch (m) {
      case 1:
        cout << "Digite as palavras em linhas separadas. Para abortar a entrada, digite X. (caso deseje inserir apenas números, digite X)"
             << endl;
        for (i = 0; i < 100; i++) {
          j = loadFromSTD(keys[i]);
          if (!j)
            break;
        }
        noOfWords = i;
        cout << "Entrada bem-sucedida." << endl;
        break;
      case 2:
        cout << "Digite um nome de arquivo: ";
        cin >> fileName;
        j = loadFromFile(fileName, keys, noOfWords);
        if (j)
          cout << "Entrada bem-sucedida." << endl;
        break;
      }
      for (int k = 0; k < noOfWords; k++)
        tree.addKey(keys[k], red);
      break;

    case 2:
      if (!isActive) {
        cout << "A árvore não foi inicializada!" << endl;
        continue;
      } else {
        cout << "Digite a chave de pesquisa: ";
        cin >> key;
        if (key.length() < 1) {
          cout << "Palavra digitada incorretamente!" << endl;
          continue;
        } else {
          bool found = tree.search(key);
          if (found)
            cout << "Chave " << key << " foi encontrada!" << endl;
          else
            cout << "Chave " << key << " não encontrada!" << endl;
        }
      }
      break;

    case 3:
      if (!isActive) {
        cout << "A árvore não foi inicializada!" << endl;
        continue;
      }
      cout << "Insira a chave que deseja adicionar à árvore: ";
      cin >> key;
      if (key.length() < 1) {
        cout << "Entrada de palavra incorreta." << endl;
        continue;
      }
      added = tree.addKey(key, red);
      if (added)
        cout << "Chave " << key << " inserido com sucesso na árvore!" << endl;
      else
        cout << "Chave " << key << " já existe na árvore!" << endl;
      break;

    case 4:
      if (!isActive) {
        cout << "A árvore não foi inicializada!" << endl;
        continue;
      }
      cout << "Digite a chave que deseja excluir da árvore: ";
      cin >> key;
      if (key.length() < 1) {
        cout << "Entrada de chave incorreta." << endl;
        continue;
      }
      removed = tree.removeKey(key, red);
      if (removed)
        cout << "Chave " << key << " excluído com sucesso da árvore!" << endl;
      else
        cout << "Chave " << key << " não existe na árvore!" << endl;
      break;

    case 5:
      if (!isActive) {
        cout << "A árvore não foi inicializada!" << endl;
        continue;
      }
      // tree.print();
      cout << endl << endl << tree;
      break;

    case 6:
      if (!isActive) {
        cout << "A árvore não foi inicializada!" << endl;
        continue;
      }
      cout << "Digite a chave para a qual você deseja que o número de palavras seja encontrado "
              "lexicograficamente menor que ele: ";
      cin >> key;
      if (key.length() < 1) {
        cout << "Entrada de chave incorreta." << endl;
        continue;
      }
      less = tree.findLesserKeys(key);
      cout << "O número de palavras na árvore que são lexicograficamente menores do que as inseridas é "
           << less << "." << endl;
      break;

    case 7:
      cout << "Olá!" << endl;
      cycle = false;
      break;
    }
  }

  return 0;
}