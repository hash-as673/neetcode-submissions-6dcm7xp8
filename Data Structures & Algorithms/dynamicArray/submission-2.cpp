class DynamicArray {
public:

    int *arr;
    int size;
    int capacity;

    DynamicArray(int capacity) {
        this -> capacity = capacity;
        this-> size = 0;
        this->arr = new int[this->capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity){
            resize();
        }
        arr[size] = n;
        size++; 
    }

    int popback() {
        if (size>0) {
            size--;
        }
        return arr[size];
    }

    void resize() {
        capacity = capacity * 2;
        int *newarr = new int[capacity];
        for(int i = 0 ; i < size; i++){
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
