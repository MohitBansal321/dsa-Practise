#include<iostream>
using namespace std;
struct myHash{
    int *arr;
    int cap,size;
    myHash(int c){
        cap=c;
        size=0;
        for(int i=0;i<cap;i++){
            arr[i]=-1;
        }
    }
    int hash(int key){
        return key%cap;
    }
    bool search(int key){
        int h=hash(key);
        int i=h;
        while(i!=-1){
            if(arr[i]==key)
                return true;
            i=(i+1)%cap;
            if(i==h)
                return false;
        }
        return false;
    }
    bool insert(int key){
        int h=hash(key);
        int i=h;
        if(size==cap)
            return false;
      
        while(arr[i]!=-1 && arr[i]!=-2 && arr[i]!=key){
            i=(i+1)%cap;
        }
        if(arr[i]==key){
            return false;
        }
        else{
            arr[i]=key;
            size++;
            return true;
        }
    }
    bool deletee(int key){
        int i=hash(key);
        int h=i;
        while(arr[h]!=-1){
            if(arr[h]==key){
                arr[h]=-2;
                size--;
                return true;
            }
            h=(h+1)%cap;
            if(h==i)
                return false;
        }
        return false;
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    myHash m(7);
    m.insert(12);
    m.insert(11);
    m.insert(14);
    m.insert(15);
    m.insert(13);
    m.insert(19);
    m.insert(15);
    m.print();
    cout<<"done"<<endl;
    return 0;
}
