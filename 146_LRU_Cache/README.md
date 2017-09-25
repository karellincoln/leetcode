## 问题

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.

put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:

Could you do both operations in `**O(1)**` time complexity?

Example:
```
LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
```

## 想法

要达到O(1)的时间复杂度，在get的查找操作中**需要使用哈希表**，的由于LRU的特性将最近访问的数据提到前面**需要使用链表**。

那么问题就在如何结合两个结构。
通过这次，自己对STL中的数据结构提供了哪一些操作还是很不熟悉。

```
list 的 splice函数，back(), pop_back();
map  的 erase(), []=(直接赋值(插入))
```