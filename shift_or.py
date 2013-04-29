def pre(t):
    B = {}
    for i in xrange(len(t)):
        c = t[i]
        if c in B:
            B[c] ^= (1 << i)
        else:
            B[c] = ~(1 << i)
    return B

def shift_or_match(s, t):
    B = pre(t)
    D = -1
    m = len(t)
    mask = ~(1 << (m - 1))
    res = []
    for i in xrange(len(s)):
        c = s[i]
        if c in B:
            D = (D << 1) | B[c]
        else:
            D = -1
        if (~(mask | D)):
            res.append(i - m + 1)
    return res

if __name__ == '__main__':
    s = raw_input("Source string:\n")
    t = raw_input("Pattern string:\n")
    res = shift_or_match(s, t)
    print 'Find "%s" in "%s" by positions: ' % (t, s), res
