#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define tam 26

// CARTAS
typedef struct
{
	char nome[40];
	int atq;
	int def;
}TCARTAS;
// ----------

// Nó
struct NO
{
	TCARTAS cartas;
	struct NO *prox;
	
};
// ----------

// LISTA
typedef struct NO *LISTA;
// ----------

// FUNÇÕES LISTA
void Inicializar(LISTA *pLista)
{
	(*pLista) = NULL;
}

/*LISTA NovaLista(LISTA pLista)
{
	return NULL;
}*/

int ListaVazia(LISTA pLista)
{
	return (pLista == NULL);
}

void InserirInicio (TCARTAS pCart, LISTA *pLista)
{
	struct NO *pAux;
	
	pAux = (struct NO *) malloc (sizeof(struct NO));
	pAux->cartas = pCart;
	
	if ((*pLista) == NULL)
	{
		pAux->prox = NULL;
	}    
	else
	{
		pAux->prox = (*pLista);         
	}
	
	(*pLista) = pAux;
	
}

void ImprimirLista(LISTA pLista)
{
	struct NO *paux;
	TCARTAS caux;
	
	paux = pLista;
	
	while (paux != NULL)
	{
		caux = paux->cartas;
		printf("\n Nome: %s \tAtaque: %d \tDefesa: %d\n ", caux.nome, caux.atq, caux.def); 
		paux = paux->prox;
	}
}

void InserirFinal (TCARTAS pCart, LISTA *pLista)
{
	LISTA novo, pAux, pAux2;
	
	novo = (struct NO *) malloc (sizeof(struct NO));
	novo->cartas = pCart;
	novo->prox = NULL;
	
	pAux = NULL;
	pAux2 = (*pLista);
	
	if (pAux2 == NULL)
	{
		(*pLista) = novo;
	}
	else
	{
		while (pAux2 != NULL)
		{
			pAux = pAux2;
			pAux2 = pAux->prox;
		}
		
		pAux->prox = novo;
	}
	
}

void InserirPosicao (TCARTAS pCart, LISTA *pLista, int p)
{
	LISTA novo, pAux, pAux2;
	int i = 0;
	
	novo = (struct NO *) malloc (sizeof(struct NO));
	novo->cartas = pCart;
	novo->prox = NULL;
	
	pAux = NULL;
	pAux2 = (*pLista);
	
	if (pAux2 == NULL)
	{
		pAux2 = novo;
	}
	else
	{
		if (p == 0)
		{
			novo->prox = (*pLista);
			(*pLista) = novo;
		}
		else
		{
			while (i < p)
			{
				pAux = pAux2;
				pAux2 = pAux->prox;
				i++;
			}
			
			pAux->prox = novo;
			novo->prox = pAux2;
		}
		
	}
	
}

void RemoverPosicao (LISTA *pLista, int p)
{
	LISTA pAux, pAux2;
	int i = 0;
	
	pAux = NULL;	
	pAux2 = (*pLista);
	
	if (pAux2 == NULL)
	{
		printf ("Lista vazia\n");
	}
	else
	{
		if (p == 0)
		{
			(*pLista) = pAux2->prox;
		}
		else
		{
			while (i < p)
			{
				pAux = pAux2;
				pAux2 = pAux2->prox;
				i++;
			}
			
			pAux->prox = pAux2->prox;
			pAux2 = pAux;
			
		}
	}
}

void RemoverFinal (LISTA *pLista)
{
	LISTA pAux, pAux2;
	//int i = 0;
	
	pAux = NULL;	
	pAux2 = (*pLista);
	
	if (pAux2 == NULL)
	{
		printf ("Lista vazia\n");
	}
	else if (pAux2->prox == NULL)
	{
		(*pLista) = NULL;
	}
	else
	{
		while (pAux2->prox != NULL)
		{
			pAux = pAux2;
			pAux2 = pAux->prox;
		}
		
		pAux->prox = NULL;
		pAux2 = pAux;
		//free(pAux2);

	}
}

TCARTAS RetornaCarta(LISTA *pLista, int p)
{
	LISTA aux;
	int i;
	aux = (*pLista);
	TCARTAS teste;

	//printf ("\nRandom P%d: %d\n", n, p);
	
	if (p != 0){
		for (i = 0; i<p; i++)
		{
			aux = aux->prox;
		}
	}

	teste = aux->cartas;
	
	return teste;
}

TCARTAS RetornaCartaFinal(LISTA *pLista)
{
	LISTA aux;
	//int i = 0;
	aux = (*pLista);
	TCARTAS teste;

	//printf ("\nRandom P%d: %d\n", n, p);
	
	while (aux->prox != NULL)
	{
		aux = aux->prox;
	}

	teste = aux->cartas;
	
	return teste;
}

