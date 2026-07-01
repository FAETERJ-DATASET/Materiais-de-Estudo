#ifndef _BStarTree_h_
#define _BStarTree_h_

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#define MAX_KEYS 12
using namespace std;

class BStarTree {
private: // PROMENITI U PRIVATE POSLE
	typedef struct Node {
		string keys[MAX_KEYS];
		int maxNoKeys, minNoKeys, curNoKeys;
		struct Node *children[MAX_KEYS + 1];
		struct Node* parent;
		int childNo, level;
		Node() {
			maxNoKeys = 0;
			minNoKeys = 0;
			curNoKeys = 0;
			parent = nullptr;
			childNo = 0;
			level = 0;
			for (int i = 0; i < MAX_KEYS + 1; i++) children[i] = nullptr;
			for (int i = 0; i < MAX_KEYS; i++) keys[i] = "/";
		}
	} Node;

	Node* root;

public:
	BStarTree(); // Konstruktor stabla
	~BStarTree(); // Destruktor stabla

	bool search(string key) const;
	bool addKey(string key, int m);
	bool removeKey(string key, int m);
	friend ostream& operator<<(ostream& os, const BStarTree& tree);
	void print() const;
	int findLesserKeys(string key) const;
};

#endif