
////////////////////////////
#include<iostream>
using namespace std;

//node information
struct node {
    int data;
    node* next;
};

class linkedlist {
private:
    node* head;
public:
    linkedlist() : head(nullptr) {} //sazande root ro null mizare

	//function for add node 
    void addnode(int x) {
        node* newnode = new node();
        newnode->data = x;
        newnode->next = head;
        head = newnode;
    }

	//print member of linklist
    void print() {
        for (node* ptr = head; ptr != nullptr; ptr = ptr->next)
            cout << ptr->data << " ";
        cout << endl;
    }
	//add node to front of list
    void push_front(int n) {
        node* newnode = new node();
        newnode->data = n;
        newnode->next = head;
        head = newnode;
    }
	
	//Delete data from the beginning of the list
    int pop_front() {
        if (empty()) {
            cout << "List is empty!" << endl;
            return -1;
        }

        int data = head->data;
        node* temp = head;
        head = head->next;
        delete temp;
        return data;
    }

	//Check the list if it is empty
    bool empty() const {
        return (head == nullptr);
    }
    
    //counting how many a are in list
    int count(int a){
    	int counter=0;
		for (node* ptr = head; ptr != nullptr; ptr = ptr->next){
    		if(ptr->data==a)
			counter++;
		}
		return counter;
	}
	
	//dellete an element in list
	 void remove(int a) {
        node* current = head;
        node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == a) {
                if (prev != nullptr)
                    prev->next = current->next;
                else
                    head = current->next;
                delete current;
                cout << "Number " << a << " removed from the list." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Number " << a << " not found in the list." << endl;
    }
    
	//remove all node with data a in list
	void remove_all(int a) {
        node* current = head;
        node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == a) {
                if (prev != nullptr)
                    prev->next = current->next;
                else
                    head = current->next;
                node* temp = current;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }

        cout << "All nodes with data " << a << " removed from the list.";
    }
};

int main() {
    linkedlist mylist;
    int num, choice,number, x;

    cout << "Enter three numbers:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        mylist.addnode(num);
    }

    cout << "Your first three numbers are: ";
    mylist.print();

    while (true) {
        cout << "What do you want to do?" << endl;
        cout << "1. Add a number to the beginning of the list" << endl;
        cout << "2. Delete a number from the beginning of the list" << endl;
      	cout << "3. Number for count  "<<endl;
	    cout << "4. Delet a node  " << endl;
	    cout << "5. Delete an element in the entire list "<< endl;
		cout << "6. Exit " << endl;
        cout<<"****************************************"<<endl;
	    cout << "Enter your choice: ";
        cin >> choice;
		
        switch (choice) {
        case 1:
            cout << "Enter the number to add: ";
            cin >> num;
            mylist.push_front(num);
            cout << "Updated list: ";
            mylist.print();
            break;

        case 2:
            num = mylist.pop_front();
            if (num != -1)
                cout << "Deleted number: " << num << endl;
            cout << "Updated list: ";
            mylist.print();
            break;

       	case 3:
       		cout<<"enter a number :"<<endl;
       		cin>>number;
       	cout<<"there are "<<mylist.count(number) << "  of "<<number<<" in list "<<endl;
       			
       		break;
       			
	   	 case 4:
           
           cout<<" Enter a number to delet it`s node :"<<endl;
           cin>>x;
           mylist.remove(x);
           cout<<"new list :";
           mylist.print();
           cout<<endl;
      	    break;
	    
		 case 5:
		 	cout<<"enter a number :"<<endl ;
            cin>>x;
            mylist.remove_all(x);
            cout<<endl;
			cout<<"new list ";
			mylist.print();
            break;
            
            case 6:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
	    }
    }

    return 0;
}


