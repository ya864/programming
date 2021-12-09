using System;

public class Test
{	
	static int[] permArray = new int[1];
	static int n = 0;

	public static void Main()
	{
		string line;
		line = Console.ReadLine();
		n = int.Parse(line); //取り出す要素数＆要素の最大値
		Array.Resize(ref permArray, n+1);

		junretu(1);

	}
	
	//二進数の順列を生成する関数　
	public static void junretu(int k){
		//要素数を超えたらreturn
		if(k > n){
			for(int i=1;i<permArray.Length;i++){
				Console.Write(permArray[i]);
			}
			Console.WriteLine("");
			return;
		}
		//次の要素を生成する
		for(int x=1;x<=n;x++){
		    for(int y=0; y<=1; y++){
		    	if(x == k){
					permArray[k] = y;
					junretu(k+1);	
				}
		    }
		}
		return;
	}
}