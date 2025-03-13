#include "pch.h"

TEST(LinkedListCase, addNode) {
  LinkedList<int> testList;
	//check empty, get entry on empty, push an element then check again, get length, get element
  EXPECT_TRUE(testList.isEmpty());
  EXPECT_THROW({
	int entry = testList.getEntry(1);
	  }, PrecondViolatedExcep);
  testList.push(1);
  EXPECT_FALSE(testList.isEmpty());
  EXPECT_EQ(testList.getLength(), 1);
  EXPECT_EQ(testList.getEntry(1), 1);
  
	//set bad entry, push an element then set good entry
  EXPECT_THROW({
	  testList.setEntry(2,2);
	  }, PrecondViolatedExcep);
  testList.push(2);
  testList.setEntry(2, 100);
  EXPECT_EQ(testList.getEntry(2), 100);
}

TEST(LinkedListCase, clear) {
  LinkedList<int> testList;
  testList.push(1);
  testList.push(2);
  testList.push(3);

}