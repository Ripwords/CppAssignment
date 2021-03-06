# Programming Concepts, C++Assignment Group 45

### Deadline @ 30th of August

### Job distribution

| **Tasks**          | **Description**                                           | **By**   |
| ------------------------ | --------------------------------------------------------------- | -------------- |
| Data Structure           | Manage the input data and structuring of the data               | JJ             |
| Logic                    | Checking for the correct PIN and phone number                   | Osama & Harshi |
| Generating Notifications | Generating the PIN, email and state of the locker               | Zitang & Bunny |
| Interface of the program | UI/UX for the program                                           | Bryan          |

### Data Structure for this assignment
#### Currently the data structure used is **map** that has an increasing order with a search time of *O(log(n))*, alternatively **unordered_map** can be used with no ordering with a search time of *O(1) or O(n)*. Thus map is more efficient and should be used unless no ordering is required at a later point
```cpp
map<int, vector<vector<string>>> userData = {
    {
        unitOne, {
            {name1, phone1, email1, ic1},
            {name2, phone2, email2, ic2}
        }
    },
    {
        unitTwo, {
            {name1, phone1, email1, ic1},
            {name2, phone2, email2, ic2}
        }
    }
}

// Reference data using the follow format:
userData[unitNumber][userOne or userTwo][name or phone1 or email or ic]
lockerData[lockerID][unit or status]
```

### Try to leave comments where you see fit while you write your code

```cpp
// Function for adding two integers
int function(int a, int b)
{
    int addition = a + b; // add two numbers
    return addition;
}
```

### Creating your own namespace functions

#### Namespace allows you to differentiate two functions with the same name

```cpp
// Creating your own namespace for functions in the standard library
namespace R {
    float round(x, place) {
        int dec = pow(10, place);
        float value = (int)(var * dec + 0.5);
        return (float)value / dec;
    }
}

R::round(10.2341, 2);
std::round(10.2341);
```