void ImprimirListaCartas(LISTA pLista)
{
	struct NO *paux;
	TCARTAS caux;
	int i = 0;
	
	paux = pLista;
	
	while (paux != NULL)
	{
		caux = paux->cartas;
		printf("\n(%d) Nome: %s \tAtaque: %d \tDefesa: %d\n ", i, caux.nome, caux.atq, caux.def); 
		paux = paux->prox;
		i++;
	}
}


void CriarDeck(LISTA *pDeck)
{
	
	TCARTAS c;
	
	strcpy (c.nome, "Curupira");
	c.atq = 200;
	c.def = 300;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Saci");
	c.atq = 300;
	c.def = 150;
	
	InserirFinal(c, pDeck);	
	
	strcpy (c.nome, "Quibungo");
	c.atq = 250;
	c.def = 200;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Iansa");
	c.atq = 275;
	c.def = 180;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Dandara");
	c.atq = 300;
	c.def = 200;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Zaki");
	c.atq = 400;
	c.def = 100;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Oxala");
	c.atq = 220;
	c.def = 280;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Boitata");
	c.atq = 350;
	c.def = 150;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Mula sem cabeca");
	c.atq = 400;
	c.def = 100;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Lobisomem");
	c.atq = 320;
	c.def = 300;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Chimbamba");
	c.atq = 300;
	c.def = 300;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Gonga");
	c.atq = 250;
	c.def = 250;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Tau");
	c.atq = 325;
	c.def = 325;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Exu");
	c.atq = 350;
	c.def = 325;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Oxossi");
	c.atq = 325;
	c.def = 300;
	
	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Cabeca de Cuia");
	c.atq = 225;
	c.def = 225;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Boto");
	c.atq = 200;
	c.def = 100;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Iara");
	c.atq = 100;
	c.def = 325;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Tupa");
	c.atq = 350;
	c.def = 250;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Diogo Caramuru");
	c.atq = 225;
	c.def = 225;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Jurupari");
	c.atq = 250;
	c.def = 325;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Ceuci");
	c.atq = 200;
	c.def = 200;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Mae do Ouro");
	c.atq = 200;
	c.def = 250;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Cuca");
	c.atq = 325;
	c.def = 250;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Capelobo");
	c.atq = 350;
	c.def = 150;

	InserirFinal(c, pDeck);
	
	strcpy (c.nome, "Alamoa");
	c.atq = 250;
	c.def = 250;

	InserirFinal(c, pDeck);
	
}

void DistribuiCartasDeck(LISTA *pDeck, LISTA *pLista, int p)
{
	int random;
	// Gera um numero aleatório e tira a carta do deck de posição correspondente e entrega ao Jogador
	random = rand() % tam;
	InserirFinal(RetornaCarta(pDeck, random), pLista);	
}

void DistribuiCartasMao(LISTA *pLista, LISTA *pMao)
{
	int random;
	// Gera um numero aleatório e tira a carta do deck de posição correspondente e entrega ao Jogador
	random = rand() % 6;
	InserirFinal(RetornaCarta(pLista, random), pMao);	
}

int MenuJogador (int jogador)
{
	int esc;
	printf ("|Jogador %d|\n", jogador+1);
	printf ("(1) Jogar carta no campo\n");
	printf ("(2) Atacar carta inimiga\n");
	printf ("(3) Cavar carta do deck\n");
	printf ("(4) Fim de turno\n");
	printf ("Escolha: ");
	scanf ("%d", &esc);
	
	return esc;
}

void ImprimeCampo(TCARTAS *pCartas)
{
	// Cartas ou cartas vazias
	// Cada carta vai mostrar o nome 
	printf ("Campo Jogador 1:\n");
	printf ("Nome: %s\t", pCartas[0].nome);
	printf ("Ataque: %d\t", pCartas[0].atq);
	printf ("Defesa: %d\n", pCartas[0].def);
	printf ("\n");
	
	printf ("Campo Jogador 2:\n");
	printf ("Nome: %s\t", pCartas[1].nome);
	printf ("Ataque: %d\t", pCartas[1].atq);
	printf ("Defesa: %d\n", pCartas[1].def);
	printf ("\n");

}

/*int Menu()
{
	int escolha;
	printf ("(1) Iniciar partida\n");
	printf ("(2) Sair\m");
	printf ("Escolha: ");
	scanf ("%d", &escolha);
}*/

