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
        for (int i = 0; i < 101; i++) {
            if (hashTable[i] == s || size > 100)
                return 0;
        }
        
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
        int pos;
        
        for (int i = 0; i < 101; i++) {
            if (hashTable[i] == s)
                pos = i;
            else
                return 0;
        }

        hashTable[pos] = "empty";
        size--;

        return 1;
    }

    void print() {
        cout << endl << size;

        for (int i = 0; i < 101; i++) {
            if (hashTable[i] != "empty")
                cout << endl << i << ":" << hashTable[i];
        }
    }

};

int main() {
    Hash h;
    int t, n;
    string op, key;

    cin >> t;
    cin.ignore();

    do {
        cin >> n;
        cin.ignore();
        
        do {
            cin >> op;
            cin.ignore();
            
            key = op.substr(4, op.size());

            if (op[0] == 'A')
                if (!(key == ""))
                    h.insert(key);
            else
                if (!(key == ""))
                    h.remove(key);
        } while (--n);

        h.print();
    } while (--t);

    return 0;
}
