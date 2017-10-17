## 187. Repeated DNA Sequences

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,
```
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
```


## 思考

首先是使用hash，map。现在我看了一下别人写的代码，后悔当初为什么要自己写一个字符hash直接使用map的方法不就可以了吗？
**在更好的写法中使用像桶排序一样的方式，将字符串映射成数字，同时也是利用只有四个字符的原因。**

## 代码

```
// 自己的代码
func BKDRHash(s string, pos int) int {
    seed, hash := 131, 0
    for i := 0; i < 10; i++ {
        hash = hash * seed + int(s[pos])
        pos++
    }
    
    return hash
}

func findRepeatedDnaSequences(s string) []string {
    seq_count := make(map[int] int)
    str_pos := make(map[int] int)
    
    for i := 0; i < len(s) - 9; i++ {
        hash := BKDRHash(s, i)
        seq_count[hash]++
        str_pos[hash] = i
    }
    var res []string
    for key, value := range seq_count {
        if value > 1 {
            pos := str_pos[key]
            res = append(res, s[pos:pos+10])
        }
    }
    
    return res
}

// 好一点的写法

func findRepeatedDnaSequences(s string) []string {
    var res []string
    if len(s) <= 10 {
        return nil
    }

    str := ""
    rec := make(map[string]int, len(s)-9)
    for i := 0; i+10 <= len(s); i++ {
        str = s[i : i+10]
        if v := rec[str]; v == 1 {
            res = append(res, str)
        }
        rec[str]++
    }

    return res
}

// 更好的写法
func strToInt(s string) int {
    bit := func(c byte) int {
        switch c {
        case 'A':
            return 0
        case 'C':
            return 1
        case 'G':
            return 2
        case 'T':
            return 3
        }

        return 0
    }

    var ret int

    for i := len(s) - 1; i >= 0; i-- {
        ret = (ret << 2) | bit(s[i])
    }

    return ret
}

func findRepeatedDnaSequences(s string) []string {
    const max int = 1048576 // 4 ^ 10

    var counter [max + 1]uint8
    var ret []string

    for i := 0; i+10 <= len(s); i++ {
        subStr := s[i : i+10]
        index := strToInt(subStr)
        if counter[index] == 0 {
            counter[index] = 1
        } else if counter[index] == 1 {
            ret = append(ret, subStr) // append to result only once
            counter[index] = 2
        }
    }

    return ret
}


```

