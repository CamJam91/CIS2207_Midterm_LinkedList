#include "pch.h"

TEST(LinkedListCase, addNode) {
  LinkedList<int> testList;
	//check empty, push an element then check again, get length
  EXPECT_TRUE(testList.isEmpty());
  testList.push(1);
  EXPECT_FALSE(testList.isEmpty());
  EXPECT_EQ(testList.getLength(), 1);
}

TEST(LinkedListCase, setNode) {
  LinkedList<int> testList;
  testList.push(1);
	//set bad entry, push an element then set good entry
EXPECT_ANY_THROW(testList.setEntry(2, 2););
testList.push(2);
testList.setEntry(2, 100);
EXPECT_EQ(testList.getEntry(2), 100);
}

TEST(LinkedListCase, clear) {
  LinkedList<int> testList;
  testList.push(1);
  testList.clear();
  EXPECT_TRUE(testList.isEmpty());
  testList.push(1);
  testList.push(2);
  testList.push(3);
  testList.clear();
}

TEST(LinkedListCase, insertandRemove) {
	LinkedList<int> testList;
	testList.push(1);
	testList.push(2);
	testList.push(3);
		//insert
	testList.insert(2, 100);
	EXPECT_EQ(testList.getEntry(2), 100);
	EXPECT_EQ(testList.getEntry(1), 1);
	EXPECT_EQ(testList.getEntry(3), 2);
	EXPECT_EQ(testList.getEntry(4), 3);
		//remove
	testList.remove(2);
	EXPECT_EQ(testList.getEntry(1), 1);
	EXPECT_EQ(testList.getEntry(2), 2);
	EXPECT_EQ(testList.getEntry(3), 3);
	EXPECT_ANY_THROW(testList.getEntry(4));
}


TEST(RainDataCase, addAndGet) {
	struct RainData {
		chrono::year_month_day date;
		double rainInCm;
	};
	chrono::year_month_day testDate = 1999y / 12 / 23;
	LinkedList<RainData> rainData;
	RainData testData{ testDate, 12 };
	rainData.push(testData);
	EXPECT_EQ(rainData.getEntry(1).date, testDate);
}

TEST(RainDataCase, getAndsetEntry) {
	struct RainData {
		chrono::year_month_day date;
		double rainInCm;
	};
	chrono::year_month_day testDate;
	LinkedList<RainData> rainData;

	for (int count = 1; count < 10; count++) {
		testDate = 1999y / count / 10;
		rainData.push(RainData{ testDate, .1+count });
	}
	for (int count = 1; count < 10; count++) {
		EXPECT_EQ(rainData.getEntry(count).date, chrono::year_month_day(1999y / count / 10));
		EXPECT_EQ(rainData.getEntry(count).rainInCm, .1+count);
	}
	RainData setRainData{ chrono::year_month_day(2003y / 8 / 05), 13 };
	rainData.setEntry(2, setRainData);
	EXPECT_EQ(rainData.getEntry(2).date, chrono::year_month_day(2003y/ 8/ 05 ));
	EXPECT_EQ(rainData.getEntry(2).rainInCm, 13);
}

