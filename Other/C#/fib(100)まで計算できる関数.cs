using System;
using System.Linq;


public class Test
{
	public static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		decimal ans = fib(n);
	    Console.WriteLine(ans);
	}

	public static decimal fib(int n){
          decimal[] dp = new decimal[n];
          dp[0] = 1;
          dp[1] = 1;
          for(int i=0; i<n-2;i++){
               dp[i+2] = dp[i] + dp[i+1];
          }
          return dp[n-1];
	}
}