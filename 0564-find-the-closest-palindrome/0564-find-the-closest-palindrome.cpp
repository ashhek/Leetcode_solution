class Solution {
public:
    bool ispal(string s)
    {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    //checking if string is 9999....
    bool all9(string &s)
    {
        for(auto x:s)
            if(x!='9')
                return false;
        return true;
    }
    // checking if string is 100000... or 100000...1
    bool one0(string &s)
    {
        int len=s.length();
        if(s[0]!='1')
            return false;
        if(s[len-1]!='1' && s[len-1]!='0' )
            return false;
        for(int i=1;i<len-1;i++)
            if(s[i]!='0')
                return false;
        return true;
    }
    //incrementing 1 in string 
    string increment1(string s)
    {
        int len=s.length();
        int i=len-1;
        int c=1;
        while(i>=0 && c==1)
        {
            int x=s[i]-'0';
            x = x==9?0:x+c;
            c = x?0:1;
            s[i]=x+'0';
            i-=1;
        }
        if(c)
        {
            string ans="1";
            ans+=s;
            s=ans;
        }
        return s;
    }
    // decrementing 1 in string 
    string decrement1(string s)
    {
        int len=s.length();
        int i=len-1;
        int c=1;
        while(i>=0 && c==1)
        {
            int x=s[i]-'0';
            x = x?x-1:9;
            c = x==9?1:0;
            s[i]=x+'0';
            i-=1;
        }
        if(c)
        {
            s="-1";
        }
        if(s[0]=='0')
        {
            for(int i=0;i<len-1;i++)
                s[i]=s[i+1];
            s.pop_back();
        }
        return s;
    }
    //making palindrome from root(half string) 
    void makepal(string &root,int len)
    {
        int i=root.length()-1;
        if(len/2 < i+1)
            i--;
        
        while(i>=0)
            root+=root[i--];
    }
    // To find absolute diffrence (s1-s2) 
    long long diff(string s1,string s2) 
    {
        bool neg=false;
        if(s2>s1)
        {
            swap(s1,s2);
            neg=true;
        }
        int i=s1.size()-1;
        
        long long ans=0;
        long long mul=1;
        int c=0;
        while(i>=0)
        {
            int d1=s1[i]-'0';
            int d2=s2[i]-'0';
            if(d1>=(d2+c))
            {
                ans+=(d1-(d2+c))*mul;
                c=0;
            }
            else
            {
                d1= 10 + d1;
                ans+=(d1-(d2+c))*mul;
                c=1;
            }
            mul*=10;
            i--;
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        int len=n.length();
        
        // if string is less than 10 decrement by 1,if 11 return 9
        if(len<=2)
        {
            int k=stoi(n);
            if(k==11)
                return "9";
            else if(k<=10)
                return to_string(k-1);
        }
        // if string is 9999... = 100000...
        if(all9(n))
        {
            string ans="1";
            while(len--)
                ans+='0';
            ans.pop_back();
            ans+='1';
            return ans;
        }
        // if string is 10000... or 10000...1  = 99999...
        if(one0(n))
        {
            for(auto &x:n)
                x='9';
            n.pop_back();
            return n;
        }
        // else
        bool palin=ispal(n);
        string root1="";
        for(int i=0;i<(len+1)/2;i++)
            root1+=n[i];
			
        string root0=decrement1(root1);
        string root2=increment1(root1);
        
        makepal(root0,len);
        makepal(root2,len);
        
        long long d0=diff(n,root0);
        long long d2=diff(n,root2);
        
        string ans="";
        if(d0<=d2)
            ans= root0;
        else
            ans= root2;
        
        // if string is palindrome we compare 2 strings decremented and incremented.
        if(palin)
            return ans;
        
        //if string is not palindrome check for 3 cases.
        makepal(root1,len);
        long long d1=diff(n,root1);
        if(d1<=d2 && d1<d0)
            return root1;
        
        return ans;
    }
};