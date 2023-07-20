/*
  The given code takes inpout in the form of Quadraples.
  0 #2 #2 +
  1 #4 #2 -
  2 0 1 +
  3 c 2 =
  The given code simplifies the given quadraples and prints the easiest way to get he value into the variable c.
  3 c #6 =
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n], ind;

    cin.ignore();

    for (int j = 0; j < n-1; j++) {
        string S;
        getline(cin, S);
        int i = 0;
        int flag = 0, arg1, arg2;

        while (S[i] != '\n') {
            if (S[i] == ' ') {
                i++;
            }
            else if (S[i] != ' ') {
                if (flag == 0) {
                    ind = int(S[i]) - '0';
                    flag++;
                }
                else if (flag == 1) {
                    if (S[i] == '#') {
                        arg1 = int(S[++i]) - '0';
                    }
                    else {
                        int x = int(S[i]) - '0';
                        arg1 = arr[x];
                    }
                    flag++;
                }
                else if (flag == 2) {
                    if (S[i] == '#') {
                        arg2 = int(S[++i]) - '0';
                    }
                    else {
                        int x = int(S[i]) - '0';
                        arg2 = arr[x];
                    }
                    flag++;
                }
                else if (flag == 3) {
                    if (S[i] == '+') {
                        arr[ind] = arg1 + arg2;
                    }
                    else if (S[i] == '-') {
                        arr[ind] = arg1 - arg2;
                    }
                    else if (S[i] == '*') {
                        arr[ind] = arg1 * arg2;
                    }
                    else if (S[i] == '/') {
                        arr[ind] = arg1 / arg2;
                    }
                    break;
                }
                i++;
            }
        }
        printf("%d %d %d %d\n", ind, arg1, arg2, arr[ind]);
    }
    string S;
    getline(cin, S);
    for (int i = 0; i < 4; i++) {
        cout << S[i];
    }
    cout << '#' << arr[ind] << " =" << endl;
    return 0;
}
