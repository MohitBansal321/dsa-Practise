queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> s;
    for(int i=0;i<k;i++){
        int ans=q.front();
        q.pop();
        s.push(ans);
    }
    while(!s.empty()){
        int ans=s.top();
        s.pop();
        q.push(ans);
    }
    int t=q.size()-k;
    while(t--){
        int ans=q.front();
        q.pop();
        q.push(ans);
    }
    return q;
}
