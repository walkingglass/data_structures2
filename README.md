
---

Max/Min Heap

題目原文：
```
template <class T>  
class MaxPQ {  
public:  
    virtual ~MaxPQ() {}

    // return true iff the priority queue is empty
    virtual bool IsEmpty() const = 0;  

    // return reference to max element
    virtual const T& Top() const = 0;  

    // add an element to the priority queue
    virtual void Push(const T&) = 0;  

    // delete element with max priority
    virtual void Pop() = 0;  
};

翻譯：
```

撰寫一個與 ADT 5.2 類似的 C++ 抽象類別 MinPQ，用來定義最小優先佇列（min priority queue）。
接著撰寫一個名為 MinHeap 的 C++ 類別，從 MinPQ 繼承，並實作所有的虛擬函式。
這些函式的時間複雜度應該與 MaxHeap 中相對應的函式相同。


---

2. 二元搜尋樹 Binary Search Tree

(a) 題目原文：

Write a program to start with an initially empty binary search tree and make n random insertions.
Use a uniform random number generator to obtain the values to be inserted.
Measure the height of the resulting BST and divide this height by log2(n).
Do this for n = 100, 500, 1000, 2000, 3000, ..., 10000.
Plot the ratio height / log2(n) as a function of n. The ratio should be approximately constant (around 2). Verify this.

翻譯：

撰寫一個程式，從一棵初始為空的二元搜尋樹開始，並進行 n 次隨機插入。
使用均勻隨機數產生器來產生插入的數值。
接著，計算最終 BST 的高度，並將該高度除以 log₂(n)。
請針對以下 n 值測試：100、500、1000、2000、3000、...、10000。
將高度與 log 比值作圖：height / log₂(n) 對 n 作圖。此比值應大約為常數（約 2）。請驗證這一點。


---

(b) 題目原文：

Write a C++ function to delete the pair with key k from a binary search tree.
What is the time complexity of your function?

翻譯：

撰寫一個 C++ 函式，用來從一棵二元搜尋樹中刪除鍵值為 k 的節點。
請說明你的函式的時間複雜度。


---

3. 外部排序 External Sorting

(a) 題目原文：

n records are to be sorted on a computer with a memory capacity of S records (S << n).
Assume that the entire S-record capacity may be used for input/output buffers.
The input is on disk and consists of m runs.
Assume that each time a disk access is made:

the seek time is t,

the latency time is t, and

the transmission time is t per record transmitted.


What is the total input time t_input for phase two of external sorting if a k-way merge is used,
with internal memory partitioned into input/output buffers to permit overlap of input, output, and CPU processing (as in Program 7.21)?

翻譯：

有 n 筆資料需進行排序，電腦的記憶體只能容納 S 筆資料（假設 S << n）。
整個 S 容量可以完全用作輸入/輸出緩衝區（buffers）。
輸入資料儲存在磁碟上，並被切成 m 個 run（初始排序段）。

假設每次磁碟存取包含以下時間成本：

尋道時間（seek time）：t

延遲時間（latency time）：t

傳輸時間（每筆紀錄）：t


若使用 k 路合併（k-way merge） 並將內部記憶體分割成多個輸入/輸出緩衝區，使得輸入、輸出與 CPU 可同時執行（如同課本的 Program 7.21），
請計算第二階段外部排序的總輸入時間 t_input。


---

(b) 題目原文：

Let the CPU time needed to merge all the runs together be t_cpu (assume it is independent of k, hence constant).
Let:

t = 80 ms

t = 20 ms

n = 200,000

m = 64

t = 10^-3 sec/record

S = 2000


Plot the total input time t_input versus k.
Will there always be a value of k for which t_cpu < t_input?

翻譯：

假設將所有 run 合併的 CPU 所需時間為 t_cpu，且它不依賴 k，也就是為常數。
給定參數如下：

尋道時間 t = 80 毫秒

延遲時間 t = 20 毫秒

總資料筆數 n = 200,000

初始 run 數 m = 64

傳輸時間 t = 10^-3 秒/每筆紀錄

記憶體容量 S = 2000


請繪製 總輸入時間 t_input 與 k 的關係圖。
並回答：是否總是存在某個 k，使得 t_cpu < t_input？


---

如果你需要這些問題的完整程式實作、模擬或繪圖，我可以進一步幫你補上！是否需要？

