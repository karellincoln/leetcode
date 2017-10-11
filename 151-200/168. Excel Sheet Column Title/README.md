## 168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:
```
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
```

## 思考

相当于26进制。

## 代码

```

func convertToTitle(n int) string {
    var res string
    for n > 0 {
        res = string('A' + (n - 1) % 26) + res
        n = (n - 1) / 26
    }
    
    return res
}

```
