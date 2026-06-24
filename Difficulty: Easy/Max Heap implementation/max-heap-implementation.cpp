class maxHeap {
  private:
    // Initialize your data members
    vector<int>heap;
    
    void heapifyUp(int index){
        while(index>0){
            int parent=(index-1)/2;
            if(heap[index]>heap[parent]){
                swap(heap[index],heap[parent]);
                index=parent;
            }
            else{
                break;
            }
        }
    }
    void heapifyDown(int index){
        int n=heap.size();
        while(true){
            int leftchild=2*index+1;
            int rightchild=2*index+2;
            int largest=index;
            
            if(leftchild<n && heap[leftchild]>heap[largest]){
                largest=leftchild;
            }
            if(rightchild<n && heap[rightchild]>heap[largest]){
                largest=rightchild;
            }
            if(largest!=index){
                swap(heap[index],heap[largest]);
                index=largest;
            }
            else{
                break;
            }
        }
    }
    
  public:

    void push(int x) {
        // Insert x into the heap
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }

    void pop() {
        // Remove the top (maximum) element
        if(heap.empty()){
            return;
        }
        heap[0]=heap.back();
        heap.pop_back();
        if(!heap.empty()){
            heapifyDown(0);
        }
    }

    int peek() {
        // Return the top element or -1 if empty
        if(heap.empty()){
            return -1;
        }
        return heap[0];
    }

    int size() {
        // Return the number of elements in the heap
        return heap.size();
    }
};