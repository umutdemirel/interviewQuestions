//
//  MultiplyStrings.h
//  
//
//  https://leetcode.com/problems/multiply-strings/description/
//

#ifndef MultiplyStrings_h
#define MultiplyStrings_h

class Solution {
public:
    int charToNum(char c)
    {
        return (int)c - 48;
    }
    
    string numToStr(int num)
    {
        string result = "";
        
        while (num > 0)
        {
            int remainder = num % 10;
            char c = '0' + remainder;
            result = c + result;
            num = (num - remainder) / 10;
        }
        
        return result;
    }
    
    string add(string num1, string num2)
    {
        string result = "";
        
        int iteratorNum1 = num1.length() - 1;
        int iteratorNum2 = num2.length() - 1;
        
        int extra = 0;
        while (iteratorNum1 >= 0 && iteratorNum2 >= 0)
        {
            //cout << num1[iteratorNum1] << " " << charToNum(num1[iteratorNum1]) << endl;
            //cout << num2[iteratorNum2] << " " << charToNum(num2[iteratorNum2]) << endl;
            
            int tempTotal = charToNum(num1[iteratorNum1]) + charToNum(num2[iteratorNum2]) + extra;
            
            //cout << "temp total : " << tempTotal << endl;
            
            extra = tempTotal > 9 ? 1 : 0;
            char tempTotalChar = '0' + (tempTotal % 10);
            
            //cout << tempTotalChar << endl;
            
            result = tempTotalChar + result;
            iteratorNum1--;
            iteratorNum2--;
        }
        
        if (iteratorNum1 < 0 && iteratorNum2 < 0)
        {
            if (extra == 1)
            {
                result = '1' + result;
            }
        }
        else if (iteratorNum1 < 0)
        {
            for (int i = iteratorNum2; i >= 0; i--)
            {
                int tempTotal = charToNum(num2[i]) + extra;
                extra = tempTotal > 9 ? 1 : 0;
                char tempTotalChar = '0' + (tempTotal % 10);
                result = tempTotalChar + result;
            }
            if (extra == 1)
            {
                result = '1' + result;
            }
        }
        else if (iteratorNum2 < 0)
        {
            for (int i = iteratorNum1; i >= 0; i--)
            {
                int tempTotal = charToNum(num1[i]) + extra;
                extra = tempTotal > 9 ? 1 : 0;
                char tempTotalChar = '0' + (tempTotal % 10);
                result = tempTotalChar + result;
            }
            if (extra == 1)
            {
                result = '1' + result;
            }
        }
        
        return result;
    }
    
    string multiply(string num1, string num2) {
        string result = "0";
        
        if (num1 == "0" || num2 == "0")
        {
            return result;
        }
        
        string tenTimes = "";
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            string tenTimes2 = "";
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                int multiple = charToNum(num1[i]) * charToNum(num2[j]);
                
                //cout << charToNum(num1[i]) << " * " << charToNum(num2[j]) << " = " << multiple << endl;
                
                string multipleStr = numToStr(multiple);
                
                //cout << multipleStr << endl;
                multipleStr += tenTimes2;
                tenTimes2 += "0";
                
                multipleStr += tenTimes;
                
                //cout << result << " + " << multipleStr;
                
                result = add(result, multipleStr);
                
                //cout << " = " << result << endl;
            }
            tenTimes += "0";
        }
        
        return result;
    }
};

#endif /* MultiplyStrings_h */
