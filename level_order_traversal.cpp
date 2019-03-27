#include<iostream>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};
struct Queue {
	Queue *next;
	node *container;
};
class Bst_LevelOrderTraversal {
private:
	node *root;
	Queue *front, *rear;
public:

	Bst_LevelOrderTraversal() {
		root = NULL;
		front = rear = NULL;
		
	}

	Queue* Q_Create(node *temp) {
		Queue *temp_ = new Queue();
		temp_->next = NULL;
		temp_->container = temp;
		return temp_;
	}

	void Enqueue(node *temp) {
		if (front == NULL) {
			
			front =  Q_Create(temp);
			rear = front;
			return;
		}
		
		rear->next = Q_Create(temp);
		rear = rear->next;

	}

	bool is_queue_empty(Queue *temp) {
		if (temp == NULL)
			return false;
		else return true;
	}

	Queue* Dqueue() {

		Queue *raw = front;
		front = front->next;
		return raw;
	}
	
	void level_order(node *temp) {
		Enqueue(temp);
		while (is_queue_empty(front)) {

			Queue *q_node = Dqueue();
			node *b_node = q_node->container;
			if (!check_left(b_node)) {
				Enqueue(b_node->left);
			}
			if (!check_right(b_node)) {
				Enqueue(b_node->right);
			}
			cout<<b_node->data<<" ";
			delete q_node;
		}

	}

	bool check_left(node *temp) {
		if (temp->left == NULL) {
			return true;
		}
		else return false;
	}

	bool check_right(node *temp) {
		if (temp->right == NULL)
			return true;
		else return false;
	}

	bool is_greater(int val, int val_1) {
		if (val > val_1)
			return true;
		else return false;
	}

	node* Create(int data) {
		node *Node = new node();
		Node->data = data;
		Node->left == NULL;
		Node->right == NULL;
		return Node;
	}

	void Insertion(node *temp, int data) {
		if (root == NULL) {
			root = Create(data);
			return;
		}
		if (is_greater(temp->data, data)) {
			if (check_left(temp)) {
				temp->left = Create(data);
				return;
			}
			else Insertion(temp->left, data);

		}
		else {
			if (check_right(temp)) {
				
				temp->right = Create(data);
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else Insertion(temp->right, data);
		}

	}

	node *Get_Root() {
		return root;
	}

	void print(node *temp) {
		if (temp == NULL)
			return;
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}
};

int main() {
	Bst_LevelOrderTraversal bst;
	node *root = NULL;
	bst.Insertion(root, 12);
	root = bst.Get_Root();
	bst.Insertion(root, 1);
	bst.Insertion(root, 20);
	bst.Insertion(root, 18);
	bst.Insertion(root, 17);
	bst.Insertion(root, 2);
	bst.print(root);
	cout << endl << "'''''''''''''''''" << endl;
	bst.level_order(root);
}