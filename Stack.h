#pragma once 

template <typename T>
class stack {
private:
	struct node;
	node* head;
	struct node {
		T data;
		node* next;
		node(T data, node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};
public:
	stack() { head = nullptr; }
	stack(T data) { head = new node(data); }
	bool is_empty() { return head == nullptr; }
	void push(T data) { head = new node(data, head); }
	T pop();
};

template <typename T> T stack<T>::pop() {
	if (!is_empty()) {
		T to_return = head->data;
		node* victim = head;
		head = head->next;
		delete victim;
		return to_return;
	}
}
