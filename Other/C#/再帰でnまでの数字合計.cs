using System;

public class Test
{
	public static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		int[] array = new int[n];
		for(int i=0;i<n;i++){
			array[i] = i+1;
		}
		int ans = Sum(array,n-1,0);
		Console.WriteLine(ans);
	}

	public static int Sum(int[] array,int n,int sum)
	{	
		sum += array[n];
		if(n==0){
			return sum;
		}
			return Sum(array,n-1,sum);
		}
}