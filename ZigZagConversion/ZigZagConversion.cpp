//
// Created by jerrybai on 2019-01-01.
//

/**********************************************************************
 *
 * Description:
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 * (you may want to display this pattern in a fixed font for better legibility).
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"

 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string s, int numRows);
 *
 * Example 1:
 *
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 * Example 2:
 *
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 *
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 *
 *
***********************************************************************/

// Solution:
//
// Print by line:
//
// Find the character of index of each line, print each line in order.
//
// Algorithm:
//
// 1. If no full ZigZag, return original s. This means that if input string length <= numRows  or numRows == 1.
// 2. For the first line and the last line, the delta between two adjacent index is fixed 2(m - 1), m is the number of rows.
// 3. For other lines, there are two kinds of delta. First one is 2(m - i - 1), the other is 2i.
// 4. Base the analysis above, format the output string line by line.
// 5. Return result
//
// Time Complexity O(n)
// Space Complexity O(1)


class Solution {
public:
    string convert(string s, int numRows) {
        if (1 == numRows || s.length() <= numRows)
        {
            return s;
        }

        int len = s.length();
        string formatLine;
        for (int i = 0; i < numRows; i++)
        {
            int index = i;
            int delta = 0;
            bool oddFlag = true;

            while (index < len)
            {
                formatLine += s[index];
                if (0 == i || numRows - 1 == i)
                {
                    delta = 2 * (numRows - 1);
                }
                else
                {
                    if (oddFlag)
                    {
                        delta = 2 * (numRows - i - 1);
                    }
                    else
                    {
                        delta = 2 * i;
                    }
                    oddFlag = !oddFlag;
                }
                index += delta;
            }
        }

        return formatLine;
    }
};
