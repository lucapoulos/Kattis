#include <bits/stdc++.h>
using namespace std;


struct oper {
    string str;
    int prio;
};

oper create(string s) {
    oper op;
    if (s == "/" || s == "*") op.prio = 1;
    else op.prio = 0;
    op.str = s;
    return op;
}

int compute(string s, int a, int b) { // perform arithmetic 16 16
    switch (s[0]) {
        case '/':
            a /= b;
            break;
        case '*':
             a *= b;
            break;
        case '-':
            a -= b;
            break;
        case '+':
            a += b;
            break;
    }
    return a;
}

int main() {
    int t;
    cin >> t;
    string arr[] = {"/", "*", "+", "-"};

    while (t>0) {
        int n;
        cin >> n;
        string str = "4 ";
        bool valid = false;
        for (int i = 0; i < 4; ++i) { // first conditional change
            oper op1 = create(arr[i]);
            for (int j = 0; j < 4; ++j) { // second conditional change
                oper op2 = create(arr[j]);
                    for (int k = 0; k < 4; ++k) { // third conditional change
                        oper op3 = create(arr[k]);
                        int final = 4;
                        if (op2.prio < op3.prio) {
                            final = compute(op3.str, 4, 4); // 16
                            if (op1.prio > op2.prio) { // 3 and 4 then 1 then 2
                                int temp = compute(op1.str, 4, 4); // 16
                                final = compute(op2.str, temp, final);
                            } else { // 1 and 2 first then 3 and 4
                                int temp = compute(op2.str, 4, final);
                                final = compute(op1.str, 4, temp);
                            }
                        } else if (op2.prio > op1.prio) { // 2 < 3
                            final = compute(op2.str, 4, 4);
                            if (op3.prio > op1.prio) {
                                int temp = compute(op3.str, final, 4);
                                final = compute(op1.str, 4, temp);
                            } else {
                                final = compute(op1.str, 4, final);
                                final = compute(op3.str, final, 4);
                            }
                       } else {
                            final = compute(op1.str, 4, 4);
                            final = compute(op2.str, final, 4);
                            final = compute(op3.str, final, 4);
                        }

                    if (final == n) {
                        str = "4 " + arr[i] + " 4 " + arr[j] + " 4 " + arr[k] + " 4 = " + to_string(n);
                        valid = true;
                        goto label;
                    }

                }
            }
        }

        label: if (!valid) cout << "no solution" << endl;
        else cout << str << endl;
        t--;
    }

    return 0;
}
