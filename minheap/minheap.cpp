#include<iostream>
using namespace std;
int *x , size , c;
//swap two element 
void swap(int *x , int *y){
	int temp=*x;
	*x = *y;
	*y=temp;
}
//for return The parent of an element
int parent(int i){
	return (i-1)/2;
}
//for adding element to array
void add(int item){
	if(size == c)
	return;
	size++;
	int i=size -1;
	x[i]=item;
	while(i != 0 && x[i]<x[parent(i)]){
		swap(&x[i] , &x[parent(i)]);
		i=parent(i);
	}
}
//build minheap tree
void minheapify(int i){
	int l=i*2+1;
	int r=i*2+2;
	int smallest=i;
	if(r<size && x[l]<x[i])
		smallest=l;
	if(smallest !=i){
	
	swap(&x[i],&x[smallest]);	
	minheapify(smallest);
}
}
//for removing root
int remove(){
	if(size==1){
		return x[size--];
	}
	int root = x[0];
	x[0]=x[size-1];
	size--;
	minheapify(0);
	return root;
}
//Replacing one element with another
void decrease(int i , int v){
	x[i]=v;
	while(i!=0 && x[i]<x[parent(i)])
	{
		swap(&x[i],&x[parent(i)]);
		i=parent(i);
	}
}
//check kardan bozorgtar bodan node az farzandanesh
void maxheapify(int x[],int n , int i){
	
	int largest , l ,r;
	largest = i;
	l=2*i +1;
	r = 2*i+2;
	
	if(l<n && x[l] > x[largest])
		largest = l;
		
	if(r<n && x[r] > x[largest])
		largest = r;
		
	if(largest != i)
	{
		swap(x[i] , x[largest]);
		maxheapify(x , n , largest);
	}
	
}
//build heap tree
void heapsort(int x[],int n){
	
	int i;
	for(i=n/2-1;i>=0;i--)
	maxheapify(x,n,i);
	
	for(i=n-1;i>=0;i--)
	{
		swap(x[0],x[i]);
		maxheapify(x,i,0);
	}
	
}

int main()
{
	 x = new int [6];
	size=0;
	c=6;
	
	int num, y;
	char answer ;
	
	add(11);
	add(1);
	add(2);
	add(8);
	add(6);
	add(10);
	
	cout<<"Min Heap tree :";
	for(int i=0 ; i<size ; i++)
	cout<<x[i]<<"  ";
	cout<<endl;
	
	cout<<"do you want to add a node ? if yes enter one , else enter two"<<endl;
	cin>>answer;
	if(answer=='1')
	{
		 cout << "Enter the element to add: ";
        cin >> y;
        add(y);
        cout << "Min Heap after adding " << y << ": ";
        for (int i = 0; i < 7; i++)
            cout << x[i] << "  ";
        cout << endl;
    }

	cout<<"deleted element :"<<remove()<<endl;
	cout<<"Min Heap after delete root :";
	for(int i=0 ; i<6 ; i++)
	cout<<x[i]<<"  ";
	cout<<endl;
	
	cout<<"enter a number for replacing with another element :"<<endl;
	cin>>num;
	decrease(1,num);
	cout<<"Min Heap with new memeber :";
	for(int i=0 ; i<6 ; i++)
	cout<<x[i]<<"  ";
	cout<<endl;
	
	cout<<"sort array with Max_Heap :"<<endl;
	heapsort(x,6);
	for(int i=0 ; i<6 ; i++)
	cout<<x[i]<<"  ";	
}



















