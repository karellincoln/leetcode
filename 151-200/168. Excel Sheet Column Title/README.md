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



## 171. Excel Sheet Column Number

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
```
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
```


## 代码

```
func titleToNumber(s string) int {
    var res int
    for _, char := range s {
        res = res * 26 + int(char - 'A' + 1)
    }
    return res
}
```
