// Lista doppiamente concatenata.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <typeinfo>

using namespace std;

class nodo {
public:
	int val;
	nodo* succ;
	nodo* prec;
};

class listadoppia {
	nodo* testa;
public:
	listadoppia() {
		cout <<"CREO LISTA" << endl;
	}
	void inserTesta(int x) {
		cout << endl << "INSERISCO TESTA" << endl;
		nodo* nuovo = new nodo; //creo un nuovo nodo
		nuovo->val = x; //al nuovo nodo, assegno il valore passato
		nuovo->prec = NULL;// dato che stiamo inserendo la testa, il precedente sar� null,  non c'� nulla prima della testa
		if (this->testa) { //controllo se la testa � valida
			nuovo->succ = this->testa; //se passa il controllo, il successivo del nuovo nodo, diventer� la testa che avevamo in precedenza
			this->testa->prec = nuovo;//mentre il precedente della testa sar� il nuovo nodo
			this->testa = nuovo; //quindi il nuovo nodo diventa la testa
		}
		else { //se la testa non c'�
			nuovo->succ = NULL; //il successivo del nodo nuovo � null perch� in lista abbiamo un solo elemento cio� la testa stessa
			this->testa = nuovo;//quindi il nodo nuovo diventa la testa
		}
	}

	void inserCoda(int x) {
		cout << endl << "INSERISCO CODA" << endl;
		nodo* nuovo = new nodo; // creo intento un nodo nuovo
		nuovo->val = x; //assegno il valore
		nuovo->succ = NULL; //dato che aggiungiamo in coda, il successivo del nodo nuovo sar� NULL
		if (this->testa) { //se la testa esiste
			nodo* iter = this->testa; //creo nodo di scorrimento
			while (iter->succ != NULL) {// finch� non arrivo alla fine della lista, quindi il succ del nodo di scorrimento sar� null
				iter = iter->succ; //vado al prossimo nodo
			}
			iter->succ = nuovo;//quando arrivo qua, vuol dire che sono alla fine della lista,quindi alla coda, quindi posiziono il nuovo nodo
			nuovo->prec = iter;//come precedente del nodo nodo assegno la vecchia coda

		}
		else {// se la testa non � presente creo una testa
			nuovo->prec = NULL; //da00to che stiamo aggiungendo una testa, il precendente � null
			this->testa = nuovo; //il nodo nuovo diventa una testa
		}
	}

	void inser(int x, nodo* pre) { //aggiungo il valore passato dopo il nodo dato
		cout << endl << "INSERISCO NODO DATO VALORE E NODO PRECEDENTE" << endl;
		nodo* nuovo = new nodo;//creo il nodo
		nuovo->val = x;//assegno il valore passato al valore del nodo

		nuovo->succ = pre->succ; //il successivo del nuovo nodo diventa il successivo del nodo precedente
		nuovo->prec = pre;//il precedente del nuovo nodo � appunt il nodo pre, quindi il nodo precedente
		pre->succ = nuovo;// il successivo del precedente � appunto il nuovo nodo
	}

	nodo* ricerca(int x) { // funzione ricerca
		cout <<"CERCO" << endl;//se non sai cosa significa, cambia facolt�
		nodo* iter = this->testa;//salvo testa
		if(iter){//controllo se esiste la testa
			while (iter != NULL) { //finch� la testa � valida
				if (iter->val == x) {// controllo il valore se � quello cercato
					cout << "TROVATO" << endl;
					return iter; //ritorna il nodo cercato
				}
				else {
					iter = iter->succ;// altrimenti passa al prossimo
				}
			}
			cout << "NODO NON TROVATO" << endl;// se arriva qua, il nodo non � presente
			return NULL; //quindi torna null
		}
		else { //se non esiste la testa la lista � vuota
			cout << "LISTA VUOTA";
			return NULL;//se la lista � vuota torna un nodo nullo
		}
		return NULL;// se non torna nulla, o la lista � vuota o non trova il nodo, quindi torna null
	}

	void rimuovi(int x) {
		nodo* daDel = ricerca(x);//cerco il nodo da cancellare
		nodo* t = this->testa;//prendo la testa
		if (t) {//controllo la testa
			if (t->val == x) {//se il valore si trova in testa
				cout << "VALORE TROVATO IN TESTA"<<endl;
				this->testa = t->succ;//il successivo di t, sar� la nuova testa
				this->testa->prec = NULL;//il precedente della testa � null
				delete t;//eliminiamo il nodo
			}
			else if (daDel->succ==NULL) {//se non � in testa, controlliamo che non sia in coda			
				daDel->prec->succ = NULL;//se � in coda, il successivo, della nuova coda � null
				delete daDel;//quindi cancelliamo il nodo, cio� la coda			
			}
			else if (daDel) {//se non � ne in coda, ne in testa, � in mezzo
				daDel->prec->succ = daDel->succ;//il successivo del precedente del nodo da eliminare diventa successivo di quello da cancellare
				//cio� colleghiamo il nodo precedente di quello da cancellare a quello successivo da quello da cancellare
				//cio� saltiamo il nodo da cancellare
				daDel->succ->prec = daDel->prec; //lo stesso discorso di prima, per� viceversa
				delete daDel;//cacelliamo il nodo
			}

		}
		
	}
	friend ostream& operator<<(ostream &os, listadoppia &l); //overloading
};

ostream& operator<<(ostream &os, listadoppia &l)
{
	nodo* iter = l.testa;  //passo la testa ad un nuovo nodo
	if (iter){
		os << "NULL";
		while (iter != NULL) {
			os << "<-" << iter->val << "->";
			iter = iter->succ;
		}
		os << "NULL";
	}
	else {
		os << "LISTA VUOTA" << endl;
	}
	return os;
}

int main()
{
	listadoppia l;
	int x = 0;
	cout<<l<<endl;
	cout << "Inserisci il valore che vuoi inserire nella testa della lista" << endl;
	cin >> x;
	l.inserTesta(x);
	cout << l << endl;
	cout << "Inserisci il valore che vuoi inserire nella coda della lista" << endl;
	cin >> x;
	l.inserCoda(x);
	cout << l << endl;
	cout << "Inserisci il valore che vuoi cercare nella lista" << endl;
	cin >> x;
	nodo *n=l.ricerca(x);
	cout << "Inserisci il valore che vuoi inserire nel mezzo" << endl;
	cin >> x;
	cout << l << endl;
	if (n) {	
		l.inser(x,n);
	}
	else {
		l.inserCoda(x);
	}

	cout << l << endl;
	cout << "Inserisci il valore che vuoi rimuovere" << endl;
	cin >> x;
	l.rimuovi(x);
	cout << l << endl;

}
