using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class ABC
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        
        //　N桁の二進数組み合わせを生成する
        for(long bit = 0; bit < (1 << N); bit++)
        {
            for(int i = 0 ; i < N ;i++){
                // N桁目の論理和が１なら１を０なら０を出力する
                if((bit & (1 << i)) == (1 << i))
                {
                    Console.Write(1);
                }
                else {
                    Console.Write(0);
                }
            }
            Console.WriteLine();
        }
    }
}