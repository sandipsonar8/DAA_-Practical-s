#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int a[100],size;
class heap{
	public:
		int i,j,item;
		void get();
		void show();
		void maxAdjust(int [],int,int);
		void minAdjust(int [],int,int);
		void heapify(int [],int);
};

void heap::get(){
	cout<<"enter the size:\n";
	cin>>size;
	for(i=1;i<=size;i++){
		a[i]=random(100);
	}
}
void heap::show(){
	cout<<"elements are:\n";
	for(i=1;i<=size;i++){
		cout<<a[i]<<"\t";
	}
}
void heap::heapify(int a[],int size){

	for(i=size/2;i>=1;i--){
		maxAdjust(a,i,size);
	}
	cout<<"\nMAX HEAPIFY:\n";
	show();

	for(i=size/2;i>=1;i--){
		minAdjust(a,i,size);
	}
	cout<<"\nMIN HEAPIFY:\n";
	show();
}
void heap::maxAdjust(int a[],int i,int size){
	j=2*i;
	item=a[i];
	while(j<=size){
		if( (j<size) && (a[j]<a[j+1]) ){
			j++;
		}
		if(item>=a[j]){
			break;
		}
		a[j/2]=a[j];
		j=2*j;
	}
	a[j/2]=item;
}
void heap::minAdjust(int a[],int i,int size){
	j=2*i;
	item=a[i];
	while(j<=size){
		if( (j<size) && (a[j]>a[j+1]) ){
			j++;
		}
		if(item<=a[j]){
			break;
		}
		a[j/2]=a[j];
		j=2*j;
	}
	a[j/2]=item;
}

void main(){
	clrscr();
	heap h;
	h.get();
	h.show();
	h.heapify(a,size);
	getch();
}