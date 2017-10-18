## 189. Rotate Array

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

**Note:**   
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.


## 思考

和部分旋转string一样。go 的代码写起来还是挺简约的。

## 代码

```

func rotate(nums []int, k int)  {
    rot := func (nums []int) {
        size := len(nums)
        for i := 0; i < size / 2; i++ {
            nums[i], nums[size - 1 - i] = nums[size - 1 - i], nums[i]
        }
    }
    k = k % len(nums)
    rot(nums[:len(nums)-k])
    rot(nums[len(nums)-k:])
    rot(nums[:])
}

```


## 190. Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

## 思考
还是要对32位访问一遍，没有想到简便的直接计算的公式

## 代码

```

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result= 0;
        for(int i=0; i<32; i++)
            result = (result<<1) + (n>>i &1);
        
        return result;
    }
};

```
