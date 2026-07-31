#include <iostream>
#include<stack>
#include<vector>
using namespace std;

int getMaxArea(vector<int>& arr) {
    int n = arr.size();
    
    stack<int> st;

    int res = 0;
    int tp, curr;

    for (int i = 0; i < n; i++) {      
         
        while (!st.empty() && arr[st.top()] >= arr[i]) {
          
            // The popped item is to be considered as the 
            // smallest element of the Histogram
            tp = st.top(); 
            st.pop();
          
            // For the popped item previous smaller element is 
            // just below it in the stack (or current stack top)
            // and next smaller element is i
            int width = st.empty() ? i : i - st.top() - 1;
          
            res = max(res,  arr[tp] * width);
        }
        st.push(i);
    }

    // For the remaining items in the stack, next smaller does
    // not exist. Previous smaller is the item just below in
    // stack.
    while (!st.empty()) {
        tp = st.top(); st.pop();
        curr = arr[tp] * (st.empty() ? n : n - st.top() - 1);
        res = max(res, curr);
    }

    return res;
}

int main() {
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << getMaxArea(arr);
    return 0;
}