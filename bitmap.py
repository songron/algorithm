#coding=utf8

"""
    Bitmap by python array.

    python array: http://docs.python.org/2/library/array.html
"""
import array
import hashlib


class BitMap():
    '''
        array(0b00000000, 0b00000000, 0b00000000, ... )
    '''

    def __init__(self, n):
        self.arr = array.array('B', [0]*n)
        self.length = n

    def set_bit(self, i):
        i, r = divmod(i, 8)
        self.arr[i] |= (1<<r)
        return True

    def get_bit(self, i):
        i, r = divmod(i, 8)
        if self.arr[i] & (1<<r):
            return True
        return False


def sort_demo(li):
    bm = BitMap( max(li)/8 + 1 )
    for i in li:
        bm.set_bit(i)
    res = []
    base = 0
    for a in bm.arr:
        bi = 0b1
        for i in xrange(8):
            if a & bi:
                res.append( base+i )
            bi = bi << 1
        base += 8
    return res


def test():
    import random
    li = random.sample( range(100), 10 )
    print li
    print
    print sort_demo(li)


if __name__ == '__main__':
    test()

