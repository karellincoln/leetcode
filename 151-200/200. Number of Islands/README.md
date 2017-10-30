## 200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
```
11110
11010
11000
00000
```
Answer: 1

Example 2:
```
11000
11000
00100
00011
```
Answer: 3


### 思考

印象中我leetcode中有类似的题目，是使用变量加深度优先搜索，想了一下这个也可以做到。


### 代码

```

func numIslands(grid [][]byte) int {
    result := 0
    for i, row := range grid {
        for j, val := range row {
            if val == '1' {
                result++
                DFS(grid, i, j)
            }
        } 
    }
    return result
}

func DFS(grid [][]byte, i, j int) {
    if i >= len(grid) || i < 0 || j >= len(grid[0]) || j < 0 {
        return 
    }
    if grid[i][j] != '1' {
        return
    }
    grid[i][j] = '0'
    
    DFS(grid, i + 1, j)
    DFS(grid, i - 1, j)
    DFS(grid, i, j + 1)
    DFS(grid, i, j - 1)
}

```
