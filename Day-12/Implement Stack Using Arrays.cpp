// Stack class.
class Stack {
	int t;
	int arr[1002];
	int cap;
public:
    
    Stack(int capacity) {
        // Write your code here.
		t = -1;
		cap = capacity;
		for(int i=0;i<capacity;i++) arr[i] = -1;
    }

    void push(int num) {
        // Write your code here.
		if(isFull()){
			return;
		}
		t++;
		arr[t] = num;
    }

    int pop() {
        // Write your code here.
		if(isEmpty()) return -1;
		int val = arr[t];
		t--;
		return val;
    }
    
    int top() {
        // Write your code here.
		if(isEmpty()) return -1;
		return arr[t];
    }
    
    int isEmpty() {
        // Write your code here.
		return t == -1;
    }
    
    int isFull() {
        // Write your code here.
		return t == (cap-1);
    }
    
};