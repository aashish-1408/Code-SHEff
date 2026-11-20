# [Car Range (CARRANGE)](https://www.codechef.com/problems/CARRANGE)

- **Difficulty Rating**: 938
- **Solved in**: 1 attempt(s)

## Problem Summary
A car has a fuel capacity of $V$ litres. When there is only the driver (1 person), the car provides a fuel economy of $M$ km/l. For every additional passenger beyond the driver, the fuel economy decreases by 1 km/l. Given the total number of people $P$ (including the driver), calculate the maximum distance the car can travel with $V$ litres of fuel.

## Intuition & Mathematical Observation
1. **Identify the variables**:
   - $P$: Total number of people in the car.
   - $M$: Fuel economy with only the driver.
   - $V$: Total fuel capacity.
2. **Calculate the reduction**: Since the driver is already accounted for in the base economy $M$, the number of *extra* passengers is $(P - 1)$.
3. **Determine effective economy**: Each extra passenger reduces the economy by 1 km/l. Therefore, the new fuel economy is $M - (P - 1)$.
4. **Calculate distance**: Distance is simply the product of the effective fuel economy and the total fuel volume:
   $$\text{Distance} = (M - (P - 1)) \times V$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Base fuel economy is M km/l (for 1 person).
 * - Every extra passenger decreases fuel economy by 1 km/l.
 * - Total people = P.
 * - Extra passengers = P - 1.
 * - Effective fuel economy = M - (P - 1).
 * - Total fuel = V litres.
 * - Maximum distance = Effective fuel economy * V.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long P, M, V;
        cin >> P >> M >> V;

        // Calculate effective fuel economy
        // The driver is 1 person, so there are (P - 1) extra passengers.
        long long effective_economy = M - (P - 1);

        // Calculate maximum distance
        long long max_distance = effective_economy * V;

        cout << max_distance << "\n";
    }

    return 0;
}
```