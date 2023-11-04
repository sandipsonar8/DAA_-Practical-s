#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
int a[100],size,i;
class heap{
  public:
	void getdata();
	void show();
	void heapsort(int [],int);
	void heapify(int [],int);
	void adjust(int [],int,int);
};
void heap::getdata(){
	cout<<"enter the size";
	cin>>size;
	for(i=1;i<=size;i++){
		a[i]=random(100);
	}
}
void heap::show(){
	for(i=1;i<=size;i++){
		cout<<a[i]<<"\t";
	}
}
void heap::heapsort(int a[],int size){
	heapify(a,size);
	for(i=size;i>=2;i--){
		int t=a[i];
		a[i]=a[1];
		a[1]=t;
		adjust(a,1,i-1);
	}
}

void heap::heapify(int a[],int size){
	for(i=size;i>=1;i--){
	   adjust(a,i,size);
	}
}
void heap::adjust(int a[],int i,int size){
	int j=2*i;
	int item=a[i];
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
/*void heap::adjust(int a[],int i,int size){
	int j=2*i;
	int item=a[i];
	while(j<=size){
		if( (j<size) && (a[j]>a[j+1]) ){
			j++;
		}
		if(item>=a[j]){
			break;
		}
		a[j/2]=a[j];
		j=2*j;
	}
	a[j/2]=item;
}*/
void main(){
	clrscr();
	heap h;
	cout<<"\nbefore:\n";
	h.getdata();
	h.show();
	cout<<"\nafter:\n";
	h.heapsort(a,size);
	h.show();
	getch();
}