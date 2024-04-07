#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;


// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		NO* atual = primeiro;
		NO* anterior = NULL;

		while (atual != NULL && atual->valor < novo->valor)
		{
			anterior = atual;
			atual = atual->prox;
		}
		if (atual != NULL && atual->valor == novo->valor) {
			cout << "Elemento ja existe" << endl;
			free(novo);
			return;
		}

		if (anterior == NULL) {
			novo->prox = primeiro;
			primeiro = novo;
		}
		else {
			anterior->prox = novo;
			novo->prox = atual;
		}
	}
}

void excluirElemento()
{
	NO* aux = primeiro;
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	NO* anterior = NULL;

	int valor;

	cout << "Digite o elemento para excluir: ";
	cin >> valor;

	if (posicaoElemento(valor) == NULL) {
		cout << "Valor nao encontrado na lista. \n";
	}
	while (aux != NULL) {
		if (aux->valor == valor) {
			if (anterior == NULL) {
				primeiro = aux->prox;
			}
			else {
				anterior->prox = aux->prox;
			}
			free(aux);
			cout << "Elemento excluido da lista.\n";
			return;
		}
		else {
			anterior = aux;
			aux = aux->prox;
		}
	}
}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		int valor;
		cout << "Digite o elemento para buscar: ";
		cin >> valor;
		if (posicaoElemento(valor) == NULL) {
			cout << "Elemento nao encontrado";
			return;
		}
		cout << "Elemento encontrado";
	}
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}