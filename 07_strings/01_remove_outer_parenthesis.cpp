#include<bits/stdc++.h>
using namespace std;

class Solution
{
    // Okay, so the solution is a bit crude and can be made readable, but i am keeping the crude one to 
    // when i revisit, i know what my thought process was
public:
    string removeOuterParentheses(string s)
    {
        if (s == "()" || s == "")
            return "";
        // so these are the base cases, i dont want my code to run into, which were reduced
        // from question's description
        string ans = ""; 
        // we initialize a output string
        int i = 0, j = 0; // this is a linear search, not two pointer, i and j are used for clarity
        // i is used to find the starting opening brackets which are the outermost parenthesis
        while (i < s.length())
        {
            if (s[i] == '(' && s[i + 1] == '(') // so if you encounter double opening brackets, this is the staring of nested parenthesis
            {
                j = i + 1; // we ignore the opening bracket and start from inner ones
                int openBrackets = 1, closedBrackets = 0; // to avoid the string appending, prematurely because fo ede case
                // as we are breaking for opening == closed
                // (()(('))') the closing parenthesis would break the condition, hence i keep opening bracket as 1 to avoid that
                while (j < s.length())
                {
                    if (s[j] == '(')
                    {
                        openBrackets++;
                        ans += s[j];
                        j++;
                    }
                    else
                    {
                        closedBrackets++;
                        ans += s[j];
                        j++;
                    }
                    // the above if else fills up the string with the 
                    // but it also fills the closing bracket of outer parenthesis, hence we pop that bracket after the loop
                    if (openBrackets == closedBrackets)
                        break;
                }
                ans.pop_back();
                i = j; // now that we have appended the strings, we move the i pointer to next set of parenthesis
            }
            else if (s[i] == '(' && s[i + 1] == ')') // say if we nested parenthesis, and () appear, by question's description we replace it wit "", so we dont append it in output
                i = i + 2;
            else
                i++;
        }
        return ans;
    }
};

// now that we have the crude optimal solution
// it was not as much readable, but it helped me understand the question deeply

// here is a more readable version

class Solution2
{
public:
    string removeOuterParentheses(string s)
    {
        if (s == "()" || s == "")
            return "";
        //in this scenario,, i am keeping the base condition as it is
        string ans = "";
        int i = 0, open = 0;
        // from above solution we understood that we need the contigious open brackets > 1 for a nested parenthesis
        // but to implement it with a stopping condition, we reduce open count when a closing bracket is encountered
        while(i < s.length()){
            if(s[i] == '('){
                if(open > 0) ans += s[i];
                open++;
                //if open bracket is encountered, we increament it.
                //but we only append the bracket in string if it is not outermost parethesis
                // which is confirmed when open > 0, as on 0 it is outermost
            }
            else{
                open--;
                if(open!=0){
                    ans += s[i];
                }
                // similar to opening bracket, when we encounter the closing bracket, we decreament open
                // but only append in the string if open != 0
            }
            i++;
        }

        return ans;
    }
};