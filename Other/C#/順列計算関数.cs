
// 順列計算関数

    public static long Permutations(long n,long r)
    {
        long N = 1;
        for(long a=n;a>1;a--){
            N = N*a;
        }

        long R = 1;

        for(long b=(n-r);b>1;b--){
            R = R*b;
        }

        long ans = N/R;
	
        return ans;
    }
