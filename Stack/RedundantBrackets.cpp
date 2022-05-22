#include<stack>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
	for(int i=0;i<s.length();i++){
		char ch=s[i];
		if(ch=='(' || ch=='+' || ch=='-' || ch=='/' || ch=='*'){
			st.push(ch);
		}
		else{
			if(ch==')'){
				bool isredund=true;
				while(st.top() != '('){
					char top=st.top();
					if(top=='+' || top=='-' || top=='/' || top=='*'){
						isredund=false;
					}
					st.pop();
				}
				if(isredund==true){
					return true;
				}
				st.pop();
			}
		}
	}
	return false;
}
