#include "priority-queue.h"
#include <vector>
#include <utility>
#include <gtest.h>

TEST(Queue, canCreateQueue) {
	EXPECT_NO_THROW(PriorityQueue<int> Q);
}

// If I dont have "selfmade" copy constructor, do I need to test it?

TEST(Queue, canPushElement) {
	PriorityQueue<int> Q;

	EXPECT_NO_THROW(for (int i = 0; i < 1000; i++) Q.push({ i, 1 }));
}

TEST(Queue, canPopElement) {
	PriorityQueue<int> Q;

	for (int i = 0; i < 1000; i++) Q.push({ i, 1 });

	EXPECT_NO_THROW(for (int i = 0; i < 1000; i++) Q.pop());
}

TEST(Queue, cantPopFromEmptyQueue) {
	PriorityQueue<int> Q;

	EXPECT_ANY_THROW(Q.pop());
}

TEST(Queue, canGetTopElement) {
	PriorityQueue<int> Q;

	Q.push({ 1, 1 });

	EXPECT_NO_THROW(Q.top());
}

TEST(Queue, cantGetTopElementFromEmptyQueue) {
	PriorityQueue<int> Q;

	EXPECT_ANY_THROW(Q.top());
}

TEST(Queue, canCheckForEmptiness) {
	PriorityQueue<int> Q;
	bool check1 = Q.empty();
	Q.push({ 1, 1 });
	bool check2 = Q.empty();

	EXPECT_TRUE(check1);
	EXPECT_FALSE(check2);
}

TEST(Queue, HoldsRightOrder1) {
	std::vector<int> rightOrder;
	std::vector<int> order;
	PriorityQueue<int> Q;

	for (int i = 0; i < 10000; i++) {
		Q.push({ i, i });
		rightOrder.push_back(i);
	}

	while (!Q.empty()) {
		order.push_back(Q.top());
		Q.pop();
	}

	EXPECT_EQ(rightOrder, order);
}

TEST(Queue, HoldsRightOrderWithSameIndex1) {
	std::vector<int> rightOrder;
	std::vector<int> order;
	PriorityQueue<int> Q;

	for (int i = 0; i < 10000; i++) {
		Q.push({ i, 1 });
		rightOrder.push_back(i);
	}

	while (!Q.empty()) {
		order.push_back(Q.top());
		Q.pop();
	}

	EXPECT_EQ(rightOrder, order);
}
