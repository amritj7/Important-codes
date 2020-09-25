#include<bits/stdc++.h>
using namespace std ;
vector <int> heap;
void heapStartTop( int k ){
	int largest = k;
	
	int left = 2*k + 1;
	int right = 2*k + 2;
	if(heap.size()>left&&heap[left]>heap[k])
	largest = left;
	if(heap.size()>right&&heap[right]>heap[largest])
	largest = right;
	
	
	if(largest!=k){
		int t= heap[k];
		heap[k]= heap[largest];
		heap[largest]= heap[k];
	heapStartTop(largest);
	}
}
void heapStartBottom(int var ){
	int i = var;
	while(i>0){
		if(heap[i]>heap[i/2]){
			int t= heap[i];
			heap[i]=heap[i/2];
			heap[i/2]=heap[i];
			i=i/2;
		}
		else
		i=0;
		
	}
	
}
void heapAdd(int var ) {
	heap.push_back(var);
	heapStartBottom(heap.size()-1);
}
void heapFindMax( ){
	if(heap.size()!=0){
		cout<<"The max element of the heap is "<<heap[0]<<endl;
	}
	else
		cout<<"Heap is empty"<<endl;
		
}
void heapRemoveMax( ){
	if(heap.size()!=0){
		int t= heap[0];
		heap[0]=heap[heap.size()-1];
		heap[heap.size()-1]=t;
		heap.pop_back();
		heapStartTop(0);
	}
	else
		cout<<"Heap is empty"<<endl;
}

int main(){
	
	
    bool status = true;
    while(status){
        cout << "Enter 1.Add element to heap 2.Get max element 3.Delete max element 4.exit" << endl;
        int choice;
        cin >> choice;
        switch(choice){
            case 1: cout << "enter element to be added" << endl;
                    int val;
                    cin >> val;
                    heapAdd(val);
                    break;
            case 2: heapFindMax();
                    break;
            case 3: heapRemoveMax();
                    break;
            case 4: status = false;
                    break;                            
            default: cout << "wrong choice" << endl;
                    break;
        }
    }    
    return 0;
}
