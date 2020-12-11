#ifndef PILHA
#define PILHA

#include <iostream>
#include <cstdio>



template <typename T>
class Pilha{
	private:
		struct Node{
			T value;
			Node* prev=nullptr;
		};

		Node* first=nullptr; //topo da pilha
		size_t nodeCount=0;	
	
	public:
		size_t size(){
			//std::cout<<"tamanho da pilha: "<<nodeCount<<std::endl;
			return nodeCount;
		}

		void push(T value){
			//std::cout<<"Inserindo elemento na pilha: "<<value<<std::endl;
			if(first==nullptr){
				first=new Node();
				first->value=value;
				nodeCount++;
			}else{
				Node* other=new Node();
				other->value=value;
				other->prev=first;
				first=other;
				nodeCount++;
			}
		}

		Node* top(){
			//std::cout<<"Elemento do topo da pilha: "<<first->value<<std::endl;
			return first;
		}

		void pop(){
			if(first==nullptr){
				return;
			}else{
				//std::cout<<"Removendo elemento na pilha"<<std::endl;
				Node* currentNode=first;
				first=first->prev;
				delete currentNode;
				if(this->size()==0){
					first=nullptr;
				}
				nodeCount--;
			}
		}
};
#endif
