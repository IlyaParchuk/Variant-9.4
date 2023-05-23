// Вар.5 Зад.4 Сем.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


using namespace std;

class Node {
public:
    int value;
    Node* left_child;
    Node* right_child;

    Node(int value) {
        this->value = value;
        this->left_child = nullptr;
        this->right_child = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        this->root = nullptr;
    }

    void insert(int value) {
        if (this->root == nullptr) {
            this->root = new Node(value);
        }
        else {
            _insert(value, this->root);
        }
    }

    void _insert(int value, Node* current_node) {
        if (value < current_node->value) {
            if (current_node->left_child == nullptr) {
                current_node->left_child = new Node(value);
            }
            else {
                _insert(value, current_node->left_child);
            }
        }
        else if (value > current_node->value) {
            if (current_node->right_child == nullptr) {
                current_node->right_child = new Node(value);
            }
            else {
                _insert(value, current_node->right_child);
            }
        }
        else {
            cout << "Значение уже существует в дереве." << endl;
        }
    }

    bool search(int value) {
        if (this->root != nullptr) {
            return _search(value, this->root);
        }
        else {
            return false;
        }
    }

    bool _search(int value, Node* current_node) {
        if (value == current_node->value) {
            return true;
        }
        else if (value < current_node->value && current_node->left_child != nullptr) {
            return _search(value, current_node->left_child);
        }
        else if (value > current_node->value && current_node->right_child != nullptr) {
            return _search(value, current_node->right_child);
        }
        else {
            return false;
        }
    }
};

// Пример использования
int main() {
    setlocale(LC_ALL, "Russian");
    BinaryTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(7);
    //tree.insert(7); //ошибка значение уже существует
    tree.insert(12);
    tree.insert(20);

    cout << boolalpha << tree.search(10) << endl;  // true
    cout << boolalpha << tree.search(7) << endl;   // true
    cout << boolalpha << tree.search(22) << endl;  // false

    return 0;
}

