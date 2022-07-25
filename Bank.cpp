//Sistema Bancário 1.0

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <unistd.h>


using namespace std;

class Register{  //classe pai
	private:
		string password, username, completename; 
		int flag=0; 
		float money; 
		
	public:
		//** getters and setters
		Register(){
			setMoney(10);
			
		}
		void setUsername(string x){ 
			username = x;
		}
		string getUsername(){ 
			return username;
		}
		void setPassword(string x){ 
			password = x;
		}
		string getPassword(){ 
			return password;
		}	
		
		int getFlag(){
			return flag;
		}
		void setMoney(float y){
			money= y;
		}
		float getMoney(){
			return money; 
		}
	
		//**
	
		void activate_register();
		void activate_login();
		
};
	void Register::activate_register(){
		
		string user, name,pass;


		cout<<name<<"\nInsira o nome de usuario:"<<"\n";
		cin>>user;
		cout<<"Usuario Registrado  \n"<<"\n"<<"Prossiga com a criacao de senha:\n";;
		cin>>pass;
		cout<<"Senha Registrada! \n \n "; 
		
		this->flag = 1;
		this->username= user;
		this->password= pass;
		this->completename = name; 
	}
	
	void Register::activate_login(){
		
		int	test_login=0;
		string userlog, passlog;
	
		
		if (getFlag() == 0){
			cout<<"Ainda nao temos usuarios registrados, registre-se"<<endl;
			activate_register();
		}
		
		while (getFlag() == 1 && test_login == 0)	{
			cout<<"Insira o nome de usuario"<<"\n";
			cin>>userlog;
			cout<<"\n"<<"Prossiga com a senha:\n";;
			cin>>passlog;
			cout<<"Verificando...\n \n"; 
			
			if (getUsername() == userlog) {
				if (getPassword()==passlog){
					cout<<"USUARIO AUTENTICADO \n"<<endl;
					test_login = 1;
					this ->flag = test_login; 
					break;
				} 	else{
				cout<<"usuario ou senha incorretos \n \n Insira novamente \n\n\n";}
	
	
			}	else{
				cout<<"usuario ou senha incorretos \n \n Insira novamente \n\n\n";}
				
			}
		}

class Access: public Register { //herda as propriedades e métodos da REGISTER
	public:
		Access(); // protótipo do método do contrutor
		void saque();
		void extrato();

};
		Access::Access(){//criando um construtor
	//		activate_login();
		}
		void Access::extrato(){
			float value;
			value=getMoney();
			cout<<" O valor atual da conta: "<<value;
			  //Cria o objeto de arquivo
   				 ofstream arquivodesaida;

   			 //Abre o aruivo ou cria caso não exista
   				 arquivodesaida.open("Texto.txt", std::ios_base::app);

   			 //Escreve algo
    			arquivodesaida << "O saldo do Usuário: "<<getUsername()<<"fica em "<<value<<endl;
    
   			 //Fecha o arquivo
    			arquivodesaida.close();
		
}
		void Access::saque(){
			
			float value, in_dados,cashe;
			cout<<"Insira o Valor que deseja sacar \n";
			cin>>in_dados;
			
			value =getMoney();
			
			if (in_dados<value){
				cashe= getMoney() - in_dados;
				setMoney(cashe);
				cout<<"O valor atual da conta: "<<getMoney()<<"\n";
			}
			
			else{
				cout<<"Valor Insuficiente \n";
			}
		
		}
		
	int	menu(){
	int select;
	do{
	cout<<" 1.SAIR \n 2.CADASTRO \n 3.LOGIN \n 4.SAQUE \n 5.EXTRATO \n \n \n"; 
	cin>>select;
	} while (select<0 || select>6);
	return select; 
	}
	
int main(){
	system("color 1F");
	int x=1;
	
	Register *Objeto1 = new Register;
	Access *ValueObj1 = new Access;//subclass

	do{
	
	switch (menu()){
		case 1:
			return 0;		
			
		case 2:
			Objeto1 -> activate_register();
			break;
			
		case 3:
			Objeto1 -> activate_login();
			break;
		case 4:
			Objeto1 -> activate_login();
			ValueObj1 -> saque();	
			break;
			
		case 5:
			Objeto1 -> activate_login();
			ValueObj1 -> extrato();	
			system("start Texto.txt");
			break;
			
		}
		
	}while(x==1);
}

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

