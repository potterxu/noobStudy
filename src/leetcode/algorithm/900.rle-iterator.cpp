class RLEIterator
{
public:
    RLEIterator(vector<int> &A)
    {
        v = A;
    }

    int next(int n)
    {
        while (n > 0)
        {
            if (pos >= v.size())
            {
                break;
            }
            else if (v[pos] > 0)
            {
                if (n >= v[pos]) {
                    n -= v[pos];
                    v[pos] = 0;
                } else {
                    v[pos] -= n;
                    n = 0;
                }
            }
            else if (v[pos] == 0)
            {
                pos += 2;
            }
        }
        if (pos >= v.size()) {
            return -1;
        }
        return v[pos+1];
    }

    int pos = 0;
    vector<int> v;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
