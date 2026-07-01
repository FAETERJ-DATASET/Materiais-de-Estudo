#include "BStarTree.h"
using namespace std;

BStarTree::BStarTree() {
	root = nullptr;
}


BStarTree::~BStarTree() {
	if (root != nullptr) {
		queue<BStarTree::Node*> queue;
		queue.push(root);
		while (!(queue.empty())) {
			BStarTree::Node* p;
			p = queue.front();
			queue.pop();
			for (int i = 0; i < MAX_KEYS + 1; i++) {
				if (p->children[i] != nullptr) queue.push(p->children[i]);
			}
			delete p;
		}
	}
}


bool BStarTree::search(string key) const {
	if (root == nullptr) return false;
	Node* p = root;
	while (p) {
		int i;
		for (i = 0; i < p->curNoKeys; i++) {
			if (key == p->keys[i]) return true;
			if (key < p->keys[i]) break;
		}
		p = p->children[i];
	}
	return false;
}


int BStarTree::findLesserKeys(string key) const {
	int n = 0;
	if (root == nullptr) return n;

	stack<BStarTree::Node*> stack1;
	stack<int> stack2;
	BStarTree::Node* p;
	int m;
	stack1.push(root);
	stack2.push(root->curNoKeys + 1);
	//cout << "INORDER:" << endl;

	while (!stack1.empty() && !stack2.empty()) {
		p = stack1.top();
		stack1.pop();
		m = stack2.top();
		stack2.pop();
		if (m <= p->curNoKeys) {
			//cout << p->keys[p->curNoKeys - m] << "->";
			if (key > p->keys[p->curNoKeys - m]) n++;
		}
		m--;
		if (m > 0) {
			stack1.push(p);
			stack2.push(m);
		}
		if (p->children[p->curNoKeys - m] != nullptr) {
			stack1.push(p->children[p->curNoKeys - m]);
			stack2.push(p->children[p->curNoKeys - m]->curNoKeys + 1);
		}
	}
	//cout << endl;
	return n;
}


ostream& operator<<(ostream& os, const BStarTree& tree) {
	BStarTree::Node* root = tree.root;
	if (root == nullptr) return os;
	int maxlvl = 0;
	queue<BStarTree::Node*> queue;
	root->level = 0;
	queue.push(root);															// Inicijalizacija nivoa svih cvorova stabla.
	while (!queue.empty()) {
		BStarTree::Node* p = queue.front();
		queue.pop();
		for (int i = 0; i < p->curNoKeys + 1; i++) {
			if (p->children[i] != nullptr) {
				p->children[i]->level = p->level + 1;
				if (p->children[i]->level > maxlvl) maxlvl = p->children[i]->level;
				queue.push(p->children[i]);
			}
		}
	}

	queue.push(root);
	int prevlvl = -1, curlvl = 0;
	while (!queue.empty()) {
		BStarTree::Node* p = queue.front();
		queue.pop();
		string blanks = "       ";

		prevlvl = curlvl;
		curlvl = p->level;
		if (prevlvl != curlvl) os << endl;

		int noOfChildren = 0;
		for (int i = 0; i < MAX_KEYS + 1; i++) if (p->children[i] != nullptr) noOfChildren++;
		for (int i = 0; i < (int)floor((maxlvl) / (p->level + 1.) * ((noOfChildren + 1.) / 2)); i++) blanks += "       ";
		os << blanks;
		if (p->curNoKeys > 0) os << "(";
		for (int i = 0; i < p->curNoKeys; i++) {
			if (i == p->curNoKeys - 1) os << p->keys[i];
			else os << p->keys[i] << "|";
		}
		os << ")";
		for (int i = 0; i < p->curNoKeys + 1; i++) {
			if (p->children[i] != nullptr) {
				queue.push(p->children[i]);
			}
		}
	}
	os << endl << endl;
	return os;
}


void BStarTree::print() const {
	if (root == nullptr) return;
	queue<BStarTree::Node*> queue;
	root->level = 0;
	queue.push(root);															// Inicijalizacija nivoa svih cvorova stabla.
	while (!queue.empty()) {
		BStarTree::Node* p = queue.front();
		queue.pop();
		for (int i = 0; i < p->curNoKeys + 1; i++) {
			if (p->children[i] != nullptr) {
				p->children[i]->level = p->level + 1;
				queue.push(p->children[i]);
			}
		}
	}
	stack<BStarTree::Node*> stack;
	stack.push(root);															// Svi cvorovi se stavljaju na stek i vrsi se ispis.
	while (!stack.empty()) {													// Nije moglo dva reda, pa se koristi stek sa obrnutim umetanjem.
		BStarTree::Node* p = stack.top();
		stack.pop();
		string blanks = "";
		for (int i = 0; i < p->level; i++) blanks += "- - - - ";
		if (p != root) {
			blanks += to_string(p->childNo);
			blanks += ". ";
		}
		cout << p->level << " " << blanks;
		if (p->curNoKeys > 0) cout << "|";
		for (int i = 0; i < p->curNoKeys; i++) cout << p->keys[i] << "|";
		cout << endl;
		for (int i = p->curNoKeys; i >= 0; i--) {
			if (p->children[i] != nullptr) {
				stack.push(p->children[i]);
			}
		}
	}
	return;
}


