


// 組み合わせの総数を求める関数
//組み合わせ爆発に対応するためにlong型で引数を設定することを忘れないように。


    public static long Combinations(long n,long r)
    {
        long N = 1;
        for(long a=n;a>r;a--){
            N = N*a;
        }

        long R = 1;

        for(long b=(n-r);b>1;b--){
            R = R*b;
        }

        long ans = N/R;
	
        return ans;
    }
