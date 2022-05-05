class MyStack {
  private:
    int pos = 0;
    int arr[101];
  public:
    MyStack() {
      for(int i = 0; i < 101; i++){
        arr[i] = -1;
      }
    }
    
    void push(int x) {
      if(arr[pos] != -1) pos++;
      arr[pos] = x;
    }
    
    int pop() {
      if(arr[pos] == -1) {
        return false;
      }
      
      int ret = arr[pos];
      arr[pos] = -1;
      if(pos > 0) pos -= 1;
      return ret;
    }
    
    int top() {
      return arr[pos]; 
    }
    
    bool empty() {
      if(arr[pos] == -1) return true;
      return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */