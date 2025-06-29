# 外部排序第二階段輸入時間分析報告

## 題目背景

在進行外部排序（External Sorting）時，由於資料量遠大於內部記憶體容量（S << n），我們將排序分為兩個階段：

- **第一階段（Initial Run Formation）**：將資料分成小區塊並進行內部排序後，寫入磁碟成為 `m` 個 sorted runs。
- **第二階段（K-Way Merge）**：利用多路合併演算法，將這些 run 合併為最終的排序結果。

本報告聚焦於**第二階段的輸入時間分析**，並依照下列假設進行：

- 電腦內部記憶體大小為 S（可儲存 S 筆資料），可完全用於 I/O 緩衝。
- 有 n 筆資料被劃分為 m 個 run。
- 使用 `k` 路合併（k-way merge）策略。
- 每次磁碟存取需花費：
  - 尋道時間（Seek Time） `t_seek = 80 ms`
  - 延遲時間（Rotational Latency） `t_latency = 20 ms`
  - 傳輸時間 `t_transfer = 10^-3 秒 / 筆`

---

## 題目參數

| 參數符號 | 數值 | 單位 | 說明 |
|----------|------|------|------|
| `n` | 200,000 | 筆 | 總資料數量 |
| `m` | 64 | 個 | 初始 run 數量 |
| `S` | 2,000 | 筆 | 記憶體可容納資料數 |
| `t_seek` | 0.08 | 秒 | 每次磁碟尋道時間 |
| `t_latency` | 0.02 | 秒 | 每次磁碟延遲時間 |
| `t_transfer` | 0.001 | 秒 / 筆 | 每筆資料的傳輸時間 |
| `k` | 變數 | 無 | 合併路數 |
| `t_cpu` | 常數 | 秒 | CPU 合併所需時間（與 k 無關）|

---

## 第二階段輸入時間 `t_input` 推導

在第二階段，系統將對所有資料執行若干次合併。每進行一次合併層（pass），每筆資料都會被：

- **讀取一次**
- **寫入一次**

因此，每一層合併將產生總共 `2 × n` 筆 I/O 操作。

進行合併所需的層數（passes）為：

num_passes = ⌈log_k m⌉


每筆資料的 I/O 時間為：
t_per_record = t_seek + t_latency + t_transfer
= 0.08 + 0.02 + 0.001
= 0.101 秒

總輸入時間 `t_input` 為：
t_input = num_passes × 2 × n × t_per_record

將數值代入：
t_input = ⌈log_k 64⌉ × 2 × 200000 × 0.101


---

## 不同 `k` 值下的 `t_input` 計算表

| k 值 | ⌈logₖ 64⌉ | t_input（秒） |
|------|------------|----------------|
| 2    | 6          | 6 × 2 × 200000 × 0.101 = **242,400** |
| 4    | 3          | 3 × 2 × 200000 × 0.101 = **121,200** |
| 8    | 3          | 同上 = **121,200** |
| 16   | 2          | 2 × 2 × 200000 × 0.101 = **80,800** |
| 32   | 2          | 同上 = **80,800** |
| 64   | 1          | 1 × 2 × 200000 × 0.101 = **40,400** |

> 註：logₖ64 若非整數需向上取整。

---

## 圖表趨勢（文字說明）
k 值 → 2 4 8 16 32 64
t_input（秒）→ 242400 121200 121200 80800 80800 40400

由上可知：

- `k` 越小 → 合併層數越多 → `t_input` 越大
- `k` 越大 → 合併層數越少 → `t_input` 越小

但當 `k` 非常大時，t_input 的下降趨勢趨緩。

---

## 問題分析：是否總存在某個 `k`，使得 `t_cpu < t_input`？

- 題目指出 `t_cpu` 為常數，與 `k` 無關。
- 而 `t_input` 則會隨著 `k` 增加而遞減。
- 在 `k=2` 時，`t_input = 242,400 秒`，極大，幾乎必定大於任何合理的 `t_cpu`。

因此可得結論：

> ✅ **是的，總存在某個 `k`，使得 `t_cpu < t_input` 成立。**

---

## 結論

- 合併路數 `k` 對總輸入時間 `t_input` 具有決定性影響。
- 增加 `k` 可有效減少合併層數與總 I/O 次數。
- `t_input` 為：  
t_input = ⌈log_k m⌉ × 2 × n × (t_seek + t_latency + t_transfer)
- 因 `t_cpu` 為常數，當 `k` 小時 `t_input` 明顯遠大於 `t_cpu`，因此一定存在某個 `k` 使得：

t_cpu < t_input

- 選擇適當的 `k` 可最佳化 I/O 效能與資源使用。

![image](https://github.com/walkingglass/data_structures2/blob/main/src/%E4%B8%8B%E8%BC%89.png)
