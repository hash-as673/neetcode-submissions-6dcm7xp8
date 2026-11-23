class MinStack {

private:
    std::vector<int> data_;
    std::vector<int> mins_;

public:
    MinStack() = default;
    
    void push(int val) {
        data_.push_back(val);
        if (mins_.empty() || val <= mins_.back())
        {
            mins_.push_back(val);
        }
    }
    
    void pop() {
        if (data_.back() == mins_.back())
        {
            mins_.pop_back();
        }
        data_.pop_back();
    }
    
    int top() const {
        return data_.back();
    }
    
    int getMin() {
        return mins_.back();
    }
};
