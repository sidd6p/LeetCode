## **Question**
Design a system that manages the reservation state of n seats that are numbered from 1 to n.

Implement the SeatManager class:

SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.

int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.

void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.
 

__Example 1:__

Input
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]

[[5], [], [], [2], [], [], [], [], [5]]

Output

[null, 1, 2, null, 2, 3, 4, 5, null]

Explanation

SeatManager seatManager = new SeatManager(5); // Initializes a SeatManager with 5 seats.

seatManager.reserve();    // All seats are available, so return the lowest numbered seat, which is 1.

seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.

seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are [2,3,4,5].

seatManager.reserve();    // The available seats are [2,3,4,5], so return the lowest of them, which is 2.

seatManager.reserve();    // The available seats are [3,4,5], so return the lowest of them, which is 3.

seatManager.reserve();    // The available seats are [4,5], so return the lowest of them, which is 4.

seatManager.reserve();    // The only available seat is seat 5, so return 5.

seatManager.unreserve(5); // Unreserve seat 5, so now the available seats are [5].


## **Solution**

#### **Code**

```cpp
class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SeatManager(int n) {
        while (n) {
            pq.push(n--);
        }
    }
    
    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
```

## **Complexity**

#### Time Complexity: 
* SeatManager(): __O(nlogn)__ equivalent to create priority_queue, by inserting element throug loop
* reserve():  __O(logn)__,  equivalent to delete element from priority_queue
* unreserve(): __O(logn)__, equivalent to add element from priority_queue

#### Space Complexity: **O(n)**

<br>

 __Check out all [my](https://leetcode.com/siddp6/) recent solutions [here](https://github.com/sidd6p/LeetCode)__

 
 __Feel Free to Ask Doubts
And Please Share Some Suggestions
HAPPY CODING :)__


