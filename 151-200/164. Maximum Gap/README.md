## 164. Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.


## 思考

**难度挺高的**

要实现线性的时间，我自己真的想不出来。首先思考如果是排序好的直接遍历找最大就可以了。但是排序好需要nlogn。   

思考 **鸽巢原理，抽屉原理**   
Suppose you have n pigeons with labels and you put them into m holes based on their label with each hole of the same size. Why bother putting pigeons into holes? Because you want to disregard the distance between pigeons within each one hole.  
Only when at least one hole is empty can we disregard the distance between pigeons within each one hole and compute the maximum gap solely by the distance between pigeons in adjacent holes. We make sure that at least one hole is empty by using m=n-1 (i.e. n-2 pigeons in n-1 holes => at least one hole is empty).  


