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
		
		Console.WriteLine(cnt);
	}
	
	//順列を生成する関数　
	public static void junretu(int k){
		//要素数を超えたらreturn 何か処理するのもよし
		if(k > n){
			return;
		}
		//次の要素を生成する
		int y;
		for(int x=1; x<=n; x++){
		//すでに決定した要素と、重複する場合は戻る
			for(y=1; y<k; y++){
				if(permArray[y] == x){
					break;
				}
			}
			//重複しないなら配列に格納する。
			if(y == k){
					permArray[k] = x;
					junretu(k+1);	
				}
		}
		return;
		
	}
	
}