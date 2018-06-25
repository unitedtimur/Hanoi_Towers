/*
*
*Created by UnitedTimur
*
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

struct Usel {

	int key;

	Usel *next;

};

struct Stack {

	Usel * head;

	Stack() : head(0) {}

	Usel * Push(int k) {

		Usel* p;

		p = new Usel;

		p->key = k; p->next = head;

		head = p; return head;

	}

	int Pop() {

		Usel *p = head;

		int k = head->key;

		head = head->next;

		delete p;

		return k;

	}

	void Print() {

		Usel *p;

		for (p = head; p; p = p->next) {

			cout << p->key << " ";

		}

	}

	void Del() {

		Usel* p;

		while (head) {

			p = head;

			head = head->next;

			delete p;

		}
	}

	bool Empty() {

		return head == 0 ? true : false;

	}

};

void Han(Stack *st, int n, int from, int to, int help) {

	if (n == 1) {

		int k = st[from].Pop(); 
		
		st[to].Push(k);
		
	puts("\nWorking...");

	st[2].Print();

	cout << endl;

	st[0].Print();

	cout << endl;

	st[1].Print();

	}

	else {

		Han(st, n - 1, from, help, to);

		Han(st, 1, from, to, help);

		Han(st, n - 1, help, to, from);

	}

}

int main(void) {

	Stack st[3];

	unsigned int n;

	cout << "Enter the n, please: ";

	cin >> n;

	for (int i = n; i; i--) {

		st[2].Push(i);

	}

	st[2].Print();

	unsigned int start = clock();

	Han(st, n, 2, 1, 0);

	unsigned int end = clock();

	cout << endl << "Program work about ~ " << end - start << "'ms" << " or " << (end - start) / 1000 << "'s" << endl;

	for (int i = 0; i < 3; i++) {

		if (st[i].Empty()) {

			st[i].Del();

		}

	}

	system("pause");
	system("cls");
	system("pause");
}
