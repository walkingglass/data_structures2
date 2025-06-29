#include <vector>
#include <stdexcept>
#include <algorithm>

template <class T>
class MinPQ {
public:
    virtual ~MinPQ() {}

    virtual bool IsEmpty() const = 0;
    virtual const T& Top() const = 0;
    virtual void Push(const T&) = 0;
    virtual void Pop() = 0;
};

template <class T>
class MinHeap : public MinPQ<T> 
{
private:
    std::vector<T> heap;

    void HeapifyUp(int idx) {
        while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
            std::swap(heap[idx], heap[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    void HeapifyDown(int idx) {
        int n = heap.size();
        while (2 * idx + 1 < n) {
            int smallest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < n && heap[left] < heap[smallest]) smallest = left;
            if (right < n && heap[right] < heap[smallest]) smallest = right;

            if (smallest != idx) {
                std::swap(heap[idx], heap[smallest]);
                idx = smallest;
            }
            else {
                break;
            }
        }
    }

public:
    bool IsEmpty() const override {
        return heap.empty();
    }

    const T& Top() const override {
        if (IsEmpty()) throw std::out_of_range("堆為空");
        return heap[0];
    }

    void Push(const T& value) override {
        heap.push_back(value);
        HeapifyUp(heap.size() - 1);
    }

    void Pop() override {
        if (IsEmpty()) throw std::out_of_range("堆為空");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            HeapifyDown(0);
        }
    }
};
