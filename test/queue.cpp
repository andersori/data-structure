#include <iostream>
#include "../include/Queue.h"

using namespace std;

struct Coisa{
	Coisa(){}
	Coisa(int cont, const char* desc): cont(cont), desc(desc){}
	
	Coisa& operator+=(const Coisa& temp)
	{
		this->cont += temp.cont;
		return *this;
	}

	int cont;
	const char* desc;
};

int main()
{
	Queue<Coisa> lis;

	//Inserindo
	for(int i = 0; i < 6; i++)
	{
		//Criando uma coisa qualquer
		Coisa c = Coisa(i+1, "empty");

		lis.push(c);
	}


	//Mudando o primeiro item da fila
	lis.front() = Coisa(102, "undefined");

	//Mudando o ultimo
	lis.back() += lis.front(); //6 + 102 = 108


	//Removendo todos os itens
	while(lis.size() != 0)
	{
		Coisa temp =  lis.pop();
		cout << temp.cont << " - " << temp.desc << endl;
	}

	return 0;
}