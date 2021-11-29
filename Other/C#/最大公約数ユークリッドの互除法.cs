

   // ユークリッドの互除法により、最大公約数を返す
        public static int GCD(int a , int b)
        {
            int c = 0;
            // 引数bの方が大きい場合、入れ替える。　c = a % b　のため
            if(a < b) return GCD(b,a);
            while(b != 0)
            {
                c = a % b;
                a = b;
                b = c;
            }
            return a;
        }