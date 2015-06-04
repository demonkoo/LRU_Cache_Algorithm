# LRU Cache Algorithm （LRU缓存算法）
C++版本，适用于[Leetcode 146](https://leetcode.com/problems/lru-cache/)
##LRU算法介绍
引自[维基百科](http://en.wikipedia.org/wiki/Cache_algorithms#LRU)：
> Discards the least recently used items first. This algorithm requires keeping track of what was used when, which is expensive if one wants to make sure the algorithm always discards the least recently used item. General implementations of this technique require keeping "age bits" for cache-lines and track the "Least Recently Used" cache-line based on age-bits. In such an implementation, every time a cache-line is used, the age of all other cache-lines changes. LRU is actually a family of caching algorithms with members including 2Q by Theodore Johnson and Dennis Shasha,[3] and LRU/K by Pat O'Neil, Betty O'Neil and Gerhard Weikum.

更多详细原理可参考[缓存淘汰算法系列之1——LRU类](http://blog.csdn.net/yunhua_lee/article/details/7599671) 第1节。

##实现细节
* 使用`双向链表`+`哈希表`保证算法效率
	- 双向链表：插入删除效率较高，不需要查找前驱节点
	- 哈希表：查找效率高（保存节点地址），时间复杂度O(1)

