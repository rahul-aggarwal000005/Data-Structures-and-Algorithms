class Queue {
	int f;
	int rear;
	int arr[10000];
public:
    Queue() {
        // Implement the Constructor
		f = 0;
		rear = 0;
		for(int i=0;i<10000;i++) arr[i] = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
		return rear == f;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
		arr[rear] = data;
		rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
		if(isEmpty()) return -1;
		int val = arr[f];
		arr[f] = -1;
		f++;
		if(isEmpty()){
			f = 0;
			rear = 0;
		}
		return val;
    }

    int front() {
        // Implement the front() function
		if(isEmpty()) return -1;
		return arr[f];
    }
};