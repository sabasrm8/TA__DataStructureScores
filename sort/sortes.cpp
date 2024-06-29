#include<iostream>
using namespace std;

void swap(int & x , int &y){
	
	int temp=x;
	x=y;
	y=temp;
	
}

void bubblesort(int arr1[] , int size){
	
	for(int i=0;i<size-1;i++){
	
		for(int j=0;j<size-i-1;j++){
	
			if(arr1[j]>arr1[j+1]){
			
			swap(arr1[j],arr1[j+1]);

		}
	}
}

}

void insertionSort(int arr2[], int n) {
   
    for (int i = 1; i < n; i++) {
   
        int item = arr2[i];
   
        int j = i - 1;
        
        while (j >= 0 && arr2[j] > item) {
   
            arr2[j + 1] = arr2[j];
   
            j = j - 1;
   
        }
   
        arr2[j + 1] = item;
   
    }
}


int division(int arr3[], int low, int high) {
    
	int temp = arr3[high];          //انتخاب اخرین عنصر به عنوان یک عنصر محوری و مقایسه بقیه اعضا با این عضو
    
	int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
    
	    if (arr3[j] < temp) {
    
	        i++;
    
	        swap(arr3[i], arr3[j]);
        }
    }
    
	swap(arr3[i + 1], arr3[high]);
    
	return (i + 1);
}

void quickSort(int arr3[], int low, int high) {
    
	if (low < high) {
    
	    int devide = division(arr3, low, high);
    //کوییک سورت را یک بار برای قسمت اول ارایه و یک بار برای قسمت دوم ارایه صدا میزنیم
	    quickSort(arr3, low, devide - 1);
    
	    quickSort(arr3, devide + 1, high);
    }
}

void merge(int arr[], int left, int mid, int right) {
    
	int n1 = mid - left + 1;
    
	int n2 = right - mid;
//ساخت دو ارایه با سایز های مساوی با نیمه اول ارایه و نیمه دوم ارایه
	int* leftArray = new int[n1];
    
	int* rightArray = new int[n2];

    for (int i = 0; i < n1; i++)
  
        leftArray[i] = arr[left + i];
  
    for (int j = 0; j < n2; j++)
  
        rightArray[j] = arr[mid + 1 + j];

    int i = 0;
  
    int j = 0;
  
    int k = left;

    while (i < n1 && j < n2) {
  
        if (leftArray[i] <= rightArray[j]) {
  
            arr[k] = leftArray[i];
  
            i++;
  
        } else {
  
            arr[k] = rightArray[j];
  
            j++;
       }
 
        k++;
    }
//مقادیری که از دو ارایه باقی ماندن درون ارایه اصلی قرار میگیرند
    while (i < n1) {
 
        arr[k] = leftArray[i];
 
        i++;
 
        k++;   }

    while (j < n2) {
        
		arr[k] = rightArray[j];
        
		j++;
        
		k++;
    }

}

void mergeSort(int arr[], int left, int right) {
    
	if (left < right) {
     
	    int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
     
	    mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(){

	int arr1[6]={4,6,1,2,10,9};
	
	int size1=sizeof(arr1) / sizeof(arr1[0]);
	
	bubblesort(arr1,size1);
	
	cout<<"sorted array :"<<"  ";
	
	for(int i=0;i<size1;i++)

	cout<<arr1[i]<<"  ";
	
	cout<<endl;
	
	int arr2[6]={9,11,16,4,20,2};
	
	int size2 =sizeof(arr2) / sizeof(arr2[0]);
	
	insertionSort(arr2,size2);
	
	cout<<"sorted array :"<<"  ";
	
	for(int i=0;i<size2;i++)

	cout<<arr2[i]<<"  ";
	
	cout<<endl;
	
	int arr3[6]={40,10,44,20,50,60};
	
	int size3=sizeof(arr3) / sizeof(arr3[0]);
	
	quickSort(arr3,0,size3-1);
	
	cout<<"sorted array :"<<"  ";
	
	for(int i=0;i<size3;i++)

	cout<<arr3[i]<<"  ";
	
	cout<<endl;
	
	int arr4[6]={120,113,101,200,100,150};
	
	int size4=sizeof(arr4) / sizeof(arr4[0]);
	
	mergeSort(arr4,0,size4-1);
	
	cout<<"sorted array :"<<"  ";
	
    for(int i=0;i<size4;i++)

    cout<<arr4[i]<<"  ";
	
	cout<<endl;

}

















