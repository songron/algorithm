#coding=utf8

"""
    Knuth-Morris-Pratt algorithm -- KMP-search for string matching.
    Reference: http://www.inf.fh-flensburg.de/lang/algorithmen/pattern/kmpen.htm

    complexity of preprocess or kmpsearch is O(m), O(n) respectly.
    n > m, so overall complexity of KMP algorithm is O(n)
"""

def preprocess(t):
    m = len(t)
    next = [0]*(m)
    i = 1
    j = 0
    """
        In this loop, i+=1 is excuted exactly m times.
        j=next[j-1], it will decrease the value of j by at least 1. 
        j can only be increased at most m times, 
        so j=next[j-1] will be excuted at most m times.
        So, overall loop requires at most 2m=O(m) steps.
    """
    while i<m:
        if t[i] == t[j]:
            j += 1
            next[i] = j
        elif j == 0:
            next[i] = 0
        else:
            j = next[j-1]
            continue
        i += 1
    return next

def kmpsearch(s, t, next):
    n = len(s)
    m = len(t)
    i = j = 0
    res = []
    """
        In this loop, i+=1 will be excuted at most n times.
        j+=1 is excuted at most n times.
        j=next[j-1] decrease j at least 1, so it will be excuted at most n times.
        i+=1 is not excuted only when j=next[j-1] is excuted !
        So, overall loop requires at most 2n=O(n) steps.
    """
    while i < n and m-j <= n-i:  #if m-j>n-1, remain of t cannot match any substring of remain of s
        while j<m and s[i] == t[j]:
            i += 1
            j += 1
        if j == 0:
            i += 1
        else:
            if j == m: #find a result
                res.append(i-j)
            j = next[j-1] # decrease j at least 1
    return res


def test():
    s = 'abababaaasdfababaaasdfababa'
    t = 'ababaa'
    next = preprocess(t)
    res = kmpsearch(s, t, next)
    print res

if __name__ == '__main__':
    test()
