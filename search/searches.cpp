#include<iostream>
using namespace std;
 
 int linearsearch(int arr[] , int size , int num){
 
 	for(int i=0 ; i<size ; i++){
	 
 
 	if(arr[i] == num)

		return i;
   }

		return -1;
 }
 
 int binarysearch(int arr[],int left,int right,int num){
 	
	while(left<=right){

		int mid = (left + right)/2;

	while(arr[mid]== num)
	 
	  return mid;
	  
	if(arr[mid] < num)
	
		left = mid +1;
		
	if(arr[mid]> num)
	
		right = mid - 1;
 }
   return -1;
 }
 
 int main(){

int num=5;

int arr1[6]={9,5,2,3,1,10};
 	
int size1 = sizeof(arr1) / sizeof(arr1[0]);
 	
int result1 = linearsearch(arr1,size1,num);
 	
if(result1 == -1)	
{
  cout<<"your number isn`t in array1..."<<endl;	 	
}

  else

 	cout<<"your number is on index "<<result1<<" in array1 ..."<<endl;	
 	
int arr2[6] = {20 , 44 , 23 , 30 ,50 ,18};
 	
int size2 = sizeof(arr2) / sizeof(arr2[0]);
 	
int result2 = binarysearch(arr2,0,size2-1,num);
 	
if(result2 == -1)

	cout<<"your number isn`t in array2..."<<endl;	 

else

	cout<<"your number is on index "<<result2<<"in array2..."<<endl;	
 	
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 