#include <iostream>

struct Node {
	int value;
	Node* next;
	Node* prev;
};

class doubly_linked_list {
private:
	Node* root = nullptr;

public:
	
	void insert_at_head(int data)
	{
		Node* new_node = new Node();
		new_node->value = data;

		if (root == nullptr)
		{
			new_node->prev = nullptr;
			root = new_node;
			new_node->next = nullptr;
			return;
		}

		new_node->prev = nullptr;
		new_node->next = root;
		root->prev = new_node;
		root = new_node;

	}

	void insert_at_tail(int data)
	{
		Node* tmp = root, *new_node = new Node();
		new_node->value = data;

		if (tmp->next == nullptr)
		{
			root->next = new_node;
			new_node->prev = root;
			new_node->next = nullptr;
			return;
		}
		else if (root == nullptr)
		{
			insert_at_head(data);
			return;
		}


		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}

		// last node

		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = nullptr;
	}

	void print_list(Node* node)
	{
		if (node == nullptr)
		{
			std::cout << "[Empty]\n";
			return;
		}

		std::cout << node->value << " ";
		print_list(node->next);
	}

	void print_reverse_list()
	{
		if (root == nullptr) return;

		Node* tmp = root;

		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}

		while (tmp != nullptr)
		{
			std::cout << tmp->value << " ";
			tmp = tmp->prev;
		}

	}

	Node* get_root()
	{
		return root;
	}

	void free_list()
	{
		Node* tmp;
		while (root != nullptr)
		{
			tmp = root;
			root = root->next;
			delete tmp;

		}
	}
	
};

int main()
{
	doubly_linked_list doubly;
	doubly.insert_at_head(1);
	doubly.insert_at_tail(5);
	doubly.insert_at_tail(6);
	doubly.insert_at_tail(7);
	doubly.insert_at_tail(8);
	doubly.insert_at_tail(9);
	doubly.insert_at_tail(10);
	doubly.print_list(doubly.get_root());
	
	std::cout << "\n\n-------------------\n\n";

	doubly.print_reverse_list();

	std::cout << "\n\n---------------------\n\n";
	doubly.free_list();
	doubly.print_list(doubly.get_root());
}
