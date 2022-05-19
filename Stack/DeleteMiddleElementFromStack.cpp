//recursive solution
void solve(stack<int>&inputStack,int count,int size){
	if(count==size/2){
		inputStack.pop();
		return ;
	}
	int num=inputStack.top();
	inputStack.pop();
	solve(inputStack,count+1,size);
	inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	int count=0;
	solve(inputStack,count,N);
   
}

//itrative solution
void deleteMiddle(stack<int>&inputStack, int N){

 

   int x=N/2;

   stack<int>temp;

   

   while(x!=0){

       temp.push(inputStack.top());

       inputStack.pop();

       x--;

   }

   inputStack.pop();

   

   while(!temp.empty()){

       inputStack.push(temp.top());

       temp.pop();

   }

   

  // Write your code here

   

}
