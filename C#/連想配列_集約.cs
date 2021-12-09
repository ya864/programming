using System;
using System.Linq;
using System.Collections.Generic;

public class Test
{
	public static void Main()
	{
        //連想配列の宣言<キーとなる型, 値となる型>
		Dictionary<string, int> dic = new Dictionary<string, int>();

		int n = int.Parse(Console.ReadLine());
	    string line;
	    for(int i = 0 ; i < n ; i++){
	        line = Console.ReadLine();
            //連想配列に存在するか確認（存在するなら何もしない）
            if(dic.ContainsKey(line)){
	            
	        } else {
	            dic.Add(line,1);
	        }
	    }

	    //連想配列の要素数を数える
	    //4 5 8 8 という数字を与えられた時に、違った数字の種類は３というように集約できる
        Console.WriteLine(dic.Count());
	}                                                                                                                                                                       
}