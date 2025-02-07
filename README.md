# N-Queens-Problem-C-
📌 Problem Statement The N-Queens problem is a classic backtracking problem where we must place N queens on an N×N chessboard such that no two queens attack each other. Queens can attack in the same row, column, or diagonal.  👉 Goal: Find all valid solutions where N queens can be placed safely.

The **N-Queens** problem is available on **LeetCode**:  

🔗 **LeetCode Problem Link:**  
👉 [**52. N-Queens II**](https://leetcode.com/problems/n-queens-ii/)  
👉 [**51. N-Queens**](https://leetcode.com/problems/n-queens/)  

These problems involve finding all valid placements of `N` queens on an `N×N` chessboard using **backtracking**.

### **🔍 Deep Explanation of the N-Queens Code**  

This code solves the **N-Queens** problem using **backtracking**. Let’s break it down **step by step**.  

---

## **📌 1. Class `NQueens`**
The `NQueens` class contains:  
- **A vector of solutions** → `solutions` stores all valid N-Queens placements.  
- **Helper functions** → `isSafe()` checks if a queen can be placed, and `solve()` performs backtracking.  

```cpp
class NQueens {
private:
    vector<vector<string>> solutions;  // Store all valid board configurations
```

---

## **📌 2. Function `isSafe()`**
This function checks if a queen can be safely placed at `board[row][col]` **without being attacked**.

```cpp
bool isSafe(vector<string>& board, int row, int col, int n) {
```

👉 **Three Conditions to Check:**  
1️⃣ **Same Column:**  
   - If any queen exists in the same column above, return `false`.  
   ```cpp
   for (int i = 0; i < row; i++)
       if (board[i][col] == 'Q') return false;
   ```

2️⃣ **Upper Left Diagonal:**  
   - Move diagonally left-up and check for a queen.  
   ```cpp
   for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
       if (board[i][j] == 'Q') return false;
   ```

3️⃣ **Upper Right Diagonal:**  
   - Move diagonally right-up and check for a queen.  
   ```cpp
   for (int i = row, j = col; i >= 0 && j < n; i--, j++)
       if (board[i][j] == 'Q') return false;
   ```

✅ **If none of these conditions fail, return `true` (safe to place a queen).**  

---

## **📌 3. Function `solve()`**
This **recursive function** places queens row by row.

```cpp
void solve(int row, vector<string>& board, int n) {
```

👉 **Base Case:**  
- If we successfully placed queens in all rows (`row == n`), store the board as a solution.  
  ```cpp
  if (row == n) {
      solutions.push_back(board);
      return;
  }
  ```

👉 **Recursive Step:**  
- Try placing a queen in **each column of the current row**.  
  ```cpp
  for (int col = 0; col < n; col++) {
  ```

- **Check if it's safe** to place a queen.  
  ```cpp
  if (isSafe(board, row, col, n)) {
  ```

- **Place the queen (`'Q'`), move to the next row, and backtrack if needed.**  
  ```cpp
  board[row][col] = 'Q';
  solve(row + 1, board, n);
  board[row][col] = '.';  // Backtrack
  ```

---

## **📌 4. Function `solveNQueens()`**
This initializes the chessboard and starts solving.

```cpp
vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));  // Initialize board with empty spaces
    solve(0, board, n);  // Start from row 0
    return solutions;
}
```

---

## **📌 5. `main()` Function**
Takes user input for `N` and prints all solutions.

```cpp
int main() {
    int n;
    cout << "Enter board size (N): ";
    cin >> n;

    NQueens solver;
    vector<vector<string>> solutions = solver.solveNQueens(n);

    cout << "\nTotal Solutions: " << solutions.size() << "\n";
```

👉 **Prints each valid board configuration:**  
```cpp
for (const auto& board : solutions) {
    for (const string& row : board)
        cout << row << endl;
    cout << endl;
}
```

---

## **📌 Example Execution (`N = 4`)**
**Input:**
```
Enter board size (N): 4
```

**Output:**
```
Total Solutions: 2

. Q . .
. . . Q
Q . . .
. . Q .

----------------

. . Q .
Q . . .
. . . Q
. Q . .
```

---

## **⏳ Time Complexity Analysis**
- **Worst-case:** **O(N!)** (exploring all placements).  
- **Optimized with pruning:** Faster than brute force.  

---

## **🔗 Summary**
- **Backtracking explores all possibilities** but avoids unnecessary paths.  
- **Each row gets exactly one queen** ensuring no conflicts in the same row.  
- **isSafe() prevents conflicts** in columns and diagonals.  

✅ **Efficient and elegant recursive approach to solving N-Queens!** 🚀


---

## 📧 Contact & Contribution  

📩 Email: surajpratap469@gmail.com  

⭐ If you found this project useful, please **star** the repository on GitHub! 🚀  
