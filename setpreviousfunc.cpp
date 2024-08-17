int Length() {
	Node* tmp = root_;
	int i = 0;
	while (tmp != nullptr) {
		tmp = tmp->next;
		i++;
	}

	return i;
}

void setprevious() {

	Node* current = root_;
	Node* previous = nullptr;

	for (int i = 0; i < Length() && current != nullptr; i++) {
	
		current->previous = previous;
		previous = current;
		current = current->next;
	}


}
