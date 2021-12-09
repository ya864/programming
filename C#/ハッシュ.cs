
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Hashset
{
	public static void Main()
	{
        int n = int.Parse(Console.ReadLine());

        HashSet<string> hs = new HashSet<string>();
        StringBuilder sb = new StringBuilder();

        for(int i = 0 ; i < n ; i++){
            string[] input = Console.ReadLine().Split(' ');

            if(input[0] == "insert") hs.Add(input[1]);
            else{
                if(hs.Contains(input[1])){
                    sb.AppendLine("yes");
                } else {
                    sb.AppendLine("no");
                }
            }
        }

        Console.Write(sb);
    }
}
