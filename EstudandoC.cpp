#include <cstdlib>
#include <iostream>
#include <locale>
#include <math.h>
using namespace std;

int area();
int media();
int parouimpar();
int calc_sal();
int compra_prod();
int transf_graus();
char acoes_semaforo();
int calc_desc();
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");
    bool programa_ativo;
    programa_ativo = true;
    
    while(programa_ativo){
        int operacao;
        system("cls");
        cout << "\n\n";
        cout << "---------------------MENU DE OPERAÇÕES---------------------| \n";
        cout << "Escolha a operaçao que deseja fazer:                        \n";
        cout << "1- Calcular a area de um terreno.							 \n";
        cout << "2- Calcular a media AV1, AV2 e AV3.                         \n";
        cout << "3- Par ou Impar.											 \n";
        cout << "4- Calculo do salario liquido.								 \n";
        cout << "5- Compra de produto de informática.						 \n";
        cout << "6- Converter graus centígrados em fahrenheit.				 \n";
        cout << "7- Ações de acordo com o semáfaro.							 \n";
        cout << "8- Calculando desconto. 									 \n";
        cout << "0- Fechar a aplicaçao.                                      \n";
        cout << "-----------------------------------------------------------| \n";
        cout << "Digite o numero da operaçao que deseja utilizar: ";
        cin >> operacao;
        cout << "\n\n";
        
        // int opcao, define as opções em cada operação
        int opcao;
        switch(operacao){
          case 1:
               	area();
               	break;
          case 2:
               	media();
               	break;
          case 3:
          	   	parouimpar();
          	   	break;
          case 4:
          		calc_sal();
          		break;
          case 5:
          		compra_prod();
          		break;
          case 6:
          		transf_graus();
          		break;
          case 7:
          		acoes_semaforo();
          		break;
          case 8:
          		calc_desc();
          		break;
          case 0:
               	programa_ativo = false;
               	break;
          default:
               	cout << "Não existe esta opção \n";     
        }
    } //fim while(programa_ativo)
    system("PAUSE");
    return EXIT_SUCCESS;
}

int area(){
    system("cls");
    float c, l, a;
	cout << "Informe o comprimento: ";
		cin>>c;
	cout << "Informe a largura: ";
		cin>>l;
	a = c * l;
	cout << "A área é: " << a <<"\n";
	system("pause");
}

int media(){
    system("cls");
	float av1, av2, av3, m;
	cout << "Digite a Av1: ";
		cin >> av1;
	cout << "Digite a Av2: ";
		cin >> av2;
	cout << "Digite a Av3: ";
		cin >> av3;
	if (av1>av3 && av2>av3) 
		m = (av1+av2)/2;
	else
		if (av1>av2 && av3>av2) 
			m = (av1+av3)/2;
		else
			m = (av2+av3)/2;
	if (m>=6)
		cout<<"Aprovado = "<<m<<"\n";
	else
		cout<<"Reprovado = "<<m<<"\n";
	system("pause");
}

int parouimpar(){
    system("cls");
	int numero;
	cout<<"informe um numero: ";
	cin>>numero;
	if(numero % 2 == 0 ){
	
	cout<<"Numero par\n";
	}else
	cout<<"Numero impar\n";
	
	system("pause");
	}
	
