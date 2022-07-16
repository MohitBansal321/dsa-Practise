#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insertion(int num){
        size=size+1;
        int index=size;
        arr[index]=num;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return ;
            }
        }
    }
    void printing(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" "<<endl;
        }
    }
    void deleteFromHeap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return ;
        }
        arr[1]=arr[size];
        arr[size]=0;
        size--;
        int index=1;
        while(index<size){
            int left=2*index;
            int right=2*index+1;
            if(arr[left]>arr[index]){
                    swap(arr[index],arr[left]);
                    index=left;
                }
            else if(arr[right]>arr[index]){
                    swap(arr[index],arr[right]);
                    index=right;
                }
            else{
                return ;
            }
        }
    }
};
int main(){
    heap h1;
    h1.insertion(30);
    h1.insertion(50);
    h1.insertion(20);
    h1.insertion(60);
    h1.insertion(10);
    h1.deleteFromHeap();
    h1.printing();
    return 0;
}
