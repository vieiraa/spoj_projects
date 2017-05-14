#include <iostream>
#include <vector>

using namespace std;

class Hash {
    string hashTable[101];
    int size;

public:
    Hash() {
        for (int i = 0; i < 101; i++)
            hashTable[i] = "empty";

        size = 0;
    }

    int hashKey(string s) {
        int pos = 0;

        for (int i = 0; i < s.size(); i++)
            pos += s[i] * (i + 1);

        pos *= 19;
        pos %= 101;

        return pos;
    }

    int insert(string s) {
        int pos = hashKey(s);

        for (int i = 1; i < 20; pos = (hashKey(s) + (i*i) + (23 * i) % 101), i++) {
            if (hashTable[pos] != s) {
                hashTable[pos] = s;
                size++;

                return 1;
            }
        }

        return 0;
    }

    int remove(string s) {
        int pos = hashKey(s);

        if (pos < 0)
            return 0;

        hashTable[pos] = "empty";
        size--;

        return 1;
    }

    void print() {
        cout << size << endl;

        for (int i = 0; i < 101; i++) {
            if (hashTable[i] != "empty")
                cout << i << ":" << hashTable[i] << endl;
        }
    }

};

int main() {
    Hash h;
    int t, n;
    char op[30], key[30];

    cin >> t;

    do {
        cin >> n;

        do {
            scanf(" %3s:", op);
            scanf(" %s", key);

            string s(key);

            switch(op[0]) {
                case 'A':
                    h.insert(s);
                    break;

                case 'D':
                    h.remove(s);
            }
        } while (--n);

        h.print();
    } while (--t);

    return 0;
}
