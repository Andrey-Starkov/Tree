#include<iostream>
using namespace std;
struct Tree { //Дерево
	int value;
	Tree* left;
	Tree* right;
};

Tree* Add(Tree* current, int a) { //Добавление элемента в дерево
	if (current == nullptr) {
		current = new Tree;
		current->value=a;
		current->right = nullptr;
		current->left = nullptr;
	}
	else {
		if (a < current->value) {
			current->left=Add(current->left, a);
		}
		else {
			current->right=Add(current->right, a); }
	}
	return current;
}


Tree* del_elem(Tree* current, int aData) { //Удаление элемента из дерева
	if (current == nullptr)
		return current;

	if (aData == current->value) {
		Tree* temp = nullptr;
		if ((current->right == nullptr) && (current->left == nullptr)) {
			delete current;
			return temp;
		}
		else {
			if ((current->right == nullptr) || (current->left == nullptr))
			{

				if (current->right == nullptr) {
					current = current->left;
				}
				else {
					current = current->right;
				}
				return current;
			}

			else {
				Tree* temp = current->right;
				Tree* prev= current->right;
				while (temp->left != nullptr) {
					prev = temp;
					temp = temp->left;
				}
				current->value = temp->value;
				if (temp->right == nullptr) {
					prev->left = nullptr;
				}
				else {
					prev->left = prev->left->right;
					prev->left->right = nullptr;
				}
					temp = current;
				return temp;
			}
		}
	}
	else if (aData <= current->value)
		current->left = del_elem(current->left, aData);
	else
		current->right = del_elem(current->right, aData);
	return current;
}

void search(Tree* current,int a) { //Поиск

	while (current != nullptr) {
		if (current->value == a) { cout << "Данный элемент существует в дереве\n"; return; }
		if (a < current->value) { current = current->left; }
		else(current = current->right);
	}
	cout << "Такого элемента нет в дереве\n";
}


void Output(Tree* current) { //Постфиксный обход и вывод
	if (current != nullptr) {
		Output(current->left);
		cout << current->value << " ";
		Output(current->right);

	}
}
void DelALL(Tree* front) { //Удаляет все элементы дерева
	if (front != nullptr) {
		DelALL(front->left);
		DelALL(front->right);
		delete front;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Tree* front=new Tree;
	front = nullptr;
	int a=0;
	int b;

	
	while (a!=6)
	{
		cout << "1 Добавить элемент\n";
		cout << "2 Удалить элемент\n";
		cout << "3 Поиск\n";
		cout << "4 Вывод\n";
		cout << "5 Удаление всего дерева\n";
		cout << "6 Выход\n";
		cin >> a;
		switch (a)
		{
		case 1:
			//Output(Derevo, 0);
			cout << "Введите элемент: ";
			cin >> b;
			front = Add(front, b);
			break;
		case 2:
			cout << "Введите элемент, который хотите удалить\n";
			cin >> b;
			front = del_elem(front,b);
			break;
		case 3:
			cout << "Введите элемент: ";
			cin >> b;
			search(front, b);
			break;
		case 4:
			Output(front);
			cout << endl;
			break;
		case 5:
			DelALL(front);
			front = nullptr;
			break;
		}

	}

}