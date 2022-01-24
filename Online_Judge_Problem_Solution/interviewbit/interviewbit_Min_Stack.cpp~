stack<int>s;
stack<int>s2;
int mi;
MinStack::MinStack() {
    s = stack<int>();
    s2 = stack<int>();
    mi=0;
}
void MinStack::push(int x) {
    if(s.empty()){
        mi=x;
    }
    else{
        mi=s2.top();
    }
    if(mi>=x)mi=x;
    s.push(x);
    s2.push(mi);
}

void MinStack::pop() {
    if(s.empty()){
        return;
    }
    else{
        s.pop();
        s2.pop();
    }
}

int MinStack::top() {
    if(s.empty()){
        return -1;
    }
    else{
        return s.top();
    }
}

int MinStack::getMin() {
    if(s.empty()){
        return -1;
    }
    return s2.top();
}