bool BStarTree::addKey(string key, int m) {
	if (root == nullptr) {
		Node* p = new Node;
		p->maxNoKeys = (int)(2 * floor((2 * m - 2) / 3));
		p->minNoKeys = 1;
		p->childNo = -1;
		p->keys[0] = key;
		(p->curNoKeys)++;
		root = p;
		return true;
	}
	Node* p = root, * q = nullptr;
	int i, j;
	while (p) {
		for (i = 0; i < p->curNoKeys; i++) {
			if (key == p->keys[i]) return false; // Neuspesno umetanje
			if (key < p->keys[i]) break;
		}
		q = p;
		p = p->children[i];
	}
	//cout << q->keys[0] << "---";
	// Kada se odavde izadje q pokazuje na list gde treba umetnuti kljuc

	// Ovde treba neka while petlja da bi se propagiralo umetanje punih listova do korena
	while (q != nullptr) {
		if (q->curNoKeys + 1 <= q->maxNoKeys) { // Slucaj ako list nije maksimalno popunjen.
			i = 0;
			if (q->curNoKeys == 0) {
				q->keys[0] = key;
				(q->curNoKeys)++;
				return true;
			}
			while (q->keys[i] < key&& q->keys[i] != "/") i++;
			for (j = q->curNoKeys; j > i; j--) q->keys[j] = q->keys[j - 1];
			q->keys[j] = key;
			(q->curNoKeys)++;
			return true;
		}
		else { // Slucaj ako list jeste maksimalno popunjen.
			if (q == root) { // Ako je u pitanju koren, vrsi se prelom

				string keystmp[13] = { "/", "/", "/", "/", "/", "/", "/", "/", "/", "/", "/", "/", "/" }; // Ne moze biti vise od 12 kljuceva u korenu.

				// Stavljanje kljuceva iz punog cvora, kao i novog kljuca u pomocni niz - sortiran.
				for (i = 0; i < q->curNoKeys; i++) keystmp[i] = q->keys[i];
				i = 0;
				while (keystmp[i] < key&& keystmp[i] != "/") i++;
				for (j = q->curNoKeys; j > i; j--) keystmp[j] = keystmp[j - 1];
				keystmp[j] = key;

				// Odredjivanje sredisnjeg kljuca i granica.
				int half = ((q->curNoKeys + 1 - 1) / 2);
				string midkey = keystmp[half];
				int end = q->curNoKeys + 1;

				// Ucitavanje kljuceva nova dva cvora.
				Node* first = new Node, * second = new Node;
				for (i = 0; i < half; i++) first->keys[i] = keystmp[i];
				for (i = half + 1; i < end; i++) second->keys[i - half - 1] = keystmp[i];

				// Inicijalizacija novih cvorova.
				first->maxNoKeys = second->maxNoKeys = m - 1;
				first->minNoKeys = second->minNoKeys = (int)(ceil((2 * m - 1) / 3.0) - 1);
				first->parent = second->parent = q;
				first->childNo = 0;
				second->childNo = 1;
				first->curNoKeys = half;
				second->curNoKeys = end - half - 1;

				// Prevezivanje pokazivaca
				for (i = 0; i < half + 1; i++) {
					first->children[i] = q->children[i];
					if (first->children[i] != nullptr) first->children[i]->parent = first;
				}
				for (i = 0; i < end - half; i++) {
					second->children[i] = q->children[i + half + 1];
					if (second->children[i] != nullptr) {
						second->children[i]->childNo -= half + 1;
						second->children[i]->parent = second;
					}
				}

				// Restovanje korena koji postaje "nov" koren.
				for (i = 0; i < MAX_KEYS; i++) q->keys[i] = "/";
				for (int i = 0; i < MAX_KEYS + 1; i++) q->children[i] = nullptr;
				q->keys[0] = midkey;
				q->children[0] = first;
				q->children[1] = second;
				q->curNoKeys = 1;
				q->maxNoKeys = (int)(2 * floor((2 * m - 2) / 3));
				q->minNoKeys = 1;
				q->childNo = -1;
				q->parent = nullptr;
				return true;
			}
			else {
				int childID = q->childNo;
				//cout << childID;
				Node* brother, * parent = q->parent;
				//cout << parent->children[childID + 1]->curNoKeys + 1 << "-" << parent->children[childID + 1]->maxNoKeys << endl;

				string keystmp[25];
				for (i = 0; i < 25; i++) keystmp[i] = "/";


				// Ako nije poslednji sin, i ako njegov desni brat ima mesta vrsi se prelivanje u njega.
				if (childID < parent->curNoKeys && parent->children[childID + 1] != nullptr && parent->children[childID + 1]->curNoKeys + 1 <= parent->children[childID + 1]->maxNoKeys) {
					//cout << "HI";
					brother = parent->children[childID + 1];
					// Stavljanje kljuceva iz punog cvora, njegovog brata, kao i novi kljuc u pomocni niz.
					for (i = 0; i < q->curNoKeys; i++) keystmp[i] = q->keys[i];

					for (j = 0; j < brother->curNoKeys; j++) keystmp[j + i] = brother->keys[j];

					keystmp[j + i] = key;
					keystmp[j + i + 1] = parent->keys[childID]; // Stavljanje razdelnog kljuca u pomocni niz.
					for (int k = childID; k < parent->curNoKeys - 1; k++) parent->keys[k] = parent->keys[k + 1];
					parent->keys[parent->curNoKeys] = "/";
					(parent->curNoKeys)--; // Privremeno brisanje razdelnog kljuca iz roditeljskog cvora.

					int len = j + i + 2;
					for (i = 0; i < len; i++) { // Sortiranje niza
						for (j = i; j < len; j++) {
							if (keystmp[i] > keystmp[j]) {
								string t = keystmp[i];
								keystmp[i] = keystmp[j];
								keystmp[j] = t;
							}
						}
					}
					//for (int k = 0; k < 25; k++) cout << keystmp[k] << "-";
					//cout << len;
					// Odredjivanje sredisnjeg kljuca i granica.
					int half = ((len - 1) / 2);
					string midkey = keystmp[half];
					int end = len;

					// Prepovezivanje pokazivaca brace.
					int noPointers1 = q->curNoKeys + 1, noPointers2 = brother->curNoKeys + 1;
					if (q->children[q->curNoKeys + 1] != nullptr) noPointers1++;
					int move = noPointers1 - (half + 1); // Ovoliko pokazivaca iz levog prelazi u desnog brata.
					//cout << move << endl;
					for (i = noPointers2 - 1; i >= 0; i--) {
						brother->children[i + move] = brother->children[i];
						//brother->children[i + move]->childNo += move;
						if (brother->children[i + move] != nullptr) {
							brother->children[i + move]->childNo = i + move;
							brother->children[i + move]->parent = brother;
						}
					}
					for (i = 0; i < move; i++) {
						brother->children[i] = q->children[q->curNoKeys + 1 - i];
						brother->children[i]->childNo = i;
						brother->children[i]->parent = brother;
						q->children[q->curNoKeys + 1 - i] = nullptr;
					}


					// Restovanje kljuceva brace.
					for (i = 0; i < MAX_KEYS; i++) {
						q->keys[i] = "/"; brother->keys[i] = "/";
					}
					for (i = 0; i < half; i++) q->keys[i] = keystmp[i];
					for (i = half + 1; i < end; i++) brother->keys[i - half - 1] = keystmp[i];

					q->maxNoKeys = brother->maxNoKeys = m - 1;
					q->minNoKeys = brother->minNoKeys = (int)(ceil((2 * m - 1) / 3.0) - 1);
					q->curNoKeys = half;
					brother->curNoKeys = end - half - 1;

					// Prenos sredisnjeg kljuca u roditelja, i propagacija na gore.
					key = midkey;
					q = q->parent;
				}
				// Ako nije prvi sin, i ako njegov levi brat ima mesta vrsi se prelivanje u njega.
				else if (childID > 0 && parent->children[childID - 1] != nullptr && parent->children[childID - 1]->curNoKeys + 1 <= parent->children[childID - 1]->maxNoKeys) {
					//cout << "BYE";
					brother = parent->children[childID - 1];
					// Stavljanje kljuceva iz punog cvora, njegovog brata, kao i novi kljuc u pomocni niz.
					for (i = 0; i < q->curNoKeys; i++) keystmp[i] = q->keys[i];

					for (j = 0; j < brother->curNoKeys; j++) keystmp[j + i] = brother->keys[j];

					//cout << q->parent->keys[0] << " " << brother->keys[0];
					keystmp[j + i] = key;
					keystmp[j + i + 1] = parent->keys[childID - 1]; // Stavljanje razdelnog kljuca u pomocni niz.
					for (int k = childID - 1; k < parent->curNoKeys - 1; k++) parent->keys[k] = parent->keys[k + 1];
					parent->keys[parent->curNoKeys - 1] = "/"; // ??????????????????? mozda parent->curNoKeys bez -1
					(parent->curNoKeys)--; // Privremeno brisanje razdelnog kljuca iz roditeljskog cvora.

					int len = j + i + 2;
					for (i = 0; i < len; i++) { // Sortiranje niza
						for (j = i; j < len; j++) {
							if (keystmp[i] > keystmp[j]) {
								string t = keystmp[i];
								keystmp[i] = keystmp[j];
								keystmp[j] = t;
							}
						}
					}
					//for (int k = 0; k < 25; k++) cout << keystmp[k] << "-";
					//cout << len;
					// Odredjivanje sredisnjeg kljuca i granica.
					int half = ((len - 1) / 2);
					string midkey = keystmp[half];
					int end = len;

					// Prepovezivanje pokazivaca brace.
					int noPointers1 = q->curNoKeys + 1, noPointers2 = brother->curNoKeys + 1;
					if (q->children[q->curNoKeys + 1] != nullptr) noPointers1++;
					//cout << noPointers1 << "-" << half + 1 << noPointers2 << endl;
					int move = noPointers1 - (half + 1); // Ovoliko pokazivaca iz desnog prelazi u levog brata.
					//for (i = noPointers2 - 1; i >= 0; i--) brother->children[i + move] = q->children[i];
					for (i = noPointers2 - 1; i > 0; i--) {
						brother->children[i + move] = q->children[i - 1];
						if (brother->children[i + move] != nullptr) {
							brother->children[i + move]->childNo = i + move; // ????
							brother->children[i + move]->parent = brother;
						}
					}
					for (i = 0; i < noPointers1 - move; i++) {
						q->children[i] = q->children[i + move]; // move -> move-1 ????
						if (q->children[i] != nullptr) {
							q->children[i]->childNo = i; // ????
							q->children[i]->parent = q;
						}
					}
					for (j = i; j < i + move; j++) q->children[j] = nullptr;

					// Restovanje kljuceva brace.
					for (i = 0; i < MAX_KEYS; i++) {
						q->keys[i] = "/"; brother->keys[i] = "/";
					}
					for (i = 0; i < half; i++) brother->keys[i] = keystmp[i];
					for (i = half + 1; i < end; i++) q->keys[i - half - 1] = keystmp[i];

					q->maxNoKeys = brother->maxNoKeys = m - 1;
					brother->minNoKeys = q->minNoKeys = (int)(ceil((2 * m - 1) / 3.0) - 1);
					brother->curNoKeys = half;
					q->curNoKeys = end - half - 1;
					//cout << q->curNoKeys << " " << brother->curNoKeys << endl;

					// Prenos sredisnjeg kljuca u roditelja, i propagacija na gore.
					key = midkey;
					q = q->parent;
				}
				// Ako je prvi, poslednji ili su mu oba brata puna, vrsi se prelom.
				else {
					//cout << "PRELOM 2-3" << endl;
					if (childID < parent->curNoKeys && parent->children[childID + 1] != nullptr) { // Ako ima desnog brata
						//cout << "HI";
						brother = parent->children[childID + 1];

						Node* nodestmp[25];
						for (i = 0; i < 25; i++) nodestmp[i] = nullptr;

						for (i = 0; i < q->curNoKeys; i++) keystmp[i] = q->keys[i];
						for (j = 0; j < brother->curNoKeys; j++) keystmp[j + i] = brother->keys[j];
						keystmp[j + i] = key;
						keystmp[j + i + 1] = parent->keys[childID]; // Stavljanje razdelnog kljuca u pomocni niz.

						int k, l;
						for (k = 0; k < q->curNoKeys + 1; k++) nodestmp[k] = q->children[k];
						if (q->children[k] != nullptr) {
							nodestmp[k] = q->children[k];
							k++;
						}
						for (l = 0; l < brother->curNoKeys + 1; l++) nodestmp[k + l] = brother->children[l];
						

						int len = j + i + 2;
						for (i = 0; i < len; i++) { // Sortiranje niza
							for (j = i; j < len; j++) {
								if (keystmp[i] > keystmp[j]) {
									string t = keystmp[i];
									keystmp[i] = keystmp[j];
									keystmp[j] = t;
								}
							}
						}

						//for (int k = 0; k < 25; k++) cout << keystmp[k] << "-";
						int firstThird = floor((2 * m - 2) / 3.);
						int secondThird = floor((2 * m - 1) / 3.);
						string midkey1 = keystmp[firstThird];
						string midkey2 = keystmp[firstThird + secondThird + 1];
						int end = len;

						// Restovanje kljuceva brace.
						for (i = 0; i < MAX_KEYS; i++) {
							q->keys[i] = "/"; brother->keys[i] = "/";
						}
						for (i = 0; i < firstThird; i++) q->keys[i] = keystmp[i];
						for (i = firstThird + 1; i < firstThird + secondThird + 1; i++) brother->keys[i - firstThird - 1] = keystmp[i];
						BStarTree::Node* n = new Node;
						n->curNoKeys = floor(2 * m / 3.);
						n->maxNoKeys = m - 1;
						n->minNoKeys = (int)(ceil((2 * m - 1) / 3.0) - 1);
						for (i = firstThird + secondThird + 2; i < end; i++) n->keys[i - (firstThird + secondThird + 2)] = keystmp[i];


						q->maxNoKeys = brother->maxNoKeys = m - 1;
						q->minNoKeys = brother->minNoKeys = (int)(ceil((2 * m - 1) / 3.0) - 1);
						q->curNoKeys = firstThird;
						brother->curNoKeys = secondThird;

						for (i = 0; i < MAX_KEYS + 1; i++) q->children[i] = brother->children[i] = nullptr;
						for (i = 0; i < q->curNoKeys + 1; i++) {
							q->children[i] = nodestmp[i];
							if (q->children[i] != nullptr) {
								q->children[i]->childNo = i;
								q->children[i]->parent = q;
							}
						}
						for (j = 0; j < brother->curNoKeys + 1; j++) {
							brother->children[j] = nodestmp[i + j];
							if (brother->children[j] != nullptr) {
								brother->children[j]->childNo = j;
								brother->children[j]->parent = brother;
							}
						}
						for (int k = 0; k < n->curNoKeys + 1; k++) {
							n->children[k] = nodestmp[i + j + k];
							if (n->children[k] != nullptr) {
								n->children[k]->childNo = k;
								n->children[k]->parent = n;
							}
						}
						for (i = 0; i < 25; i++) {
							//if (nodestmp[i] != nullptr) cout << nodestmp[i]->keys[0] << "-";
							nodestmp[i] = nullptr;
						}
						//cout << "HI" << childID;
						// Pomeranje pokazivaca i uvezivanje novog cvora
						for (i = parent->curNoKeys + 1; i > childID + 2; i--) {
							//if (parent->children[i - 1] != nullptr) (parent->children[i]->childNo)++;
							parent->children[i] = parent->children[i - 1];
							if (parent->children[i - 1] != nullptr) (parent->children[i]->childNo)++;
						}
						//cout << "HI";
						parent->children[i] = n;
						n->parent = parent;
						n->childNo = childID + 2;

						parent->keys[childID] = midkey1; // Manji kljuc se stavlja na mesto prethodnog razdelnog kljuca, a veci se salje na umetanje.
						key = midkey2;
						q = q->parent;
					}
					else if (childID == parent->curNoKeys && parent->children[childID - 1] != nullptr) { // Ako je najdesnji sin pa ima samo levog brata
						//cout << "TEST";
						brother = parent->children[childID - 1];

						Node* nodestmp[25];
						for (i = 0; i < 25; i++) nodestmp[i] = nullptr;

						for (i = 0; i < q->curNoKeys; i++) keystmp[i] = q->keys[i];
						for (j = 0; j < brother->curNoKeys; j++) keystmp[j + i] = brother->keys[j];

						int k, l;
						for (k = 0; k < brother->curNoKeys + 1; k++) nodestmp[k] = brother->children[k];
						for (l = 0; l < q->curNoKeys + 1; l++) nodestmp[k + l] = q->children[l];
						if (q->children[l] != nullptr) nodestmp[k + l] = q->children[l];
						//cout << brother->curNoKeys + 1 << " " << q->curNoKeys + 1;
						keystmp[j + i] = key;
						keystmp[j + i + 1] = parent->keys[childID - 1]; // Stavljanje razdelnog kljuca u pomocni niz.

						int len = j + i + 2;
						for (i = 0; i < len; i++) { // Sortiranje niza
							for (j = i; j < len; j++) {
								if (keystmp[i] > keystmp[j]) {
									string t = keystmp[i];
									keystmp[i] = keystmp[j];
									keystmp[j] = t;
								}
							}
						}

						//for (int k = 0; k < 25; k++) cout << keystmp[k] << "-";
						int firstThird = floor((2 * m - 2) / 3.);
						int secondThird = floor((2 * m - 1) / 3.);
						string midkey1 = keystmp[firstThird];
						string midkey2 = keystmp[firstThird + secondThird + 1];
						int end = len;

						// Restovanje kljuceva brace.
						for (i = 0; i < MAX_KEYS; i++) {
							q->keys[i] = "/"; brother->keys[i] = "/";
						}
						for (i = 0; i < firstThird; i++) brother->keys[i] = keystmp[i];
						for (i = firstThird + 1; i < firstThird + secondThird + 1; i++) q->keys[i - firstThird - 1] = keystmp[i];
						BStarTree::Node* n = new Node;
						n->curNoKeys = floor(2 * m / 3.);
						n->maxNoKeys = m - 1;
						n->minNoKeys = (int)(ceil((2 * m - 1) / 3.0) - 1);
						for (i = firstThird + secondThird + 2; i < end; i++) n->keys[i - (firstThird + secondThird + 2)] = keystmp[i];


						q->maxNoKeys = brother->maxNoKeys = m - 1;
						q->minNoKeys = brother->minNoKeys = (int)(ceil((2 * m - 1) / 3.0) - 1);
						brother->curNoKeys = firstThird;
						q->curNoKeys = secondThird;

						for (i = 0; i < MAX_KEYS + 1; i++) q->children[i] = brother->children[i] = nullptr;
						for (i = 0; i < brother->curNoKeys + 1; i++) {
							brother->children[i] = nodestmp[i];
							if (brother->children[i] != nullptr) {
								brother->children[i]->childNo = i;
								brother->children[i]->parent = brother;
							}
						}
						for (j = 0; j < q->curNoKeys + 1; j++) {
							q->children[j] = nodestmp[i + j];
							if (q->children[j] != nullptr) {
								q->children[j]->childNo = j;
								q->children[j]->parent = q;
							}
						}
						for (int k = 0; k < n->curNoKeys + 1; k++) {
							n->children[k] = nodestmp[i + j + k];
							if (n->children[k] != nullptr) {
								n->children[k]->childNo = k;
								n->children[k]->parent = n;
							}
						}
						for (i = 0; i < 25; i++) {
							//if (nodestmp[i] != nullptr) cout << nodestmp[i]->keys[0] << "-";
							nodestmp[i] = nullptr;
						}

						// Uvezivanje novog cvora (ne pomeraju se prethodni jer se svakako umece najdesnije)
						parent->children[childID + 1] = n;
						n->parent = parent;
						n->childNo = childID + 1;

						parent->keys[childID - 1] = midkey1; // Manji kljuc se stavlja na mesto prethodnog razdelnog kljuca, a veci se salje na umetanje.
						key = midkey2;
						q = q->parent;
					}
				}
			}
		}
	}
	return false;
}


