using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
	public static string StringReverse(string s)
	{
		char[] charArray = s.ToCharArray();
		Array.Reverse(charArray);
		return new string(charArray);
	}

	public static void Main()
	{
		string str = "abcde";
        str = StringReverse(str);
        // str = "edcba";
	}                                                                                                                                                                       
}