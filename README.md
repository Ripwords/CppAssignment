# Programming Concepts, C++Assignment Group 45
### Deadline @ 30th of August


### Job distribution
| **Tasks** | **Description** | **By** |
| ---------- | ---------- | ---------- |
| *task* | *details about the task* | *who is/are doing this task* |


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
