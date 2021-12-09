

//　素数判定

    public static bool IsPrime(double num)
        {
            if (num % 2 == 0) return false;
        
            double sqrtNum = Math.Sqrt(num);
            for (int i = 3; i <= sqrtNum; i += 2)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
        
            return true;
        }