// appraoch one (no space optizimed)
#include<iostream>
using namespace std;

class kstack{
    int n, k;
    int *arr, *top;
    public:
    kstack(int n, int k){
        this->n = n; this->k = k;
        arr = new int[n];
        top = new int[k];
        for(int i=0; i<n; i++) arr[i]=-1;
        for(int i=0; i<k; i++) top[i] = (i*n)/k;
    }

    void push(int value, int stack_no){
        stack_no--;
        if(top[stack_no]==(stack_no*n)/k and arr[top[stack_no]]==-1) arr[top[stack_no]]=value;
        else if(top[stack_no]+1<((stack_no+1)*n)/k and arr[top[stack_no]+1]==-1) top[stack_no]++, arr[top[stack_no]]=value;
        else cout<<"Stack no "<<stack_no+1<<" is Full, can't enter "<<value<<endl;
    }

    int pop(int stack_no){
        int temp=-1;
        stack_no--;
        if(top[stack_no]==(stack_no*n)/k and arr[top[stack_no]]==-1) cout<<"Stack no "<<stack_no+1<<" is Empty"<<endl;
        else if(top[stack_no]==(stack_no*n)/k and arr[top[stack_no]]!=-1) temp=arr[top[stack_no]], arr[top[stack_no]]=-1;
        else temp=arr[top[stack_no]], arr[top[stack_no]]=-1, top[stack_no]--;
        return temp;
    }

    ~kstack(){
        delete [] arr;
        delete [] top;
    }
};

void solve(){
    // Stack with k=2 and n=4
    kstack k1(4, 2);

    // Adding elements to stack 1
    k1.push(1, 1);
    k1.push(2, 1);
    k1.push(3, 1);

    // Adding elements to stack 2
    k1.push(4, 2);
    k1.push(5, 2);
    k1.push(6, 2);

    // Removing elements from Stack 1
    cout<<k1.pop(1)<<endl;
    cout<<k1.pop(1)<<endl;
    cout<<k1.pop(1)<<endl;

    // Removing elements from Stack 2
    cout<<k1.pop(2)<<endl;
    cout<<k1.pop(2)<<endl;
    cout<<k1.pop(2)<<endl;
}

int main(){
    solve();
    return 0;
}
