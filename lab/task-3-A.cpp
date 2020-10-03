#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class List{
    private:
        node *head;
      //  node* tail; // i used for task only, it has nothing to with link list implementation
    public:
        List(){
            head = NULL;
        }
    
    node * get_new_node(int data){
        node* link_node = new node();
        link_node->data=data;
        link_node->next=NULL;
        return link_node;
    }

    void add_link_node_to_head(int data){
        if(head==NULL){
            head = get_new_node(data);
            return;
        }
        node* data_node = get_new_node(data);
        data_node->next = head;
        head = data_node;
    }

    void add_link_node_to_tail(int data){
        if(head==NULL){
           // head = get_new_node(data);
           node *temp = new node();
           temp->data = data;
           head = temp;
            return;
        }
        node *temp = new node();
        temp->data = data;
        temp->next = NULL;
       // node* data_node = get_new_node(data);
       // node *tail = get_tail(head);
       // tail->next = data_node;
       
    }

    node* get_head(){
        return head;
    }

    node* get_tail(node* head){
        node* tail_hunter =head;
        while(tail_hunter->next!=NULL)
        tail_hunter = tail_hunter->next;
        return tail_hunter;
    }

    // Task solution

    int get_data(node* random_node){
        if (random_node==NULL)
            return 0;
        else return random_node->data;
    }

    node* get_prev(node* random_node){
        node* temp_iter = head;
        if (random_node==NULL)
                return NULL;
        if (random_node==head)return head;
        while(temp_iter->next!=random_node){
            temp_iter=temp_iter->next;
        }
        return temp_iter;
    }

    void add_two_list(List l1, List l2, List &output){

           // cout<<"inside head function"<<endl;
            node* head1_tail = get_tail(l1.get_head());
            node* head2_tail = get_tail(l2.get_head());
           // cout<<"Two list initial tail is achieved"<<endl;
            int carry = 0;
            int sum = 0;
            int quot = 0;

            while (head1_tail!= NULL || head2_tail!=NULL)
            {
                int var1 = l1.get_data(head1_tail);
                int var2 = l2.get_data(head2_tail);
                if (head1_tail == l1.get_head())
                    head1_tail = NULL;
                if (head2_tail == l2.get_head())
                    head2_tail = NULL;
                
                if (head1_tail == NULL && head2_tail == NULL){
                    sum = var1+var2+carry;
                    output.add_link_node_to_head(sum);
                }
                else {
                    sum = var1+var2+carry;
                    carry = sum/10;
                    quot = sum%10;
                    output.add_link_node_to_head(quot);
                }
                head1_tail = l1.get_prev(head1_tail);
                head2_tail = l2.get_prev(head2_tail);
                
            }
            

    }

    void print(){
        node* itera = head;
        while(itera){
            cout<<itera->data<<" ";
            itera = itera->next;
        }
    }
};

int main(){
    List l1,l2,output;
    l1.add_link_node_to_tail(0);
    l1.add_link_node_to_tail(9);
    l1.add_link_node_to_tail(3);
    l1.print();
    cout<<endl;
    l2.add_link_node_to_tail(4);
    l2.add_link_node_to_tail(9);
    l2.add_link_node_to_tail(6);
    l2.print();
    cout<<endl;
    l1.add_two_list(l1, l2, output);
    output.print();
    cout<<endl;

}