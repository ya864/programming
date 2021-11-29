
using System;
using System.Collections.Generic;
using System.Linq;

public class SortProgPartition
{
    public static int Partition(int[] A , int p , int r){
        int x = A[r];
        int i = p - 1;
        int temp = 0;

        for(int j = p ; j < r ; j++){
            if(A[j] <= x){
                i++;
                temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
        temp = A[i+1];
        A[i+1] = A[r];
        A[r] = temp;
        return i+1;
    }

	public static void Main()
	{
        int n = int.Parse(Console.ReadLine());
        string[] str = Console.ReadLine().Split(' ');
        int[] A = new int[str.Length+1];

        for(int i = 0 ; i < n ; i++){
            A[i] = int.Parse(str[i]);
        }

        int q = Partition(A, 0 , n-1);

        for(int i = 0; i < n ; i++){
            if(i == q) Console.Write("["+A[i]+"]");
            else  Console.Write(A[i]);
            if(i < n-1){
                Console.Write(" ");
            }
        }
        Console.WriteLine("");

    }

}
