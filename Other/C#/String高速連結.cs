using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace MyProgram
{
    public class Program
    {	
        // ABC_072B OddString
        public static void Main(string[] args)
        {
            string s = Console.ReadLine();
            // 高速で連結するためにStringBuilderを生成
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            
            //　sの奇数文字のみ連結
            for(int i = 0 ; i < s.Length ; i++)
            {
                if((i+1) % 2 == 1)
                {
                    sb.Append(s[i]);
                }
            }
            Console.WriteLine(sb);
        }
    }
}