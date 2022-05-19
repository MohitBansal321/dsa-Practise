void insertAtBottom(stack<int>& myStack,int x){
	if(myStack.empty()){
		myStack.push(x);
		return ;
	}
	int num=myStack.top();
	myStack.pop();
	solve(myStack,x);
	myStack.push(num);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
		return;
	}
	int num=stack.top();
	stack.pop();
	reverseStack(stack);
	insertAtBottom(stack,num);
}
