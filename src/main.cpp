#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include "pilha2.hpp"
#include "levenshtein.h"
#include "funcoes.cpp"

int main(int argc, char const *argv[]){

if(argc<3){
	std::cout<<"Uso "<<argv[0]<<" <dicionario> <texto>"<<std::endl;
	return -1;
}
	
std::string arqDicio=argv[1];
std::string arqTexto=argv[2];


std::unordered_set<std::string> dicionario;

std::string palavra;
int quantPalavras=0;

Pilha <PalavraErrada> pilhaDeErradas;

std::ifstream arquivo1(arqDicio); //inserção das palavras no dicionario
while(arquivo1>>palavra){
	dicionario.insert(palavra);
	quantPalavras++;
}
arquivo1.close();

std::ifstream arquivo2(arqTexto); //ajustes nas palavras lidas do texto
while(arquivo2>>palavra){
	retiraPontuacaoFinal(palavra);
	retiraPontuacaoInicial(palavra);
	//inicialParaMinuscula(palavra);
	if(dicionario.find(palavra)==dicionario.end()){ //busca pela palavra no dicionario
		PalavraErrada palavraErrada;
		palavraErrada.errada=palavra;
		std::string opcao="teste";
		
		for(auto& opc:dicionario){      //ATIVAR ESSE LOOP PARA USAR LEVENSHTEIN
			if(palavraErrada.opcoes.size()<5 && levenshtein(palavra,opc)<2){
				palavraErrada.opcoes.push(opc);
			}
		}
		
		//palavraErrada.opcoes.push(opcao); //DESATIVAR ESSA LINHA PARA USAR LEVENSHTEIN
		pilhaDeErradas.push(palavraErrada);
	}
}
arquivo2.close();

int tamPilha=pilhaDeErradas.size();

for(size_t i=0;i<tamPilha;i++){ //impressão das palavras erradas
	std::cout<<pilhaDeErradas.top()->value.errada<<":"<<std::endl;
	int tamOpcoes=pilhaDeErradas.top()->value.opcoes.size();
		for(size_t j=0;j<tamOpcoes;j++){ //impressão das opções de correção
			std::cout<<"  -"<<pilhaDeErradas.top()->value.opcoes.top()->value<<std::endl;
			pilhaDeErradas.top()->value.opcoes.pop();
		}
	pilhaDeErradas.pop();
	std::cout<<std::endl;
}

/*
std::cout<<quantPalavras<<std::endl;
palavra=".Teste!";
retiraPontuacaoFinal(palavra);
retiraPontuacaoInicial(palavra);
inicialParaMinuscula(palavra);
std::cout<<palavra<<std::endl;*/

return 0;
}