using System;
using System.Collections;
using System.Linq;


public class BinarySearch
{
    public static int upperBinarySearch(int[] A , int key){
        int left = 0;
        int right = A.Length;

        while(left < right) {
                int mid = (left + right) / 2;
                if (key < A[mid]){
                    right = mid;
                } else {
                    left = mid +1;
                }
            }
            return A.Length - right;
    }


	public static void Main()
	{
        //配列の個数
        int n = int.Parse(Console.ReadLine());

        //配列の要素を数値に入れてソート       
        string[] str = Console.ReadLine().Split(' ');
        int[] nums = new int[n];
        for(int i = 0 ; i < n ; i++){
            nums[i] = int.Parse(str[i]);
        }
        Array.Sort(nums);
        
        //指定値
        int key = int.Parse(Console.ReadLine());

        //指定要素以下の数を二分探索
        int ans = upperBinarySearch(nums, key);

        //表示
        Console.WriteLine(ans);

    }
}