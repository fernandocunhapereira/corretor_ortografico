#ifndef FUNCOES
#define FUNCOES

struct PalavraErrada{
	std::string errada;
	Pilha <std::string> opcoes;
};

void inicialParaMinuscula(std::string& palavra){
	if(65<=palavra[0]<=90){
		palavra[0]=palavra[0]+32;
	}
}

void retiraPontuacaoFinal(std::string& palavra){
	int tam=palavra.length();
	if(palavra[palavra.length()-1]<65 || (palavra[palavra.length()-1]>90 && palavra[palavra.length()-1]<97) || palavra[palavra.length()-1]>122){
		palavra.resize(tam-1);
	}
}

void retiraPontuacaoInicial(std::string& palavra){
	int tam=palavra.length();
	std::string temp;
	if(palavra[0]<65 || (palavra[0]>90 && palavra[0]<97) || palavra[0]>122){
		for(int i=1;i<palavra.length();i++){
			temp[i]=palavra[i];
		}
		palavra.resize(tam-1);
		for(int i=0;i<palavra.length();i++){
			palavra[i]=temp[i+1];
		}
	}
}

#endif