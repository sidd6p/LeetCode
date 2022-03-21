## **Question**


Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

__Example 1:__

Input

["KthLargest", "add", "add", "add", "add", "add"]

[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

Output

[null, 4, 5, 5, 8, 8]

Explanation

KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);

kthLargest.add(3);   // return 4

kthLargest.add(5);   // return 5

kthLargest.add(10);  // return 5

kthLargest.add(9);   // return 8

kthLargest.add(4);   // return 8



## **Solution**


### Logic 
- We need to maintain ```k``` largest element into storage and when we add new element, we update our storage accordingly
- We may use ```vector``` to store element and then running sort everytime when we add new element, this will increase time complexity as sorting take (nlogn) time.
- So we use ```heap``` data stracture as ```priority_queue``` in ```C++``` implement ```binary heap``` we can use this.
- We need to use ```min_heap```, beacuse we need to delete element from  ```priority_queue```  until it size get reduce to ```k```.
- After that top element of  ```priority_queue``` will be the ```kth``` largest element

#### **Code**

```cpp
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num : nums) {
            this->pq.push(num);
        }
        while (pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > this->k) {
            pq.pop();            
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```

## **Complexity**

#### Time Complexity:  **O(1)**, for add function.

#### Space Complexity: **O(k)**, because at any moment ```pq``` will have at most ```k``` elements in it.

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


