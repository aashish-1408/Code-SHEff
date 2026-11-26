# [Yet Another Number Game (NUMGAME)](https://www.codechef.com/problems/NUMGAME)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The game starts with an integer $N$. Two players, Alice and Bob, take turns choosing a proper divisor $d$ of the current number $N$ and replacing $N$ with $N - d$. A proper divisor is any divisor of $N$ excluding $N$ itself. The player who cannot make a move (i.e., when $N=1$) loses. Alice goes first. We need to determine the winner assuming optimal play.

## Intuition & Mathematical Observation
To solve this game, we analyze the parity of $N$:

1.  **If $N$ is even:** Alice can always choose to subtract $1$ (since $1$ is a proper divisor of any even number). Subtracting $1$ from an even number results in an odd number.
2.  **If $N$ is odd:** Any proper divisor $d$ of an odd number $N$ must also be odd. Subtracting an odd divisor from an odd number results in an even number ($Odd - Odd = Even$).

**Game Flow:**
*   If $N$ is **even**, Alice can subtract $1$ to pass an **odd** number to Bob. Bob is then forced to subtract an odd divisor, which will result in an **even** number. Alice will always receive an even number until she eventually reaches $N=2$, where she subtracts $1$ to leave Bob with $N=1$, causing Bob to lose.
*   If $N$ is **odd**, Alice is forced to subtract an odd divisor, resulting in an **even** number for Bob. Bob now holds the winning strategy described above.

**Conclusion:**
*   If $N$ is even, **ALICE** wins.
*   If $N$ is odd, **BOB** wins.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution only requires a single parity check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Game Analysis:
 * - If N is even, Alice can subtract 1 to make it odd.
 * - If N is odd, any move leads to an even number.
 * - Therefore, if N is even, Alice wins. If N is odd, Bob wins.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // If N is even, Alice wins.
        // If N is odd, Bob wins.
        if (n % 2 == 0) {
            cout << "ALICE" << "\n";
        } else {
            cout << "BOB" << "\n";
        }
    }
    return 0;
}
```