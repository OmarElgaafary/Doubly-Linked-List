int Length() {
	Node* tmp = root_;
	int i = 0;
	while (tmp != nullptr) {
		tmp = tmp->next;
		i++;
	}

	return i;
}

void setPrevious() {

	Node* current = root_;
	Node* previous = nullptr;

	for (int i = 0; i < Length() && current != nullptr; i++) {
	
		current->previous = previous;
		previous = current;
		current = current->next;
	}


}

void getPrevious(int position) {

		int i = 0;
		Node* tmp = root_;
		while (tmp != nullptr && i != position) {
			tmp = tmp->next;
			i++;
		} 

		std::cout <<"[" << tmp->previous->data << "]" << std::endl;
	
	}

