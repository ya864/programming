using System;

public class Test
{
	//文字の出現回数をカウント
	public static int CountChar(string line, char c) {
		return line.Length - line.Replace(c.ToString(), "").Length;
	}
	
	public static void Main()
	{
		
		//標準入力読み込み部
		string line;		
        line = Console.ReadLine();
		// 例　22-(22-22)
		// 例のような数字を[22],[-],[(],[22],[-],[22]と格納する
		string[] line2 = new string[100];
		int x = 0;
		
		char[]　cArray = line.ToCharArray();
		for(int i=cArray.Length-1; i >=0; i--){
			if(char.IsDigit(cArray[i])){
				line2[x] = line2[x] + cArray[i];
				
			} else {
				++x;
				Array.Resize(ref line2, x);
				line2[x];
			}
		}
		
		Console.WriteLine(line2);
		/*　（の数を数えてループ回数を決定する
		// ( の出現回数をカウント
		int kakko = CountChar(line, '(');
		
		int num;
		num = int.Parse(line);
		
		Console.WriteLine(num);

		// Console.WriteLine(answer);
		*/
	}
}