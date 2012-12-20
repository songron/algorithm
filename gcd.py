#coding=utf8

"""
    Greatest Common Divisor by Euclid's algorithm.
    gcd(n, m) = gcd(m, n mod m)

    n = km+b => n%m = b = n-km
    1, if gcd(n,m) = r  
        then n=pr and m=qr => n%m = pr-kqr = (p-kq)r 
       So, r is common divisor of (m,n%m)

    2, if gcd(m,n%m) = r 
        then m=pr and n%m=qr => n-km=qr => n=qr+km=qr+kpr=(q+kp)r 
       So, r is common divisor of (n,m)  

    Since 1 and 2, we know gcd(n,m) = gcd(m,n%m)
"""

def gcd(n, m):
    if n < m:
        t = m
        m = n
        n = t

    while m:
        r = n%m
        n = m
        m = r

    return n



def lcm(n, m):
    """
        Least Common Multiple
        lcm(n,m) = n*m/gcd(n,m)
    """
    return n*(m/gcd(n,m))


if __name__ == '__main__':
    print gcd(25,30)
    print lcm(30,25)

