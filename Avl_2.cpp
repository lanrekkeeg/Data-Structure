#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node *right;
};

class BST {
private:

	node *temp_;
	int left;
	int right;
	int _height_;
public:
	
	node *root;
	BST(){
		root = temp_ = NULL;
		_height_ = 0;

	}
	void insert(node *&temp, int value)
	{
		if (root == NULL){
			root = new node;
			root->left = NULL;
			root->right = NULL;
			root->data = value;
			return;
		}

		
		else if (temp->data > value){
			
			if (temp->left == NULL){
				temp->left = new node;
				temp->left->data = value;
				temp->left->left = NULL;
				temp->left->right = NULL;
				return;
			}
			else{
				
				insert(temp->left, value);
				General_height(temp, value);
			}

		}
		else if (temp->data < value){

			if (temp->right == NULL){
				temp->right = new node;
				temp->right->data = value;
				temp->right->left = NULL;
				temp->right->right = NULL;
				return;
			}
			else {
				insert(temp->right, value);
			  	General_height(temp, value);
			}
		}
	}
	node* General_height(node *&temp, int value){
		
		int height_ = 0;
		cal(temp->left);
		int left_height = Return_height();
		_height_ = 0; // reset the height :: Remeber this height is class data member
		cal(temp->right);
		int right_height = Return_height();
		_height_ = 0;
		height_ = left_height - right_height;
		if (height_ <= -2){
			if (temp->data<value&&temp->right->data<value){
				 zag_zag(temp);
			}
			else
				zag_zig(temp);

		}
		else if (height_ >= 2){
			if (temp->data>value&&temp->left->data>value)
				 zig_zig(temp);
			else  zig_zag(temp);
		}
	}
	void zag_zag(node*& temp) {
		
		node *temp_1 = 	temp->right->left;
		temp->right->left = temp;
		temp = 	temp->right;
		temp->left->right = temp_1;
	}
	void zig_zig(node *&temp) {
		cout<<"Zig Zig is called "<<endl;
		node *temp_1 = 	temp->left->right;
		temp->left->right = temp;
		temp = 	temp->left;
		temp->right->left = temp_1;
		print(root);

	}
	void zag_zig(node *&temp) {
		cout<<"Zag zig is called "<<endl;
		node* temp1 = temp->right;
		temp->right = temp1->left;
		temp1->left = temp1->left->right;
		temp->right->right = temp1;
		zag_zag(temp);
	}
	node* zig_zag(node *&temp) {

	cout<<"Zig Zag is called "<<endl;
		node* temp_1 = temp->left;
		temp->left = temp_1->right;
		temp_1->right = temp->left->left;
		temp->left->left = temp_1;
		zig_zig(temp);
	}
	void print(node *temp){
		if (temp == NULL){
			return;
		}
		print(temp->left);
		cout << temp->data << " ";
		print(temp->right);
	}
	// inorder traversal used for height
	void height(node *temp,int i){
		
		if(temp==NULL)
			return;
		if(temp->left!=NULL){
			i++;
			height(temp->left,i);
			i--;
		}
		if(_height_<i){
			_height_ = i;
		}
		if(temp->right!=NULL){
			i++;
			height(temp->right,i);
			i--;
		}
			
	}
	int cal(node *temp){
		if(temp==NULL)
			return 0;
		 height(temp,1);
	}
	int Return_height() const{
		return _height_;
}
	void init_height() {
		_height_ = 0;
	}
};
int main(){
	
	BST B_1;
	int x = 0;
	for (int i = 1; i <= 11; i++){
		cout << "Enter the value:" << endl;
		cin >> x;
		B_1.insert(B_1.root, i);
	}
	system("CLS");
	B_1.cal(B_1.root->left);
	cout<<"Height of Left Sub tree is "<<B_1.Return_height()<<endl;
	B_1.init_height();
	B_1.cal(B_1.root->right);
	cout<<"Height of Right Sub tree is "<<B_1.Return_height()<<endl;
	
	cout << endl;
	B_1.print(B_1.root);
	cout << endl;
}