main ()
{
	LISTA l1, l2, m1, m2, deck;
	int i;
	char jogador1[40], jogador2[40];
	
	// Deck Jogador 1
	Inicializar(&l1);
	// Deck Jogador 2
	Inicializar(&l2);
	// Mão Jogador 1
	Inicializar(&m1);
	// Mão Jogador 2
	Inicializar(&m2);
	// Campo
	//Inicializar(&campo);
	// Deck
	Inicializar(&deck);
	
	// Criar Cartas e Deck
	CriarDeck(&deck);
	// -------------------
	
	/*printf ("\nDeck:\n");
	ImprimirLista(deck);*/
	
	// Seed para o random não repetir
	srand(time(NULL));
	// ------------------------------

	// ----------Distribui cartas----------
	for (i = 0; i < tam; i++)
	{
		if (i % 2 == 0)
		{
			DistribuiCartasDeck(&deck, &l1, 1);
		}
		else
		{
			DistribuiCartasDeck(&deck, &l2, 2);
		}	
	}
	// ------------------------------------
	
	int r;
	//char j1[40], j2[40];
    /*printf ("Entre com o nome do jogador 1: ");
    scanf (" %s", &j1);
    printf ("\nEntre com o nome do jogador 2: ");
    scanf (" %s", &j2);*/

    r = rand() % 2;
    if (r == 0)
    {
        printf ("\nO jogador 1 comeca");
    }
    else if (r == 1)
    {
        printf ("\nO jogador 2 comeca");
    }

	
	for (i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			DistribuiCartasMao(&l1, &m1);
		}
		else
		{
			DistribuiCartasMao(&l2, &m2);
		}	
	}
	
	// Partida
	int turno = 1;
	int escPartida = 0;
	int pontos = 4;
	int escCarta = 0;
	int result = 0;
	int winCond[0];
	int acoes = 0;
	int qtdCartas[2];
	qtdCartas[0] = 3;
	qtdCartas[1] = 3;
	winCond[0] = 0;
	winCond[1] = 0;
	TCARTAS campo[2];
	
	strcpy(campo[0].nome, "VAZIO");
	campo[0].atq = 0;
	campo[0].def = 0;
	
	strcpy(campo[1].nome, "VAZIO");
	campo[1].atq = 0;
	campo[1].def = 0;
	
	do
	{
		if (r != -1)
		{
			printf ("\n\n|Turno %d|\n\n", turno);
			ImprimeCampo (campo);
			escPartida = MenuJogador(r);
		}
		
		if (r == 0)
		{
			// Jogador 1
			
			/*printf ("\nMao Jogador 1\n");
			ImprimirListaCartas (m1);*/
			
			if (escPartida == 1)
			{
				if (m1 == NULL)
				{
					printf ("\n|Voce nao tem cartas na mao|\n");
					system ("PAUSE");
				}
				else
				{
					printf ("\nEscolha uma carta para jogar no campo: \n");
					ImprimirListaCartas (m1);
					
					printf ("\nEscolha: ");
					scanf ("%d", &escCarta);
					if ((escCarta < 0) || (escCarta > qtdCartas[0]))
					{
						printf ("\nCarta Invalida\n");
						system ("PAUSE");
						system ("cls");
					}
					else
					{
						campo[0] = RetornaCarta(&m1, escCarta);
						RemoverPosicao(&m1, escCarta);
						ImprimeCampo (campo);
						qtdCartas[0]--;
						
						system ("PAUSE");
						system ("cls");
					}
					
				}
			}
			else if (escPartida == 2)
			{
				// Atacar carta inimiga
				if (campo[0].atq == 0 || campo[1].atq == 0)
				{
					printf ("Voce ou seu inimigo nao tem cartas no campo\n");
					system ("PAUSE");
					system ("cls");
				}
				else
				{
					printf ("Voce atacou o jogar inimigo!\n");
					result = campo[0].atq - campo[1].def;
					if (result > 0)
					{
						printf ("Carta inimiga destruida\n");
						strcpy(campo[1].nome, "VAZIO");
						campo[1].atq = 0;
						campo[1].def = 0;
						system ("PAUSE");
						system ("cls");
					}
					else
					{
						printf ("Nada aconteceu\n");
						system ("PAUSE");
						system ("cls");
					}
				}
			}
			else if (escPartida == 3)
			{
				// Cavar carta do deck
				if (l1 == NULL)
				{
					printf ("\nVoce nao tem mais cartas no deck\n");
					system ("PAUSE");
					system ("cls");
				}
				else
				{
					if (acoes == 0)
					{
						InserirFinal(RetornaCartaFinal(&l1), &m1);
						/*ImprimirLista(m1);
						ImprimirLista(l1);*/
						printf ("\nMao Jogador 1\n");
						ImprimirListaCartas (m1);
						RemoverFinal(&l1);
						system ("PAUSE");
						system ("cls");
						//printf ("\n\n|Pos remocao|\n\n");
						//ImprimirLista(l1);
						qtdCartas[0]++;
						acoes++;
					}
					else
					{
						printf ("\nVoce nao pode mais cavar neste turno\n");
						system ("PAUSE");
						system ("cls");
					}
					
				}
			}
			else if (escPartida == 4)
			{
				// Fim de turno
				//printf ("Lista: %d\tMao: %d\n", ListaVazia(l1), ListaVazia(m1));
				/*if ((!ListaVazia(l1) && !ListaVazia(m1)) || (!ListaVazia(l2) && !ListaVazia(m2)))
				{
					r = -1;
				}
				else
				{
					r = 1;
				}*/
				r = 1;
				acoes = 0;
				system ("PAUSE");
				system ("cls");
			}
			else
			{
				printf ("\nEscolha invalida!\n");
			}
			
		}
		else if (r == 1)
		{
			// Jogador 2
			/*printf ("\nMao Jogador 2\n");
			ImprimirListaCartas (m2);*/
	
			if (escPartida == 1)
			{
				if (m2 == NULL)
				{
					printf ("\n|Voce nao tem cartas na mao|\n");
					system ("PAUSE");
					system ("cls");
				}
				else
				{
					printf ("Escolha uma carta para jogar no campo: ");
					ImprimirListaCartas (m2);
					
					printf ("\nEscolha: ");
					scanf ("%d", &escCarta);
					if ((escCarta < 0) || (escCarta > qtdCartas[1]))
					{
						printf ("\nCarta Invalida\n");
						system ("PAUSE");
						system ("cls");
					}
					else
					{
						campo[1] = RetornaCarta(&m1, escCarta);
						RemoverPosicao(&m1, escCarta);
						ImprimeCampo (campo);
						qtdCartas[1]--;
						
						system ("PAUSE");
						system ("cls");
					}
				}
			}
			else if (escPartida == 2)
			{
				// Atacar carta inimiga
				if (campo[0].atq == 0 || campo[1].atq == 0)
				{
					printf ("Voce ou seu inimigo nao tem cartas no campo\n");
					system ("PAUSE");
					system ("cls");
				}
				else
				{
					printf ("Voce atacou o jogar inimigo!\n");
					result = campo[1].atq - campo[0].def;
					if (result > 0)
					{
						printf ("Carta inimiga destruida\n");
						strcpy(campo[0].nome, "VAZIO");
						campo[0].atq = 0;
						campo[0].def = 0;
						system ("PAUSE");
						system ("cls");
					}
					else
					{
						printf ("Nada aconteceu\n");
						system ("PAUSE");
						system ("cls");
					}
				}
			}
			else if (escPartida == 3)
			{
				// Cavar carta do deck
				if (l2 == NULL)
				{
					printf ("\nVoce nao tem mais cartas no deck\n");
					system ("PAUSE");
					system ("cls");
				}
				else
				{
					if (acoes == 0)
					{
						InserirFinal(RetornaCartaFinal(&l2), &m2);
						/*ImprimirLista(m1);
						ImprimirLista(l1);*/
						printf ("\nMao Jogador 2\n");
						ImprimirListaCartas (m2);
						RemoverFinal(&l2);
						system ("PAUSE");
						system ("cls");
						//printf ("\n\n|Pos remocao|\n\n");
						//ImprimirLista(l1);
						qtdCartas[1]++;
						acoes++;
					}
					else
					{
						printf ("\nVoce nao pode mais cavar neste turno\n");
						system ("PAUSE");
						system ("cls");
					}
				}
			}
			else if (escPartida == 4)
			{
				// Fim de turno
				/*if (!ListaVazia(l1) && !ListaVazia(m1) || !ListaVazia(l2) && !ListaVazia(m2))
				{
					r = -1;
				}
				else
				{
					r = 0;
				}*/
				r = 0;
				acoes = 0;
				system ("PAUSE");
				system ("cls");
			}
			else
			{
				printf ("\nEscolha invalida!\n");
			}
		}
		if (ListaVazia(l1) && ListaVazia(m1) || ListaVazia(l2) && ListaVazia(m2))
		{
			printf ("\n|Fim da partida|\n");
			break;
		}
		
		turno++;
		
	}while (!ListaVazia(l1) && !ListaVazia(m1) || !ListaVazia(l2) && !ListaVazia(m2));
	
	if (ListaVazia(l2) && ListaVazia(m2))
	{
		printf ("\n VITORIA JOGADOR 1! \n");
	}
	else if (ListaVazia(l1) && ListaVazia(m1))
	{
		printf ("\n VITORIA JOGADOR 2! \n");
	}

	/*printf ("\nDeck Jogador 1: \n");
	ImprimirLista(l1);
	
	printf ("\nDeck Jogador 2: \n");
	ImprimirLista(l2);*/
	
	system ("PAUSE");
	return 0;
	
}
