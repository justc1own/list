#include <bits/stdc++.h>

using namespace std;

struct Node{
	Node* next;
	int count;
	string word;
};

typedef Node* pNode;

pNode add(string w) {
	pNode New = new Node;
	New->next = nullptr;
	New->count = 1;
	New->word = w;

	return New;
}

void addFirst(pNode& head, pNode new_) {
	new_->next = head;
	head = new_;
}

void addAfter(pNode p, pNode New) {
	New->next = p->next;
	p->next = New;
}

void addBefore(pNode p, pNode New, pNode head) {
	if(p == head) {
		addFirst(head, New);
		return;
	}

	pNode after = head;
	while(p && after->next != p) {
		after = after->next;
	}

	if(after) {
		addAfter(after, New);
	}
}

void addLast(pNode New, pNode& head) {
	if(head == nullptr) {
		addFirst(head, New);
		return;
	}

	pNode after = head;
	while(after && after->next != nullptr) {
		after = after->next;
	}

	addAfter(after, New);
}

pNode find(pNode head, string w) {
	pNode p = head;
	while(p && p->word != w) {
		p = p->next;
	}

	return p; 
}

int main() {
	int n; cin >> n;
	pNode HEAD = add("");

	while(n--) {
		string s; cin >> s;
		if(find(HEAD, s) != nullptr) {
			pNode q = add(s);
			addAfter(HEAD, q);
		}  else {
			pNode q = find(HEAD, s);
			
		}
		/*string command; cin >> command;
		if(command == "add") {

		}
		*/
	}
}