bool BStarTree::removeKey(string key, int m) {
	Node* p = root, * q = nullptr, * parent = nullptr, * brother = nullptr;
	int i, j, keyNo;
	bool found = false;
	while (p && !found) {
		for (i = 0; i < p->curNoKeys; i++) {
			if (key == p->keys[i]) {
				keyNo = i;
				found = true;
				break;
			}
			if (key < p->keys[i]) break;
		}
		q = p;
		p = p->children[i];
	}
	if (!found) return false;

	bool isLeaf = true;
	for (i = 0; i < q->curNoKeys + 1; i++) {
		if (q->children[i] != nullptr) {
			isLeaf = false;
			break;
		}
	}
	//cout << isLeaf << endl;
	if (!isLeaf) { // Pronalazenje sledbenika
		for (i = 0; i < q->curNoKeys; i++) {
			if (q->keys[i] == key) {
				p = q->children[i + 1];
				break;
			}
		}
		while (p && p->children[0] != nullptr) p = p->children[0]; // Kretanje levo do lista
		string succ;
		if (p) succ = p->keys[0]; // Sledbenik je najlevlji kljuc tu.
		// Zamena sa sledbenikom
		//cout << succ << endl;
		if (p) {
			p->keys[0] = q->keys[keyNo];
			q->keys[keyNo] = succ;
		}
		if (p) q = p; // Oznaka da se cvor koji se brise nalazi sad u listu, promena q na list p
		//cout << q->keys[0]; // Kljuc koji se brise ce sigurno biti najlevlji u cvoru jer je bio zamenjen sa sledbenikom
	}
	bool rootMerge = false;
	while (q) {
		parent = q->parent;
		//if (parent) cout << parent->children[0]->keys[0];
		if (q->curNoKeys - 1 >= q->minNoKeys || (q == root && q->curNoKeys == 1 && q->children[0] == nullptr)) { // Slucaj ako list(cvor) ostaje bar minimalno popunjen nakon brisanja. ()
			//cout << "EVO" << endl;
			if (q == root && q->curNoKeys == 1 && q->children[0] == nullptr) {
				root = nullptr;
				return true;
			}
			i = 0;
			while (q->keys[i] != key) i++;
			if (i >= q->curNoKeys) return false;
			for (j = i; j < q->curNoKeys - 1; j++) q->keys[j] = q->keys[j + 1];
			q->keys[j] = "/";
			(q->curNoKeys)--;
			//for (j = 0; j < q->curNoKeys; j++) q->keys[i + j] = q->keys[i + j + 1]; // ??
			return true;
		}
		else {
			int childID = q->childNo;
			if (q == root && rootMerge) { 
				//cout << "CPX" << endl;
				if (q->children[0] != nullptr) {
					root = q->children[0];
					root->parent = nullptr;
				}
				else { root = nullptr; }
				delete q;
				return true; 
			} // Ako koren ostaje nepopunjen, vrsi se spajanje 2 u 1.

			else if (childID < parent->curNoKeys && parent->children[childID + 1] != nullptr && parent->children[childID + 1]->curNoKeys - 1 >= parent->children[childID + 1]->minNoKeys) {
				// Ako desni brat nakon uklanjanja ostaje iznad minimuma, pozajmljuje se od njega
				brother = parent->children[childID + 1];
				//cout << "DESNI1 " << parent->children[childID + 1]->curNoKeys << " MIN -> " << parent->children[childID + 1]->minNoKeys  << endl;
				
				// Brisanje trazenog kljuca iz cvora
				i = 0;
				while (q->keys[i] != key) i++;
				if (i >= q->curNoKeys) return false;
				for (j = i; j < q->curNoKeys - 1; j++) q->keys[j] = q->keys[j + 1];
				q->keys[j] = "/";
				(q->curNoKeys)--;

				// Premestanje kljuceva
				q->keys[q->curNoKeys] = parent->keys[childID];
				parent->keys[childID] = brother->keys[0];
				(q->curNoKeys)++;

				// Pomeranje kljuceva i pokazivaca u bratu za jedno mesto ulevo i premestanje jednog pokazivaca na tren cvor
				q->children[q->curNoKeys] = brother->children[0];
				if (q->children[q->curNoKeys] != nullptr) q->children[q->curNoKeys]->childNo = q->curNoKeys; // ***
				//q->children[q->curNoKeys]->parent = q; // ne mora, ako su braca imaju istog oca
				for (j = 0; j < brother->curNoKeys - 1; j++) {
					brother->keys[j] = brother->keys[j + 1];
				}
				brother->keys[j] = "/";
				for (i = 0; i < brother->curNoKeys; i++) {
					brother->children[i] = brother->children[i + 1];
					//brother->children[i]->parent = brother;
					if (brother->children[i] != nullptr) brother->children[i]->childNo--;
				}
				brother->children[i] = nullptr;
				(brother->curNoKeys)--;

				return true; // UKLONITI pa zameniti sa q = q->parent;
			}

			else if (childID > 0 && parent->children[childID - 1] != nullptr && parent->children[childID - 1]->curNoKeys - 1 >= parent->children[childID - 1]->minNoKeys) {
				// Ako levi brat nakon uklanjanja ostaje iznad minimuma, pozajmljuje se od njega
				brother = parent->children[childID - 1];

				// Brisanje trazenog kljuca iz cvora
				i = 0;
				while (q->keys[i] != key) i++;
				if (i >= q->curNoKeys) return false;
				for (j = i; j < q->curNoKeys - 1; j++) q->keys[j] = q->keys[j + 1];
				q->keys[j] = "/";
				(q->curNoKeys)--;

				// Premestanje kljuceva
				q->keys[q->curNoKeys] = parent->keys[childID - 1];
				parent->keys[childID - 1] = brother->keys[brother->curNoKeys - 1];
				(q->curNoKeys)++;

				// Pomeranje kljuceva i pokazivaca u bratu za jedno mesto ulevo i premestanje jednog pokazivaca na tren cvor
				q->children[q->curNoKeys - 1] = brother->children[brother->curNoKeys];
				if (q->children[q->curNoKeys - 1] != nullptr) q->children[q->curNoKeys - 1]->childNo = q->curNoKeys - 1; // ***
				//q->children[q->curNoKeys - 1]->parent = q; // ne mora, ako su braca imaju istog oca
				brother->keys[brother->curNoKeys - 1] = "/";
				brother->children[brother->curNoKeys] = nullptr;
				(brother->curNoKeys)--;

				return true; // UKLONITI pa zameniti sa q = q->parent;
			}

			else if (childID < parent->curNoKeys - 1 && parent->children[childID + 2] != nullptr && parent->children[childID + 2]->curNoKeys - 1 >= parent->children[childID + 2]->minNoKeys) {
				// Ako drugi desni brat nakon uklanjanja ostaje iznad minimuma, pozajmljuje se od njega
				brother = parent->children[childID + 2];
				Node* midbrother = parent->children[childID + 1];

				// Brisanje trazenog kljuca iz cvora
				i = 0;
				while (q->keys[i] != key) i++;
				if (i >= q->curNoKeys) return false;
				for (j = i; j < q->curNoKeys - 1; j++) q->keys[j] = q->keys[j + 1];
				q->keys[j] = "/";
				(q->curNoKeys)--;

				// Operacije izmedju naseg cvora i prvog brata
				// Premestanje kljuceva
				q->keys[q->curNoKeys] = parent->keys[childID];
				parent->keys[childID] = midbrother->keys[0];
				(q->curNoKeys)++;

				// Pomeranje kljuceva i pokazivaca u bratu za jedno mesto ulevo i premestanje jednog pokazivaca na tren cvor
				q->children[q->curNoKeys] = midbrother->children[0];
				if (q->children[q->curNoKeys] != nullptr) q->children[q->curNoKeys]->childNo = q->curNoKeys;
				//q->children[q->curNoKeys]->parent = q; // ne mora, ako su braca imaju istog oca
				for (j = 0; j < midbrother->curNoKeys - 1; j++) {
					midbrother->keys[j] = midbrother->keys[j + 1];
				}
				midbrother->keys[j] = "/";
				for (i = 0; i < midbrother->curNoKeys; i++) {
					midbrother->children[i] = midbrother->children[i + 1];
					//brother->children[i]->parent = brother;
					if (midbrother->children[i] != nullptr) midbrother->children[i]->childNo--;
				}
				midbrother->children[i] = nullptr;
				(midbrother->curNoKeys)--;

				// Operacije izmedju prvog i drugog brata
				// Premestanje kljuceva
				int childIDnew = childID + 1;
				midbrother->keys[midbrother->curNoKeys] = parent->keys[childIDnew];
				parent->keys[childIDnew] = brother->keys[0];
				(midbrother->curNoKeys)++;

				// Pomeranje kljuceva i pokazivaca u bratu za jedno mesto ulevo i premestanje jednog pokazivaca na tren cvor
				midbrother->children[midbrother->curNoKeys] = brother->children[0];
				if (midbrother->children[midbrother->curNoKeys] != nullptr) midbrother->children[midbrother->curNoKeys]->childNo = midbrother->curNoKeys;
				//q->children[q->curNoKeys]->parent = q; // ne mora, ako su braca imaju istog oca
				for (j = 0; j < brother->curNoKeys - 1; j++) {
					brother->keys[j] = brother->keys[j + 1];
				}
				brother->keys[j] = "/";
				for (i = 0; i < brother->curNoKeys; i++) {
					brother->children[i] = brother->children[i + 1];
					//brother->children[i]->parent = brother;
					if (brother->children[i] != nullptr) brother->children[i]->childNo--;
				}
				brother->children[i] = nullptr;
				(brother->curNoKeys)--;

				return true; // UKLONITI pa zameniti sa q = q->parent;
			}

			else if (childID > 1 && parent->children[childID - 2] != nullptr && parent->children[childID - 2]->curNoKeys - 1 >= parent->children[childID - 2]->minNoKeys) {
				// Ako drugi levi brat nakon uklanjanja ostaje iznad minimuma, pozajmljuje se od njega
				brother = parent->children[childID - 2];
				Node* midbrother = parent->children[childID - 1];

				// Brisanje trazenog kljuca iz cvora
				i = 0;
				while (q->keys[i] != key) i++;
				if (i >= q->curNoKeys) return false;
				for (j = i; j < q->curNoKeys - 1; j++) q->keys[j] = q->keys[j + 1];
				q->keys[j] = "/";
				(q->curNoKeys)--;

				// Operacije izmedju naseg cvora i prvog brata
				// Premestanje kljuceva
				q->keys[q->curNoKeys] = parent->keys[childID - 1];
				parent->keys[childID - 1] = midbrother->keys[midbrother->curNoKeys - 1];
				(q->curNoKeys)++;

				// Pomeranje kljuceva i pokazivaca u bratu za jedno mesto ulevo i premestanje jednog pokazivaca na tren cvor
				q->children[q->curNoKeys - 1] = midbrother->children[midbrother->curNoKeys];
				if (q->children[q->curNoKeys - 1] != nullptr) q->children[q->curNoKeys - 1]->childNo = q->curNoKeys - 1;
				//q->children[q->curNoKeys - 1]->parent = q; // ne mora, ako su braca imaju istog oca
				midbrother->keys[midbrother->curNoKeys - 1] = "/";
				midbrother->children[brother->curNoKeys] = nullptr;
				(midbrother->curNoKeys)--;

				// Operacije izmedju prvog i drugog brata
				// Premestanje kljuceva
				int childIDnew = childID - 1;
				midbrother->keys[midbrother->curNoKeys] = parent->keys[childIDnew - 1];
				parent->keys[childIDnew - 1] = brother->keys[brother->curNoKeys - 1];
				(midbrother->curNoKeys)++;

				// Pomeranje kljuceva i pokazivaca u bratu za jedno mesto ulevo i premestanje jednog pokazivaca na tren cvor
				// Pomeramo pokazivace za jedno mesto unapred kako bi se oslobodilo mesto za novi pokaivac na pocetku
				for (i = 0; i < midbrother->curNoKeys; i++) {
					midbrother->children[i + 1] = midbrother->children[i];
					if (midbrother->children[i + 1] != nullptr) midbrother->children[i + 1]->childNo++;
				}
				//midbrother->children[midbrother->curNoKeys - 1] = brother->children[brother->curNoKeys];
				midbrother->children[0] = brother->children[brother->curNoKeys];
				if (midbrother->children[0] != nullptr) midbrother->children[0]->childNo = 0;
				//q->children[q->curNoKeys - 1]->parent = q; // ne mora, ako su braca imaju istog oca
				brother->keys[brother->curNoKeys - 1] = "/";
				brother->children[brother->curNoKeys] = nullptr;
				(brother->curNoKeys)--;

				return true; // UKLONITI pa zameniti sa q = q->parent;
			}

			else if (parent->curNoKeys >= 2) { // Ako ima bar 2 kljuca (3 sina) vrsi se spajanje 3 u 2;
				//cout << "ENTER2";
				Node* first = nullptr, * second = nullptr, * third = nullptr;
				int k, l, m;
				if (q->childNo == 0 && parent->children[1] != nullptr && parent->children[2] != nullptr) { // Ako je q prvi sin
					first = q;
					second = parent->children[1];
					third = parent->children[2];
				}
				else if (q->childNo == parent->curNoKeys && parent->children[q->childNo - 1] != nullptr && parent->children[q->childNo - 2] != nullptr) { // Ako je q poslednji sin
					first = parent->children[q->childNo - 2];
					second = parent->children[q->childNo - 1];
					third = q;
				}
				else if (parent->children[q->childNo - 1] != nullptr && parent->children[q->childNo + 1] != nullptr) { // Ako nije ni prvi ni poslednji
					first = parent->children[q->childNo - 1];
					second = q;
					third = parent->children[q->childNo + 1];
				}
				else return false;

				string keystmp[38];
				for (i = 0; i < 38; i++) keystmp[i] = "/";

				Node* nodestmp[38];
				for (i = 0; i < 38; i++) nodestmp[i] = nullptr;

				// Umetanje svih pokazivaca u pomocni niz
				for (i = 0; i < first->curNoKeys + 1; i++) nodestmp[i] = first->children[i];
				for (j = 0; j < second->curNoKeys + 1; j++) nodestmp[j + i] = second->children[j];
				for (k = 0; k < third->curNoKeys + 1; k++) nodestmp[k + j + i] = third->children[k];

				// Umetanje svih kljuceva i razdelnih u pomocni niz
				int count = 0;
				for (i = 0; i < first->curNoKeys; i++) {
					if (first->keys[i] != key) keystmp[count++] = first->keys[i];
				}
				for (j = 0; j < second->curNoKeys; j++) {
					if (second->keys[j] != key) keystmp[count++] = second->keys[j];
				}
				for (k = 0; k < third->curNoKeys; k++) {
					if (third->keys[k] != key) keystmp[count++] = third->keys[k];
				}
				keystmp[count++] = parent->keys[first->childNo];
				keystmp[count++] = parent->keys[second->childNo];

				int len = count;
				for (i = 0; i < len; i++) { // Sortiranje niza
					for (j = i; j < len; j++) {
						if (keystmp[i] > keystmp[j]) {
							string t = keystmp[i];
							keystmp[i] = keystmp[j];
							keystmp[j] = t;
						}
					}
				}

				int half = ((len - 1) / 2);
				string midkey = keystmp[half];
				int end = len;
				//for (i = 0; i < 38; i++) cout << keystmp[i] << "/";
				Node* new1 = new Node, * new2 = new Node;
				new1->maxNoKeys = new2->maxNoKeys = first->maxNoKeys;
				new1->minNoKeys = new2->minNoKeys = first->minNoKeys;
				new1->parent = new2->parent = q->parent;
				new1->childNo = first->childNo; new2->childNo = second->childNo;
				new1->curNoKeys = half; new2->curNoKeys = end - half - 1;

				for (i = 0; i < half; i++) new1->keys[i] = keystmp[i];
				for (j = half + 1; j < end; j++) new2->keys[j - half - 1] = keystmp[j];
				for (i = 0; i < half + 1; i++) {
					new1->children[i] = nodestmp[i];
					if (new1->children[i] != nullptr) {
						new1->children[i]->parent = new1;
						new1->children[i]->childNo = i;
					}
				}
				for (j = half + 1; j < end + 1; j++) { // end + 2???
					new2->children[j - half - 1] = nodestmp[j];
					if (new2->children[j - half - 1] != nullptr) {
						new2->children[j - half - 1]->parent = new2;
						new2->children[j - half - 1]->childNo = j - half - 1;
					}
				}



				for (i = 0; i < 38; i++) nodestmp[i] = nullptr;
				parent->keys[first->childNo] = midkey;
				parent->keys[second->childNo] = key + "*";
				parent->children[first->childNo] = new1;
				parent->children[second->childNo] = new2;
				//parent->children[third->childNo] = nullptr;
				for (i = third->childNo; i < parent->curNoKeys; i++) {
					parent->children[i] = parent->children[i + 1];
					if (parent->children[i] != nullptr) parent->children[i]->childNo--;
				}
				delete first;
				delete second;
				delete third;

				key = key + "*";
				q = new1->parent;
				//continue;
				//return true;
			}

			else if (parent->curNoKeys == 1) { // Ako ima tacno 2 sina, vrsi se spajanje 2 u 1
				//cout << "ENTER1";
				Node* first = nullptr, * second = nullptr;
				int k, l;
				first = parent->children[0];
				second = parent->children[1];

				string keystmp[25];
				for (i = 0; i < 25; i++) keystmp[i] = "/";

				Node* nodestmp[25];
				for (i = 0; i < 25; i++) nodestmp[i] = nullptr;

				//cout << first->keys[0] << " - " << second->keys[0] << endl;
				//cout << first->curNoKeys << " - " << second->curNoKeys << endl;
				// Umetanje svih pokazivaca u pomocni niz
				int countp = 0;
				if (first != nullptr && first->children[first->curNoKeys] != nullptr) countp = 1;
				for (i = 0; i < first->curNoKeys + countp; i++) {
					nodestmp[i] = first->children[i];
				}

				for (j = 0; j < second->curNoKeys + 1; j++) {
					nodestmp[j + i] = second->children[j];
				}

				// Umetanje svih kljuceva i razdelnih u pomocni niz
				int count = 0;
				for (i = 0; i < first->curNoKeys; i++) {
					if (first->keys[i] != key) keystmp[count++] = first->keys[i];
				}
				for (j = 0; j < second->curNoKeys; j++) {
					if (second->keys[j] != key) keystmp[count++] = second->keys[j];
				}
				keystmp[count++] = parent->keys[first->childNo];

				int len = count;
				for (i = 0; i < len; i++) { // Sortiranje niza
					for (j = i; j < len; j++) {
						if (keystmp[i] > keystmp[j]) {
							string t = keystmp[i];
							keystmp[i] = keystmp[j];
							keystmp[j] = t;
						}
					}
				}

				//for (i = 0; i < 25; i++) cout << keystmp[i] << "-";
				//cout << "CP" << endl;
				Node* new1 = new Node;
				new1->maxNoKeys= first->maxNoKeys;
				new1->minNoKeys = first->minNoKeys;
				new1->parent = q->parent;
				new1->childNo = first->childNo;
				new1->curNoKeys = len;

				//cout << "CP" << endl;
				for (i = 0; i < len; i++) new1->keys[i] = keystmp[i];
				count = 0;
				for (i = 0; i < len + 1; i++) {
					new1->children[i] = nodestmp[i + count];
					if (new1->children[i] != nullptr) {
						new1->children[i]->parent = new1;
						new1->children[i]->childNo = i;
					}
				}
				for (i = 0; i < 25; i++) nodestmp[i] = nullptr;

				parent->keys[first->childNo] = key + "*";
				parent->children[first->childNo] = new1;
				parent->children[second->childNo] = nullptr;
				delete first;
				delete second;

				key = key + "*";
				q = new1->parent;
				if (q->parent == nullptr) { // potencijalno i q != nullptr
					rootMerge = true;
				}
				//cout << q->parent->children[0];
				//print();
				//continue;
				//return true;
			}
		}
		//print();
	}
	return false;
}