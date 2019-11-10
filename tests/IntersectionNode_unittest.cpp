// Copyright 2005, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// A sample program demonstrating using Google C++ testing framework.

// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "gtest/gtest.h"

#include "../IntersectionofTwoLinkedLists/IntersectionofTwoLinkedLists.h"

using namespace ::testing;

namespace {

// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

// Tests Length of Lists

class GTestList : public Test {
    public:
        GTestList() : Test() {
            headA = NULL;
            headB = NULL;
        }

        ~GTestList() override {

        }

        void SetUp() override {
            ListNode* nodeA = NULL;
            int nodesA[] = {4, 1};
            for (auto num : nodesA) {
                if (!headA) {
                    nodeA = new ListNode(num);
                    headA = nodeA;
                }
                else {
                    nodeA->next = new ListNode(num);
                    nodeA = nodeA->next;
                }
            }

            ListNode* nodeB = NULL;
            int nodesB[] = {5, 0, 1};
            for (auto num : nodesB) {
                if (!headB) {
                    nodeB = new ListNode(num);
                    headB = nodeB;
                }
                else {
                    nodeB->next = new ListNode(num);
                    nodeB = nodeB->next;
                }
            }

            int nodesCom[] = {7, 8, 4, 5};
            for (auto num : nodesCom) {
                nodeA->next = new ListNode(num);
                nodeA = nodeA->next;
                nodeB->next = nodeA;
                nodeB = nodeB->next;
            }
            std::cout << "Test fixture setup." << std::endl;
        }

        void TearDown() override {
            ListNode* deleteA = headA;
            ListNode* nextNode = deleteA;
            while (nextNode) {
                deleteA = nextNode;
                nextNode = nextNode->next;
                delete deleteA;
            }
            headA = NULL;
            std::cout << "Test fixture teardown." << std::endl;
        }

    public:
        ListNode *headA;
        ListNode *headB;
};

TEST_F(GTestList, test_list_length) {
    Solution s;
    EXPECT_EQ(7, s.getIntersectionNode(headA, headB));
}


//TEST(listLengthTest, Equal) {
//    // This test belongs to the listLengthTest test case.
//    // Following are some cases for traversal list to get right length
////    EXCEPT_EQ(2, )
//}

//// Tests negative input.
//TEST(isStrobogrammaticTest, Negative) {
//// This test belongs to the isStrobogrammaticTest test case.
//
//EXPECT_FALSE(isStrobogrammatic(""));
//EXPECT_FALSE(isStrobogrammatic("639"));
//EXPECT_FALSE(isStrobogrammatic("858"));
//}
//
//// Tests some positive cases.
//TEST(isStrobogrammaticTest, Positive) {
//EXPECT_TRUE(isStrobogrammatic("69"));
//EXPECT_TRUE(isStrobogrammatic("88"));
//EXPECT_TRUE(isStrobogrammatic("818"));
//EXPECT_TRUE(isStrobogrammatic("609"));
//}

}  // namespace

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
