#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

template <class T>
class PriorityQueue {
public:
	std::vector<std::pair<T, int>> heapStorage;

	PriorityQueue() = default;

	PriorityQueue(std::vector<std::pair<T, int>> data) { 
		heapStorage = data;
		for (int i = data.size() - 1; i >= 0; i--) {
			diving(i);
		}
	}

private:
	int leftChild(int i) {
		if (2 * i + 1 < heapStorage.size()) return 2 * i + 1;
		return -1;
	}

	int rightChild(int i) {
		if (2 * i + 2 < heapStorage.size()) return 2 * i + 2;
		return -1;
	}

	int minChild(int i) {
		int l = leftChild(i);
		int r = rightChild(i);
		if (l == -1) return -1;
		if (r == -1) return l;
		if (key(l) < key(r)) return l;
		return r;
	}

	int parent(int i) {
		if (i == 0) return -1;
		return (i - 1) / 2;
	}

	int key(int i) {
		return heapStorage[i].second;
	}

	void diving(int i) {
		int j1 = i;
		int j2 = minChild(i);
		while (j2 != -1 && key(j1) > key(j2)) {
			std::swap(heapStorage[j1], heapStorage[j2]);
			j1 = j2;
			j2 = minChild(j1);
		}
	}

	void emersion(int i) {
		int j1 = i;
		int j2 = parent(i);
		while (j2 != -1 && key(j1) < key(j2)) {
			std::swap(heapStorage[j1], heapStorage[j2]);
			j1 = j2;
			j2 = parent(j1);
		}
	}

public:

	bool empty() const {
		return heapStorage.empty();
	}

	void push(const std::pair<T, int>& elem) {
		heapStorage.push_back(elem);
		emersion(heapStorage.size() - 1);
	}

	void pop() {
		if (heapStorage.empty()) {
			throw std::runtime_error("PriorityQueue is empty");
		}
		std::swap(heapStorage[0], heapStorage.back());
		heapStorage.pop_back();
		if (!heapStorage.empty()) {
			diving(0);
		}
	}

	T top() const {
		if (heapStorage.empty()) {
			throw std::runtime_error("PriorityQueue is empty");
		}
		return heapStorage[0].first;
	}

	void mergeQueue(PriorityQueue<T>& q1) {
		while (!q1.empty()) {
			push(q1.top());
			q1.pop();
		}
	}

};