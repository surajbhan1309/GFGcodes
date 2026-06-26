class Solution {
  public:
    void sortStack(stack<int> &st) {
        if(!st.empty()){
            int temp=st.top();
            st.pop();
            sortStack(st); // empty the stack;
            insert(st,temp); //after empty insertion start
        }
        
    }
    void insert(stack<int>&st,int temp){
        if(st.empty()|| st.top()<=temp){
            st.push(temp);
            return ;
        }
        int val=st.top();
        st.pop();
        insert(st,temp);
        st.push(val);
    }
};
