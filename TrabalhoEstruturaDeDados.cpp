#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Agenda{ 
	string nome;
	string telefone;
	string empresa;
}; //Estrutura que compões a agenda

Agenda *vetAgenda = new Agenda[10]; //Estanciamento da Struct dentro de um ponteiro vetor de 10 posições
static int pos = 0;  //variavel global

/*Prototipos das funções e procedimentos*/
void menu(Agenda *vetAgenda);
Agenda cadastrar(Agenda *vetAgenda);
void imprime(Agenda *vetAgenda);
void consultar(Agenda *vetAgenda);
void alterar(Agenda *vetAgenda);
void deletar(Agenda *vetAgenda);

/*Função principal do programa*/
int main(){		
	menu(vetAgenda);
}

/*Realiza o cadastro na agenda / Atribui valores as variáveis da Struct Agenda*/
Agenda cadastrar(Agenda *vetAgenda){

	cout << "Informe os dados abaixo paa o cadastro." << endl;

	if(pos < 10){
		cout << "Digite o seu nome: ";
		cin >> vetAgenda[pos].nome;
		cout << "Digite o seu telefone: ";
		cin >> vetAgenda[pos].telefone;
		cout << "Digite a sua empresa: ";
		cin >> vetAgenda[pos].empresa;
		cout << endl;
		cout << "\nCadastro realizado com sucesso na posicao " << pos << " da agenda!" << endl;
		pos++;
	}else{
		cout << "\nNão há mais espaço. Agenda Lotada!" << endl;
	}

	return(*vetAgenda);
	system("pause");
}

/*Procedimento para imprimir na tela os dados da agenda*/
void imprime(Agenda *vetAgenda){
	system("cls");
	cout << "**AGENDA COMPLETA**" << endl;
	cout << endl;

	for(int i = 0; i < pos; i++){		
		cout << "Posicao do contato: " << i << endl;
		cout << "Nome: " << vetAgenda[i].nome << endl;
		cout << "Telefone: " << vetAgenda[i].telefone << endl;
		cout << "Empresa: " << vetAgenda[i].empresa << endl;
		cout << endl;
	}	
}

/*Procedimento que realiza consulta na agenda*/
void consultar(Agenda *vetAgenda){
	bool procura = false;
	string nomeConsultado;
	int posicao;

	system("cls");
	cout << "Nome a ser consultado: ";  
	cin >> nomeConsultado;

  	for(int i = 0; i < 10; i++){
		if(nomeConsultado == vetAgenda[i].nome){
			procura = true;
			posicao = i;			
		}
	}
	if(procura){
		cout << "\nNome encontrado na posicao: " << posicao << endl;
		cout << endl;
		cout << "NOME: " << vetAgenda[posicao].nome << endl;
		cout << "TELEFONE: " << vetAgenda[posicao].telefone << endl;
		cout << "EMPRESA: " << vetAgenda[posicao].empresa << endl;
		cout << endl;
	}else{
		cout << "\nContato nao encontrado!" << endl;
	}
	system("pause");
}

/*Procedimento que realiza alteração nos dados da agenda*/
void alterar(Agenda *vetAgenda){
	bool procura = false;
	string procuraN,novo;
  	int posicao;

	cout << "Qual o nome que sera alterado: ";
	cin >> procuraN;

	for(int i=0;i<=9;i++){
		if(procuraN == vetAgenda[i].nome){
			procura = true;
			posicao = i;
		}
	}

	if(procura){
		cout << "\nDigite o novo nome: ";
		cin >> novo;
		vetAgenda[posicao].nome = novo;
		cout << "\nNovo nome cadastrado foi " << novo << endl; 
	}else{
		cout << "\nNome nao localizado!" << endl;
	}
	system("pause");
}

/*Procedimento que um registro da agenda*/
void deletar(Agenda *vetAgenda){
	bool procura = false;
	int posRemove;
	string procurarNome;

	cout << "Qual o nome do contato a ser deletado?" << endl;
	cin >> procurarNome;

	for(int i = 0; i < 10; i++){
		if(procurarNome == vetAgenda[i].nome){
		procura = true;
		posRemove = i;
		}
	}

	if(procura){
		for(int i = posRemove; i < pos-1; i++){
			vetAgenda[posRemove].nome = vetAgenda[posRemove+1].nome;
			vetAgenda[posRemove].telefone = vetAgenda[posRemove+1].telefone;
			vetAgenda[posRemove].empresa = vetAgenda[posRemove+1].empresa;
		}
		cout << "\nO contato " << procurarNome << " foi deletado!" << endl;
	}else{
		cout << "\nContato nao localizado!" << endl;
	}	
	pos--;
	system("pause");
}

/*Procedimento que monta um menu de opções no console*/
void menu(Agenda *vetAgenda){	
	int opcao;
	
	do {
	  do{
	      	system("cls");
	      	cout << "\t+--------------------------------+\n";
	      	cout << "\t|          MENU PRINCIPAL        |\n";
	      	cout << "\t+--------------------------------+\n";
	     	cout << "1- Cadastrar" << endl;
	      	cout << "2- Consultar" << endl;
	      	cout << "3- Alterar" << endl;
	      	cout << "4- Deletar" << endl;
			cout << "5- Exibir Agenda" << endl;
	      	cout << "0- Sair" << endl;
	      
		   	cout << "\nInforme a opcao desejada: ";
		   	cin >> opcao;
		   	
			}while(opcao < 0 || opcao > 5);
		
		  	if(opcao == 1){
		  		system("cls");
		  		cadastrar(vetAgenda);
				system("pause");
			  	}
				else
				if(opcao == 2){
					system("cls");
					consultar(vetAgenda);
					}					
					else
					if(opcao == 3){
						system("cls");
						alterar(vetAgenda);
						}						
						else
						if(opcao == 4){
							system("cls");
							deletar(vetAgenda); 
							}
							else
							if(opcao == 5){
								system("cls");
								imprime(vetAgenda);
								system("pause");
								}
 	}while(opcao != 0);
}
