using System;
/*
	numまでの素数をarrayに格納している。
 */
public class Test
{

	public static void Main()
	{
		string line;
        line = Console.ReadLine();
		int num = int.Parse(line);
		//最初にarrayLengthを０にしていると、array[0]=2でエラーになる。
		int arrayLength = 1;

		bool sosuu = true;
		int[] array =new int[arrayLength];
		array[0] = 2;
		
		if(num >=3){
			for(int i=3;i<=num;i+=2){
				sosuu = true;
				//平方根までの数字で割り切れるかで素数の判定をしている。
				double root = Math.Sqrt(i);
				for(int z=3;z<=root;z++){
					if(i%z==0)
					{		
						sosuu = false;
						break;
					}	
				}
				if(sosuu==true){
					//配列を拡張して素数を格納
					++arrayLength;
					Array.Resize(ref array, arrayLength);	
						
					array[array.Length-1] = i;
				}
			}
		}
		//素数を全て表示
		for(int zz=0;zz<array.Length;zz++){
			Console.WriteLine(array[zz]);
		}
	}
}