int calc_sal(){
    system("cls");
	float sal_bruto, sal_liquido;
	cout<<"AO INSERIR O VALOR DE SEU SALARIO, O PROGRAMA LHE DARÁ O VALOR LIQUIDO JA COM DESCONTO DE INSS. \n";
	cout<<"informe o salario: ";
	cin>>sal_bruto;
	
	if(sal_bruto == 0 || sal_bruto <0)
	{
	cout<<"ERRO!! Informe um salario valido\n\n";
	calc_sal();
	}	
	
	else
	if(sal_bruto > 0  && sal_bruto <=1693.72 ){
		sal_liquido = sal_bruto - (sal_bruto*0.08);
		cout<<"O valor do salario liquido é de R$: "<<sal_liquido<<"\n";
	
	}
	else
		if(sal_bruto <= 2822.90)
		{
		sal_liquido = sal_bruto - (sal_bruto*0.09);
		cout<<"O valor do salario liquido é de R$: "<<sal_liquido<<"\n";
	}
		else
		if(sal_bruto <= 5645.80)
		{
		sal_liquido = sal_bruto - (sal_bruto*0.11);
		cout<<"O valor do salario liquido é de R$: "<<sal_liquido<<"\n";
	}	else
		if(sal_bruto > 5645.80)
		{
		sal_liquido = sal_bruto- 621.04;
	cout<<"O valor do salario liquido é de R$: "<<sal_liquido<<"\n";
	}else
	if(sal_bruto == 0)
	cout<<"Informe um salario valido";
	
	system("pause");
	}
	
int compra_prod(){
	system("cls");
	float CP, QTD, total, preco;
	cout<<"ESCOLHA UMA DAS OPÇÕES ABAIXO, DIGITE O CÓDIGO DA OPÇÃO ESCOLHIDA E A QUANTIDADE \n\n";
	
	cout<<"Cod 1 - Memoria RAM 4gb DDR3 \n";
	cout<<"Cod 2 - Motherboard Asus DDR3 \n";
	cout<<"Cod 3 - Memoria RAM 8gb DDR3 \n";
	cout<<"Cod 4 - PenDrive 32gb Kingston \n";
	cout<<"Cod 5 - Caixas acusticas USB Goldentec 15W rms \n\n";
	
	cout<<"Informe o código do produto:";
		cin>>CP;
	cout<<"Informe a quantidade:";
		cin>>QTD;
	
	if(CP=1){
		preco=87;
		total=preco*QTD;
	}
		else 
		if(CP=2){
		preco=219;
		total=preco*QTD;
		}
			else
			if(CP=3){
			preco=99;
			total=preco*QTD;
			}
				else
				if(CP=4){
				preco=59;
				total=preco*QTD;
					}
					else 
					if (CP=5){
					preco=55;
					total=preco*QTD;
					}
					else
					cout<<"ERRO";
						
						
	cout<< "O total da compra é:R$ " <<total<<"\n";
system("pause");
}

int transf_graus(){
    system("cls");
    float C, F;
	cout << "Informe os graus centígrados: ";
		cin>>C;
	F = 32 + (9/5)*C;
	cout << C <<" em graus centígrados equivale a "<< F << " graus em fahrenheit. \n";
	system("pause");
}

char acoes_semaforo(){
    system("cls");
	char opcao;
	double DC;

cout<<"CONSIDERE AS CORES DE ACORDO COM CADA LETRA \n";
cout<<"Letra v = Sinal Vermelho \n";
cout<<"Letra d = Sinal Verde \n";
cout<<"Letra a = Sinal Amarelo \n\n";

cout<<"Informe a cor atual do sinal: ";
cin >> opcao;

switch(opcao){
	case 'v':
		cout << "PARE \n";
		break;
	case 'd':
		cout << "SIGA EM FRENTE \n";
		break;
	case 'a': 
		cout<<"Informe a distância em metros \n";
		cin>>DC;
      
		if(DC<5.0){
          cout<<"PODE PASSAR \n";
       	}else{
        cout<<"NÃO DÁ PARA PASSAR \n";
    	}
		break;
	}
	system("pause");
}

int calc_desc(){
    system("cls");
	int PRECO, DESC, PRECOF;
	cout << "Informe o preço do produto antes do desconto: ";
		cin>>PRECO;
	cout << "Informe o preço do produto após o desconto: ";
	cin>>PRECOF;
	DESC = 100 - ((PRECOF * 100) / PRECO);
	cout << "Percentual de desconto concedido é de " << DESC <<"%"<<"\n\n";
	system("pause");
}