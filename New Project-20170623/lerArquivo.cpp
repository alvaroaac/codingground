#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Criado por Alvaro Carvalho

// Referencias: leitura de arquivo, disponivel em https://stackoverflow.com/questions/17142026/function-to-return-output-from-text-file#17142094
// utilizacao do istringstream: https://stackoverflow.com/questions/236129/split-a-string-in-c


// Sintaxe do C para utilizar caminho completo:
// C:\\Users\\usuario\\Desktop\\C++\\pocketcpp\\in.txt -- Usar duas contra-barras para o codigo nao reconhecer como comandos (ex: \n)
#define ARQUIVO_SAIDA "out.txt"
#define ARQUIVO_ENTRADA "in.txt"

using namespace std;

void lerArquivo( string F_NAME );


int main () {
	// executar a funcao lerArquivo
	lerArquivo(ARQUIVO_ENTRADA);
	return 0;
}


void lerArquivo( string F_NAME )
{
	int M;
    string line;
	FILE * fp1;
	
	fp1 = fopen(ARQUIVO_SAIDA, "w"); // modo escrita, arquivo de saida
    
	ifstream myfile (F_NAME.c_str());
    if (myfile.is_open())
    {
		getline(myfile,line);
		istringstream ss(line); 	// ler o numero na primeira linha
		
		ss >> M; // joga o numero para uma variavel int 

        getline (myfile,line);
			
		istringstream iss(line); // separa a linha palavra por palavra
		
		string linha;
		string aux;
		while (iss) {
			iss >> aux; // passa cada palavra para variavel auxiliar
			if ((aux.length() + linha.length()) + 1 <= M && (iss)) {
				linha += aux + " "; // se a soma da auxiliar com a linha atual for <= M, continua adicionando palavra
			} else {
				//cout << linha << endl;
				for(int i = 0; i < linha.length(); i++) {
					fprintf(fp1,"%c", linha[i]); // caso contrario, imprime no arquivo out.txt e reinicia a variavel linha
				}
				fprintf(fp1,"\n"); // pular linha

				linha = aux + " "; 
			}	
		}
        myfile.close();
		fclose(fp1);
    }
    else cout << "Erro ao abrir o arquivo"; 
}
