#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) { 
    int temp = a;
    a = b;
    b = temp;
}

void add(int a, vector<int>& arr) {  
    arr.push_back(a);
    int i = arr.size() - 1;
    while (i != 0 && arr[i] > arr[(i - 1) / 2]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int maxDel(vector<int>& arr) {  
    int i = 0;
    swap(arr[0], arr[arr.size() - 1]);
    int ans = arr[arr.size() - 1];
    arr.pop_back();
    int m = 2 * i + 1;
    if (m + 1 < arr.size() && arr[m] < arr[m + 1]) {  
        m++;
    }
    while (m < arr.size() && arr[i] < arr[m]) {  
        swap(arr[i], arr[m]);
        i = m;
        m = 2 * i + 1;
        if (m + 1 < arr.size() && arr[m] < arr[m + 1]) {
            m++;
        }
    }
    return ans;
}

int main() {
    int s;
    cin >> s;
    vector<int> arr;
    for (int i = 0; i < s; i++) {
        int num;
        cin >> num;
        add(num, arr); 
    }
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = s - 1; i >= 0; i--) {
        arr[i] = maxDel(arr);
    }
    for (int i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}