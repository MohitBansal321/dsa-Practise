// link
https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=1

class TwoStack {

public:
	int *arr;
	int top1;
	int top2;
	int size;
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size=s;
		arr=new int[s];
		top1=-1;
		top2=size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
		if(top2-top1>1){
			top1++;
			arr[top1]=num;
		}
		
		
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
		if(top2-top1>1){
			top2--;
			arr[top2]=num;
		}
		
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
		if(top1>=0){
			int res=arr[top1];
			top1--;
			return res;
		}
		else{
			return -1;
		}
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
		if(top2<size){
			int res=arr[top2];
			top2++;
			return res;
		}
		else{
			return -1;
		}
    }

};
