#include<iostream>
#include<stack>
using namespace std;

//node information
struct node{
	int data;
	node* left;
	node* right;
	
};

//add a number in node
//pointer be node jadid ro bazghasht midahad
node* insert(int item){
	node* newnode = new node;
	newnode->data = item;
	newnode->left = nullptr;
	newnode->right = nullptr;
	return newnode;
}

//peymayesh vlr
void preorder(struct node* p )
{
	 if (p != NULL)
	 {
		cout<<p->data<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

//peymayesh lvr
void inorder(struct node* p){
	
	if(p != NULL)
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
		
	}
	
}

//peymayesh lrv
void postorder(struct node* p){
	
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<" ";
	}
}
//creat a queue return an array with pointer to nodes 
struct node** Queue(int *front , int *rear){
	
	struct node **q;
	q = (struct node **) malloc(sizeof(struct node*)*200);
	*front = *rear = 0;
	return q;
	
}

//insert to queue
void add(struct node **q , int *rear , struct node *n){
	
	q[*rear] = n;
	(*rear)++;
	
}

//dellete from queue
struct node *dellete(struct node **q , int *front){
	
	(*front)++;
	return q[*front - 1 ];
	
}

//peymayesh bfs
void bfs(struct node* root){
	
	struct node* t;
	t = root;
	struct node** q;
	int rear , front;
	q = Queue(&front , &rear);
	
	while(t){
		
		cout<<t->data<<" ";
	if(t->left)
		add(q , &rear , t->left);
		
	if(t->right)
		add(q, &rear , t->right);
		
	t = dellete(q , &front);
		
	}
	
}

//peymayesh dfs
void dfs(struct node* root){
	
	if(root == NULL)
		return;
	stack<struct node*> st;  //create a stack
	st.push(root);
	
	while(!st.empty()){
		struct node* current = st.top();   //اگر صف خالی نباشه مقدار عنصر بالای صف برداشته میشود
		st.pop();
		cout<<current->data << " ";
		
		if(current->right){
			
			st.push(current->right);
			
		}
		
		if(current->left){
			st.push(current->left);
		}
	}
}

int main(){

	struct node* r;
	r = insert(1);
	r->left = insert(2);
	r->right = insert(3);
	r->left->left = insert(4);
	r->left->right = insert(5);
	r->right->left = insert(6);
	r->right->right = insert(7);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	
	cout<<"Preorder:";
	preorder(r);
	cout<<endl;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	cout<<"Inorder:";
	inorder(r);
	cout<<endl;	
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	cout<<"Postorder:";
	postorder(r);
	cout<<endl;
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	cout<<"Breadth-first:";
	bfs(r);
	cout<<endl;	
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~	

	cout<<"Depth-first:";
	dfs(r);

}

